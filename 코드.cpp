#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include <time.h>
#define countryamount 7 //국가 갯수
#define eventRate 10//이벤트 발생 확률의 역수, 작을수록 빈도 많음. 최소 5부터

typedef enum upgrades_ { level = 1, infect, inhibit }upgrades;
typedef enum choose_ { kill = 1, upgrade }choose;
typedef enum events_ { addDNA, addVAC, lessVAC, addmoreVAC }events;


typedef struct disease_ {
	int DNA;//DNA양
	int level;//바이러스 레벨
	int die;//감염률
}disease;
typedef struct countryl_ {
	char name[100];//국가 이름
}countryl;
typedef struct countries_
{
	int population;//인구수
	int maxpopulation;//최대 인구수
	int infectpopulation;//기본 감염 인구수

}countries;


disease virus1;
int vac, vacwarn = 0;//백신 및 개발도 경고에 대한 변수
int back;//뒤로가기 위한 변수

int day = 1;//지난 일자
countries country[countryamount];
int population[countryamount] = { 1568776, 2310224, 594860, 1100010, 385742, 528720, 38895 };

countryl countryname[countryamount] = { {"East Asia"},{"West Asia"},{"Europe"},{"Africa"},{"South America"},{"North America"},{"Australia"} };// 대륙 이름
char type[100];//질병 이름

int total = population[0] + population[1] + population[2] + population[3] + population[4] + population[5] + population[6];//총 인구수
int maxtotal = total;//최대 인구수 총합
void clear_stdin()
{
	int ch;
	while ((ch = getchar()) != EOF && ch != '\n');
}//입력 버퍼 초기화

int upgrademenu()
{
	int choice;
	system("cls");
	if (virus1.die == 100)
	{
		printf("1 : LEVEL 업그레이드 \n");
		printf("X : 감염률이 최대치(100%%)입니다. \n");//감염률100%면 업그레이드 못하게 함 
		printf("3 : 백신 방해하기 \n");
		printf("\n0: 뒤로가기\n");

		scanf("%d", &choice);
		printf("\n\n");

		if (choice == 0)
			return -1;

		while (choice != 1 && choice != 3)
		{
			printf("유효하지 않은 명령입니다.\n");
			clear_stdin();
			scanf("%d", &choice);
		}
		clear_stdin();
	}
	else
	{
		printf("1 : LEVEL 업그레이드 \n");
		printf("2 : 감염률 업그레이드 \n");
		printf("3 : 백신 방해하기 \n");
		printf("\n0: 뒤로가기\n");

		scanf("%d", &choice);
		printf("\n\n");

		if (choice == 0)
			return -1;
		while (0 >= choice || choice > 3)
		{
			printf("유효하지 않은 명령입니다.\n");
			clear_stdin();
			scanf("%d", &choice);
		}
	}
	back = 0;
	return choice;
}

void killfunc(int countrynum)
{
	countrynum--;
	vac += (virus1.die) / 3 + virus1.level / 10; //감염률/3+level/10 만큼 백신 연구 올라감
	if (vac > 100) vac = 100;            //백신 최대치는 100

	if (country[countrynum].population > 100 * (virus1.level) * (virus1.die))
	{
		country[countrynum].population -= 100 * (virus1.level) * (virus1.die); //선택한 대륙의 사람 감염
		virus1.DNA += (virus1.level) * (virus1.die);      //감염자 수/100 만큼 DNA 획득 
		printf("%s대륙에서 %d명이 감염되어 %d명 남았습니다.\n", countryname[countrynum].name, 100 * (virus1.level) * (virus1.die), country[countrynum].population);
	}
	else {
		printf("%s대륙에서 %d명이 감염되어 0명 남았습니다.\n", countryname[countrynum].name, country[countrynum].population);;
		country[countrynum].population = 0;//감염 가능 인원이 비감염자보다 많으면 비감염자 0으로 만듦
	}
	Sleep(1000);
}
void vaccinefunc()
{
	if (country[day % countryamount].population + virus1.level * vac <= country[day % countryamount].maxpopulation) {
		country[day % countryamount].population += virus1.level * vac;
		printf("당신이 업그레이드 하는 동안 백신으로 %s대륙 에서 %d명이 살아났습니다.\n", countryname[day % 6].name, virus1.level*vac);
		printf("\n");
	}
	else {

		printf("당신이 업그레이드 하는 동안 백신으로 %s대륙 에서 %d명이 살아났습니다.\n", countryname[day % 6].name, country[day % 6].maxpopulation - country[day % 6].population);
		printf("\n");
		country[day % countryamount].population = country[day % countryamount].maxpopulation;
		Sleep(1500);
	}
}
int LVfunc()
{
	int amount; //얼마나 업그레이드 할건지 
	int cost;//업그레이드 비용
	printf("얼마나 업그레이드 하실겁니까?\n");
	printf("LEVEL 1당 DNA 필요량이 10개씩 증가합니다. 기본치 10.\n");
	printf("0:뒤로가기\n\n");
	printf("보유 DNA: %d     현재 level: %d\n", virus1.DNA, virus1.level);
	scanf("%d", &amount);

	cost = ((virus1.level + amount) * (virus1.level + amount - 1) - virus1.level *(virus1.level - 1)) * 5;
	while (virus1.DNA < cost || amount < 0)
	{
		printf("유효하지 않은 명령입니다.\n");
		clear_stdin();
		scanf("%d", &amount);
		cost = ((virus1.level + amount) * (virus1.level + amount - 1) - virus1.level *(virus1.level - 1)) * 5;
	}

	if (amount == 0)
		return -1;
	virus1.DNA -= cost;             //DNA사용하고 
	virus1.level += amount;                    //업그레이드 해주고 

	vaccinefunc();
	return 0;
}
int Infectfunc()
{
	int amount = 0;
	printf("얼마나 업그레이드 하실겁니까?\n");                      //얼마나 업그레이드 할건지 
	printf("감염률 1%%당 DNA 5개가 필요합니다.\n");
	printf("0:뒤로가기\n\n");
	printf("보유 DNA: %d     현재 감염률: %d%%\n", virus1.DNA, virus1.die);
	scanf("%d", &amount);

	while (virus1.DNA < amount * 5 || amount < 0)
	{
		printf("유효하지 않은 명령입니다.\n");
		clear_stdin();
		scanf("%d", &amount);
	}

	if (amount == 0)
		return -1;

	virus1.DNA -= amount * 5;                               //DNA 사용한만큼 빼주고 
	virus1.die += amount;

	if (virus1.die > 100)
		virus1.die = 100;//치사율 최댓값 100으로 설정
	vaccinefunc();
	return 0;
}
int Inhibitfunc()
{
	int amount = 0;
	printf("백신의 완성도를 얼마 감소시킬겁니까?\n");
	printf("백신의 완성도 1%% 감소시키는데 DNA 25개가 필요합니다.\n");
	printf("0:뒤로가기\n\n");
	printf("보유 DNA: %d     백신 완성도: %d%%\n", virus1.DNA, vac);

	scanf("%d", &amount);

	while (virus1.DNA < amount * 25 || amount < 0 || vac < amount)
	{
		printf("유효하지 않은 명령입니다.\n");
		clear_stdin();
		scanf("%d", &amount);
	}

	if (amount == 0)
		return -1;

	vac -= amount;
	virus1.DNA -= amount * 25;
	Sleep(1500);
	return 0;
}
void EndofDay()
{
	virus1.DNA = 1000000;
	int totalinfect = 0;//일일 추가 감염자 총합
	total = country[0].population + country[1].population + country[2].population + country[3].population + country[4].population + country[5].population + country[6].population;
	vac += virus1.level / 20 + virus1.die / 25;//기본 연구량 증가
	for (int i = 0;i < countryamount;i++)
	{
		country[i].infectpopulation = (country[i].maxpopulation - country[i].population)*(virus1.die / 20);//기본 감염자 수 설정
		
		if (country[i].population <= country[i].infectpopulation)
			country[i].infectpopulation = country[i].population;//기본 감염자 수는 현재 인구수보다 적어야 함
		totalinfect += country[i].infectpopulation;

		country[i].population -= country[i].infectpopulation;//기본 감염자 수 증가량
	}

	printf("%s PROFILE\n\n", type);

	printf("일일 %s 비감염자 통계:\n", type);
	for (int i = 0; i < countryamount;i++)
		printf(" %s 대륙: %d명(%d%%)\n", countryname[i].name, country[i].population, country[i].population * 100 / country[i].maxpopulation);//대륙별 살아있는 인원
	printf("총 비감염자: %d명(%d%%).\n\n\n", total, total * 100 / maxtotal);//살아있는 총 인원

	printf("일일 %s 추가 감염자 통계:\n", type);
	for (int i = 0; i < countryamount;i++)
		printf(" %s 대륙: %d명(%d%%)\n", countryname[i].name, country[i].infectpopulation, country[i].infectpopulation * 20 / country[i].maxpopulation);//대륙별 살아있는 인원
	printf("일일 총 감염자: %d명(%d%%).\n\n\n", totalinfect, totalinfect * 100 / maxtotal);//감염된 총 인원

	printf("질병 LEVEL: %d \n", virus1.level);
	printf("%s는 %d%% 확률로 감염됨.\n\n", type, virus1.die);

	printf("Anti-%s 백신 완성도: %d%%\n", type, vac);
	printf("현재 보유 DNA: %d\n\n\n\n", virus1.DNA);

	printf("다음 날로 넘어가려면 아무 키나 누르십시오...");
	getch();
	clear_stdin();
	system("cls");
	day++;
}

void Startscreen()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 252);//흰 배경에 붉은 글자
	printf("                               \n");
	printf("                               \n");
	printf("           .,    ,.            \n");
	printf("         .:,      ,;.          \n");
	printf("         *.         *          \n");
	printf("        !!          !*         \n");
	printf("       ,@-          -@,        \n");
	printf("       ;@.          .@:        \n");
	printf("       =@.          .@=        \n");
	printf("       #@-  .-::-.  -@$        \n");
	printf("       $@* =@@@@@@= *@$        \n");
	printf("       !@@-=$!::!$$-@@!        \n");
	printf("       ~@@@~      ~@@@-        \n");
	printf("    -*@@@@@@*;--;*@@@@@@*,     \n");
	printf("   ~@@@@@@@@@@==@@@@@@@@@@-    \n");
	printf("  #*   ~@~-#@-  -@#;-#~  .*#   \n");
	printf(" =     ,@=  .$!!$-  *@,     $  \n");
	printf(".~      #@,  #@@@.  ##.     ~. \n");
	printf("..      ~@#, $@@$ .#@;      .. \n");
	printf("         !@#-=@@$-$@=        . \n");
	printf(" .        !@:$@@#:@$           \n");
	printf("           ,-@@@@--            \n");
	printf("            #@@@@#             \n");
	printf("   .       =@@**@@*            \n");
	printf("    ,-..,:$@@;  ;@@$~.  ,,.    \n");
	printf("     .*@@@@!     .*@@@@$-      \n");
	printf("        ..          ...        \n");
	printf("         Infection Inc.        \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	printf("   2406 박세연   2416 전상진   \n");
	printf("   2417  정욱    2420 최장헌   \n");
	printf("  시작하려면 질병 이름을 입력  \n");
}
void Tutorial()
{
	printf("전염병 주식회사에 오신 것을 환영합니다!\n");
	Sleep(1000);
	printf("당신의 목표는 %d개의 대륙의 모든 인간을 당신의 질병에 감염시키는 것입니다!\n", countryamount);
	Sleep(1000);
	printf("이를 위해서는 DNA를 모아 질병을 업그레이드해야합니다.\n");
	Sleep(1000);
	printf("DNA는 각 대륙의 사람들을 감염시켜 얻을 수 있습니다.\n");
	Sleep(1000);
	printf("모인 DNA는 질병 LEVEL, 감염률을 올리거나 백신 완성도를 낮추는 데에 쓸 수 있습니다.\n");
	Sleep(1000);
	printf("백신 완성도가 100%%에 도달하면 패배합니다.\n");
	Sleep(1000);
	printf("한 가지 유의할 점은, 감염이 죽음을 의미하지는 않는다는 것입니다.\n");
	Sleep(1000);
	printf("견투를 빌며, 게임을 즐기시길 바랍니다!\n");
	Sleep(1000);
	printf("\n\n넘어가려면 아무 키나 누르십시오...");
	getch();
}
void Warnvaccine()
{
	system("cls");
	if (vacwarn == 0 && vac >= 25)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 251);
		printf("Anti-%s 약물에 대한 연구가 25%% 완료되었습니다.\n", type);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		printf("업그레이드 탭의 백신 막기를 통해 연구 진행도를 낮추는 것을 고려하십시오.");
		vacwarn++;
		Sleep(1500);
	}
	else if (vacwarn == 1 && vac >= 50)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 251);
		printf("Anti-%s 약물에 대한 연구가 50%% 완료되었습니다.\n", type);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		printf("업그레이드 탭의 백신 막기를 통해 연구 진행도를 낮출 수 있습니다.");
		vacwarn++;
		Sleep(1500);
	}
	else if (vacwarn == 2 && vac >= 75)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 251);
		printf("Anti-%s 약물에 대한 연구가 75%% 완료되었습니다.\n", type);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		printf("업그레이드 탭의 백신 막기를 통해 연구 진행도를 낮춰야합니다.");
		vacwarn++;
		Sleep(1500);
	}
	else if (vac >= 95)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 251);
		printf("Anti-%s 약물에 대한 연구가 95%% 완료되었습니다.\n", type);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		printf("업그레이드 탭의 백신 막기를 통해 연구 진행도를 낮출 필요가 있습니다!");
		Sleep(1500);
	}
}
void Randomevent()
{
	srand(time(NULL));
	int randevent;
	randevent = rand();

	system("cls");
	switch (randevent % eventRate)
	{
	case addDNA:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 252);
		printf("\n\n   무작위 의사유전자 활성화\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		printf(" 질병 안의 의사유전자가 우연히 활성을 갖게 되었습니다.\n 추가 DNA를 얻습니다.");
		printf("\n\n넘어가려면 아무 키나 누르십시오...");
		virus1.DNA += (randevent % 10 + 10);
		getch();
		break;
	case addVAC:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 251);
		printf("\n\n   과학자들의 미생물에 대한 이해도 증가\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		printf(" 과학자들이 우연한 결과에 의해 %s에 대한 연구 과정에서\n 감염의 중요한 인자를 발견합니다.\n", type);
		printf(" 백신 완성도가 증가합니다.");
		printf("\n\n넘어가려면 아무 키나 누르십시오...");
		vac += randevent % 10;
		if (vac > 100)
			vac = 100;
		getch();
		break;
	case lessVAC:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 252);
		printf("\n\n   %s의 변종 발생\n\n", type);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		printf(" 숙주 내에서 %s가 변종을 일으켰습니다. 백신 개발에 있어서 난항을 겪습니다.\n", type);
		printf(" 백신 완성도가 감소합니다.");
		printf("\n\n넘어가려면 아무 키나 누르십시오...");
		vac -= randevent % 10;
		if (vac < 0)
			vac = 0;
		getch();
		break;
	case addmoreVAC:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 251);
		printf("\n\n   숙주 면역계와의 공진화\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		printf(" 인간의 면역계가 %s에 대한 면역 기작을 갖게 되기 시작했습니다.\n", type);
		printf(" 백신 완성도가 크게 증가합니다.");
		printf("\n\n넘어가려면 아무 키나 누르십시오...");
		vac += randevent % 10 + 10;
		if (vac > 100)
			vac = 100;
		getch();
		break;
	}
}

void vir()
{
	virus1.DNA = 0;
	virus1.level = 1;
	virus1.die = 4;
	vac = 0;//초기값설정 
	int choice1, choice2;
	while ((total > 0) && (vac < 100))
	{
		Randomevent();
	mainmenu:
		system("cls");
		printf("%d번째 날입니다.\n", day);
		printf("오늘 수행할 작업을 선택하십시오.\n\n");
		printf("1 : 감염시키기\n");
		printf("2 : 업그레이드 또는 백신 막기\n");

		scanf(" %d", &choice1); //죽일지 업그레이드할지 선택 
		while (choice1 != 1 && choice1 != 2)
		{
			printf("유효하지 않은 명령입니다.\n");
			clear_stdin();
			scanf("%d", &choice1);
		}
		clear_stdin();
		printf("\n");


		switch (choice1) {


		case kill: //죽이는거         		
			printf("어느 대륙을 감염시키겠습니까?\n");

			for (int i = 0; i < countryamount;i++)
				printf("%d : %s (%d명)\n", i + 1, countryname[i].name, country[i].population);
			printf("\n0: 뒤로가기\n");

			scanf("%d", &choice2); //대륙 선택

			while (0 > choice2 || choice2 > countryamount)
			{
				printf("유효하지 않은 명령입니다.\n");
				clear_stdin();
				scanf("%d", &choice2);
			}
			clear_stdin();

			if (choice2 == 0)
				goto mainmenu;
			else if (country[choice2 - 1].population == 0)
			{
				printf("해당 대륙에는 비감염자가 없습니다!");
				goto mainmenu;
			}

			killfunc(choice2);
			break;

		case upgrade: //업그레이드   
		upgradesave:
			choice2 = upgrademenu();

			switch (choice2)
			{
			case level:  // LEVEL 업그레이드 
				back = LVfunc();
				if (back == -1)
					goto upgradesave;
				break;

			case infect: //감염률 업그레이드 
				back = Infectfunc();
				if (back == -1)
					goto upgradesave;
				break;

			case inhibit:  //백신 방해 
				back = Inhibitfunc();
				if (back == -1)
					goto upgradesave;
				break;
			case -1:
				goto mainmenu;
				break;
			}
		}
		Warnvaccine();
		system("cls");
		EndofDay();
	}

	if (vac >= 100)
	{
		printf("  패배하였습니다.\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 251);
		printf("   %s는 여느 질병과도 같이, 한 때를 풍미한 질병으로서\n   인류사의 한 페이지를 장식하는 장식품 신세를 면치 못 할 것입니다.", type);
	}
	else
	{
		printf("  Congradulations! 승리하였습니다! \n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 252);
		printf("   이미 끝나버린 세상에서, 더 이상 감염시킬 숙주가 없는\n   바이러스는 영원히 세상을 떠돌게 됩니다. 다시는 온기\n   돌아올 일 없는 황폐한 세계에서...");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
	printf("\n\n걸린 일 수 : %d", day);
	getchar();
	return;
}
int main() {
	int choice;

	for (int i = 0;i < countryamount;i++)
	{
		country[i].population = population[i]; //대륙별 인구수
		country[i].population = population[i];//대륙별 인구수
		country[i].maxpopulation = population[i];//대륙별 최대 인구수
		country[i].infectpopulation = 0;//대륙별 기본 감염자수
	}//인구 설정
	Startscreen();
	scanf("%s", type);

	system("cls");
	printf("\n\n\n튜토리얼(규칙 설명)이 필요하십니까?\n");
	printf("1:네          다른 키: 아니오      \n");
	scanf("%d", &choice);

	if (choice == 1)
		Tutorial();
	clear_stdin();
	vir();
	return 0;
}//Special Thanks to. 신수, 나무사관, 엘로이

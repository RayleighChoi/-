#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#define countryamount 6

typedef enum upgrades_ { level = 1, death, inhibit }upgrades;
typedef enum choose_ { kill = 1, upgrade }choose;


typedef struct disease_{
	int DNA;//DNA양
	int level;//바이러스 레벨
	int die;//치사량
}disease;
typedef struct countryl_{
	char name[100];//국가 이름
}countryl;

disease virus1;
int vac;

 int day = 1;//지난 일자
 int country[countryamount] = { 10000,20000,30000,40000,50000,60000 };
 int Country[countryamount] = { 10000,20000,30000,40000,50000,60000 };//대륙별 인구수
 int maxcountry[countryamount]= { 10000,20000,30000,40000,50000,60000 };
countryl countryname[countryamount] = { {'a'},{'b'},{'c'},{'d'},{'e'},{'f'} };// 네이밍 A~F
char type[100];//질병 이름
int total = country[0] + country[1] + country[2] + country[3] + country[4] + country[5];

void killfunc(int countrynum)
{
	countrynum--;
	vac += (virus1.die) / 4; //감염률/4 만큼 백신 연구 올라감
	if (vac > 100) vac = 100;            //백신 최대치는 100

	if (country[countrynum] > 10 * (virus1.level) * (virus1.die))
	{
		country[countrynum] -= 10 * (virus1.level) * (virus1.die); //선택한 대륙의 사람 감염
		virus1.DNA += 10 * (virus1.level) * (virus1.die);      //감염자 수만큼 DNA 획득 
		printf("%s대륙에서 %d명이 감염되어 %d명 남았습니다.\n", countryname[countrynum].name, 10 * (virus1.level) * (virus1.die), country[countrynum]);
		printf("현재까지 획득한 DNA양은 %d입니다.\n", virus1.DNA);
		printf("그 사이 백신이 %d%% 완성되었습니다.\n", vac);
	}
	else {                                                            //만일 다 죽였으면 0으로 만들어 준다. 
		printf("%s대륙에서 %d명이 감염되어 0명 남았습니다.\n", countryname[countrynum].name, country[countrynum]);
		virus1.DNA += country[countrynum];   //죽인만큼 DNA얻고
		printf("현재까지 획득한 DNA양은 %d입니다.\n", virus1.DNA);
		printf("그 사이 백신이 %d%% 완성되었습니다.\n", vac);
		country[countrynum] = 0;
	}
	Sleep(1000);
}
void vaccinefunc()
{
	if (country[day % 6] + virus1.level * vac <= Country[day % 6]) {
		country[day % 6] += virus1.level * vac;
		printf("당신이 업그레이드 하는 동안 백신으로 %s대륙 에서 %d명이 살아났습니다.\n", countryname[day % 6].name, virus1.level*vac);
		printf("\n");
	}
	else {

		printf("당신이 업그레이드 하는 동안 백신으로 %s대륙 에서 %d명이 살아났습니다.\n", countryname[day % 6].name, Country[day % 6] - country[day % 6]);
		printf("\n");
		country[day % 6] = Country[day % 6];
		Sleep(1000);
	}
}
void LVfunc() 
{
	int amuont; //얼마나 업그레이드 할건지 
	
	printf("얼마 업그레이드 하실겁니까?\n");
	printf("LEVEL 1 당 DNA 100개가 필요합니다.\n");
	scanf("%d", &amuont);

	while (virus1.DNA - amuont * 100 < 0)
	{
		printf("다시 입력해주세요. 만일 업그레이드 하지 못하는 상황이면 0을 누르세요");
		scanf("%d", &amuont);
	}
	virus1.DNA -= amuont * 100;              //DNA사용하고 
	virus1.level += amuont;                    //업그레이드 해주고 

	vaccinefunc();

}
void Infectfunc()
{
	int amount = 0;
	printf("얼마 업그레이드 하실겁니까?\n");                      //얼마나 업그레이드 할건지 
	printf("치사율 1%%당 DNA 50개가 필요합니다.\n");
	scanf("%d", &amount);

	while (virus1.DNA - amount * 50 < 0) 
	{
		printf("다시 입력해주세요. 만일 업그레이드 하지 못하는 상황이면 0을 누르세요\n");
		scanf("%d", &amount);
	}

	virus1.DNA -= amount * 50;                               //DNA 사용한만큼 빼주고 
	virus1.die += amount;

	if (virus1.die > 100)  
		virus1.die = 100;//치사율 최댓값 100으로 설정
	vaccinefunc();
}
void Inhibitfunc()
{
	int amount = 0;
	printf("백신의 완성도를 얼마 감소시킬겁니까?\n");
	printf("백신의 완성도 1%% 감소시키는데 DNA 200개가 필요합니다.\n");

	scanf("%d", &amount);

	while (vac < amount && vac != 0)
	{
		printf("다시 입력해주세요. 만일 방해하지 못하는 상황이면 0을 누르세요\n");
		scanf("%d", &amount);
	}

	vac -= amount;

	if (vac <= 0)
		vac = 0;//백신 개발은 0 이하로 내려갈 수 없음.
	Sleep(1000);
}
void EndofDay()
{
	printf("대륙별 %s 비감염자 통계:\n", type);
	for (int i = 0; i < countryamount;i++)
		printf(" %s 대륙: %d명(%d%%)\n", countryname[i].name, country[i], country[i] * 100 / maxcountry[i]);//대륙별 살아있는 인원

	printf("총 비감염자: %d명.\n\n\n", total);//살아있는 총 인원
	printf("Anti-%s 백신 완성도: %d%%\n", type, vac);

	printf("%s PROFILE\n", type);
	printf("질병 LEVEL: %d \n", virus1.level);
	printf("%s는 %d%% 확률로 감염됨.\n\n", type, virus1.die);

	printf("현재 보유 DNA: %d\n\n\n\n", virus1.DNA);
	printf("다음 날로 넘어가려면 아무 키나 누르십시오...");
	getch();
	system("cls");
	day = day + 1;
	total = country[0] + country[1] + country[2] + country[3] + country[4] + country[5];
}

void Startscreen()
{
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
	printf("   2406 박세연   2416 전상진   \n");
	printf("   2417  정욱    2420 최장헌   \n");
	printf("  시작하려면 질병 이름을 입력  \n");
	getch();
}

void vir1()
{
	virus1.DNA = 0;
	virus1.level = 1;
	virus1.die = 4;
	vac = 0;
	int choice1, choice2;
	
	//초기값설정 

	while (total > 0 && vac < 100) {
		system("cls");
		printf("%d번째 날입니다.\n", day);
		printf("오늘 수행할 작업을 선택하십시오.\n\n");
		printf("1 : 감염시키기\n");
		printf("2 : 업그레이드 또는 백신 막기\n");

		scanf("%d", &choice1); //죽일지 업그레이드할지 선택 
		while (choice1 != 1 && choice1 != 2)
		{
			printf("유효하지 않은 명령입니다.\n");
			scanf("%d", &choice2);
		}
		printf("\n");


		switch (choice1) {


		case kill: //죽이는거         		
			printf("어느 대륙을 감염시키겠습니까?\n");

			for (int i = 0; i < countryamount;i++)
					printf("%d : %s \n", i+1, countryname[i].name);

			scanf("%d", &choice2); //대륙 선택
			while (0 >= choice2 || choice2 > countryamount)
			{
				printf("유효하지 않은 명령입니다.\n");
				scanf("%d", &choice2); 
			}
				killfunc(choice2);
			break;

		case upgrade: //업그레이드        
			if (virus1.die == 100)
			{
				printf("1 : LEVEL 업그레이드 \n");
				printf("X : 감염률이 최대치(100%%)입니다. \n");//감염률100%면 업그레이드 못하게 함 
				printf("3 : 백신 방해하기 \n");   
				
				scanf("%d", &choice2);
				while (choice2!=1||choice2!=3)
				{
					printf("유효하지 않은 명령입니다.\n");
					scanf("%d", &choice2);
				}
				break;
			}
			else
			{
				printf("1 : LEVEL 업그레이드 \n");
				printf("2 : 감염률 업그레이드 \n");
				printf("3 : 백신 방해하기 \n");

				scanf("%d", &choice2);
				while (0 >= choice2 || choice2 > 3)
				{
					printf("유효하지 않은 명령입니다.\n");
					scanf("%d", &choice2);
				}
			}

			switch (choice2) {
			case level:  // LEVEL업그레이드 
				LVfunc();
				break;

			case death: //치사율 업그레이드 
				Infectfunc();
				break;

			case inhibit:  //백신 방해 
				Inhibitfunc();
				break;
			}
		}

		system("cls");
		EndofDay();
	}
		if (vac >= 100) printf("패배하였습니다.\n걸린 일 수: %d", day);
		else printf("Congradulations!승리하였습니다\n걸린 일 수: %d",day);
		return;
	}
int main() {






	//규칙설명필요 
	scanf("%s", type);
	//질병종류입력

	vir1();


}

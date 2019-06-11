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
	else {                                                            
		printf("%s대륙에서 %d명이 감염되어 0명 남았습니다.\n", countryname[countrynum].name, country[countrynum]);
		virus1.DNA += country[countrynum];   //죽인만큼 DNA얻고
		printf("현재까지 획득한 DNA양은 %d입니다.\n", virus1.DNA);
		printf("그 사이 백신이 %d%% 완성되었습니다.\n", vac);
		country[countrynum] = 0;//감염 가능 인원이 비감염자보다 많으면 비감염자 0으로 만듦
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
int LVfunc() 
{
	int amount; //얼마나 업그레이드 할건지 
	
	printf("얼마나 업그레이드 하실겁니까?\n");
	printf("LEVEL 1 당 DNA 100개가 필요합니다.\n");
	printf("보유 DNA: %d\n", virus1.DNA);
	scanf("%d", &amount);

	while (virus1.DNA - amount * 100 < 0)
	{
		printf("다시 입력해주세요. 만일 업그레이드 하지 못하는 상황이면 0을 누르세요");
		scanf("%d", &amount);
	}
	if (amount == 0)
		return -1;
	virus1.DNA -= amount * 100;              //DNA사용하고 
	virus1.level += amount;                    //업그레이드 해주고 

	vaccinefunc();

}
int Infectfunc()
{
	int amount = 0;
	printf("얼마 업그레이드 하실겁니까?\n");                      //얼마나 업그레이드 할건지 
	printf("감염률 1%%당 DNA 50개가 필요합니다.\n");
	printf("보유 DNA: %d\n", virus1.DNA);
	scanf("%d", &amount);

	while (virus1.DNA - amount * 50 < 0) 
	{
		printf("다시 입력해주세요. 만일 업그레이드 하지 못하는 상황이면 0을 누르세요\n");
		scanf("%d", &amount);
	}

	if (amount == 0)
		return -1;

	virus1.DNA -= amount * 50;                               //DNA 사용한만큼 빼주고 
	virus1.die += amount;

	if (virus1.die > 100)  
		virus1.die = 100;//치사율 최댓값 100으로 설정
	vaccinefunc();
}
int Inhibitfunc()
{
	int amount = 0;
	printf("백신의 완성도를 얼마 감소시킬겁니까?\n");
	printf("백신의 완성도 1%% 감소시키는데 DNA 200개가 필요합니다.\n");
	printf("보유 DNA: %d\n", virus1.DNA);

	scanf("%d", &amount);

	while (vac < amount && vac != 0)
	{
		printf("다시 입력해주세요. 만일 방해하지 못하는 상황이면 0을 누르세요\n");
		scanf("%d", &amount);
	}

	if (amount == 0)
		return -1;

	vac -= amount;
	virus1.DNA -= amount * 200;
	if (vac <= 0)
		vac = 0;//백신 개발은 0 이하로 내려갈 수 없음.
	Sleep(1000);
}
void EndofDay()
{
	total = country[0] + country[1] + country[2] + country[3] + country[4] + country[5];
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
	getch();
}
//랜덤 이벤트 발생 필요
void vir()
{
	virus1.DNA = 0;
	virus1.level = 1;
	virus1.die = 4;
	vac = 0;//초기값설정 
	int choice1, choice2;
	int back;//뒤로가기 위한 변수
	
	
	while (total > 0 && vac < 100) {
	mainmenu:
		system("cls");
		printf("%d번째 날입니다.\n", day);
		printf("오늘 수행할 작업을 선택하십시오.\n\n");
		printf("1 : 감염시키기\n");
		printf("2 : 업그레이드 또는 백신 막기\n");
		
		scanf("%d", &choice1); //죽일지 업그레이드할지 선택 
		while (choice1 != 1 && choice1 != 2)
		{
			printf("유효하지 않은 명령입니다.\n");
			scanf("%d", &choice1);
		}
		printf("\n");


		switch (choice1) {


		case kill: //죽이는거         		
			printf("어느 대륙을 감염시키겠습니까?\n");

			for (int i = 0; i < countryamount;i++)
					printf("%d : %s (%d명)\n", i+1, countryname[i].name, country[i]);
			printf("\n0: 뒤로가기\n");

			scanf("%d", &choice2); //대륙 선택

			if (choice2 == 0)
				goto mainmenu;

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
				printf("\n0: 뒤로가기\n");

				scanf("%d", &choice2);
				printf("\n\n");

				if (choice2 == 0)
					goto mainmenu;

				while (1 != choice2 && choice2 != 3)
				{
					printf("유효하지 않은 명령입니다.\n");
					scanf("%d", &choice2);
				}
			}
			else
			{
			upgrademenu:
				printf("1 : LEVEL 업그레이드 \n");
				printf("2 : 감염률 업그레이드 \n");
				printf("3 : 백신 방해하기 \n");
				printf("\n0: 뒤로가기\n");

				scanf("%d", &choice2);
				printf("\n\n");

				if (choice2 == 0)
					goto mainmenu;
				
				while (0 >= choice2 || choice2 > 3)
				{
					printf("유효하지 않은 명령입니다.\n");
					scanf("%d", &choice2);
				}
			}

			switch (choice2) {
			case level:  // LEVEL 업그레이드 
				back=LVfunc();
				if (back == -1)
					goto upgrademenu;
				break;

			case infect: //감염률 업그레이드 
				back=Infectfunc();
				if (back == -1)
					goto upgrademenu;
				break;

			case inhibit:  //백신 방해 
				back=Inhibitfunc();
				if (back == -1)
					goto upgrademenu;
				break;
			}
		}

		system("cls");
		EndofDay();
	}
		if (vac >= 100) printf("  패배하였습니다.\n걸린 일 수: %d", day);
		else printf("  Congradulations!승리하였습니다\n걸린 일 수: %d",day);
		return;
	}
int main() {
	int choice;

	Startscreen();
	scanf("%s", type);

	system("cls");
	printf("\n\n\n튜토리얼(규칙 설명)이 필요하십니까?\n");
	printf("1:네          다른 키: 아니오      \n");
	scanf("%d", &choice);

	if (choice == 1)
		Tutorial();

	vir();
	getch();
	return 0;
}//Special Thanks to. 신수&나무사관, 

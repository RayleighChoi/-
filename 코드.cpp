#include<stdio.h>
long long int day=1, a[6]={10000,20000,30000,40000,50000,60000}, A[6]={10000,20000,30000,40000,50000,60000}//대륙 네이밍, A~F
char day[100];
//몇번째 날인지, 어느대륙의 남아있는 인구수정의 
struct disease{
   long long int DNA;
   int level;
   int die;
}virus1, virus2;
//질병정보 
struct vaccin{
   int live;
}vac;
//백신정보 
void vir1(){
   virus1.DNA=0 ;
   virus1.level=1;
   virus1.die=4 ;
   vac.live=0;
   
   long long int lipp=a+b+c+d+e+f, dipp=0;
   //초기값설정 
   while(a+b+c+d+e+f>=0 && vac.live<100){
      printf("\n");
      printf("%d번째 날입니다.\n", day);
      printf("둘중 하나를 선택하십니오.\n");
      printf("\n");
      printf("1 : 감염시키기\n");
      printf("2 : 업그레이드 또는 백신 막기"); 
      printf("\n"); 
      int choose;
      
      
      scanf("%d", &choose); //죽일지 업그레이드할지 선택 
      printf("\n");
      switch(choose){
         
         
         
         case 1 : {        //죽이는거 
            int x;
            printf("어느 대륙을 감염시키겠습니까?\n");
            printf("1 : a\n");
            printf("2 : b\n");
            printf("3 : c\n");
            printf("4 : d\n");
            printf("5 : e\n");
            printf("6 : f\n");
            scanf("%d", &x);  // 어느대륙 
            switch(x){
               case 1 : {
                  vac.live=vac.live+(viruse1.die)/4;    
                  if(vac.live>100) vac.live=100;                           //치사율 만큼 백신 완성도 높아지고 
                  
                  if(a-(viruse1.level)*1000*(viruse1.die)/100>0){
                     a=a-(viruse1.level)*1000*(viruse1.die)/100;           //선택한대륙의사람죽이고
                     viruse1.DNA=viruse1.DNA+(viruse1.level)*1000*(viruse1.die)/100;      //죽인만큼 DNA얻고 
                     printf("a대륙에서 %lld명이 감염되어 %lld명 남았습니다.\n", (viruse1.level)*1000*(viruse1.die)/100, a);
                     printf("현재까지 획득한 DNA양은 %lld입니다.\n", viruse1.DNA) ;
                     printf("그 사이 백신이 %d% 완성되었습니다.\n", vac.live);
               }
               else {                                                            //만일 다 죽였으면 0으로 만들어 준다. 
                  printf("a대륙에서 %lld명이 감염되어 0명 남았습니다.\n", a );
                  viruse1.DNA=viruse1.DNA+a;      //죽인만큼 DNA얻고
                  printf("현재까지 획득한 DNA양은 %lld입니다.\n", viruse1.DNA) ;
                  printf("그 사이 백신이 %d% 완성되었습니다.\n", vac.live);
                  a=0;
               }
                  break;
               }
               case 2 : {
                  vac.live=vac.live+(viruse1.die)/4;    
                  if(vac.live>100) vac.live=100;                           //치사율 만큼 백신 완성도 높아지고 
                  
                  if(b-(viruse1.level)*1000*(viruse1.die)/100>0){
                     b=b-(viruse1.level)*1000*(viruse1.die)/100;           //선택한대륙의사람죽이고
                     viruse1.DNA=viruse1.DNA+(viruse1.level)*1000*(viruse1.die)/100;      //죽인만큼 DNA얻고 
                     printf("b대륙에서 %lld명이 감염되어 %lld명 남았습니다.\n", (viruse1.level)*1000*(viruse1.die)/100, b);
                     printf("현재까지 획득한 DNA양은 %lld입니다.\n", viruse1.DNA) ;
                     printf("그 사이 백신이 %d% 완성되었습니다.\n", vac.live);
               }
               else {
                  printf("b대륙에서 %lld명이 감염되어 0명 남았습니다.\n", b );
                  viruse1.DNA=viruse1.DNA+b;      //죽인만큼 DNA얻고
                  printf("현재까지 획득한 DNA양은 %lld입니다.\n", viruse1.DNA) ;
                  printf("그 사이 백신이 %d% 완성되었습니다.\n", vac.live);
                  b=0;
               }
                  break;
               }
               case 3 : {
                  vac.live=vac.live+(viruse1.die)/4;    
                  if(vac.live>100) vac.live=100;                           //치사율 만큼 백신 완성도 높아지고 
                  
                  if(c-(viruse1.level)*1000*(viruse1.die)/100>0){
                     c=c-(viruse1.level)*1000*(viruse1.die)/100;           //선택한대륙의사람죽이고
                     viruse1.DNA=viruse1.DNA+(viruse1.level)*1000*(viruse1.die)/100;      //죽인만큼 DNA얻고 
                     printf("c대륙에서 %lld명이 감염되어 %lld명 남았습니다.\n", (viruse1.level)*1000*(viruse1.die)/100, c);
                     printf("현재까지 획득한 DNA양은 %lld입니다.\n", viruse1.DNA) ;
                     printf("그 사이 백신이 %d% 완성되었습니다.\n", vac.live);
               }
               else {
                  printf("c대륙에서 %lld명이 감염되어 0명 남았습니다.\n", c );
                  viruse1.DNA=viruse1.DNA+c;      //죽인만큼 DNA얻고
                  printf("현재까지 획득한 DNA양은 %lld입니다.\n", viruse1.DNA) ;
                  printf("그 사이 백신이 %d% 완성되었습니다.\n", vac.live);
                  c=0;
               }
                  break;
               }
               case 4 : {
                  vac.live=vac.live+(viruse1.die)/4;    
                  if(vac.live>100) vac.live=100;                           //치사율 만큼 백신 완성도 높아지고 
                  
                  if(d-(viruse1.level)*1000*(viruse1.die)/100>0){
                     d=d-(viruse1.level)*1000*(viruse1.die)/100;           //선택한대륙의사람죽이고
                     viruse1.DNA=viruse1.DNA+(viruse1.level)*1000*(viruse1.die)/100;      //죽인만큼 DNA얻고 
                     printf("d대륙에서 %lld명이 감염되어 %lld명 남았습니다.\n", (viruse1.level)*1000*(viruse1.die)/100, d);
                     printf("현재까지 획득한 DNA양은 %lld입니다.\n", viruse1.DNA) ;
                     printf("그 사이 백신이 %d% 완성되었습니다.\n", vac.live);
               }
               else {
                  printf("d대륙에서 %lld명이 감염되어 0명 남았습니다.\n", d );
                  viruse1.DNA=viruse1.DNA+d;      //죽인만큼 DNA얻고
                  printf("현재까지 획득한 DNA양은 %lld입니다.\n", viruse1.DNA) ;
                  printf("그 사이 백신이 %d% 완성되었습니다.\n", vac.live);
                  d=0;
               }
                  break;
               }
               case 5 : {
                  vac.live=vac.live+(viruse1.die)/4;    
                  if(vac.live>100) vac.live=100;                           //치사율 만큼 백신 완성도 높아지고 
                  
                  if(e-(viruse1.level)*1000*(viruse1.die)/100>0){
                     e=e-(viruse1.level)*1000*(viruse1.die)/100;           //선택한대륙의사람죽이고
                     viruse1.DNA=viruse1.DNA+(viruse1.level)*1000*(viruse1.die)/100;      //죽인만큼 DNA얻고 
                     printf("e대륙에서 %lld명이 감염되어 %lld명 남았습니다.\n", (viruse1.level)*1000*(viruse1.die)/100, e);
                     printf("현재까지 획득한 DNA양은 %lld입니다.\n", viruse1.DNA) ;
                     printf("그 사이 백신이 %d% 완성되었습니다.\n", vac.live);
               }
               else {
                  printf("e대륙에서 %lld명이 감염되어 0명 남았습니다.\n", e );
                  viruse1.DNA=viruse1.DNA+e;      //죽인만큼 DNA얻고
                  printf("현재까지 획득한 DNA양은 %lld입니다.\n", viruse1.DNA) ;
                  printf("그 사이 백신이 %d% 완성되었습니다.\n", vac.live);
                  e=0;
               }
                  break;
               }
               case 6 : {
                  vac.live=vac.live+(viruse1.die)/4;    
                  if(vac.live>100) vac.live=100;                           //치사율 만큼 백신 완성도 높아지고 
                  
                  if(f-(viruse1.level)*1000*(viruse1.die)/100>0){
                     f=f-(viruse1.level)*1000*(viruse1.die)/100;           //선택한대륙의사람죽이고
                     viruse1.DNA=viruse1.DNA+(viruse1.level)*1000*(viruse1.die)/100;      //죽인만큼 DNA얻고 
                     printf("f대륙에서 %lld명이 감염되어 %lld명 남았습니다.\n", (viruse1.level)*1000*(viruse1.die)/100, f);
                     printf("현재까지 획득한 DNA양은 %lld입니다.\n", viruse1.DNA) ;
                     printf("그 사이 백신이 %d% 완성되었습니다.\n", vac.live);
               }
               else {
                  printf("f대륙에서 %lld명이 감염되어 0명 남았습니다.\n", f);
                  viruse1.DNA=viruse1.DNA+f;      //죽인만큼 DNA얻고
                  printf("현재까지 획득한 DNA양은 %lld입니다.\n", viruse1.DNA) ;
                  printf("그 사이 백신이 %d% 완성되었습니다.\n", vac.live);
                  f=0;
               }
                  break;
               }
            }
            break;
         }
         
         
         
         
         
         case 2 : {                  //업그레이드 
            int y;
            if(viruse1.die==100){
               printf("1 : LEVEL 업그레이드 \n");
               printf("X : 현재 치사량은 100%여서 늘릴 수 없습니다. \n");
               printf("3 : 백신 방해하기 \n");                            //치사량100%면 업그레이드 못하게 함 
               scanf("%d", &y); 
               }
               
            else {
            
                printf("1 : LEVEL 업그레이드 \n");
               printf("2 : 치사량 업그레이드 하기 \n");
               printf("3 : 백신 방해하기 \n");
               scanf("%d", &y);                               //뭐업그레이드 할지 선택 
            }
            
            switch(y){
               case 1 : {                                    // LEVEL업그레이드 
                  int add1=0;   
                                               //얼마나 업그레이드 할건지 
                  printf("얼마 업그레이드 하실겁니까?\n") ;
                  printf("LEVEL 1 당 DNA 100개가 필요합니다.\n") ;
                  scanf("%d", &add1);
                  while(viruse1.DNA-add1*100<0){
                     printf("다시 입력해주세요. 만일 업그레이드 하지 못하는 상황이면 0을 누르세요");
                     scanf("%d", &add1); 
                  }
                  viruse1.DNA=viruse1.DNA-add1*100;              //DNA사용하고 
                  viruse1.level=viruse1.level+add1;                    //업그레이드 해주고 
                  switch(day%6){                              // 여기는 업그레이드 하는동안 그 날짜에 따라서 어떤 대륙에 백신에 의해 사람들이 몇명 살아남  
                     case 1:{
                        if(a+viruse1.level*100*vac.live/100<=A){
                            a=a+viruse1.level*100*vac.live/100;
                           printf("당신이 업그레이드 하는 동안 백신으로 a대륙 에서 %d명이 살아났습니다.\n", viruse1.level*vac.live);
                           printf("\n");
                        }
                        else {
                           
                           printf("당신이 업그레이드 하는 동안 백신으로 a대륙 에서 %d명이 살아났습니다.\n", A-a);
                            printf("\n");
                            a=A;
                        }
                        
                        break;
                     }
                     case 2:{
                        if(b+viruse1.level*100*vac.live/100<=B){
                            b=b+viruse1.level*100*vac.live/100;
                           printf("당신이 업그레이드 하는 동안 백신으로 b대륙 에서 %d명이 살아났습니다.\n", viruse1.level*vac.live);
                           printf("\n");
                        }
                        else {
                           
                           printf("당신이 업그레이드 하는 동안 백신으로 b대륙 에서 %d명이 살아났습니다.\n", B-b);
                            printf("\n");
                            b=B;
                        }
                        break;
                     }
                     case 3:{
                        if(c+viruse1.level*100*vac.live/100<=C){
                            c=c+viruse1.level*100*vac.live/100;
                           printf("당신이 업그레이드 하는 동안 백신으로 c대륙 에서 %d명이 살아났습니다.\n", viruse1.level*vac.live);
                           printf("\n");
                        }
                        else {
                           
                           printf("당신이 업그레이드 하는 동안 백신으로 c대륙 에서 %d명이 살아났습니다.\n", C-c);
                            printf("\n");
                            C-c;
                        }
                        break;
                     }
                     case 4:{
                        if(d+viruse1.level*100*vac.live/100<=D){
                            d=d+viruse1.level*100*vac.live/100;
                           printf("당신이 업그레이드 하는 동안 백신으로 d대륙 에서 %d명이 살아났습니다.\n", viruse1.level*vac.live);
                           printf("\n");
                        }
                        else {
                           
                           printf("당신이 업그레이드 하는 동안 백신으로 d대륙 에서 %d명이 살아났습니다.\n", D-d);
                            printf("\n");
                            d=D;
                        }
                     }
                     case 5:{
                        if(e+viruse1.level*100*vac.live/100<=E){
                            e=e+viruse1.level*100*vac.live/100;
                           printf("당신이 업그레이드 하는 동안 백신으로 e대륙 에서 %d명이 살아났습니다.\n", viruse1.level*vac.live);
                           printf("\n");
                        }
                        else {
                           
                           printf("당신이 업그레이드 하는 동안 백신으로 e대륙 에서 %d명이 살아났습니다.\n",E-e);
                            printf("\n");
                            e=E;
                        }
                     }
                     case 6:{
                        if(f+viruse1.level*100*vac.live/100<=F){
                            f=f+viruse1.level*100*vac.live/100;
                           printf("당신이 업그레이드 하는 동안 백신으로 f대륙 에서 %d명이 살아났습니다.\n", viruse1.level*vac.live);
                           printf("\n");
                        }
                        else {
                           
                           printf("당신이 업그레이드 하는 동안 백신으로 a대륙 에서 %d명이 살아났습니다.\n", F-f);
                            printf("\n");
                            f=F;
                        }
                        break;
                     }
                  }
                  break;
               }
               case 2 : {                     //치사율 업그레이드 
               int add2=0;
                  printf("얼마 업그레이드 하실겁니까?\n") ;                      //얼마나 업그레이드 할건지 
                  printf("치사율 1%당 DNA 50개가 필요합니다.\n") ;         
                  scanf("%d", &add2);                          
                  while(viruse1.DNA-add2*50<0){
                     printf("다시 입력해주세요. 만일 업그레이드 하지 못하는 상황이면 0을 누르세요");
                     scanf("%d", &add2); 
                  }                  
                  viruse1.DNA=viruse1.DNA-add2*50;                               //DNA 사용한만큼 빼주고 
                  viruse1.die=viruse1.die+add2;
                  if(viruse1.die>100)  viruse1.die=100;                          //치사율 더해주고  만약 100넘으면 100으로 바꿔 
                  switch(day%6){                              // 여기는 업그레이드 하는동안 그 날짜에 따라서 어떤 대륙에 백신에 의해 사람들이 몇명 살아남  
                     case 1:{
                        if(a+viruse1.level*100*vac.live/100<=A){
                            a=a+viruse1.level*100*vac.live/100;
                           printf("당신이 업그레이드 하는 동안 백신으로 a대륙 에서 %d명이 살아났습니다.\n", viruse1.level*vac.live);
                           printf("\n");
                        }
                        else {
                           
                           printf("당신이 업그레이드 하는 동안 백신으로 a대륙 에서 %d명이 살아났습니다.\n", A-a);
                            printf("\n");
                            a=A;
                        }
                        
                        break;
                     }
                     case 2:{
                        if(b+viruse1.level*100*vac.live/100<=B){
                            b=b+viruse1.level*100*vac.live/100;
                           printf("당신이 업그레이드 하는 동안 백신으로 b대륙 에서 %d명이 살아났습니다.\n", viruse1.level*vac.live);
                           printf("\n");
                        }
                        else {
                           
                           printf("당신이 업그레이드 하는 동안 백신으로 b대륙 에서 %d명이 살아났습니다.\n", B-b);
                            printf("\n");
                            b=B;
                        }
                        break;
                     }
                     case 3:{
                        if(c+viruse1.level*100*vac.live/100<=C){
                            c=c+viruse1.level*100*vac.live/100;
                           printf("당신이 업그레이드 하는 동안 백신으로 c대륙 에서 %d명이 살아났습니다.\n", viruse1.level*vac.live);
                           printf("\n");
                        }
                        else {
                           
                           printf("당신이 업그레이드 하는 동안 백신으로 c대륙 에서 %d명이 살아났습니다.\n", C-c);
                            printf("\n");
                            C-c;
                        }
                        break;
                     }
                     case 4:{
                        if(d+viruse1.level*100*vac.live/100<=D){
                            d=d+viruse1.level*100*vac.live/100;
                           printf("당신이 업그레이드 하는 동안 백신으로 d대륙 에서 %d명이 살아났습니다.\n", viruse1.level*vac.live);
                           printf("\n");
                        }
                        else {
                           
                           printf("당신이 업그레이드 하는 동안 백신으로 d대륙 에서 %d명이 살아났습니다.\n", D-d);
                            printf("\n");
                            d=D;
                        }
                     }
                     case 5:{
                        if(e+viruse1.level*100*vac.live/100<=E){
                            e=e+viruse1.level*100*vac.live/100;
                           printf("당신이 업그레이드 하는 동안 백신으로 e대륙 에서 %d명이 살아났습니다.\n", viruse1.level*vac.live);
                           printf("\n");
                        }
                        else {
                           
                           printf("당신이 업그레이드 하는 동안 백신으로 e대륙 에서 %d명이 살아났습니다.\n",E-e);
                            printf("\n");
                            e=E;
                        }
                     }
                     case 6:{
                        if(f+viruse1.level*100*vac.live/100<=F){
                            f=f+viruse1.level*100*vac.live/100;
                           printf("당신이 업그레이드 하는 동안 백신으로 f대륙 에서 %d명이 살아났습니다.\n", viruse1.level*vac.live);
                           printf("\n");
                        }
                        else {
                           
                           printf("당신이 업그레이드 하는 동안 백신으로 a대륙 에서 %d명이 살아났습니다.\n", F-f);
                            printf("\n");
                            f=F;
                        }
                        break;
                     }
                  }  
                  break;
               }
               case 3 : {                    //백신 방해 
                   int add3=0;
                  printf("백신의 완성도를 얼마 감소시킬겁니까?\n") ;  
                  printf("백신의 완성도 1% 감소시키는데 DNA 200개가 필요합니다.\n") ; 
                  scanf("%d", &add3);
                  while(vac.live=vac.live-add3<0){
                     printf("다시 입력해주세요. 만일 방해하지 못하는 상황이면 0을 누르세요");
                     scanf("%d", &add3); 
                  } 
                  vac.live=vac.live-add3;
                  if (vac.live<=0) vac.live=0;
                  break;
               }
               
            } 
            break; 
         } 
      }
      //하루 지나고 상태출력 
      printf("현재 a대륙에 남아있는사람은 %lld명 입니다.\n", a);
      printf("현재 b대륙에 남아있는사람은 %lld명 입니다.\n", b); 
      printf("현재 c대륙에 남아있는사람은 %lld명 입니다.\n", c); 
      printf("현재 d대륙에 남아있는사람은 %lld명 입니다.\n", d); 
      printf("현재 e대륙에 남아있는사람은 %lld명 입니다.\n", e); 
      printf("현재 f대륙에 남아있는사람은 %lld명 입니다.\n", f);
      printf("현재 총 %lld명 살아있습니다.\n", a+b+c+d+e+f);
      printf("\n");
      printf("\n");
      printf("현재 백신의 완성도는 %d% 입니다.\n", vac.live); 
      printf("현재 보유하고 있는 DNA양은 %lld 입니다.\n", viruse1.DNA); 
      printf("현재 LEVEL은 %d 입니다.\n", viruse1.level); 
      printf("현재 질병의 치사율은 %d 입니다.\n", viruse1.die); 
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      day=day+1;
 
   }
   if(vac.live>=100) printf("실패하였습니다.");
   else printf("성공하였습니다."); 
   return; 
}
int main(){ 
               
 
 
 
 
 
                             //규칙설명필요 
 scanf("%s", type);
 //질병종류입력
 
       vir1();
   
    
}

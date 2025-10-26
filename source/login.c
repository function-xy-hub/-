//处理进入系统的初始页面逻辑。
#include <stdio.h>
#include"hz.h"
#include"MOUSE.H"
MOUSE mouse; // 定义全局变量mouse
#include"login.h"
#include"SVGAmode.h" 



void login_system()
{
	int choose=0;
	while(choose!=-1)   
	{
		choose=login();
		switch(choose)           
		{
			
			case 2: user_opt();
			        break;
			case 3: zhuce_system();
					break;	  
			case -1: break;         
			default : continue;
		}
	}
}
int login()
 {
    char *s;
	login_page();
 	Mouse_Init();
	
	while(1)
	{
		MouseShow(&mouse);
    	delay(10); 
    	if( MousePress(980,0,1024,30)==1)
    	{
    		
    		
			CloseSVGA();
			delay(1000);
			exit(1);
		}
		if(MousePress(385,445,630,500)==1)
		{
			return 2;
		}
		if(MousePress(385,595,630,650)==1)
		{
			return 3;
		}
	}
	
    return 0;
}
void login_page() 
{  
    bar1(0, 0, 1024,768,0xfffffb);
  	prt_hz16_size(390,100,4,4,"简历大师",0xfde0,"HZK\\Hz16");
  	Put_Asc16_Size(350,180,3,3,'R',0) ;
  	Put_Asc16_Size(375,180,3,3,'e',0) ;
  	Put_Asc16_Size(400,180,3,3,'s',0) ;
  	Put_Asc16_Size(425,180,3,3,'u',0) ;
  	Put_Asc16_Size(450,180,3,3,'m',0) ;
  	Put_Asc16_Size(475,180,3,3,'e',0) ;
  	Put_Asc16_Size(525,180,3,3,'M',0) ;
  	Put_Asc16_Size(550,180,3,3,'a',0) ;
  	Put_Asc16_Size(575,180,3,3,'s',0) ;
  	Put_Asc16_Size(600,180,3,3,'t',0) ;
  	Put_Asc16_Size(625,180,3,3,'e',0) ;
  	Put_Asc16_Size(650,180,3,3,'r',0) ;
  	bar1(980,0,1024,30,0x5d4f) ;
  	prt_hz16(985,5,"退出",0,"HZK\\Hz16");
   	bar1(393,453,639,508,0XFA68);
	bar1(393,603,639,658,0XFA68);
	bar1(385,445,630,500,0x4d58);
	bar1(385,595,630,650,0x4d58);
    prt_hz24d(470,460,"用户登录",0,"HZK\\hzk24k");
    prt_hz24d(470,610,"用户注册",0,"HZK\\hzk24k");
	prt_hz24(100,130,"简",0x0000,"HZK\\Hzk24k");
	prt_hz24(100,160,"历",0x0000,"HZK\\Hzk24k");
	prt_hz24(100,190,"设",0x0000,"HZK\\Hzk24k");
	prt_hz24(100,220,"计",0x0000,"HZK\\Hzk24k");
	prt_hz24(100,250,"神",0x0000,"HZK\\Hzk24k");
	prt_hz24(100,280,"器",0x0000,"HZK\\Hzk24k");
	prt_asc16_ch(110,300,',',0x0000);	
	prt_hz24(140,260,"助",0x0000,"HZK\\Hzk24k");
	prt_hz24(140,290,"你",0x0000,"HZK\\Hzk24k");
	prt_hz24(140,320,"职",0x0000,"HZK\\Hzk24k");
	prt_hz24(140,350,"场",0x0000,"HZK\\Hzk24k");
	prt_hz24(140,380,"无",0x0000,"HZK\\Hzk24k");
	prt_hz24(140,410,"敌",0x0000,"HZK\\Hzk24k");
	prt_asc16_ch(150,430,'!',0x0000);
	circle(400, 472, 10, 0x000f);
	circle(400, 622, 10, 0x000f);

}

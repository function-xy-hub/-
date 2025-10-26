
#include"mainpage.h"


void main_page(int p,int num)
{
	struct BASIC basic={"C:\\self.bmp",0};
	int choose=0; 

	

 	while(choose!=-1)
 	{
 	    choose=mainpage();
 	    switch(choose)
 	    {
 	    
 	    	case -2:
 	    		main_page(p,num);
 	    		break;
 	    	case -1:
 	    		break;
 	    	case 1:
 	    		model1(p,num,basic);
 	    		break;
	    	case 4:
 	    		personal(p,num,basic);
				break;
			case 3:
				paint_(p,num);
				break;
 	    	default :
			    continue;
		}
	}
	
}
int mainpage()
{
	mpage();
	Mouse_Init();
	while(1)
	{
		MouseShow(&mouse);
    	delay(10); 
    	 if(MousePress(980,0,1024,30)==1) 
		 {
		 
			CloseSVGA();
			delay(1000);
			exit(1);
		 } 
	
	    if(MousePress(300,100,733,259)==1)
	    {
	    	return 1;
		}
		if(MousePress(0, 0,44 ,30)==1)
		 {
		 	return -1;
		 }
		 if(MousePress(46,0,140,30)==1)
		 {
		 	return -2;
		 }
		 
		 if(MousePress(300,500,733,659)==1)
		 {
		 	return 4;
		 }
		 if (MousePress(300, 300, 733, 459) == 1)
			 return 3;
	}
}
void mpage()
{
	bar1(0, 0, 1024,768,0xfffffb);
	bar1(980,0,1024,30,0x5d4f) ;
  	prt_hz16(985,5,"退出",0,"HZK\\Hz16");
  	bar1(0,0,44,30,0x5d4f) ;
  	prt_hz16(5,5,"返回",0,"HZK\\Hz16");
  	bar1(46,0,140,30,0xff00);
  	linexie(66,0,50,16,1,0);
  	linexie(66,0,82,16,1,0);
  	linever(58,8,58,27,1,0);
  	linelevel(58,27,74,27,1,0);
  	linever(74,8,74,27,1,0);
  	prt_hz24(90,5,"主页",0,"HZK\\hzk24k");
  	bar1(300,100,733,259,0x7bef);
	bar1(300,100,724,250,0xde5d);
    bar1(300,300,733,459,0x7bef);
	bar1(300,300,724,450,0xfde0);
	bar1(300,500,733,659,0x7bef);
	bar1(300,500,724,650,0x03ff); 
	linever(305+20,125,305+20,230,2,0xffff);
	linelevel(310+20,120,370+20,120,2,0xffff);
	linever(370+20,120,370+20,225,2,0xffff);
	linelevel(305+20,230,365+20,230,2,0xffff);
	linexie(305+20,125,310+20,120,2,0xffff);
	linexie(365+20,230,370+20,225,2,0xffff);
	linelevel(320+20,145,360+20,145,4,0xffff);
	linelevel(320+20,175,350+20,175,4,0xffff);
	linelevel(320+20,205,340+20,205,4,0xffff);
	

	FillCircle(357,375,50,0xffff); 
	FillCircle(357,375,48,0xfde0);
	FillCircle(357,375,3,0xffff);
	linever(347,365,347,405,2,0xffff);
	linever(367,345,367,385,2,0xffff);
	linexie(347,365,367,345,2,0xffff);
	linexie(347,405,367,385,2,0xffff);

	FillCircle(357,545,25,0xffff); 
	FillCircle(357,545,23,0x03ff);
	FillCircle(357,620,50,0xffff); 
	FillCircle(357,620,48,0x03ff);
	bar1(300,620,410,650,0x03ff);
	bar1(300,650,410,659,0x7bef);
	bar1(300,659,410,670,0xfffffb);
	
	prt_hz16_size(480,165,2,2,"选择模板",0,"HZK\\Hz16");
	prt_hz16_size(480,365,2,2,"制作模板",0,"HZK\\Hz16");
	prt_hz16_size(480,565,2,2,"个人中心",0,"HZK\\Hz16");
	prt_hz24(320,50,"点击下方，开启你的简历制作之旅吧！",0,"HZK\\hzk24k");
}

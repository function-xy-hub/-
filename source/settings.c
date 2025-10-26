
#include"shezhi.h"

void settings(int p,int num)
{
	int choose=0; 
    int i=0;
	

 	while(choose!=-1)
 	{
 	    choose=seetings_1();
 	    switch(choose)
 	    {
 	        case -2:
 	        	main_page(p,num);
 	        	break;
 	    	case -1:
 	    		break;
 	    	case 1:
 	    		hschange(p,num);
 	    		break;
 	    	case 2:
 	    		password(p,num);
 	    		break;
 	    	case 3:
 	    		login_system();
 	    		break;
 	    	default :
			    continue;
		}
	}
}



int settings_1()
{
	setpage();
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
	
		if(MousePress(0, 0,44 ,30)==1)
		 {
		 	return -1;
		 }
		if(MousePress(46,0,140,30)==1)
		 {
		 	return -2;
		 }
		
		 if(MousePress(385,245,630,300)==1)
		 {
		 		return 1;
		 } 
		 if(MousePress(393,453-50,639,508-50)==1)
		 {
		 	return 2;
		 }
		 if(MousePress(385,595-50,630,650-50)==1)
		{
			return 3;
		 } 
	}
}



void setpage()
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
  	bar1(393,253,639,308,0x7bef);
	
	bar1(385,245,630,300,0xde5d); 
  
  	
   	bar1(393,453-50,639,508-50,0x7bef);
	bar1(393,603-50,639,658-50,0x7bef);
	bar1(385,445-50,630,500-50,0xde5d);
	bar1(385,595-50,630,650-50,0xde5d);
	circle1(400,272,10,0x000f);
	circle1(400, 472-50, 10, 0x000f);
	circle1(400, 622-50, 10, 0x000f);
	prt_hz16_size(450,100,3,3,"设置",0x00ff,"HZK\\Hz16");
	prt_hz24d(470,260,"修改头像",0,"HZK\\hzk24k");
    prt_hz24d(470,460-50,"修改密码",0,"HZK\\hzk24k");
    prt_hz24d(470,610-50,"退出登录",0,"HZK\\hzk24k");
  	prt_hz24d(90,5,"主页",0,"HZK\\hzk24k");
}


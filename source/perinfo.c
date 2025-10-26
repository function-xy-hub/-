#include"perinfo.h"

void perinfo(int p,int num,struct BASIC basic)
{
	
	int choose=0; 
    
    basic.mod =-1;		

 	while(choose!=-1)
 	{
 	    choose=sperinfo(p);
 	    switch(choose)
 	    {
 	        case -2:
 	        	main_page(p,num);
 	        	break;
 	    	case -1:
 	    		break;
 	    	case 3:
 	    		settings(p,num);
 	    		break;
 	    	case 1:
 	    		page4(p,num,basic);
 	    		break;
 	    	case 2:
 	    		jlck(p,num);
 	    		break;
 	    	default :
			    continue;
		}
	}
}

int sperinfo(int p)
{
	perpage(p);
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
		if(MousePress(250,280,774,410)==1)
		 {
		 	return 1;
		 } 
		if(MousePress(250,420,774,560)==1)
		{
			return 2;
		}
		if(MousePress(250,570,774,700)==1)
		{
			return 3;
		}
	}
}
void perpage(int p)
{  
    char pp[10];
	FILE *fp;
	char s[20];

	if((fp=fopen("C:\\toux.txt","r"))==NULL)
	{
	   	prt_hz16_size(400,250,2,2,"错误",0,"HZK\\Hz16");
		delay(1000);	
	}
	fgets(s,13,fp);
	fclose(fp);


    itoa(p,pp,10);
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
  	prt_hz24d(90,5,"主页",0,"HZK\\hzk24k");
  	
  	
  	bar1(250,280,774,700,0xffff);
	bar1(250,410,774,420,0xc618);
	bar1(250,560,774,570,0xc618);
	
	
	linever(275,315,275,380,4,0);
	linelevel(280,310,330,310,4,0);
	linever(330,310,330,384,4,0);
	linelevel(275,380,330,380,4,0);
    linexie(275,315,280,310,4,0);
	linelevel(285,330,320,330,4,0x00ff);
	linelevel(285,345,310,345,4,0x00ff);
	linelevel(285,360,300,360,4,0x00ff);
	
	
	linever(275,510,275,530,3,0);
	linelevel(275,530,295,530,3,0);
	linexie(275,510,330,455,4,0);
	linexie(295,530,350,475,4,0);
	linexie(330,455,350,475,4,0);
	linexie(320,465,340,485,4,0);
	linelevel(310,530,340,530,3,0x00ff);
	
	
	linever(275,615,275,657,3,0);
	linexie(275,615,303,587,4,0);
	linexie(303,587,331,615,4,0);
	linever(331,615,331,657,3,0);
	linexie(331,655,303,683,4,0);
	linexie(275,655,303,683,4,0);
	FillCircle(304,636,15,0x00ff);
	FillCircle(304,636,10,0xffff);
	
	
	linexie(725,320,750,345,4,0);
	linexie(725,370,750,345,4,0);
	linexie(725,460,750,485,4,0);
	linexie(725,510,750,485,4,0);
	linexie(725,610,750,635,4,0);
	linexie(725,660,750,635,4,0);

  	FillCircle(288,186,60,0xffff);
  	
	  
	Putbmp64k00(250,150,s);

  	prt_hz16_size(430,50,2,2,"个人中心",0xff00,"HZK\\Hz16");
  	prt_hz16_size(400,146,2,2,"用户",0,"HZK\\Hz16");
  	put_asc16_size(480,146,2,2,pp,0);
  	
  	prt_hz16_size(450,335,2,2,"我的模板",0,"HZK\\Hz16");
  	prt_hz16_size(450,480,2,2,"我的简历",0,"HZK\\Hz16");
  	prt_hz16_size(470,625,2,2,"设置",0,"HZK\\Hz16");
	prt_hz24(395,190,"祝您早日找到工作！",0,"HZK\\hzk24k");
	
}





void jlck(int p,int num)
{
	int choose=0; 
 	while(choose!=-1)
 	{
 	    choose=ckjl();
 	    switch(choose)
 	    {
 	        case -2:
 	        	main_page(p,num);
 	        	break;
 	    	case -1:
 	    		break;
 	    	default :
			    continue;
		}
	}
}


int ckjl()
{
	bar1(0, 0, 1024,768,0x7F50);
	bar1(980,0,1024,30,0x5d4f) ;
  	prt_hz16(985,5,"退出",0,"HZK\\Hz16");
  	bar1(241,0,773,768,0xFFFF);
    bar1(0,0,44,30,0x5d4f);
  	prt_hz16(5,5,"返回",0,"HZK\\Hz16");
  	bar1(46,0,140,30,0xff00);
  	linexie(66,0,50,16,1,0);
  	linexie(66,0,82,16,1,0);
  	linever(58,8,58,27,1,0);
  	linelevel(58,27,74,27,1,0);
  	linever(74,8,74,27,1,0);
  	prt_hz24d(90,5,"主页",0,"HZK\\hzk24k");
	printf_image(241,0,773,768,"C:\\test\\savejl.dat");
	
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
	}
}


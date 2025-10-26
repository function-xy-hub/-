
#include"tpl.h"


//模板1 
void tpl1(int p, int num, BASIC basic)
{
   
	int choose=0;
	basic.mod =1;
	while(choose!=-1)   
	{
		choose=tpl_1(p,num,basic);
		switch(choose)           
		{
			
			case 2: 
			        tpl2(p,num,basic);
			        break;
			case -2:
			        main_page(p,num);
			        break;
			case -1: 
			        break;     
			case 3:
			       selfin(p,num,&basic) ;
				   break;  
			case 4:
			       content(p,num,&basic);
				   break; 
			default : 
			
			        continue;
		}
	}
}




int tpl_1(int p,int num,BASIC basic)
{
	int cc=0;
	int cd=0;
	int xx=0;
	int yy=0;
	int hh=-1;
    int aa=-1;
    int tt=-1;
    int dd=-1;
    int bb=-1;
	tplpage1(basic);
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
		if(MousePress(46,0,140,30)==1)
		 {
		 	return -2;
		 }
			if(MousePress(0, 0,44 ,30)==1)
		 {
		 	return -1;
		 }
		if((MousePress(820,354,850,414)==1)&&(strlen(basic.name)==0))
		{
			return 2;
		}
		if((MousePress(800,600,960,700)==1)&&(strlen(basic.name)==0)&&(basic.a ==0))
		{
             return 3;
        }
        if((MousePress(800,600,960,700)==1)&&strlen(basic.name)!=0&&(basic.a ==0))
		{
             return 4;
        }
        if((basic.a ==1)&&(MousePress(800,50,950,150))) 
        {
        	save_image(241,0,773,768,"C:\\test\\savejl.dat");
        	bar1(450,340,600,440,0xff00);
        	prt_hz24d(475,360,"保存成功",0,"HZK\\hzk24k"); 
        	delay(500);
        	return -2;
		}
		if((basic.a ==1)&&(MousePress(800,200,950,300)))
		{
		    cc=1;
			bar1(800,350,870,400,0xff00);
			bar1(900,350,970,400,0xff00);
			prt_hz16(800,360,"添加内容",0,"HZK\\Hz16");
			prt_hz16(900,360,"删减内容",0,"HZK\\Hz16");
		}
		if((cc==1)&&(MousePress(800,350,870,400)))
		{
			bar1(780,450,1000,480,0xffff);
			prt_hz24d(800,500,"请选择修改位置",0x7d58,"HZK\\hzk24k");
			MouseOff(&mouse);
			bar1(800,350,870,400,0x0fff);
			bar1(900,350,970,400,0xff00);
			prt_hz16(800,360,"添加内容",0,"HZK\\Hz16");
			prt_hz16(900,360,"删减内容",0,"HZK\\Hz16");
			MouseOn(mouse);
			bar1(800,590,870,640,0xff00);
			bar1(900,590,970,640,0xff00);	
			prt_hz16(810,600,"取消",0,"HZK\\Hz16");
			prt_hz16(910,600,"确认",0,"HZK\\Hz16");
			cd=1;
		}
		if((cc==1)&&(MousePress(880,350,950,400)))
		{
			bar1(780,450,1000,480,0xffff);
			prt_hz24d(800,500,"请选择修改位置",0x00ff,"HZK\\hzk24k");
			MouseOff(&mouse);
			bar1(800,350,870,400,0xff00);
			bar1(900,350,970,400,0x0fff);
			prt_hz16(800,360,"添加内容",0,"HZK\\Hz16");
			prt_hz16(900,360,"删减内容",0,"HZK\\Hz16");
			MouseOn(mouse);
			bar1(800,590,870,640,0xff00);
			bar1(900,590,970,640,0xff00);	
			prt_hz16(810,600,"取消",0,"HZK\\Hz16");
			prt_hz16(910,600,"确认",0,"HZK\\Hz16");
			cd=2;
		}
		if((cd!=0)&&(MousePress(265,215,773,768)))
		{
			xx=MouseX(&mouse);
			yy=MouseY(&mouse);
			delay(100);
			
			hh=-1;
			delay(20);
			amend(xx,yy,&hh,265,217,773,basic.txpp,basic,&dd,&tt,&bb,&aa);
		
			if(hh==-1)
			{
				bar1(800,490,1000,530,0x7F50); 
				prt_hz24d(800,500,"此处无法修改",0xf81f,"HZK\\hzk24k");
			}
			else if(hh!=-1)
			{
				bar1(780,490,1000,530,0x7F50); 
				MouseOff(&mouse);
		    	strcpy(basic.pa,"\0");
			   	bar1(780,450,1000,480,0xffff);
				Getinfo1(780,450,basic.pa ,20,265+(hh-tt)*8,217+25+bb*42+aa*8+dd*8,0xffff);
				
				
			     MouseOn(mouse);
				if(strcmp(basic.pa ,"\0")==0)
				{
					bar1(800,490,1000,530,0x7F50); 
				    prt_hz24d(800,500,"请选择修改位置",0,"HZK\\hzk24k");
				}
			  
			} 
	    }
			if(MousePress(800,590,870,640)&&strlen(basic.name)!=0&&(basic.a !=0))
			{
				cc=0;
				cd=0;
				bar1(800,350,1000,640,0x7F50);
			}
			if(MousePress(900,590,970,640)&&strlen(basic.name)!=0&&(basic.a !=0&&(cc!=0)&&(cd!=0)))
			{
				if(cd==1)
				{
					delay(100);
					addin(bb,hh,&basic);
					MouseOff(&mouse);
					modpage1(basic);
					MouseOn(mouse);
					cc=0;
				    cd=0;
				}
				if(cd==2)
				{
					
					basic.ap=atoi(basic.pa);
					delay(100);
					delate(bb,hh,&basic);
					MouseOff(&mouse);
					modpage1(basic);
					MouseOn(mouse);
					cc=0;
				    cd=0;
				 } 
			}
		
	}
}






void tplpage1(BASIC basic)
{
	
	int i=0;
	

	bar1(0, 0, 1024,768,0x7F50);
	bar1(980,0,1024,30,0x5d4f) ;
  	prt_hz16(985,5,"退出",0,"HZK\\Hz16");
  	bar1(241,0,773,768,0xFFFF);
    bar1(0,0,44,30,0x5d4f) ;
  	prt_hz16(5,5,"返回",0,"HZK\\Hz16");
  	bar1(46,0,140,30,0xff00);
  	linexie(66,0,50,16,1,0);
  	linexie(66,0,82,16,1,0);
  	linever(58,8,58,27,1,0);
  	linelevel(58,27,74,27,1,0);
  	linever(74,8,74,27,1,0);
  	prt_hz24d(90,5,"主页",0,"HZK\\hzk24k");
  	bar1(241,0,535,50,0x000F);
  	FillCircle(535,25,25,0x000F);
  	prt_hz24d(250,10,"个人简历",0xffff,"HZK\\hzk24k");
  	linever(350,5,350,45,2,0xffff);
  	put_asc16_size(360,4,1,1,"PERSONAL RESUME",0xFFFF);
  	put_asc16_size(360,26,1,1,"Start with every detail",0xffff);
  	prt_hz24d(600,10,"姓名",0,"HZK\\hzk24k") ;
    put_asc16_size(650,10,1,1,basic.name,0);
  	FillCircle(265,75,10,0x000f);
  	bar1(265,65,330,85,0x000f);
  	prt_hz16(260,67,"基本信息",0xffff,"HZK\\Hz16");
  	prt_hz16(265,100,"性别",0,"HZK\\Hz16");
  	prt_hz16(315,100,basic.sex ,0,"HZK\\Hz16");
  	prt_hz16(265,130,"年龄",0,"HZK\\Hz16");
  	put_asc16_size(315,130,1,1,basic.age ,0);
  	prt_hz16(265,160,"政治面貌",0,"HZK\\Hz16");
  	prt_hz16(335,160,basic.zzmm  ,0,"HZK\\Hz16");
  	prt_hz16(265,190,"婚姻状况",0,"HZK\\Hz16");
  	prt_hz16(335,190,basic.mar ,0,"HZK\\Hz16");
  
  	prt_hz16(450,100,"城市",0,"HZK\\Hz16") ;
  	put_asc16_size(500,100,1,1,basic.city,0);
  	prt_hz16(450,130,"电话",0,"HZK\\Hz16") ;
  	put_asc16_size(500,130,1,1,basic.phone ,0);
 
  	prt_hz16(450,160,"邮箱",0,"HZK\\Hz16") ;
  	put_asc16_size(500,160,1,1,basic.email,0);
 
  	Putbmp64k(660,100,basic.photo);
 
  	if(basic.a==0)
    {
	FillCircle(265,225,10,0x000f);
  	bar1(265,215,330,235,0x000f);
  	prt_hz16(260,217,"求职意向",0xffff,"HZK\\Hz16");
  	bar1(330,215,740,235,0xC618);
    FillCircle(265,300,10,0x000f);
  	bar1(265,290,330,310,0x000f);
  	prt_hz16(260,292,"教育背景",0xffff,"HZK\\Hz16");
  	bar1(330,290,740,310,0xC618);
    FillCircle(265,420,10,0x000f);
  	bar1(265,410,330,430,0x000f);
  	prt_hz16(260,412,"个人荣誉",0xffff,"HZK\\Hz16");
  	bar1(330,410,740,430,0xC618);
    FillCircle(265,500,10,0x000f);
  	bar1(265,490,330,510,0x000f);
  	prt_hz16(260,492,"自我评价",0xffff,"HZK\\Hz16");
  	bar1(330,490,740,510,0xC618);
  	FillCircle(265,630,10,0x000f);
  	bar1(265,620,330,640,0x000f);
  	prt_hz16(260,622,"其它信息",0xffff,"HZK\\Hz16");
  	bar1(330,620,740,640,0xC618);
    linexie(850,384,820,354,5,0xff00);
    linexie(850,384,820,414,5,0xff00);
    bar1(810,610,968,708,0x4bef);
    bar1(800,600,960,700,0xff00);
    if(strlen(basic.name)==0)
	{
    prt_hz24d(850,620,"选择",0,"HZK\\hzk24k");
	prt_hz24d(840,660,"此模板",0,"HZK\\hzk24k"); 
    }
    else
    {
    prt_hz24d(850,620,"继续",0,"HZK\\hzk24k");
	prt_hz24d(850,660,"输入",0,"HZK\\hzk24k"); 
	}
	}
	if(basic.a ==1)
	{
	bar1(800,200,950,300,0xff00);
	prt_hz24d(820,220,"内容修改",0,"HZK\\hzk24k");
	bar1(800,50,950,150,0xff00);
	prt_hz24d(820,70,"保存简历",0,"HZK\\hzk24k");
	readput(265,217,773,basic.txpp ,&i,basic);
	}
}




//模板2 
void tpl2(int p,int num,BASIC basic)
{
	
	int choose=0;
	basic.mod =2;
	while(choose!=-1)   
	{
		choose=tpl_2(p,num,basic);
		switch(choose)           
		{
			
			case -2:
			       main_page(p,num);
				   break;  
			case -1: 
			        break;    
			case 1:
			       tpl1(p,num,basic);  
		    case 3:
			       selfin(p,num,&basic) ;
				   break;  
			case 4:
			       content(p,num,&basic);
				   break;    
			default :
			        continue;
		}
	}
 } 
 
 
 
 int tpl_2(int p,int num,BASIC basic)
 {  int cc=0;
	int cd=0;
	int xx=0;
	int yy=0;
	int hh=-1;
    int aa=-1;
    int tt=-1;
    int dd=-1;
    int bb=-1;
 	
 	tplpage2(basic);
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
		if(MousePress(46,0,140,30)==1)
		 {
		 	return -2;
		 }
		 	if(MousePress(0, 0,44 ,30)==1)
		 {
		 	return -1;
		 }
	    if(strlen(basic.name)==0)
		 {
		if(MousePress(164,354,194,414)==1)
		{
			return 1;
		}
		if(MousePress(820,354,850,414)==1)
		 {
		 	return 2;
		 }
       	}
	
		if((MousePress(800,600,960,700)==1)&&(strlen(basic.name)==0)&&(basic.a ==0))
		{
             return 3;
        }
        if((MousePress(800,600,960,700)==1)&&strlen(basic.name)!=0&&(basic.a ==0))
		{
             return 4;
        }
         if((basic.a ==1)&&(MousePress(800,50,950,150))) 
        {
        	save_image(241,0,773,768,"C:\\test\\savejl.dat");
        	bar1(450,340,600,440,0xff00);
        	prt_hz24d(475,360,"保存成功",0,"HZK\\hzk24k"); 
        	delay(500);
        	return -2;
		}
		if((basic.a ==1)&&(MousePress(800,200,950,300)))
		{
		    cc=1;
			bar1(800,350,870,400,0xff00);
			bar1(900,350,970,400,0xff00);
			prt_hz16(800,360,"添加内容",0,"HZK\\Hz16");
			prt_hz16(900,360,"删减内容",0,"HZK\\Hz16");
		}
		if((cc==1)&&(MousePress(800,350,870,400)))
		{
			bar1(780,450,1000,480,0xffff);
			prt_hz24d(800,500,"请选择修改位置",0x7d58,"HZK\\hzk24k");
			MouseOff(&mouse);
			bar1(800,350,870,400,0x0fff);
			bar1(900,350,970,400,0xff00);
			prt_hz16(800,360,"添加内容",0,"HZK\\Hz16");
			prt_hz16(900,360,"删减内容",0,"HZK\\Hz16");
			MouseOn(mouse);
			bar1(800,590,870,640,0xff00);
			bar1(900,590,970,640,0xff00);	
			prt_hz16(810,600,"取消",0,"HZK\\Hz16");
			prt_hz16(910,600,"确认",0,"HZK\\Hz16");
			cd=1;
		}
		if((cc==1)&&(MousePress(880,350,950,400)))
		{
			bar1(780,450,1000,480,0xffff);
			prt_hz24d(800,500,"请选择修改位置",0x00ff,"HZK\\hzk24k");
			MouseOff(&mouse);
			bar1(800,350,870,400,0xff00);
			bar1(900,350,970,400,0x0fff);
			prt_hz16(800,360,"添加内容",0,"HZK\\Hz16");
			prt_hz16(900,360,"删减内容",0,"HZK\\Hz16");
			MouseOn(mouse);
			bar1(800,590,870,640,0xff00);
			bar1(900,590,970,640,0xff00);	
			prt_hz16(810,600,"取消",0,"HZK\\Hz16");
			prt_hz16(910,600,"确认",0,"HZK\\Hz16");
			cd=2;
		}
		if((cd!=0)&&(MousePress(455,30,773,768)))
		{
			xx=MouseX(&mouse);
			yy=MouseY(&mouse);
			delay(100);
			
			hh=-1;
			amend(xx,yy,&hh,455,30,773,basic.txpp,basic,&dd,&tt,&bb,&aa);
		
			if(hh==-1)
			{
				bar1(800,490,1000,530,0x7F50); 
				prt_hz24d(800,500,"此处无法修改",0xf81f,"HZK\\hzk24k");
			}
			else if(hh!=-1)
			{
				bar1(780,490,1000,530,0x7F50); 
				MouseOff(&mouse);
		    	strcpy(basic.pa,"\0");
			   	bar1(780,450,1000,480,0xffff);
				Getinfo1(780,450,basic.pa ,20,455+(hh-tt)*8,30+25+bb*42+aa*8+dd*8,0xffff);
				
				
			     MouseOn(mouse);
				if(strcmp(basic.pa ,"\0")==0)
				{
					bar1(800,490,1000,530,0x7F50); 
				    prt_hz24d(800,500,"请选择修改位置",0,"HZK\\hzk24k");
				}
			  
			} 
	    }
			if(MousePress(800,590,870,640)&&strlen(basic.name)!=0&&(basic.a !=0))
			{
				cc=0;
				cd=0;
				bar1(800,350,1000,640,0x7F50);
			}
			if(MousePress(900,590,970,640)&&strlen(basic.name)!=0&&(basic.a !=0))
			{
				if(cd==1)
				{
					delay(100);
					addin(bb,hh,&basic);
					MouseOff(&mouse);
					modpage2(basic);
					MouseOn(mouse);
					cc=0;
				    cd=0;
				}
				if(cd==2)
				{
					
					basic.ap=atoi(basic.pa);
					delay(100);
					delate(bb,hh,&basic);
					MouseOff(&mouse);
					modpage2(basic);
					MouseOn(mouse);
					cc=0;
				    cd=0;
				 } 
			}
	
	}
}
 

 
void tplpage2(BASIC basic)
 {
 	char *pp=malloc(25);
 	int i=0;
 	bar1(0, 0, 1024,768,0x7F50);
	bar1(980,0,1024,30,0x5d4f) ;
  	prt_hz16(985,5,"退出",0,"HZK\\Hz16");
  	bar1(241,0,773,768,0xFFFF); 
    bar1(0,0,44,30,0x5d4f) ;
  	prt_hz16(5,5,"返回",0,"HZK\\Hz16");	
  	bar1(46,0,140,30,0xff00);
  	linexie(66,0,50,16,1,0);
  	linexie(66,0,82,16,1,0);
  	linever(58,8,58,27,1,0);
  	linelevel(58,27,74,27,1,0);
  	linever(74,8,74,27,1,0);
  	prt_hz24d(90,5,"主页",0,"HZK\\hzk24k");
  	Putbmp64k(241,0,"c:\\mod1.bmp") ;
  	prt_hz24d(250,10,"姓名",0xffff,"HZK\\hzk24k");
  	put_asc16_size(310,10,1,1,basic.name ,0xffff);
  	bar1(280,50,360,150,0xffff);
  	Putbmp64k(280,50,basic.photo);
  	prt_hz16(250,180,"基本信息",0xffff,"HZK\\Hz16"); 
  	put_asc16_size(245,200,1,1,"-----------------",0xffff); 
  	prt_hz16(255,230,"性别",0xffff,"HZK\\Hz16");
  	prt_hz16(310,230,basic.sex ,0xffff,"HZK\\Hz16");
  	prt_hz16(255,260,"年龄",0xffff,"HZK\\Hz16");
  	put_asc16_size(310,260,1,1,basic.age ,0xffff);
  	prt_hz16(255,290,"政治面貌",0xffff,"HZK\\Hz16");
  	prt_hz16(340,290,basic.zzmm ,0xffff,"HZK\\Hz16");
  	prt_hz16(255,320,"婚姻状况",0xffff,"HZK\\Hz16");
  	prt_hz16(340,320,basic.mar  ,0xffff,"HZK\\Hz16");
  	
    prt_hz16(255,355,"城市",0xffff,"HZK\\Hz16");
  	putput1(290,355,1,1,basic.city ,0xffff,415,0,0x000f);
  	prt_hz16(255,400,"电话",0xffff,"HZK\\Hz16");
  	putput1(290,400,1,1,basic.phone,0xffff,415,0,0x000f);
  	prt_hz16(255,450,"邮箱",0xffff,"HZK\\Hz16");
  	strcpy(pp,basic.email );
  	strcpy(pp+strlen(basic.email ),"\0");	
	
  	putput1(290,450,1,1,pp,0xffff,415,0,0x000f);
  	free(pp);
  	pp=NULL;
	 if(basic.a==0)
   { 
	prt_hz16(250,500,"个人荣誉",0xffff,"HZK\\Hz16"); 
  	put_asc16_size(245,520,1,1,"-----------------",0xffff); 
  	linever(440,40,440,750,2,0); 
  	FillCircle(440,40,7,0x000f);
  	prt_hz24d(455,30,"求职意向",0x000f,"HZK\\Hzk24k"); 
  	FillCircle(440,150,7,0x000f);
  	prt_hz24d(455,140,"教育背景",0x000f,"HZK\\Hzk24k"); 
  	FillCircle(440,300,7,0x000f);
  	prt_hz24d(455,290,"自我评价",0x000f,"HZK\\Hzk24k"); 
  	FillCircle(440,500,7,0x000f);
  	prt_hz24d(455,490,"其它信息",0x000f,"HZK\\Hzk24k"); 
  	linexie(850,384,820,354,5,0xff00);
    linexie(850,384,820,414,5,0xff00);
    linexie(164,384,194,354,5,0xff00);
    linexie(164,384,194,414,5,0xff00);
    bar1(810,610,968,708,0x4bef);
    bar1(800,600,960,700,0xff00);
    if(strlen(basic.name)==0)
	{
    prt_hz24d(850,620,"选择",0,"HZK\\hzk24k");
	prt_hz24d(840,660,"此模板",0,"HZK\\hzk24k"); 
    }
    else
    {
    prt_hz24d(850,620,"继续",0,"HZK\\hzk24k");
	prt_hz24d(850,660,"输入",0,"HZK\\hzk24k"); 
	}
	}
	else if (basic.a==1)
	{
		linever(440,40,440,750,2,0); 
		readput(455,30,773,basic.txpp ,&i,basic);
		bar1(800,200,950,300,0xff00);
		prt_hz24d(820,220,"内容修改",0,"HZK\\hzk24k");
		bar1(800,50,950,150,0xff00);
		prt_hz24d(820,70,"保存简历",0,"HZK\\hzk24k");
	
	}
  } 
  
  //模板3
  void tpl3(int p,int num,BASIC basic)
  {
  	int choose=0;
	basic.mod =3;
	while(choose!=-1)
	{
		choose=tpl_3(p,num,basic);
		switch(choose)
		{
			case -2:
			       main_page(p,num);
				   break;
			case -1:
			        break;
			case 1:
			       tpl1(p,num,basic);
		    case 3:
			       selfin(p,num,&basic) ;	
		    case 4:
			       content(p,num,&basic);
				   break;
			default :
			        continue;
		}	
	}
}

void tpl_3(int p,int num,BASIC basic)
{  int cc=0;
	int cd=0;
	int xx=0;
	int yy=0;
	int hh=-1;
    int aa=-1;
    int tt=-1;
    int dd=-1;
    int bb=-1

 	tplpage3(basic);
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
		if(MousePress(46,0,140,30)==1)
		 {
		 	return -2;
		 }
		 	if(MousePress(0, 0,44 ,30)==1)
		 {
		 	return -1;
		 }
	    if(strlen(basic.name)==0)
		 {
		if(MousePress(164,354,194,414)==1)
		{
			return 1;
		}
		if(MousePress(820,354,850,414)==1)
		 {
		 	return 2;
		 }
       	}
	
		if((MousePress(800,600,960,700)==1)&&(strlen(basic.name)==0)&&(basic.a ==0))
		{
             return 3;
        }
        if((MousePress(800,600,960,700)==1)&&strlen(basic.name)!=0&&(basic.a ==0))
		{
             return 4;
        }
         if((basic.a ==1)&&(MousePress(800,50,950,150))) 
        {
        	save_image(241,0,773,768,"C:\\test\\savejl.dat");
        	bar1(450,340,600,440,0xff00);
        	prt_hz24d(475,360,"保存成功",0,"HZK\\hzk24k"); 
        	delay(500);
        	return -2;
		}
		if((basic.a ==1)&&(MousePress(800,200,950,300)))
		{
		    cc=1;
			bar1(800,350,870,400,0xff00);
			bar1(900,350,970,400,0xff00);
			prt_hz16(800,360,"添加内容",0,"HZK\\Hz16");
			prt_hz16(900,360,"删减内容",0,"HZK\\Hz16");
		}
		if((cc==1)&&(MousePress(800,350,870,400)))
		{
			bar1(780,450,1000,480,0xffff);
			prt_hz24d(800,500,"请选择修改位置",0x7d58,"HZK\\hzk24k");
			MouseOff(&mouse);
			bar1(800,350,870,400,0x0fff);
			bar1(900,350,970,400,0xff00);
			prt_hz16(800,360,"添加内容",0,"HZK\\Hz16");
			prt_hz16(900,360,"删减内容",0,"HZK\\Hz16");
			MouseOn(mouse);
			bar1(800,590,870,640,0xff00);
			bar1(900,590,970,640,0xff00);	
			prt_hz16(810,600,"取消",0,"HZK\\Hz16");
			prt_hz16(910,600,"确认",0,"HZK\\Hz16");
			cd=1;
		}
		if((cc==1)&&(MousePress(880,350,950,400)))
		{
			bar1(780,450,1000,480,0xffff);
			prt_hz24d(800,500,"请选择修改位置",0x00ff,"HZK\\hzk24k");
			MouseOff(&mouse);
			bar1(800,350,870,400,0xff00);
			bar1(900,350,970,400,0x0fff);
			prt_hz16(800,360,"添加内容",0,"HZK\\Hz16");
			prt_hz16(900,360,"删减内容",0,"HZK\\Hz16");
			MouseOn(mouse);
			bar1(800,590,870,640,0xff00);
			bar1(900,590,970,640,0xff00);	
			prt_hz16(810,600,"取消",0,"HZK\\Hz16");
			prt_hz16(910,600,"确认",0,"HZK\\Hz16");
			cd=2;
		}
		if((cd!=0)&&(MousePress(455,30,773,768)))
		{
			xx=MouseX(&mouse);
			yy=MouseY(&mouse);
			delay(100);
			
			hh=-1;
			amend(xx,yy,&hh,455,30,773,basic.txpp,basic,&dd,&tt,&bb,&aa);
		
			if(hh==-1)
			{
				bar1(800,490,1000,530,0x7F50); 
				prt_hz24d(800,500,"此处无法修改",0xf81f,"HZK\\hzk24k");
			}
			else if(hh!=-1)
			{
				bar1(780,490,1000,530,0x7F50); 
				MouseOff(&mouse);
		    	strcpy(basic.pa,"\0");
			   	bar1(780,450,1000,480,0xffff);
				Getinfo1(780,450,basic.pa ,20,455+(hh-tt)*8,30+25+bb*42+aa*8+dd*8,0xffff);
				
				
			     MouseOn(mouse);
				if(strcmp(basic.pa ,"\0")==0)
				{
					bar1(800,490,1000,530,0x7F50); 
				    prt_hz24d(800,500,"请选择修改位置",0,"HZK\\hzk24k");
				}
			  
			} 
	    }
			if(MousePress(800,590,870,640)&&strlen(basic.name)!=0&&(basic.a !=0))
			{
				cc=0;
				cd=0;
				bar1(800,350,1000,640,0x7F50);
			}
			if(MousePress(900,590,970,640)&&strlen(basic.name)!=0&&(basic.a !=0))
			{
				if(cd==1)
				{
					delay(100);
					addin(bb,hh,&basic);
					MouseOff(&mouse);
					tplpage3(basic);
					MouseOn(mouse);
					cc=0;
				    cd=0;
				}
				if(cd==2)
				{
					
					basic.ap=atoi(basic.pa);
					delay(100);
					delate(bb,hh,&basic);
					MouseOff(&mouse);
					tplpage3(basic);
					MouseOn(mouse);
					cc=0;
				    cd=0;
				 } 
			}
	
	}
}


void tplpage3(BASIC basic)
{
    char *pp = malloc(25);
    int i = 0;

    // 背景设置
    bar1(0, 0, 1024, 768, 0x6699CC);
    bar1(980, 0, 1024, 30, 0x336699);
    prt_hz16(985, 5, "退出", 0, "HZK\\Hz16");
    bar1(0, 0, 140, 30, 0x336699);
    prt_hz16(5, 5, "返回", 0, "HZK\\Hz16");
    bar1(142, 0, 240, 30, 0xff00);
    linexie(162, 0, 150, 16, 1, 0);
    linexie(162, 0, 182, 16, 1, 0);
    linever(158, 8, 158, 27, 1, 0);
    linelevel(158, 27, 174, 27, 1, 0);
    linever(174, 8, 174, 27, 1, 0);
    prt_hz24d(190, 5, "主页", 0, "HZK\\hzk24k");

    // 个人信息区域
    bar1(20, 50, 300, 300, 0xFFFFFF);
    Putbmp64k(30, 60, basic.photo);
    prt_hz24d(40, 220, "姓名", 0x000000, "HZK\\hzk24k");
    put_asc16_size(100, 220, 1, 1, basic.name, 0x000000);
    prt_hz24d(40, 250, "性别", 0x000000, "HZK\\hzk24k");
    prt_hz16(100, 250, basic.sex, 0x000000, "HZK\\Hz16");
    prt_hz24d(40, 280, "年龄", 0x000000, "HZK\\hzk24k");
    put_asc16_size(100, 280, 1, 1, basic.age, 0x000000);

    // 联系信息区域
    bar1(320, 50, 600, 300, 0xFFFFFF);
    prt_hz24d(330, 60, "联系信息", 0x000000, "HZK\\hzk24k");
    put_asc16_size(335, 80, 1, 1, "-----------------", 0x000000);
    prt_hz16(335, 110, "城市", 0x000000, "HZK\\Hz16");
    putput1(380, 110, 1, 1, basic.city, 0x000000, 415, 0, 0x000f);
    prt_hz16(335, 140, "电话", 0x000000, "HZK\\Hz16");
    putput1(380, 140, 1, 1, basic.phone, 0x000000, 415, 0, 0x000f);
    prt_hz16(335, 170, "邮箱", 0x000000, "HZK\\Hz16");
    strcpy(pp, basic.email);
    strcpy(pp + strlen(basic.email), "\0");
    putput1(380, 170, 1, 1, pp, 0x000000, 415, 0, 0x000f);
    free(pp);
    pp = NULL;

    // 其他信息区域
    if (basic.a == 0)
    {
        prt_hz16(20, 350, "个人荣誉", 0x000000, "HZK\\Hz16");
        put_asc16_size(20, 370, 1, 1, "-----------------", 0x000000);
        linever(620, 50, 620, 750, 2, 0);
        FillCircle(620, 50, 7, 0x000f);
        prt_hz24d(635, 40, "求职意向", 0x000f, "HZK\\Hzk24k");
        FillCircle(620, 200, 7, 0x000f);
        prt_hz24d(635, 190, "教育背景", 0x000f, "HZK\\Hzk24k");
        FillCircle(620, 400, 7, 0x000f);
        prt_hz24d(635, 390, "自我评价", 0x000f, "HZK\\Hzk24k");
        FillCircle(620, 600, 7, 0x000f);
        prt_hz24d(635, 590, "其它信息", 0x000f, "HZK\\Hzk24k");
        linexie(850, 384, 820, 354, 5, 0xff00);
        linexie(850, 384, 820, 414, 5, 0xff00);
        linexie(164, 384, 194, 354, 5, 0xff00);
        linexie(164, 384, 194, 414, 5, 0xff00);
        bar1(810, 610, 968, 708, 0x4bef);
        bar1(800, 600, 960, 700, 0xff00);
        if (strlen(basic.name) == 0)
        {
            prt_hz24d(850, 620, "选择", 0, "HZK\\hzk24k");
            prt_hz24d(840, 660, "此模板", 0, "HZK\\hzk24k");
        }
        else
        {
            prt_hz24d(850, 620, "继续", 0, "HZK\\hzk24k");
            prt_hz24d(850, 660, "输入", 0, "HZK\\hzk24k");
        }
    }
    else if (basic.a == 1)
    {
        linever(620, 50, 620, 750, 2, 0);
        readput(635, 40, 773, basic.txpp, &i, basic);
        bar1(800, 200, 950, 300, 0xff00);
        prt_hz24d(820, 220, "内容修改", 0, "HZK\\hzk24k");
        bar1(800, 50, 950, 150, 0xff00);
        prt_hz24d(820, 70, "保存简历", 0, "HZK\\hzk24k");
    }
}    
 
//自动排版功能 *****
  int readput(int x1,int y1,int x2,char*path ,int *d,struct BASIC basic)
  {
  
	FILE *fp;
	int i,j,k=0,l=0,m=0,n=0,a=0,b=0;
  	
    char*abc=malloc(1000);
	char*s=malloc(1000);
	char*p=malloc(1000);	
	if((fp=fopen(path,"r"))==NULL)
	{
		prt_hz24d(100,100,"读取文件错误",0x000f,"HZK\\Hzk24k");
	}
	for(i=0;i<1000;i++)
	{
		abc[i]=fgetc(fp); 
		if(abc[i]==' '&&abc[i-1]==' ')
		{
			break;
		}	
	}
	abc[i-1]='\0';
	fclose (fp);
   for(j=0;j<strlen(abc)-k;j++)
	{
		
	
	strcpy(s,abc+k+j+l);
	
	strcpy(s+5,"\0");
	if(strcmp(s,"educa")==0||
	   strcmp(s,"honor")==0||
	   strcmp(s,"objec")==0||
	   strcmp(s,"other")==0||
	   strcmp(s,"jobsk")==0||
	   strcmp(s,"evalu")==0
	)
	    {
	    	for(m=0;m<7;m++)
		{
			if (abc[k+j+5+m]==':')
		    	{
				n=1;
		    	break;
		    }
		}
		if(n==1)
	   	break;
    	}
    }
   for(i=0;i<6;i++)
 {
    strcpy(p,abc+k+j+l);
	k=k+j+l+7;
	l=m;
    strcpy(p+5+l,"\0");
    if(basic.mod==1)
    {
	
    if((strcmp(p,"objective")==0&&basic.object ==1)||
       (strcmp(p,"education")==0&&basic.edu==1)||
       (strcmp(p,"jobskill")==0&&basic.jobskill ==1)||
       (strcmp(p,"honors")==0&&basic.honor ==1)||
       (strcmp(p,"evaluate")==0&&basic.selfpj ==1)||
       (strcmp(p,"others")==0&& basic.other ==1))
    {
   	 
	 FillCircle(x1,y1+b*42+a*8+8,9,0x000f);
    bar1(x1+69,y1+b*42+a*8-1,740,y1+b*42+a*8+17,0xc618);
    bar1(x1,y1+b*42+a*8-1,x1+75,y1+b*42+a*8+17,0x000f);
    a=a+putput1(x1,y1+b*42+a*8,1,1,p,0xffff,x2,*d,0xffff);
    }
    }
    else if(basic.mod==2)
    {
    	if((strcmp(p,"objective")==0&&basic.object ==1)||
       (strcmp(p,"education")==0&&basic.edu==1)||
       (strcmp(p,"jobskill")==0&&basic.jobskill ==1)||
       (strcmp(p,"evaluate")==0&&basic.selfpj ==1)||
       (strcmp(p,"others")==0&& basic.other ==1))
    {
   	FillCircle(440,y1+b*42+a*8+8,7,0x000f);
    a=a+putput1(x1,y1+b*42+a*8,1,1,p,0x000f,x2,*d,0xffff);
    }
        else if((strcmp(p,"honors")==0&&basic.honor ==1))
        {
        	putput1(250,500,1,1,p,0xffff,400,0,0x000f);
		}
	}
    strcpy(s,"\0");
    for(j=0;j<strlen(abc)-k;j++)
	{
		
	
	strcpy(s,abc+k+j+l);
	strcpy(s+5,"\0");
	if(strcmp(s,"educa")==0||
	   strcmp(s,"honor")==0||
	   strcmp(s,"objec")==0||
	   strcmp(s,"other")==0||
	   strcmp(s,"jobsk")==0||
	   strcmp(s,"evalu")==0)
	   
	{
		for(m=0,n=0;m<7;m++)
		{
			if (abc[k+j+5+l+m]==':')
		    	{
				n=1;
				break;
		    	}
		}
		if(n==1)
	   	break;
	}
    }
   strcpy(s,abc+k+l);
   strcpy(s+j,"\0");
   if(basic.mod==1)
   {
   
   if((strcmp(p,"objective")==0&&basic.object ==1)||
       (strcmp(p,"education")==0&&basic.edu==1)||
       (strcmp(p,"jobskill")==0&&basic.jobskill ==1)||
       (strcmp(p,"honors")==0&&basic.honor ==1)||
       (strcmp(p,"evaluate")==0&&basic.selfpj ==1)||
       (strcmp(p,"others")==0&& basic.other ==1))
   {
   a=a+putput1(x1,y1+25+b*42+a*8,1,1,s,0,x2,*d,0xffff);
   b++;
   }
   }
   else if(basic.mod==2)
   {
   	    if((strcmp(p,"objective")==0&&basic.object ==1)||
       (strcmp(p,"education")==0&&basic.edu==1)||
       (strcmp(p,"jobskill")==0&&basic.jobskill ==1)||
       (strcmp(p,"evaluate")==0&&basic.selfpj ==1)||
       (strcmp(p,"others")==0&& basic.other ==1))
   {
   a=a+putput1(x1,y1+25+b*42+a*8,1,1,s,0,x2,*d,0xffff);
   b++;
   }
       else if( (strcmp(p,"honors")==0&&basic.honor ==1))
       putput1(250,516,1,1,s,0xffff,400,0,0x000f);
   }
}
 
    free(abc);
    abc=NULL;
    free(s);
    s=NULL;
    free(p);
    p=NULL;
return 0;
}



//简历内容修改//
void amend(int xx,int yy,int *hh,int x1,int y1,int x2,char*path,struct BASIC basic,int *dd,int *tt,int *bb,int *aa)
{

	FILE *fp;
	int i,j,k=0,l=0,m=0,n=0,a=0,b=0;
  	int c;
    char*abc=malloc(1000);
	char*s=malloc(1000);
	char*p=malloc(1000);	
	if((fp=fopen(path,"r"))==NULL)
	{
		prt_hz24d(100,100,"读取文件错误",0x00ff,"HZK\\Hzk24k");
		 put_asc16_size(100,200,1,1,path,0);
		 put_asc16_size(100,300,1,1,basic.txpp ,0);
	}
	for(i=0;i<1000;i++)
	{
		abc[i]=fgetc(fp); 
		if(abc[i]==' '&&abc[i-1]==' ')
		{
			break;
		}	
	}
	abc[i-1]='\0';
	fclose (fp);
   for(j=0;j<strlen(abc)-k;j++)
	{
		
	
	strcpy(s,abc+k+j+l);
	
	strcpy(s+5,"\0");
	if(strcmp(s,"educa")==0||
	   strcmp(s,"honor")==0||
	   strcmp(s,"objec")==0||
	   strcmp(s,"other")==0||
	   strcmp(s,"jobsk")==0||
	   strcmp(s,"evalu")==0
	)
	    {
	    	for(m=0;m<7;m++)
		{
			if (abc[k+j+5+m]==':')
		    	{
				n=1;
		    	break;
		    }
		}
		if(n==1)
	   	break;
    	}
    }
   for(i=0;i<6;i++)
 {
    strcpy(p,abc+k+j+l);
	k=k+j+l+7;
	l=m;
    strcpy(p+5+l,"\0");
    if(basic.mod==1)
    {
	
    if((strcmp(p,"objective")==0&&basic.object ==1)||
       (strcmp(p,"education")==0&&basic.edu==1)||
       (strcmp(p,"jobskill")==0&&basic.jobskill ==1)||
       (strcmp(p,"honors")==0&&basic.honor ==1)||
       (strcmp(p,"evaluate")==0&&basic.selfpj ==1)||
       (strcmp(p,"others")==0&& basic.other ==1))
    {
   	 
	FillCircle(x1,y1+b*42+a*8+8,9,0x000f);
    bar1(x1+69,y1+b*42+a*8-1,740,y1+b*42+a*8+17,0xc618);
    bar1(x1,y1+b*42+a*8-1,x1+75,y1+b*42+a*8+17,0x000f);
    a=a+putput1(x1,y1+b*42+a*8,1,1,p,0xffff,x2,0,0xffff);
    
    }
    }
    else if(basic.mod==2)
    {
    	if((strcmp(p,"objective")==0&&basic.object ==1)||
       (strcmp(p,"education")==0&&basic.edu==1)||
       (strcmp(p,"jobskill")==0&&basic.jobskill ==1)||
       (strcmp(p,"evaluate")==0&&basic.selfpj ==1)||
       (strcmp(p,"others")==0&& basic.other ==1))
    {
   	FillCircle(440,y1+b*42+a*8+8,7,0x000f);
    a=a+putput1(x1,y1+b*42+a*8,1,1,p,0x000f,x2,0,0xffff);
    }
        else if((strcmp(p,"honors")==0&&basic.honor ==1))
        {
        	putput1(250,500,1,1,p,0xffff,400,0,0x000f);
		}
	}
    strcpy(s,"\0");
    for(j=0;j<strlen(abc)-k;j++)
	{
		
	
	strcpy(s,abc+k+j+l);
	strcpy(s+5,"\0");
	if(strcmp(s,"educa")==0||
	   strcmp(s,"honor")==0||
	   strcmp(s,"objec")==0||
	   strcmp(s,"other")==0||
	   strcmp(s,"jobsk")==0||
	   strcmp(s,"evalu")==0)
	   
	{
		for(m=0,n=0;m<7;m++)
		{
			if (abc[k+j+5+l+m]==':')
		    	{
				n=1;
				break;
		    	}
		}
		if(n==1)
	   	break;
	}
    }
   strcpy(s,abc+k+l);
   strcpy(s+j,"\0");
   if(basic.mod==1)
   {
   
   if((strcmp(p,"objective")==0&&basic.object ==1)||
       (strcmp(p,"education")==0&&basic.edu==1)||
       (strcmp(p,"jobskill")==0&&basic.jobskill ==1)||
       (strcmp(p,"honors")==0&&basic.honor ==1)||
       (strcmp(p,"evaluate")==0&&basic.selfpj ==1)||
       (strcmp(p,"others")==0&& basic.other ==1))
   {
   	c=a;
    a=a+putput2(x1,y1+25+b*42+a*8,1,1,s,0,x2,0xffff,xx,yy,hh,dd,tt);
    if((yy>=y1+b*42+c*8)&&(yy<=(y1+(b+1)*42+a*8)))
    {
    	*bb=b;
    	*aa=c;
	}
    b++;
   }
   }
   else if(basic.mod==2)
   {
   	   if((strcmp(p,"objective")==0&&basic.object ==1)||
       (strcmp(p,"education")==0&&basic.edu==1)||
       (strcmp(p,"jobskill")==0&&basic.jobskill ==1)||
       (strcmp(p,"evaluate")==0&&basic.selfpj ==1)||
       (strcmp(p,"others")==0&& basic.other ==1))
   {
    c=a;
    a=a+putput2(x1,y1+25+b*42+a*8,1,1,s,0,x2,0xffff,xx,yy,hh,dd,tt);
    if((yy>=y1+b*42+c*8)&&(yy<=(y1+(b+1)*42+a*8)))
    {
    	*bb=b;
    	*aa=c;
	}
    b++;
   }
       else if( (strcmp(p,"honors")==0&&basic.honor ==1))
       putput1(250,516,1,1,s,0xffff,400,0,0x000f);
   }
}
 
    free(abc);
    abc=NULL;
    free(s);
    s=NULL;
    free(p);
    p=NULL;
}


void addin(int bb,int hh,struct BASIC *basic)
{
	
	FILE *fp;
	int i,j,k=0,l=0,m=0,n=0,a=0,b=0;
  	int c;
   char*abc=malloc(1000);
	char*s=malloc(1000);
	char*p=malloc(1000);

		if((fp=fopen(basic->txpp ,"r"))==NULL)
	{
		prt_hz24d(100,100,"读取文件错误",0x00ff,"HZK\\Hzk24k");
	}
	for(i=0;i<1000;i++)
	{
		abc[i]=fgetc(fp); 
		if(abc[i]==' '&&abc[i-1]==' ')
		{
			break;
		}	
	}
	abc[i-1]='\0';
     fclose(fp);
	   for(j=0;j<strlen(abc)-k;j++)
	{
		
	
	strcpy(s,abc+k+j+l);
	
	strcpy(s+5,"\0");
	if(strcmp(s,"educa")==0||
	   strcmp(s,"honor")==0||
	   strcmp(s,"objec")==0||
	   strcmp(s,"other")==0||
	   strcmp(s,"jobsk")==0||
	   strcmp(s,"evalu")==0
	)
	    {
	    	for(m=0;m<7;m++)
		{
			if (abc[k+j+5+m]==':')
		    	{
				n=1;
		    	break;
		    }
		}
		if(n==1)
	   	break;
    	}
    }
   for(i=0;i<6;i++)
 {
    strcpy(p,abc+k+j+l);
	k=k+j+l+7;
	l=m;
    strcpy(p+5+l,"\0");
    strcpy(s,"\0");
    for(j=0;j<strlen(abc)-k;j++)
	{
		
	
	strcpy(s,abc+k+j+l);
	strcpy(s+5,"\0");
	if(strcmp(s,"educa")==0||
	   strcmp(s,"honor")==0||
	   strcmp(s,"objec")==0||
	   strcmp(s,"other")==0||
	   strcmp(s,"jobsk")==0||
	   strcmp(s,"evalu")==0)
	   
	{
		for(m=0,n=0;m<7;m++)
		{
			if (abc[k+j+5+l+m]==':')
		    	{
				n=1;
				break;
		    	}
		}
		if(n==1)
	   	break;
	}
    }
   strcpy(s,abc+k+l);
   strcpy(s+j,"\0");
   if(basic->mod==1)
   {
   
   if((strcmp(p,"objective")==0&&basic->object ==1)||
       (strcmp(p,"education")==0&&basic->edu==1)||
       (strcmp(p,"jobskill")==0&&basic->jobskill ==1)||
       (strcmp(p,"honors")==0&&basic->honor ==1)||
       (strcmp(p,"evaluate")==0&&basic->selfpj ==1)||
       (strcmp(p,"others")==0&& basic->other ==1))
   {
        b++;
   }
   }
   else if(basic->mod==2)
   {
   	    if((strcmp(p,"objective")==0&&basic->object ==1)||
       (strcmp(p,"education")==0&&basic->edu==1)||
       (strcmp(p,"jobskill")==0&&basic->jobskill ==1)||
       
       (strcmp(p,"evaluate")==0&&basic->selfpj ==1)||
       (strcmp(p,"others")==0&& basic->other ==1))
   		{
        b++;
      	}
   }
    if(b==bb+1)
    {
    	break;
    }
   
}

   strcpy(p,abc+k+l+hh);
   strcpy(abc+k+l+hh,basic->pa);
   strcat(abc,p);
   strcat(abc,"    ");
   
    if((fp=fopen(basic->txpp ,"wt+"))==NULL)
	{
		prt_hz24d(100,100,"读取文件错误",0xff00,"HZK\\Hzk24k");
	}
    fputs(abc,fp);
    fclose(fp);
    free(abc);
    abc=NULL;
    free(s);
    s=NULL;
    free(p);
    p=NULL;
    strcpy(basic->pa,"\0");
    basic->ap =0;
}


void delate(int bb,int hh,struct BASIC *basic)
{
	
	FILE *fp;
	int i,j,k=0,l=0,m=0,n=0,a=0,b=0;
  	int c;
    char*abc=malloc(1000);
	char*s=malloc(1000);
	char*p=malloc(1000);

		if((fp=fopen(basic->txpp ,"r"))==NULL)
	{
		prt_hz24d(100,100,"读取文件错误",0x4d58,"HZK\\Hzk24k");
	}
	for(i=0;i<1000;i++)
	{
		abc[i]=fgetc(fp); 
		if(abc[i]==' '&&abc[i-1]==' ')
		{
			break;
		}	
	}
	abc[i-1]='\0';
     fclose(fp);
	   for(j=0;j<strlen(abc)-k;j++)
	{
		
	
	strcpy(s,abc+k+j+l);
	
	strcpy(s+5,"\0");
	if(strcmp(s,"educa")==0||
	   strcmp(s,"honor")==0||
	   strcmp(s,"objec")==0||
	   strcmp(s,"other")==0||
	   strcmp(s,"jobsk")==0||
	   strcmp(s,"evalu")==0
	)
	    {
	    	for(m=0;m<7;m++)
		{
			if (abc[k+j+5+m]==':')
		    	{
				n=1;
		    	break;
		    }
		}
		if(n==1)
	   	break;
    	}
    }
   for(i=0;i<6;i++)
 {
    strcpy(p,abc+k+j+l);
	k=k+j+l+7;
	l=m;
    strcpy(p+5+l,"\0");
    strcpy(s,"\0");
    for(j=0;j<strlen(abc)-k;j++)
	{
		
	
	strcpy(s,abc+k+j+l);
	strcpy(s+5,"\0");
	if(strcmp(s,"educa")==0||
	   strcmp(s,"honor")==0||
	   strcmp(s,"objec")==0||
	   strcmp(s,"other")==0||
	   strcmp(s,"jobsk")==0||
	   strcmp(s,"evalu")==0)
	   
	{
		for(m=0,n=0;m<7;m++)
		{
			if (abc[k+j+5+l+m]==':')
		    	{
				n=1;
				break;
		    	}
		}
		if(n==1)
	   	break;
	}
    }
   strcpy(s,abc+k+l);
   strcpy(s+j,"\0");
   if(basic->mod==1)
   {
   
   if((strcmp(p,"objective")==0&&basic->object ==1)||
       (strcmp(p,"education")==0&&basic->edu==1)||
       (strcmp(p,"jobskill")==0&&basic->jobskill ==1)||
       (strcmp(p,"honors")==0&&basic->honor ==1)||
       (strcmp(p,"evaluate")==0&&basic->selfpj ==1)||
       (strcmp(p,"others")==0&& basic->other ==1))
   {
        b++;
   }
   }
   else if(basic->mod==2)
   {
   	    if((strcmp(p,"objective")==0&&basic->object ==1)||
       (strcmp(p,"education")==0&&basic->edu==1)||
       (strcmp(p,"jobskill")==0&&basic->jobskill ==1)||
      
       (strcmp(p,"evaluate")==0&&basic->selfpj ==1)||
       (strcmp(p,"others")==0&& basic->other ==1))
   		{
        b++;
      	}
   }
    if(b==bb+1)
    {
    	break;
    }
}
   strcpy(p,abc+k+l+hh);
   strcpy(abc+k+l+hh-basic->ap ,"\0");
   strcat(abc,p);
   strcat(abc,"    ");
   if((fp=fopen(basic->txpp ,"wt+"))==NULL)
	{
		prt_hz24d(100,100,"读取文件错误",0xffff,"HZK\\Hzk24k");
	}
    fputs(abc,fp);
    fclose(fp);
    free(abc);
    abc=NULL;
    free(s);\
    s=NULL;
    free(p);
    p=NULL;
    strcpy(basic->pa,"\0");
    basic->ap =0;
}

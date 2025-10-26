#include"selfin.h"

void selfin(int p,int num,BASIC *basic)
{
	
	 int choose=0;
	 while(choose!=-1)
	 {
	 	
	 
	 choose=self_in(p,num,basic);
 	    switch(choose)
 	    {
 	    
 	       
 	    	case -2:
 	    		main_page(p,num);
 	    		break;
 	    	case -1:
 	    		break;
 	    	case 10:
 	    		photo(p,num,basic);
 	    		break;
 	    	default :  continue;
		}
	}
}

int self_in(int p,int num,BASIC *basic)
{
	
	selfpage(*basic);
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
		 if(MousePress(650,136,650+72,136+48)) 
		 {
		 	return 10;
		 }
		 if(MousePress(250,90,500,130)==1)
		 {
		 	MouseOff(&mouse);
			strcpy(basic->name,"\0");
			bar1(250,90,500,130,0xffff);
			Getinfo(250,90,basic->name,20);
			
	    	if(strlen(basic->name)==0)
			{
			prt_hz16(250,100,"点击这里输入",0x4bef,"HZK\\Hz16") ;
	        }
			MouseOn(mouse);
		 }
		 if(MousePress(250,330,500,370)==1)
		 {
		 	MouseOff(&mouse);
			strcpy(basic->age,"\0");
			bar1(250,330,500,370,0xffff);
			Getinfo(250,330,basic->age,2);
			
	    	if(strlen(basic->age)==0)
			{
			prt_hz16(250,340,"点击这里输入",0x4bef,"HZK\\Hz16") ;
	        }
			MouseOn(mouse);
		 }
		 if(MousePress(250,570,500,620)==1)
		 {
		 	MouseOff(&mouse);
			strcpy(basic->city,"\0");
			bar1(250,570,500,610,0xffff);
			Getinfo(250,570,basic->city,10);
			
	    	if(strlen(basic->city )==0)
			{
			prt_hz16(250,580,"点击这里输入",0x4bef,"HZK\\Hz16") ;
	        }
			MouseOn(mouse);
		 } 
		 if(MousePress(250,730,500,768)==1)
		 {
		 	MouseOff(&mouse);
			strcpy(basic->email ,"\0");
			bar1(250,730,500,768,0xffff);
			Getinfo(250,730,basic->email ,20);
	    	if(strlen(basic->email)==0)
			{
			prt_hz16(250,740,"点击这里输入",0x4bef,"HZK\\Hz16") ;
	        }
			MouseOn(mouse);
		 }
		 if(MousePress(250,650,500,690)==1)
		 {
		 	MouseOff(&mouse);
			strcpy(basic->phone,"\0");
			bar1(250,650,500,690,0xffff);
			Getinfo(250,650,basic->phone,11);
			
	    	if(strlen(basic->phone)==0)
			{
			prt_hz16(250,660,"点击这里输入",0x4bef,"HZK\\Hz16") ;
	        }
		
			while(1)
			{
			
			if(strlen(basic->phone)<11&&strlen(basic->phone)>0)
			{
			prt_hz16(550,660,"手机号不合法",0x4bef,"HZK\\Hz16") ;
			strcpy(basic->phone,"\0");
			bar1(250,650,500,690,0xffff);
			Getinfo(250,650,basic->phone,11);
		    }
			else
		    {
			bar1(549,650,680,680,0xffff);
			break;
			}
			MouseOn(mouse);
	    
	        }
		
		 }
		if(MousePress(260,255,310,280)==1)
		{
			MouseOff(&mouse);
			
			FillCircle(270,265,6,0x0fff);
			FillCircle(380,265,6,0xffff);
			strcpy(basic->sex,"男"); 
		    basic->sex[2]='\0';
			MouseOn(mouse); 
		}
		if(MousePress(370,255,420,280)==1)
		{
			MouseOff(&mouse);
		
			FillCircle(270,265,6,0xffff);
			FillCircle(380,265,6,0x0fff);
			strcpy(basic->sex,"女"); 
			 basic->sex[2]='\0';	
			 MouseOn(mouse); 
		}
		if(MousePress(260,255+160,310,280+160)==1)
		{	
		    MouseOff(&mouse);
			
			FillCircle(270,265+160,6,0x0fff);
			FillCircle(380,265+160,6,0xffff);
			FillCircle(490,265+160,6,0xffff);		
			strcpy(basic->zzmm,"共产党员");
	        basic->zzmm[8]='\0';
			MouseOn(mouse); 
		}
		if(MousePress(370,255+160,420,280+160)==1)
		{
			MouseOff(&mouse);
			
			FillCircle(270,265+160,6,0xffff);
			FillCircle(380,265+160,6,0x0fff);
			FillCircle(490,265+160,6,0xffff);	
			strcpy(basic->zzmm,"共青团员");
	        basic->zzmm[8]='\0';
			MouseOn(mouse); 
		}
		if(MousePress(480,255+160,530,280+160)==1)
		{
			MouseOff(&mouse);
			
			FillCircle(270,265+160,6,0xffff);
			FillCircle(380,265+160,6,0xffff);
			FillCircle(490,265+160,6,0x0fff);	
			strcpy(basic->zzmm,"群众"); 
		    basic->zzmm[4]='\0';
			MouseOn(mouse); 
		}
		 if(MousePress(800,600,960,700)==1)
		 {
		 /*	if(strlen(basic->name )==0||
			 strlen(basic->age )==0||
			 strlen(basic->city  )==0||
			 strlen(basic->email )==0||
			 strlen(basic->mar )==0||
			 strlen(basic->phone  )==0||
			 strlen(basic->sex )==0||
			 strlen(basic->zzmm )==0) 
			 {
			 	prt_hz16(800,550,"有信息未输入！",0xf81f,"HZK\\Hz16") ;
			 }
			 else*/
			 return -1;
			
		     
		 }
		 if(MousePress(260,255+240,310,280+240)==1)
		{
			MouseOff(&mouse);
		
			FillCircle(270,265+240,6,0x0fff);
			FillCircle(380,265+240,6,0xffff);
			strcpy(basic->mar,"已婚"); 
	        basic->mar[4]='\0';
			MouseOn(mouse); 
		}
		if(MousePress(370,255+240,420,280+240)==1)
		{
			MouseOff(&mouse);
		
			FillCircle(270,265+240,6,0xffff);
			FillCircle(380,265+240,6,0x0fff);
			strcpy(basic->mar,"未婚"); 
	        basic->mar[4]='\0';	
			MouseOn(mouse); 
		}
	}
}



void  selfpage(BASIC basic)
{
	bar1(0,0,1024,768,0x7F50);
	bar1(980,0,1024,30,0x5d4f);
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
    prt_hz24d(450,10,"基本信息",0,"HZK\\hzk24k");
    prt_hz24d(250,80-20,"姓名",0,"HZK\\hzk24k");
    
    prt_hz24d(250,160-20,"上传照片",0,"HZK\\hzk24k");
    prt_hz24d(250,240-20,"性别",0,"HZK\\hzk24k");
    prt_hz24d(250,320-20,"年龄",0,"HZK\\hzk24k");
    prt_hz24d(250,400-20,"政治面貌",0,"HZK\\hzk24k");
    prt_hz24d(250,480-20,"婚姻状况",0,"HZK\\hzk24k");
    prt_hz24d(250,560-20,"城市",0,"HZK\\hzk24k");
    prt_hz24d(250,640-20,"电话",0,"HZK\\hzk24k");
    prt_hz24d(250,720-20,"邮箱",0,"HZK\\hzk24k");
    linelevel(245,135,770,135,1,0); 
    linelevel(245,135+80,770,135+80,1,0); 
    linelevel(245,135+160,770,135+160,1,0); 
    linelevel(245,135+240,770,135+240,1,0); 
    linelevel(245,135+320,770,135+320,1,0); 
    linelevel(245,135+400,770,135+400,1,0); 
    linelevel(245,135+480,770,135+480,1,0); 
    linelevel(245,135+560,770,135+560,1,0); 
    if(strlen(basic.name)==0)
    {
    	
	
    prt_hz16(250,100,"点击这里输入",0x4bef,"HZK\\Hz16") ;
    
	}
	else
	{
		put_asc16_size(250,100,1,1,basic.name,0);
	}
	prt_hz16(250,180,"请上传您的清晰正脸照片，点击右侧上传照片",0x4bef,"HZK\\Hz16") ;
    Putbmp64k(650,136,basic.photo) ;
    //Putbmp64k(650,136,"c:\\pho1.bmp");
    circle1(270,265,8,0x00ff);
    prt_hz16(290,260,"男",0x4bef,"HZK\\Hz16") ;
    circle1(380,265,8,0x00ff);
    prt_hz16(400,260,"女",0x4bef,"HZK\\Hz16") ;
    if(strlen(basic.age )==0)
    prt_hz16(250,340,"点击这里输入",0x4bef,"HZK\\Hz16") ;
    else
	put_asc16_size(250,340,1,1,basic.age,0);
    circle1(270,265+160,8,0x00ff);
    prt_hz16(290,260+160,"共产党员",0x4bef,"HZK\\Hz16") ;
    circle1(380,265+160,8,0x00ff);
    prt_hz16(400,260+160,"共青团员",0x4bef,"HZK\\Hz16") ;
    circle1(490,265+160,8,0x00ff);
    prt_hz16(510,260+160,"群众",0x4bef,"HZK\\Hz16") ;
    circle1(270,265+240,8,0x00ff);
    prt_hz16(290,260+240,"已婚",0x4bef,"HZK\\Hz16") ;
    circle1(380,265+240,8,0x00ff);
    prt_hz16(400,260+240,"未婚",0x4bef,"HZK\\Hz16") ;
    if(strlen(basic.city )==0)
    prt_hz16(250,580,"点击这里输入",0x4bef,"HZK\\Hz16") ;
    else
    put_asc16_size(250,580,1,1,basic.city ,0);
    if(strlen(basic.phone)==0)
    prt_hz16(250,660,"点击这里输入",0x4bef,"HZK\\Hz16") ;
    else
    put_asc16_size(250,660,1,1,basic.phone,0);
    if(strlen(basic.email)==0)
    prt_hz16(250,740,"点击这里输入",0x4bef,"HZK\\Hz16") ;
    else
    put_asc16_size(250,740,1,1,basic.email,0);
    bar1(810,610,968,708,0x4bef);
    bar1(800,600,960,700,0xff00);
    prt_hz24d(850,640,"确认",0,"HZK\\hzk24k");
	
}


void photo(int p,int num,BASIC *basic)
{
	 int choose=0;
	 while(choose!=-1)
	 {
	 	
	 
	 choose=photoin(p,num,basic);
 	    switch(choose)
 	    {
 	    
 	    	case -2:
 	    		main_page(p,num);
 	    		break;
 	    	case -1:
 	    		break;
 	    	default :  continue;
 	    
		}
	}
 } 
 
 
 int photoin(int p,int num,struct BASIC *basic)
 {
 	
	int atc;
	int yy=0;
	int i=0;
	BmpFile bmpfile[20]={0};
	atc=Document(1,&bmpfile);
	bar1(452,600,572,660,0xff00);
	prt_hz24d(490,620,"确认",0,"HZK\\hzk24k");
	prt_hz24d(480,30,"照片选择",0,"HZK\\hzk24k");
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
		 if(MousePress(80,150,1000,150+atc*25))
		 {
		    yy=mouse.y ;
		 	yy=(yy-150)/25+1;
		 	delay(100);
			
		 	strcpy(basic->photo ,"C:\\bmp\\");
		 	
		 	bar1(450,500,600,600,0xffff); 
		 	
		 	
		 	strcat(basic->photo ,bmpfile[yy].name );
		 	strcpy(basic->photo +18,"\0");
		 	
		 	Putbmp64k(470,450,basic->photo );
		   
            
		 }
		 
		 if(MousePress(452,600,572,660)==1)
		 {
		 	/*if(strcmp(basic.photo,"C:\\self.bmp")==0)
		 	{
		 		prt_hz24d(450,700,"请选择图片",0,"HZK\\Hzk24k");
		 		delay(500);
			 }
			else*/
			return -1;
		 }
	}
 }
 
 
 
 

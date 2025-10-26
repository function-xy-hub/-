//page4 绘制自定义图形页面
#include"tplmake.h"



void display_tplpage(int p,int num,struct BASIC basic)
{
	int choose=0; 
    int i;
	graphitem graph[20]={0};
	FILE *file;
	file = fopen("C:\\test\\resume_p.dat", "rb");
	if (file == NULL)
	{
	    prt_hz24d(100,100,"错误！",0,"HZK\\hzk24k");
	}
	else
	{
		fread(&graph, sizeof(graphitem), 20, file);
		fclose(file);
	}

	

 	while(choose!=-1)
 	{
 	    choose=create_tpl(&basic,graph);
 	    switch(choose)
 	    {
 	        case -2:
 	        	main_page(p,num);
 	        	break;
 	    	case -1:
 	    		break;
 	    	case 3:
				   selfin(p,num,&basic) ;
				   break;  
			case 4:
			       txtlook1(p,num,&basic,graph);
				   break; 
 	    	default :
			    continue;
		}
	}
}


int create_tpl(struct BASIC *basic,graphitem*graph)
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
    int i;
	mtpl_page(*basic,graph);
	//鼠标操作
	Mouse_Init();
	while (1)
	{
		MouseShow(&mouse);

		//退出
		if (MouseIn(974, 0, 1024, 30) == 1 && MousePress(974, 0, 1024, 30) == 1)
		{
			CloseSVGA();
			delay(1000);
			exit(1);
		}

		if (MouseIn(0, 0, 50, 30) == 1 && MousePress(0, 0, 50, 30) == 1)
		{
			return -1;
		}
		if(MousePress(46,0,140,30)==1)
		 {
		 	return -2;
		 }
	 if((MousePress(800,600,960,700)==1)&&(strlen(basic->name)==0)&&(basic->a ==0))
		{
             return 3;
        }
        if((MousePress(800,600,960,700)==1)&&strlen(basic->name)!=0&&(basic->a ==0))
		{
			 
             return 4;
        }
     /*if((basic->a ==1)&&(MousePress(800,200,950,300)))
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
		}*/
	/*	for(i=0;i<20;i++)
		{
			if(graph[i].shape==6&&(strcmp(graph[i].title,"basic")!=0)&&MousePress(graph[i].x0,graph[i].y0,graph[i].x1,graph[i].y1)&&(cd!=0))
			{
				//prt_hz24d(graph[i].x0,graph[i].y1,"哈哈哈",0,"HZK\\hzk24k");
					xx=mouse.x ;
			        yy=mouse.y ;
			        delay(100);
			        hh=-1;
			        selfamend(xx,yy,&hh,&graph[i],*basic,&aa,&tt,&dd);
			        
			      	if(hh==-1)
					{
						bar1(800,490,1000,530,0x7F50); 
						prt_hz24d(800,500,"此处无法修改",0xf81f,"HZK\\hzk24k");
					}
				/*	else if(hh!=-1)
					{
					bar1(780,490,1000,530,0x7F50); 
					MouseOff(&mouse);
		    		strcpy(basic->pa,"\0");
			   		bar1(780,450,1000,480,0xffff);
					Getinfo1(780,450,basic->pa ,20,graph[i].x0+(hh-tt)*8,graph[i].y0+aa*8+dd*8,0xffff);
				
				
			    	 MouseOn(mouse);
				if(strcmp(basic->pa ,"\0")==0)
				{
					bar1(800,490,1000,530,0x7F50); 
				    prt_hz24d(800,500,"请选择修改位置",0,"HZK\\hzk24k");
				}
			  
		}
			}
		}*/
	}
}

void mtpl_page(struct BASIC basic,graphitem*graph)
{
	int i;
	bar1(0, 0, 1024, 768, 0x7F50);
	bar1(228,0,562+228,768,0xffff);
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
	
	for (i = 0; i<20;i++)
	{
		drawitem1(&graph[i], basic);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
	}
		
		
			 if(strlen(basic.name)==0)
		{
			bar1(800,600,960,700,0xff00);
    		prt_hz24d(850,620,"选择",0,"HZK\\hzk24k");
			prt_hz24d(840,660,"此模板",0,"HZK\\hzk24k"); 
   		 }
   		 else
   		 {
   		 	bar1(800,600,960,700,0xff00);
   		 prt_hz24d(850,620,"继续",0,"HZK\\hzk24k");
		 prt_hz24d(850,660,"输入",0,"HZK\\hzk24k"); 
		 }
		 

}
void drawitem1(graphitem *ap,struct BASIC basic)
{
    switch (ap->shape)
    {
    case 6:
        if (ap->x1 > 562+228)
            ap->x1 = 562+228;
        if (ap->y1 > 768)
            ap->y1 = 768;
        bar1(ap->x0, ap->y0, ap->x1, ap->y1, ap->color);
        //put_asc16_size(ap->x0+8,ap->y0+8,1,1,ap->title ,0);
        if(strcmp(ap->title,"basic")==0)
        { 
        	prt_hz16(ap->x0,ap->y0,"姓名",0,"HZK\\hz16");
        	putput1(ap->x0+40,ap->y0,1,1,basic.name,0,ap->x1 ,0,ap->color );
        	prt_hz16(ap->x0,ap->y0+27,"年龄",0,"HZK\\hz16");
        	putput1(ap->x0+40,ap->y0+27,1,1,basic.age,0,ap->x1 ,0,ap->color );
        	prt_hz16(ap->x0,ap->y0+27*2,"性别",0,"HZK\\hz16");
        	prt_hz16(ap->x0 +40,ap->y0 +27*2,basic.sex ,0,"HZK\\hz16");
        	prt_hz16(ap->x0,ap->y0+27*3,"政治面貌",0,"HZK\\hz16");
        	prt_hz16(ap->x0 +72,ap->y0 +27*3,basic.zzmm  ,0,"HZK\\hz16");
        	prt_hz16(ap->x0,ap->y0+27*4,"婚姻状况",0,"HZK\\hz16");
        	prt_hz16(ap->x0 +72,ap->y0 +27*4,basic.mar ,0,"HZK\\hz16");
        	prt_hz16(ap->x0,ap->y0+27*5,"城市",0,"HZK\\hz16");
        	putput1(ap->x0+40,ap->y0+27*5,1,1,basic.city ,0,ap->x1 ,0,ap->color );
        	prt_hz16(ap->x0,ap->y0+27*6,"电话",0,"HZK\\hz16");
        	putput1(ap->x0+40,ap->y0+27*6,1,1,basic.phone ,0,ap->x1 ,0,ap->color );
        	prt_hz16(ap->x0,ap->y0+27*7,"邮箱",0,"HZK\\hz16");
        	putput1(ap->x0+40,ap->y0+27*7,1,1,basic.email ,0,ap->x1 ,0,ap->color );
		}
        break;
    case 1:
        if ((ap->x0) + (ap->x1) > 562+228)
            (ap->x0) = 562+228 - (ap->x1);
        if ((ap->y0) + (ap->x1) > 768)
            (ap->y0) = 768 - (ap->x1);
        FillCircle(ap->x0, ap->y0, ap->x1, ap->color);
        break;
    case 2:
        if ((ap->x0) + (ap->x1) > 562+228)
            (ap->x0) = 562+228 - (ap->x1);
        if ((ap->y0) + (ap->y1) > 768)
            (ap->y0) = 768 - (ap->y1);
        Ellipsefill(ap->x0,ap->y0,ap->x1,ap->y1, 3, ap->color);
        put_asc16_size(ap->x0-ap->x1+8,ap->y0-8,1,1,ap->title ,0);
        break;
    case 3:
        if ((ap->x0) + (ap->x1) > 562+228)
            (ap->x0) = 562+228 - (ap->x1);
        if ((ap->y0) +( ap->y1 )> 768)
            (ap->y0) = 768 - (ap->y1);
        ladder1(ap->x0, ap->y0, ap->x1, ap->y1, ap->color);
        put_asc16_size(ap->x0+8,ap->y0 +ap->y1/2-8,1,1,ap->title ,0);
        break;
    case 4:
        if ((ap->x0) + 120 + 40 > 562+228)
            (ap->x0) = 562+228 - (ap->x1)- (ap->y1);
        if ((ap->y0) + 40 > 768)
            (ap->y0) = 768 - (ap->y1);
        ladder(ap->x0, ap->y0, ap->x1, ap->y1, ap->color);
        put_asc16_size(ap->x0+8,ap->y0 +ap->y1/2-8,1,1,ap->title ,0);
        break;
    case 5:
        if ((ap->x0) > 562+228)
            (ap->x0) = 562+228;
        if ((ap->y0) > 768)
            (ap->y0) = 768;
        if ((ap->x1) > 562+228)
            (ap->x1) = 562+228;
        if ((ap->y1 )> 768)
            (ap->y1) = 768;
        if(fabs(ap->x0-ap->x1)<=20)
            Line_Thick(ap->x0, ap->y0, ap->x0, ap->y1, 2, ap->color);
        else  if(fabs(ap->y0-ap->y1)<=20)
            Line_Thick(ap->x0, ap->y0, ap->x1, ap->y0, 2, ap->color);
        else
        Line_Thick(ap->x0, ap->y0, ap->x1, ap->y1, 2, ap->color);
        break;
    case 7:
    	bar1(ap->x0+228,ap->y0 ,ap->x1+228,ap->y1,ap->color );
    	Putbmp64k(ap->x0+228,ap->y0,basic.photo);
		break;
    }
}

void txtlook1(int p,int num, struct BASIC *basic ,graphitem*graph)
{
	int choose=0;
	while(choose!=-1)
	{
		
		choose=txt_look1(p,num,basic); 
		 
		switch(choose)           
		{
			
			case -2: main_page(p,num);
			        break;
			case -1:break;		 
		    case 2:
		    	txtout1(p,num,basic,graph);
		        break;    	
			default :continue;
		}
	}
	
 } 
 
 
  int txt_look1(int p,int num,struct BASIC *basic)
{
	int atc;
	int yy=0;
	int i=0;
	BmpFile bmpfile[20]={0};
	atc=Document(2,&bmpfile);

	prt_hz24d(480,30,"文件选择",0,"HZK\\hzk24k");
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
		    yy=MouseY(&mouse);
		 	yy=(yy-150)/25+1;
		 	delay(100);
			
		 	strcpy(basic->txpp ,"C:\\info\\");
		 	
		 	//bar1(450,500,600,600,0xffff); 
		 	
		 	
		 	strcat(basic->txpp ,bmpfile[yy].name );
		 	strcpy(basic->txpp +19,"\0");
		 	return  2;
		 }
	}
 }
 
 
void txtout1(int p,int num,struct BASIC *basic,graphitem*graph)
{

	int choose=0;
	

	while(choose!=-1)
	{
		
       	choose=txt_out1(p,num,basic,graph);
	 
		switch(choose)           
		{
			
			case -2: main_page(p,num);
			        break;
			case -1:break;		 
		    
		    
			default :continue;
		}
	}
}



int txt_out1 (int p,int num,struct BASIC *basic,graphitem*graph)
{
	txtpage1(basic);
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
		if((MousePress(0, 0,44 ,30))||(MousePress(350-100,600,470-100,660)))
		 {
		 	return -1;
		 }
		if(MousePress(46,0,140,30)==1)
		 {
		 	return -2;
		 }
		 if(MousePress(500+100,600,620+100,660))
		 {
		 	MouseOff(&mouse);
		 	page4pag1(*basic,graph);
		 	MouseOn(mouse);
		 	basic->a=1;
		 }
		 if((basic->a ==1)&&(MousePress(800,50,950,150))) 
        {
        	save_image(241,0,773,768,"C:\\test\\savejl.dat");
        	bar1(450,340,600,440,0xff00);
        	prt_hz24d(475,360,"保存成功",0,"HZK\\hzk24k"); 
        	delay(500);
        	return -2;
		}
}
}


void mtpl_page1(struct BASIC basic,graphitem*graph)
{
	int i;
	bar1(0, 0, 1024, 768, 0x7F50);
	bar1(228,0,562+228,768,0xffff);
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
	
	for (i = 0; i<20;i++)
	{
		drawitem1(&graph[i], basic);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
	}
	selfmake(basic,graph);
	bar1(800,50,950,150,0xff00);
	prt_hz24d(820,70,"保存简历",0,"HZK\\hzk24k");	 

}


void txtpage1(struct BASIC *basic)
{
	FILE *fp;
	char *abc=malloc(1500);
	int i=0,j;
	bar1(0,0,1024,768,0xffff);

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
	if((fp=fopen(basic->txpp,"r"))==NULL)
	{
		prt_hz24d(100,100,"读取文件错误",0,"HZK\\Hzk24k");
	}
	for(i=0;i<1500;i++)
	{
		abc[i]=fgetc(fp); 
		if(abc[i]==' '&&abc[i-1]==' ')
		{
			break;
		}
		
	}
	abc[i-1]='\0';
   
   fclose (fp);
   

   putput1(50,50,1,1,abc,0,1000,0,0xffff);
   free(abc);
   abc=NULL;
   bar1(350-100,600,470-100,660,0xff00);
   prt_hz24d(290,620,"返回",0,"HZK\\Hzk24k");
   bar1(500+100,600,620+100,660,0xff00);
   prt_hz24d(640,620,"选择",0,"HZK\\Hzk24k");
}

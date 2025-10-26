#include"content.h"

void content(int p,int num,struct BASIC *basic)
{
	
	int choose=0;
	while(choose!=-1)
	{
		
		choose=con_tent(p,num,basic); 
		 
		switch(choose)           
		{
			
			case -2: main_page(p,num);
			        break;
			case -1:break;
			case 1:
			      txtlook(p,num,basic)	;
				  break;	 
		             
			default :continue;
		}
	}
}


int con_tent(int p,int num,struct BASIC *basic )
{


    inset();
    
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
		if(MousePress(310,110,350,150)&&(basic->object==0))
		{
			delay(150);
			basic->object =1;
		    ppaagg1(110);
			
		}
		if(MousePress(310,110,350,150)&&(basic->object==1))
		{
			delay(150);
			basic->object=0;
			ppaagg2(310,110,350,150);
		}
		if(MousePress(310,110+60,350,150+60)&&(basic->edu ==0))
		{
			delay(150);
			basic->edu  =1;
		    ppaagg1(110+60);
			
		}
		if(MousePress(310,110+60,350,150+60)&&(basic->edu==1))
		{
			delay(150);
			basic->edu =0;
			ppaagg2(310,110+60,350,150+60);
		}
		if(MousePress(310,110+120,350,150+120)&&(basic->honor ==0))
		{
			delay(150);
			basic->honor  =1;
		    ppaagg1(110+120);
			
		}
		if(MousePress(310,110+120,350,150+120)&&(basic->honor ==1))
		{
			delay(150);
			basic->honor =0;
			ppaagg2(310,110+120,350,150+120);
		}
		if(MousePress(310,110+180,350,150+180)&&(basic->jobskill==0))
		{
			
			delay(150);
			basic->jobskill =1;
		    ppaagg1(110+180);
			
		}
		if(MousePress(310,110+180,350,150+180)&&(basic->jobskill==1))
		{
			delay(150);
			basic->jobskill=0;
			ppaagg2(310,110+180,350,150+180);
		}
		if(MousePress(310,110+240,350,150+240)&&(basic->selfpj==0))
		{
			delay(150);
			basic->selfpj=1;
		    ppaagg1(110+240);
			
		}
		if(MousePress(310,110+240,350,150+240)&&(basic->selfpj==1))
		{
			delay(150);
			basic->selfpj=0;
			ppaagg2(310,110+240,350,150+240);
		}
		if(MousePress(310,110+300,350,150+300)&&(basic->other==0))
		{
			delay(150);
			basic->other=1;
		    ppaagg1(110+300);
			
		}
		if(MousePress(310,110+300,350,150+300)&&(basic->other==1))
		{
			delay(150);
			basic->other=0;
			ppaagg2(310,110+300,350,150+300);
		}
		if(MousePress(800,600,960,700))
		{
			basic->a =1;
			return 1;
		}
}
}

void ppaagg1(int y1)
{
		MouseOff(&mouse);
		Line_Thick(320,y1+20,330,y1+30,2,0x0c63);
  	    Line_Thick(330,y1+30,345,y1+3,2,0x0c63);
  	    MouseOn(mouse);
}
void ppaagg2(int x1,int y1,int x2,int y2)
{
		MouseOff(&mouse);
		bar1(x1,y1,x2,y2,0);
        bar1(x1+3,y1+3,x2-3,y2-3,0xffff);
  	    MouseOn(mouse);
  	    
  	    
}
void inset()//选择内容 
{
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
  	prt_hz24d(450,30,"内容选择",0,"HZK\\hzk24k");
  	bar1(250+50+10,100+10,300+50,150,0);
  	bar1(253+50+10,103+10,297+50,147,0xffff);
  	prt_hz24_asc32(400,120,"求职意向(objective)", 0, "HZK\\hzk24k");
  	bar1(250+50+10,100+10+60,300+50,150+60,0);
  	bar1(253+50+10,103+10+60,297+50,147+60,0xffff);
  	prt_hz24_asc32(400,120+60,"教育经历(education)", 0, "HZK\\hzk24k");
  	bar1(250+50+10,100+10+120,300+50,150+120,0);
  	bar1(253+50+10,103+10+120,297+50,147+120,0xffff);
  	prt_hz24_asc32(400,120+120,"个人荣誉(honors)", 0, "HZK\\hzk24k");
  	bar1(250+50+10,100+10+180,300+50,150+180,0);
  	bar1(253+50+10,103+10+180,297+50,147+180,0xffff);
  	prt_hz24_asc32(400,120+180,"职业技能(jobskill)", 0, "HZK\\hzk24k");
  	bar1(250+50+10,100+10+240,300+50,150+240,0);
  	bar1(253+50+10,103+10+240,297+50,147+240,0xffff);
  	prt_hz24_asc32(400,120+240,"自我评价(evaluate)", 0, "HZK\\hzk24k");
  	bar1(250+50+10,100+10+300,300+50,150+300,0);
  	bar1(253+50+10,103+10+300,297+50,147+300,0xffff);
  	prt_hz24_asc32(400,120+300,"其他信息(others)", 0, "HZK\\hzk24k");
  	bar1(810,610,968,708,0x4bef);
    bar1(800,600,960,700,0xff00);
    prt_hz24d(850,640,"确认",0,"HZK\\hzk24k");
 } 
void txtlook(int p,int num,struct BASIC *basic)
{
	int choose=0;
	while(choose!=-1)
	{
		
		choose=txt_look(p,num,basic); 
		 
		switch(choose)           
		{
			
			case -2: main_page(p,num);
			        break;
			case -1:break;		 
		    case 2:
		    	txtout(p,num,basic);
		        break;    	
			default :continue;
		}
	}
}
int txt_look(int p,int num,struct BASIC *basic)
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
 
//显示文件 

void txtout(int p,int num,struct BASIC *basic)
{

	int choose=0;
	

	while(choose!=-1)
	{
		
       	choose=txt_out(p,num,basic);
	 
		switch(choose)           
		{
			
			case -2: main_page(p,num);
			        break;
			case -1:break;		 
		    
		    case 2:
		    	if(basic->mod==1)
		    	{
				
		    	model1(p,num,*basic);
		    	break;
			    }
			    else if(basic->mod==2)
		    	{
				
		    	model2(p,num,*basic);
		    	break;
			    }
			    else if(basic->mod ==-1)
			    {
			    	page4(p,num,*basic);
			    	break;
				}
			default :continue;
		}
	}
}



int txt_out (int p,int num,struct BASIC *basic)
{
	txtpage(basic);
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
		 	return 2;
		 }
}
}
void txtpage(struct BASIC *basic)
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
//在指定的区域输出英文字符串，自动换行  
int putput1(int x,int y,int xsize,int ysize,char *s,unsigned int color,int x1,int d,unsigned int bkcolor) 

{
	int i=0;
    int a=0,t=0,b,j=0,c=0;
    for(i=0;s[i]!=0;i++)
    {
    	if(s[i]==' ')
    	{
    		c=i;
		}
    	if(a==0)
    	{
    	if(x+(i-t)*xsize*8>(x1-8))
    	{	if(s[i]==' ')
		   {
			 b=strlen(s);
		    s[b+1]='\0';
    		for(j=0;j<b-i;j++)
    		{
    		
    			s[b-j]=s[b-j-1];
			}
			s[i]='\n';
		a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
        	}
        	else
        	{	if(c!=0)
	        	{
			    bar1(x+(c-t)*xsize*8,y+d*ysize*8+1,x+(i-t)*xsize*8+1,y+d*ysize*8+16,bkcolor);
        		i=c;
        	    b=strlen(s);
		        s[b+1]='\0';
    	    	for(j=0;j<b-i;j++)
    		    {
    		
    		    	s[b-j]=s[b-j-1];
		    	}
		    	s[i]='\n';
		    
				a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
	            }
	            else if(c==0)
	            {
	            	b=strlen(s);
		            s[b+1]='\0';
    	           	for(j=0;j<b-i;j++)
    		        {
    		
    		    	s[b-j]=s[b-j-1];
		        	}
		        	s[i]='\n';
		            a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
				}
			}
		}
		else
		a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
     	}
    	if (a==1)
    	{
    	d++;	
		t=i;
    	a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
        }
    }
    return d;
}


int putput2(int x,int y,int xsize,int ysize,char *s,unsigned int color,int x1,unsigned int bkcolor,int xx,int yy,int *hh,int *dd,int *tt)
{
	int d=0;
	int i=0;
    int a=0,t=0,b,j=0,c=0;
    for(i=0;s[i]!=0;i++)
    {
    	if(s[i]==' ')
    	{
    		c=i;
		}
    	if(a==0)
    	{
    	if(x+(i-t)*xsize*8>(x1-8))
    	{	if(s[i]==' ')
		   {
			 b=strlen(s);
		    s[b+1]='\0';
    		for(j=0;j<b-i;j++)
    		{
    		
    			s[b-j]=s[b-j-1];
			}
			s[i]='\n';
	    	a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
	         if((xx>=(x+(i-t)*xsize*8-4))&&
			     (xx<=(x+(i-t)*xsize*8+4))&&
				 (yy>=(y+d*ysize*8))&&
				 (yy<=(y+d*ysize*8+8)))
				 
				 {
				 	  *hh=i;
				 	  *dd=d;
				 	  *tt=t;
				 }
        	}
        	else
        	{	if(c!=0)
	        	{
			    bar1(x+(c-t)*xsize*8,y+d*ysize*8+1,x+(i-t)*xsize*8+1,y+d*ysize*8+16,bkcolor);
        		i=c;
        	    b=strlen(s);
		        s[b+1]='\0';
    	    	for(j=0;j<b-i;j++)
    		    {
    		
    		    	s[b-j]=s[b-j-1];
		    	}
		    	s[i]='\n';
		    
				a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
				if((xx>=(x+(i-t)*xsize*8-4))&&
			     (xx<=(x+(i-t)*xsize*8+4))&&
				 (yy>=(y+d*ysize*8))&&
				 (yy<=(y+d*ysize*8+8)))
				 
				 {
				 	  *hh=i;
				 	  *dd=d;
				 	  *tt=t;
				 }
	            }
	            else if(c==0)
	            {
	            	b=strlen(s);
		            s[b+1]='\0';
    	           	for(j=0;j<b-i;j++)
    		        {
    		
    		    	s[b-j]=s[b-j-1];
		        	}
		        	s[i]='\n';
		            a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
		        if((xx>=(x+(i-t)*xsize*8-4))&&
			     (xx<=(x+(i-t)*xsize*8+4))&&
				 (yy>=(y+d*ysize*8))&&
				 (yy<=(y+d*ysize*8+8)))
				 
				 {
				 	  *hh=i;
				 	  *dd=d;
				 	  *tt=t;
				 }
				}
			}
		}
		else
		a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
	        	if((xx>=(x+(i-t)*xsize*8-4))&&
			     (xx<=(x+(i-t)*xsize*8+4))&&
				 (yy>=(y+d*ysize*8))&&
				 (yy<=(y+d*ysize*8+8)))
				 
				 {
				 	  *hh=i;
				 	  *dd=d;
				 	  *tt=t;
				 }
     	}
    	if (a==1)
    	{
    	d++;	
		t=i;
    	a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
    	        if((xx>=(x+(i-t)*xsize*8-4))&&
			     (xx<=(x+(i-t)*xsize*8+4))&&
				 (yy>=(y+d*ysize*8))&&
				 (yy<=(y+d*ysize*8+8)))
				 
				 {
				 	  *hh=i;
				 	  *dd=d;
				 	  *tt=t;
				 }
        }
    }
    return d;
}


//指定矩形区域输出字符串 
int putput3(int x,int y,int xsize,int ysize,char *s,unsigned int color,int x1,int y1,unsigned int bkcolor) 

{
	int i=0,d=0;
    int a=0,t=0,b,j=0,c=0;
    for(i=0;s[i]!=0;i++)
    {
    	if(s[i]==' ')
    	{
    		c=i;
		}
    	if(a==0)
    	{
    	if(x+(i-t)*xsize*8>(x1-8))
    	{	if(s[i]==' ')
		   {
			 b=strlen(s);
		    s[b+1]='\0';
    		for(j=0;j<b-i;j++)
    		{
    		
    			s[b-j]=s[b-j-1];
			}
			s[i]='\n';
				if(y+d*ysize*8<y1-16)
	    		a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
	    		else 
	    	    break;
        	}
        	else
        	{	if(c!=0)
	        	{
			    bar1(x+(c-t)*xsize*8,y+d*ysize*8+1,x+(i-t)*xsize*8+1,y+d*ysize*8+16,bkcolor);
        		i=c;
        	    b=strlen(s);
		        s[b+1]='\0';
    	    	for(j=0;j<b-i;j++)
    		    {
    		
    		    	s[b-j]=s[b-j-1];
		    	}
		    	s[i]='\n';
		    
				if(y+d*ysize*8<y1-16)
	    		a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
	    		else 
	    	    break;
	            }
	            else if(c==0)
	            {
	            	b=strlen(s);
		            s[b+1]='\0';
    	           	for(j=0;j<b-i;j++)
    		        {
    		
    		    	s[b-j]=s[b-j-1];
		        	}
		        	s[i]='\n';
		           if(y+d*ysize*8<y1-16)
	    			a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
	    			else 
	    	    	break;
				}
			}
		}
		else
		{
				if(y+d*ysize*8<y1-16)
	    		a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
	    		else 
	    	    break;
	    }
     	}
    	if (a==1)
    	{
    	d++;	
		t=i;
    	if(y+d*ysize*8<y1-16)
	    a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
		else 
	    break;
        }
    }
    return d;
}

int putput4(int x,int y,int xsize,int ysize,char *s,unsigned int color,int x1,int y1,unsigned int bkcolor,int xx,int yy,int *hh,int *dd,int *tt)
{
	int d=0;
	int i=0;
    int a=0,t=0,b,j=0,c=0;
    for(i=0;s[i]!=0;i++)
    {
    	if(s[i]==' ')
    	{
    		c=i;
		}
    	if(a==0)
    	{
    	if(x+(i-t)*xsize*8>(x1-8))
    	{	if(s[i]==' ')
		   {
			 b=strlen(s);
		    s[b+1]='\0';
    		for(j=0;j<b-i;j++)
    		{
    		
    			s[b-j]=s[b-j-1];
			}
			s[i]='\n';
			if(y+d*ysize*8<y1-16)
	    	{
			a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
	         if((xx>=(x+(i-t)*xsize*8-4))&&
			     (xx<=(x+(i-t)*xsize*8+4))&&
				 (yy>=(y+d*ysize*8))&&
				 (yy<=(y+d*ysize*8+8)))
				 
				 {
				 	  *hh=i;
				 	  *dd=d;
				 	  *tt=t;
				 }
			}
			else 
	        break;
        	}
        	else
        	{	if(c!=0)
	        	{
			    bar1(x+(c-t)*xsize*8,y+d*ysize*8+1,x+(i-t)*xsize*8+1,y+d*ysize*8+16,bkcolor);
        		i=c;
        	    b=strlen(s);
		        s[b+1]='\0';
    	    	for(j=0;j<b-i;j++)
    		    {
    		
    		    	s[b-j]=s[b-j-1];
		    	}
		    	s[i]='\n';
		        if(y+d*ysize*8<y1-16)
		        {
				a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
				if((xx>=(x+(i-t)*xsize*8-4))&&
			     (xx<=(x+(i-t)*xsize*8+4))&&
				 (yy>=(y+d*ysize*8))&&
				 (yy<=(y+d*ysize*8+8)))
				 
				 {
				 	  *hh=i;
				 	  *dd=d;
				 	  *tt=t;
				 }
				}
			    else
			    break;
	            }
	            else if(c==0)
	            {
	            	b=strlen(s);
		            s[b+1]='\0';
    	           	for(j=0;j<b-i;j++)
    		        {
    		
    		    	s[b-j]=s[b-j-1];
		        	}
		        	s[i]='\n';
		        	if(y+d*ysize*8<y1-16)
		        	{
					
		            a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
		        	if((xx>=(x+(i-t)*xsize*8-4))&&
			    	 (xx<=(x+(i-t)*xsize*8+4))&&
					 (yy>=(y+d*ysize*8))&&
					 (yy<=(y+d*ysize*8+8)))
				 
					 {
				 	  *hh=i;
				 	  *dd=d;
				 	  *tt=t;
					 }
					}
					else 
	       			 break;
				}
			}
		}
		else
		{
		if(y+d*ysize*8<y1-16)
		
		{
		a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
    	
	        	if((xx>=(x+(i-t)*xsize*8-4))&&
			     (xx<=(x+(i-t)*xsize*8+4))&&
				 (yy>=(y+d*ysize*8))&&
				 (yy<=(y+d*ysize*8+8)))
				 
				 {
				 	  *hh=i;
				 	  *dd=d;
				 	  *tt=t;
				 }
		}
		else
		break;
     	}
     }
    	if (a==1)
    	{
    	d++;	
		t=i;
		if(y+d*ysize*8<y1-16)
		{
		
    	a=Put_Asc16_Size(x+(i-t)*xsize*8,y+d*ysize*8,xsize,ysize,s[i],color);
    	        if((xx>=(x+(i-t)*xsize*8-4))&&
			     (xx<=(x+(i-t)*xsize*8+4))&&
				 (yy>=(y+d*ysize*8))&&
				 (yy<=(y+d*ysize*8+8)))
				 
				 {
				 	  *hh=i;
				 	  *dd=d;
				 	  *tt=t;
				 }
		}
		else 
		break;
        }
    }
    return d;
}



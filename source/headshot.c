
#include"headshot.h"
void hschange(int p,int num)
{
	int choose=0;
	
	
	while(choose!=-1)   
	{
		choose=hs_change();
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

int hs_change()
{
	
	FILE *fp;
	hspage();
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
		  if(MousePress(355,253,375,273)==1)
		 {
		 	return -1;
		 } 
		 if(MousePress(25,255,175,405)==1)
		 {
		 		if((fp=fopen("C:\\toux.txt","wt+"))==NULL)
                   	{
	                 	prt_hz16_size(400,250,2,2,"错误",0,"HZK\\Hz16");
		                 delay(1000);	
                 	}
	            fputs("C:\\per1.bmp",fp);
	            fclose(fp);
	            bar1(340,190,684,510,0x7bef);
	            bar1(350,200,674,500,0xde5d);
	            prt_hz16_size(450,250,2,2,"更改成功",0x00ff,"HZK\\Hz16");
	            delay(500); 
			  return -1;	
		 }
		 if(MousePress(200,255,350,405)==1)
		 {
		 		if((fp=fopen("C:\\toux.txt","wt+"))==NULL)
                   	{
	                 	prt_hz16_size(400,250,2,2,"错误",0,"HZK\\Hz16");
		                 delay(1000);	
                 	}
	            fputs("C:\\per6.bmp",fp);
	            fclose(fp);
	             bar1(340,190,684,510,0x7bef);
	            bar1(350,200,674,500,0xde5d);
	            prt_hz16_size(450,250,2,2,"更改成功",0x00ff,"HZK\\Hz16");
	            delay(500); 
			  return -1;	
		 }
		 if(MousePress(25,420,175,570)==1)
		 {
		 		if((fp=fopen("C:\\toux.txt","wt+"))==NULL)
                   	{
	                 	prt_hz16_size(400,250,2,2,"错误",0,"HZK\\Hz16");
		                 delay(1000);	
                 	}
	            fputs("C:\\per7.bmp",fp);
	            fclose(fp);
	            bar1(340,190,684,510,0x7bef);
	            bar1(350,200,674,500,0xde5d);
	            prt_hz16_size(450,250,2,2,"更改成功",0x00ff,"HZK\\Hz16");
	            delay(500); 
			  return -1;	
		 }
		 if(MousePress(200,255,350,570)==1)
		 {
		 		if((fp=fopen("C:\\toux.txt","wt+"))==NULL)
                   	{
	                 	prt_hz16_size(400,250,2,2,"错误",0,"HZK\\Hz16");
		                 delay(1000);	
                 	}
	            fputs("C:\\per8.bmp",fp);
	            fclose(fp);
	            bar1(340,190,684,510,0x7bef);
	            bar1(350,200,674,500,0xde5d);
	            prt_hz16_size(450,250,2,2,"更改成功",0x00ff,"HZK\\Hz16");
	            delay(500); 
			  return -1;	
		 }
	}

}
void hspage()
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
	circle(400,272,10,0x000f);
	circle(400, 472-50, 10, 0x000f);
	circle(400, 622-50, 10, 0x000f);
	prt_hz16_size(450,100,3,3,"设置",0x00ff,"HZK\\Hz16");
	prt_hz24d(470,260,"修改头像",0,"HZK\\hzk24k");
    prt_hz24d(470,460-50,"修改密码",0,"HZK\\hzk24k");
    prt_hz24d(470,610-50,"退出登录",0,"HZK\\hzk24k");
  	prt_hz24d(90,5,"主页",0,"HZK\\hzk24k");
    bar1(20,253,375,600,0xffff);
    linever(355,253,355,273,1,0x7bef);
    linelevel(355,273,375,273,1,0x7bef);
    linexie(357,271,373,255,1,0xf800);
    linexie(357,255,373,271,1,0xf800);
    Putbmp64k00(25,255,"C:\\per5.bmp");
    Putbmp64k00(200,255,"C:\\per2.bmp");
    Putbmp64k00(25,420,"C:\\per3.bmp");
    Putbmp64k00(200,420,"C:\\per4.bmp");
}


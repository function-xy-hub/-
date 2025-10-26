//处理新用户注册逻辑。
#include"zhuce.h"



void zhuce_system()
{
	int choose=0;  
	while(choose!=-1)
	{
		
		choose=zhuce_user();   
		switch(choose)           
		{
			
			case 2: user_opt();
			        break;
			case -1:break;		 
		             
			default :continue;
		}
	}
}
int zhuce_user()
{

 		struct USER temp={0};
 		char judge[10]="\0";
    	char yzm[5];
	 	zhcue_page();
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
	    if(MousePress(0, 0,44,30)==1)
		{
		 	return -1;
		}
		 if(MousePress(200,205,824,250)==1)
		{
			MouseOff(&mouse);
			strcpy(temp.name,"\0");
			bar1(200,205,824,250,0xffff);
			Getinfo(200,220,temp.name,9);
			MouseOn(mouse);
		}
		if(MousePress(200,345,824,390)==1)
		{
		    MouseOff(&mouse);
			strcpy(temp.code,"\0");
			bar1(200,345,824,390,0xffff);
			Getcode(200,360,temp.code,9);
			MouseOn(mouse);
		}
		if(MousePress(200,495,824,540))     //重新输入密码
		{
			MouseOff(&mouse);
			bar1(200,495,824,540,0xffff);
			strcpy(judge,"\0");
			Getcode(200,510,judge,10);
			MouseOn(mouse);
		}
		if(MousePress(400,580,624,643))     //点击确认键
		{
			if(strcmp(temp.name,"\0")!=0)//用户名不为空 
			{
				if(strcmp(temp.code,"\0")!=0)//密码不为空 
				{
					if(!strcmp(temp.code,judge))//两次密码相同 
			        {
			           
				      save_user(temp);
			 	      delay(800);
				      bar1(406,660,598,684,0x9efc);
				      return 2;
				      break;
			        }
			        else
			        { 
					    bar1(406,660,598,684,0x9efc);
				        prt_hz24(406,660,"两次密码不相同！",0,"HZK\\Hzk24k");
				        delay(1500);
				    }  
				}
				else
				{
				    bar1(406,660,598,684,0x9efc);
					prt_hz24(406,660,"密码为空！",0,"HZK\\Hzk24k");
				    delay(1500);
				    
				}	
			}
			else
			{	
			    bar1(406,660,598,684,0x9efc);
				prt_hz24(406,660,"用户名为空！",0,"HZK\\Hzk24k");
				delay(1500);
			
			}	
		}
 	

	 }

}
void zhuce_page()
 {
 	bar1(0, 0, 1024,768,0xfffffb);
    bar1(980,0,1024,30,0x5d4f) ;
  	prt_hz16(985,5,"退出",0,"HZK\\Hz16");
  	bar1(0,0,44,30,0x5d4f) ;
  	prt_hz16(5,5,"返回",0,"HZK\\Hz16");
    prt_hz16_size(420,50,3,3,"用户注册",0xfde0,"HZK\\Hz16");
    prt_hz24d(460,150,"用户名",0,"HZK\\Hzk24k");
  	bar1(198,204,824,251,0xffff) ;
  	bar2(198,204,824,251,0,1);
  	prt_hz24d(470,290,"密码",0,"HZK\\Hzk24k");
  	bar1(198,344,824,391,0xffff) ;
  	bar2(198,344,824,391,0,1);
    prt_hz24d(450,440,"确认密码",0,"HZK\\Hzk24k");
    bar1(198,494,824,541,0xffff) ;
    bar2(198,494,824,541,0,1);
   	bar1(400,580,631,653,0x7bef);
  	bar1(400,580,624,643,0x4d58);
  	prt_hz24d(485,600,"注册",0,"HZK\\Hzk24k");
}
int save_user(USER temp)
{
	UserList UL={0};
	FILE *fp=NULL;
	ReadAllUser(&UL);
	if((fp=fopen("C:\\userinfo.dat","rb+"))==NULL)		//首次使用时应创建文件
	{
		prt_hz24(400,400,"无法打开文件！",10,"HZK\\Hzk24k");
		delay(5000);
		exit(1);
	}
	if(Check_info(UL,temp.name,temp.code)==-3)			//用户不存在 
	{
	    UListInsert(&UL,temp);
	    fseek(fp,0,SEEK_SET);
	    rewind(fp);
	    fwrite(&UL.length, sizeof(int), 1, fp);
	    fwrite(&UL.listsize, sizeof(int), 1, fp);
	    fwrite(UL.elem, sizeof(USER), UL.length, fp);
	    fclose(fp);
		prt_hz24(454,660,"注册成功！",10,"HZK\\Hzk24k");
		DestroyUList(&UL);
		delay(500);
		return 2;
	}
	else
	{
		prt_hz24(406,660,"用户名已被注册！",10,"HZK\\Hzk24k");
		DestroyUList(&UL);
		delay(500);		
		fclose(fp);
		return 3;
	}
}


#include"password.h"
#include"MOUSE.H"
#include"ulist.h"

void chcode(int p,int num)
{
	int choose=0;
	struct USER user={0};
	UserList UL={0};
	InitUList(&UL);
	ReadAllUser(&UL); 
	user=UL.elem[num];
	DestroyUList(&UL);
	
	while(choose!=-1)   
	{
	    choose=ch_code(&user);
		UpdataUser(user);
		
		switch(choose)           
		{
			
		    case -2:
 	        	main_page(p,num);
 	        	break;	  
			case -1: 
			    break; 
			case 1:
				user_opt();
				break;
			default : 
			    continue;
		}
	}
}


int ch_code(USER *user)
{
	int flag=0;
	char old_code[11]="\0";
	char new_code[11]="\0";
	char jud_code[11]="\0";
	codepage();
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
		 if(MousePress(200,205,824,250))
		{
			MouseOff(&mouse);
			Getcode(204,209,old_code,10);
			MouseOn(mouse);
		}
		 if(MousePress(200,345,824,390))
		{
			MouseOff(&mouse);
			Getcode(204,349,new_code,10);
			MouseOn(mouse);
		}
	     if(MousePress(200,495,824,540))
		{
			MouseOff(&mouse);
			Getcode(204,499,jud_code,10);
			MouseOn(mouse);
		}
		 if(MousePress(400,580,624,643))
		{
			if(strcmp(new_code,"\0")!=0)//新密码不为空
			{
				if(strcmp(old_code,user->code)==0)
				{
					if(strcmp(old_code,new_code)==0)
					{
					prt_hz24(550,660,"新密码不得与原密码相同！",0,"HZK\\Hzk24k");
					delay(1500);
					bar1(550,660,600,684,0xffff);
					}
					else
					{
					   if(strcmp(jud_code,new_code)!=0)
					   {
						   prt_hz24(550,660,"两次新密码不相同！",0,"HZK\\Hzk24k");
						   delay(1500);
						   bar1(550,660,700,684,0xffff);
					   }
					   else
					   {
						   strcpy(user->code,new_code);
						   bar1(300,660,724,684,0xffff);
						   prt_hz24(370,662,"修改成功！请重新登录",0,"HZK\\Hzk24k");
						   delay(1000);
				           return 1;
					   }

					}
				}
				else
				{
					prt_hz24(550,660,"原密码错误！",0,"HZK\\Hzk24k");
					delay(1500);
					bar1(550,660,700,684,0xffff);
				}
			}
			else
			{
				MouseOff(&mouse);
				prt_hz24(550,660,"新密码为空！",0,"HZK\\Hzk24k");
				delay(1500);
				bar1(550,660,700,684,0xffff);
				
			}
		}
	}
}


void codepage()
{
	bar1(0, 0, 1024,768,0xfffffb);
    bar1(980,0,1024,30,0XFED7) ;
  	prt_hz16(985,5,"退出",0,"HZK\\Hz16");
  	bar1(0,0,44,30,0x5d4f) ;
  	prt_hz16(5,5,"返回",0,"HZK\\Hz16");
    prt_hz16_size(420,50,3,3,"修改密码",0xfde0,"HZK\\Hz16");
    prt_hz24d(460,150,"原密码",0,"HZK\\Hzk24k");
  	bar1(200,205,824,250,0xffff) ;
  	bar2(200,205,824,250,0,1);
  	prt_hz24d(470,290,"新密码",0,"HZK\\Hzk24k");
  	bar1(200,345,824,390,0xffff) ;
  	bar2(200,345,824,390,0,1);
    prt_hz24d(450,440,"确认密码",0,"HZK\\Hzk24k");
    bar1(200,495,824,540,0xffff) ;
    bar2(200,495,824,540,0,1);
   	bar1(400,580,631,653,0x7bef);
  	bar1(400,580,624,643,0xde5d);
  	prt_hz24d(485,600,"确认",0,"HZK\\Hzk24k");
}

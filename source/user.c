//处理用户登录逻辑，包括用户验证和登录界面展示。
#include"user.h"
void user_opt()
{
	int choose=0;  
	int username=0;
	int usernum=0;
	while(choose!=-1)
	{
		
		choose=manage_user(&username,&usernum);   
		switch(choose)           
		{
			
			case 2: main_page(username,usernum);
			        break;
			case -1:break;		 
		             
			default :continue;
		}
	}
}
int manage_user(int *p,int *usernum)
{

   
    int i;
    int j;
	char name[10]="\0";
	char code[10]="\0";
	UserList UL={0};
	InitUList(&UL);
	ReadAllUser(&UL);
	user_page();
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
		 if(MousePress(200,205,824,250)==1)
		{
			MouseOff(&mouse);
			strcpy(name,"\0");
			bar1(200,205,824,250,0xffff);
			Getinfo(200,220,name,9);
			MouseOn(mouse);
			*p=atoi(name);
		}
		if(MousePress(200,345,824,390)==1)
		{
			
		    MouseOff(&mouse);
			strcpy(code,"\0");
			bar1(200,345,824,390,0xffff);
			Getcode(200,360,code,9);
			MouseOn(mouse);
		}
		if(MousePress(400,500,624,565)==1)
		{
			i=Check_info(UL,name,code);//登录信息验证对比查找 
			if(i>=0)
			{
		        *usernum=i; 
				DestroyUList(&UL);
				return 2;
			}
			if(i==-2)//密码输入错误 
			{
				prt_hz24(420,634,"密码错误！",0,"HZK\\Hzk24k");
			    delay(1500);
				bar1(420,634,540,658,0xfffffb);
			}
			if(i==-3)//用户不存在 
			{
				prt_hz24(408,634,"用户不存在！",0,"HZK\\Hzk24k");
			    delay(1500);
				bar1(408,634,552,658,0xfffffb);
			} 
			
		}
 

	 }
	 
}

void user_page()
 {
 
   
    bar1(0, 0, 1024,768,0xfffffb);
  	prt_hz16_size(420,50,3,3,"用户登录",0xfde0,"HZK\\Hz16");
  	bar1(980,0,1024,30,0x5d4f) ;
  	prt_hz16(985,5,"退出",0,"HZK\\Hz16");
  	bar1(0,0,44,30,0x5d4f) ;
  	prt_hz16(5,5,"返回",0,"HZK\\Hz16");
  	prt_hz24d(460,150,"用户名",0,"HZK\\Hzk24k");
  	bar1(198,205,824,250,0xffff) ;
  	bar2(198,204,824,251,0,1);
  	prt_hz24d(470,290,"密码",0,"HZK\\Hzk24k");
  	bar1(198,345,824,390,0xffff) ;
  	bar2(198,344,824,391,0,1);
  	bar1(400,500,631,573,0x7bef);
  	bar1(400,500,624,565,0x4d58);
  	prt_hz24d(485,520,"登录",0,"HZK\\Hzk24k");

}
int Check_info(UserList UL,char name[10],char code[10])
{
	int i=0;
	for(i=0;i<10;i++)
	{
		if(strcmp(UL.elem[i].name,name)==0)
		{
			if(strcmp(UL.elem[i].code,code)==0)
			{
				return i;
			}
			else
			{
				return -2;
			}
		}
	}
	  return -3;	
}
void UpdataUser(USER user)
{
	int usernum=0;
	UserList UL={0}; 
	FILE *fp=NULL;
	ReadAllUser(&UL);
	if((fp=fopen("c:\\userinfo.dat","rb+"))==NULL)
	{
		prt_hz24(400,400,"无法打开文件！",10,"HZK\\Hzk24k");
		delay(5000);
		exit(1);
	}
	usernum=Userposition(UL,user);
	UL.elem[usernum]=user; 
	fseek(fp,0,SEEK_SET);
	fwrite(&UL.length, sizeof(int), 1, fp);
	fwrite(&UL.listsize, sizeof(int), 1, fp);
	fwrite(UL.elem, sizeof(USER), UL.length, fp);
	fclose(fp);
	DestroyUList(&UL);
}
void ReadAllUser(UserList *UL)
{
	int length=0; 
	int listsize=U_LIST_INIT_SIZE;
	FILE *fp=NULL;
	if((fp=fopen("C:\\userinfo.dat","rb+"))==NULL)			
	{
		fp=fopen("C:\\userinfo.dat","wb");
		rewind(fp);
		fwrite(&length, sizeof(int), 1, fp);
		fwrite(&listsize, sizeof(int), 1, fp);
	}								
    else
    {
       fseek(fp,0,SEEK_SET);
	   fread(&length, sizeof(int), 1, fp);
	   fread(&listsize, sizeof(int), 1, fp);
	   UL->length = length;
	   UL->listsize = listsize;
	   if((UL->elem = (USER*)malloc(listsize* sizeof(USER)))==NULL)
	   {
		 CloseSVGA();
		 printf("No enough memory!\n");
		 getch();
		 exit(-1);
	   } 
	  fread(UL->elem, sizeof(USER),length, fp);
    }
	fclose(fp);
}


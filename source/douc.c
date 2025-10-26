//提供文件操作相关函数，如读取、保存文件等。
#include"douc.h"



int Document(int flag,BmpFile(*bmpfile)[20])
{
	int number=0;
	struct ffblk dir;

	bar1(0,0,1024,768,0xffff);
	bar1(980,0,1024,30,0x5d4f);
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
	prt_hz16_asc16_size(100,110,1,1,"文件名称",0x0000,"HZK\\hz16");    
	prt_hz16_asc16_size(300,110,1,1,"修改日期",0x0000,"HZK\\hz16");
	prt_hz16_asc16_size(500,110,1,1,"修改时间",0x0000,"HZK\\hz16");
	prt_hz16_asc16_size(900,110,1,1,"文件类型",0x0000,"HZK\\hz16");
	linelevel(80,150,1000,150,1,0);
	FindAllFile(&number,flag,bmpfile);
	FileListShow(flag,number,*bmpfile);
	return number;
}




int FileListShow(int flag,int number,BmpFile bmpfile[20])
{
	int i,j;
	int k;
	int n;
	char simplename[20];
	char type[20];
	char data[10];
	char time[10];
	char size[5];
	struct ffblk dir;
	for (i=1; i <= number; i++)
	{
				strcpy(simplename,bmpfile[i].name);
				k=strlen(bmpfile[i].name)-4;
				simplename[k]='\0';
				strcpy(type,bmpfile[i].name+k+1);
	            sprintf(data, "%d.%d.%d",bmpfile[i].year, bmpfile[i].month, bmpfile[i].day);
	            sprintf(time, "%d:%d:%d",bmpfile[i].hour, bmpfile[i].min, bmpfile[1].second);
	            sprintf(size, "%dKB",bmpfile[i].size);
        	    prt_hz16_asc16_size(100,130+25*i,1,1,simplename,0x0000,"HZK\\hz16");    
				prt_hz16_asc16_size(300,130+25*i,1,1,data,0x0000,"HZK\\hz16");
				prt_hz16_asc16_size(500,130+25*i,1,1,time,0x0000,"HZK\\hz16");
	           	prt_hz16_asc16_size(900,130+25*i,1,1,type,0x0000,"HZK\\hz16");
	           	linelevel(80,130+25*i+20,1000,130+25*i+20,1,0);
	}
	linever(80,150,80,130+25*number+20,1,0);
    linever(1000,150,1000,130+25*number+20,1,0);
	return 0;
}
void FindAllFile(int* number,int flag,BmpFile(*pbmpfile)[20])
{
	int i = 0;
	struct ffblk dir;
	int year, month, day;
	int hour, min, second;
	int size;
	if ((flag==1)?(!findfirst("C:\\BMP/*.bmp", &dir, 0)):(!findfirst("C:\\info/*.txt", &dir, 0)))//找到返回值为0
	{
		i = 1;//第一个就是数组里的第一个 
		strcpy(((*pbmpfile+i)->name),dir.ff_name);//把dir.ff_name给数组里元素 
	  year = ((dir.ff_fdate & 0xFE00) >> 9) + 1980;	//注意优先级
		month = (dir.ff_fdate & 0x1E0) >> 5;
		day = dir.ff_fdate & 0x1F;
		hour = (dir.ff_ftime & 0xF800) >> 11;
		min = (dir.ff_ftime & 0x7E0) >> 5;
		second = (dir.ff_ftime & 0x1F) * 2;
		size = dir.ff_fsize >> 10;
		(*pbmpfile+i)->year=year;
		(*pbmpfile+i)->month=month;
		(*pbmpfile+i)->day=day;
		(*pbmpfile+i)->hour=hour;
		(*pbmpfile+i)->min=min;
		(*pbmpfile+i)->second=second;
		(*pbmpfile+i)->size=size;
		(*pbmpfile+i)->time=year*10000000000+month*100000000+day*1000000+hour*10000+min*100+second;
		while (!findnext(&dir))	//找到的话则返回值为0
		{
			i++;
			strcpy(((*pbmpfile+i)->name),dir.ff_name);
			year = ((dir.ff_fdate & 0xFE00) >> 9) + 1980;	//注意优先级
			month = (dir.ff_fdate & 0x1E0) >> 5;
			day = dir.ff_fdate & 0x1F;
			hour = (dir.ff_ftime & 0xF800) >> 11;
			min = (dir.ff_ftime & 0x7E0) >> 5;
			second = (dir.ff_ftime & 0x1F) * 2;
			size = dir.ff_fsize >> 10;
			(*pbmpfile+i)->year=year;
			(*pbmpfile+i)->month=month;
			(*pbmpfile+i)->day=day;
			(*pbmpfile+i)->hour=hour;
			(*pbmpfile+i)->min=min;
			(*pbmpfile+i)->second=second;
			(*pbmpfile+i)->size=size;
			(*pbmpfile+i)->time=year*10000000000+month*100000000+day*1000000+hour*10000+min*100+second;
		}
	}
	*number = i;//总个数 
}

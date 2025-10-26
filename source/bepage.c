//page1 绘制主页面（起始页面）
#include <stdio.h>
#include<math.h>
#include"hz.h"
#include"mouse.h"
#include"login.h"
#include"SVGAmode.h"
#include"bepage.h"



  
/*************************画竖直波浪线******************/
void waveY(int x0,int y0,int y1,int color)
{
	int amp = 4;  // 波浪的振幅
	int wavelength = 15;  // 波浪的波长
	double f = 0.5;  // 波浪的频率
	int xPos;
	int  y;
	double x;
	int maxX = 1024;
	int maxY = 768;

	for ( y = y0; y <y1 ; y++) 
	{
		// 在 y 轴上循环
		 x =amp * sin((2 * 3.1415926 * f) * (y / (double)wavelength));  // 计算 x 坐标
		 xPos = (int)x + x0;  // 将浮点数转换为整数，并进行水平偏移

		// 在 (xPos, y) 位置画点
		Putpixel64k(xPos, y, color);
	}


}
/*************************画竖直波浪线粗******************/
void WaveY(int x0, int y0, int y1,int n, int color)
{
    
	int i;
	for (i = 0; i++; i < n)
	{
		waveY( x0,  y0,  y1,  color);
	}
}


/*************************画水平波浪线******************/
void waveX(int x0, int y0, int x1, int color)
{
	int amp = 4;  // 波浪的振幅
	int wavelength = 15;  // 波浪的波长
	double f = 0.5;  // 波浪的频率
	int yPos;
	int  x;
	double y;
	int maxX = 1024;
	int maxY = 768;

	for (x = x0; x<x1; x++)
	{
		// 在 x 轴上循环
		y = amp * sin((2 * 3.1415926 * f) * (x / (double)wavelength));  // 计算 y 坐标
		yPos = (int)y + y0;  // 将浮点数转换为整数，并进行水平偏移

		// 在 (x,yPos) 位置画点
		Putpixel64k(x,yPos, color);
	}


}
/*************************画水平波浪线粗******************/
void WaveX(int x0, int y0, int x1,int n, int color)
{
	int i;
	for (i = 0; i++; i < n)
	{
		waveX(x0, y0 + n, x1,  color);
	}
}

/***********************直角梯形*******************
下边偏右***********/

void ladder(int x1,int y1,int length,int height,int color)
{
	int i,j;
	int x0;
	int y0;
	x0=x1;
	y0=y1;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < length; j++)
		{
			Putpixel64k(x0 + j, y0 + i, color);
		}
		length++;
	}
}

/***********************等腰梯形*******************
***********/

void isosceles_trapezoid(int x1, int y1, int length, int height, int color)
{
	ladder( x1,  y1,  length,  height,  color);
	ladder1( x1,  y1,  length,  height,  color);
}

/*************************直角梯形******************上帝大于下地
*****************/
void ladder1(int x1, int y1, int length, int height, int color)
{
	int i, j;
	int x0;
	int y0;
	x0 = x1;
	y0 = y1;

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < length; j++)
		{
			Putpixel64k(x0 + j, y0 + i, color);
		}
		length--;
	}
}


/***********************平行四边形***************
下边偏左***********/
void parall1(int x1, int y1, int length, int height, int color)
{
	int i, j;
	int x0;
	int y0;
	x0 = x1;
	y0 = y1;
	for
		(j = 0; j < height; j++)
	{

		for
			(i = 0; i < length; i++)
		{
			Putpixel64k(x0, y0, color);
			x0++;
		}
		x0 = x1+height - 1;
		(x1--)+height;
		y0++;
	}
	
}
/***********************平行四边形***************
下边偏右***********/
void parall(int x1, int y1, int length, int height, int color)
{
	
	int i, j;
	int x0;
	int y0;
	x0 = x1;
	y0 = y1;
	
	for
		(j = 0; j < height; j++)
	{

		for
			(i = 0; i < length; i++)
		{
			Putpixel64k(x0, y0, color);
			x0++;
		}
		x0 = x1 + 1;
		x1++;
		y0++;
	}
}

 
/*****************设置背景颜色*******************/
void bkcolor(int color)
{
	int x,y;
	//设置背景
	for
	(x=0;x<=1024;x++)
	{
		for
		(y = 0; y <= 2024; y++)
		{
			Putpixel64k(x, y, color);
		}
	}
}



int beginpage()
{
	
	//设置背景和框架
	bkcolor(0x7BEF);//暗灰
	
	//退出
	bar1(974, 0, 1024, 30, 0x5D4F);//绿色
	prt_hz24d(974, 0, "退出", 0x0000, "HZK\\Hzk24k");//黑色
	//返回上一页
	bar1(0, 0, 50, 30, 0x5D4F);//绿色
	prt_hz24d(0, 0, "返回", 0x0000, "HZK\\Hzk24k");//黑色

	//设置简历页面
	bar1(256 - 15, 0, 758 + 15, 768, 0xFFFF);//白色
	prt_hz16_size(420, 17, 2.5, 2.5, "个人简历", 0x801F, "HZK\\Hz16");
	//prt_hz24d(470,20,"个人简历",0x801F,"HZK\\Hzk24k");//紫色
	linelevel(256, 60, 768, 60, 3, 0x07FF);//浅蓝
	/*********左边*******/
   //	waveY(250+10, 72, 200, 0x801F);
   //	waveY(254+10, 72, 200, 0x801F);
   //	waveY(255+10, 72, 200, 0x801F);
   //	waveY(256+10, 72, 200, 0x810F);

	/*************右边***********/
   //	waveY(386-10,72,200,0x801F);
   //	waveY(387-10,72,200,0x801F);
   //	waveY(388-10,72,200,0x801F);
   //	waveY(392-10,72,200,0x810F);


	/**************个人信息**********/
	Ellipsefill(320, 240, 60, 25, 3, 0xF81F);
	prt_hz24d(275, 230, "个人信息", 0x801F, "HZK\\Hzk24k");//紫色
	prt_hz24d(240, 250+20, "姓名：", 0x801F, "HZK\\Hzk24k");//紫色
	prt_hz24d(240, 280+20, "性别：", 0x801F, "HZK\\Hzk24k");//紫色
	prt_hz24d(240, 310+20, "年龄：", 0x801F, "HZK\\Hzk24k");//紫色
	prt_hz24d(240, 340+20, "城市：", 0x801F, "HZK\\Hzk24k");//紫色
	prt_hz24d(240, 370+20, "电话：", 0x801F, "HZK\\Hzk24k");//紫色
	prt_hz24d(240, 400+20, "邮箱：", 0x801F, "HZK\\Hzk24k");//紫色
	prt_hz24d(240, 430+20, "政治面貌：", 0x801F, "HZK\\Hzk24k");//紫色
	prt_hz24d(240, 460+20, "婚姻状况：", 0x801F, "HZK\\Hzk24k");//紫色
	bar1(266, 72, 376, 200, 0xC618);
	linever(385, 60, 300, 750, 3, 0x001F);

	//教育背景
	bar1(280 + 120, 70, 360 + 120, 105, 0xF81F);
	parall(420, 70, 70, 36, 0xF81F);
	prt_hz24d(405, 80, "教育背景", 0x801F, "HZK\\Hzk24k");//紫色
	linelevel(400, 106, 768, 106, 2, 0x07FF);
	bar1(400, 106, 768, 230, 0xC618);
	waveX(490, 96, 768, 0xF81F);//洋红色
	waveX(490, 100, 768, 0xF81F);
	waveX(490, 101, 768, 0xF81F);
	waveX(490, 102, 768, 0xF81F);

	//工作经历
	bar1(280 + 120, 70 + 170, 360 + 120, 105 + 170, 0xF81F);
	parall(420, 70 + 170, 70, 36, 0xF81F);
	prt_hz24d(405, 80 + 170, "工作经历", 0x801F, "HZK\\Hzk24k");//紫色
	//	linelevel(280,95,280,750,2,0x07FF);
	bar1(400, 106 + 170, 768, 230 + 170, 0xC618);
	waveX(490, 96 + 170, 768, 0xF81F);//洋红色
	waveX(490, 100 + 170, 768, 0xF81F);
	waveX(490, 101 + 170, 768, 0xF81F);
	waveX(490, 102 + 170, 768, 0xF81F);

	//个人荣誉
	bar1(280 + 120, 70 + 340, 360 + 120, 105 + 340, 0xF81F);
	parall(420, 70 + 340, 70, 36, 0xF81F);
	prt_hz24d(405, 80 + 340, "个人荣誉", 0x801F, "HZK\\Hzk24k");//紫色
	linelevel(280, 95, 280, 750, 3, 0x07FF);
	bar1(400, 106 + 340, 768, 230 + 340, 0xC618);
	waveX(490, 96 + 340, 768, 0xF81F);//洋红色
	waveX(490, 100 + 340, 768, 0xF81F);
	waveX(490, 101 + 340, 768, 0xF81F);
	waveX(490, 102 + 340, 768, 0xF81F);


	//自我评价
	bar1(280 + 120, 70 + 510, 360 + 120, 105 + 510, 0xF81F);
	parall(420, 70 + 510, 70, 36, 0xF81F);
	prt_hz24d(405, 80 + 510, "自我评价", 0x801F, "HZK\\Hzk24k");//紫色
	linelevel(280, 95, 280, 750, 2, 0x07FF);
	bar1(400, 106 + 510, 768, 280 + 470, 0xC618);
	waveX(490, 96 + 510, 768, 0xF81F);//洋红色
	waveX(490, 100 + 510, 768, 0xF81F);
	waveX(490, 101 + 510, 768, 0xF81F);
	waveX(490, 102 + 510, 768, 0xF81F);
	delay(10000);
	save_image(211, 0, 773, 768,"pageme");

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
			return 0;
		}
	}

}

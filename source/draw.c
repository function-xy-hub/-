
#include"draw.h"
void draw_(int p,int num)
{
	int choose = 0;
	while (choose != -1)
	{

		choose = draw();

		switch (choose)
		{

		case -2: 
		   main_page(p,num);
			break;
		case -1:
		    break;

		default:continue;
		}
	}
}

/**********选择标题的框****************/
void se_title()
{
	int i;
	int m;
	int mousey;
	bar1(830, 100, 985, 500,0xC618);
	prt_hz24d(830, 110, "请选择小标题：", 0, "HZK\\Hzk24k");
	Line_Thick(833, 140, 982, 140, 1, 0);
	prt_hz24d(850, 145, "求职意向", 0, "HZK\\Hzk24k");
	prt_asc16(852, 170, "objective", 0);
	Line_Thick(833, 190, 982, 190, 1, 0);
	prt_hz24d(850, 195, "教育经历", 0, "HZK\\Hzk24k");
	prt_asc16(852, 220, "education", 0);
	Line_Thick(833, 240, 982, 240, 1, 0);
	prt_hz24d(850, 245, "个人荣誉", 0, "HZK\\Hzk24k");
	prt_asc16(857, 270, "honors", 0);
	Line_Thick(833, 290, 982, 290, 1, 0);
	prt_hz24d(850, 295, "职业技能", 0, "HZK\\Hzk24k");
	prt_asc16(852, 320, "jobskill", 0);
	Line_Thick(833, 340, 982, 340, 1, 0);
	prt_hz24d(850, 345, "自我评价", 0, "HZK\\Hzk24k");
	prt_asc16(854, 370, "evaluate", 0);
	Line_Thick(833, 390, 982, 390, 1, 0);
	prt_hz24d(850, 395, "其他信息", 0, "HZK\\Hzk24k");
	prt_asc16(857, 420, "others", 0);
	Line_Thick(833, 440, 982,440, 1, 0);
	prt_hz24d(850, 445, "基本信息", 0, "HZK\\Hzk24k");
	prt_asc16(857,470, "basic", 0);
}

/***********************确认当前编辑**************
*********/
void confirm(int *select, graphitem* ap)
{
	
	Ellipsefill(855, 670, 92, 30, 3, 0x7BEF);//浅蓝色
	prt_hz16_size(800, 660, 1, 1, "是否完成对当前", 0x801F, "HZK\\Hz16");//白色
	prt_hz16_size(800, 680, 1, 1, "图形的编辑", 0x801F, "HZK\\Hz16");//白色
	bar1(750+20, 730, 800+20, 760, 0xFC00);
	prt_hz24d(770, 730, "确认", 0x801F, "HZK\\Hzk24k");//紫色
	bar1(750+120, 730, 800+120, 760, 0xFC00);
	prt_hz24d(870, 730, "取消", 0x801F, "HZK\\Hzk24k");//紫色

}
/*************************画上篮显示框over********************
**************/
void shanglan()
{
	Line_Thick(562, 30, 970, 30, 1, 0x0000);
	//调整大小
	bar1(650, 0, 730, 30, 0xFC00);//白色
	prt_hz16_size(663, 5, 1, 1, "调整大小", 0, "HZK\\Hz16");
	Line_Thick(730, 0, 730, 30, 1, 0x0000);

	//删除
	bar1(730, 0, 810, 30, 0xFC00);//白色
	prt_hz16_size(743, 5, 1, 1, "颜色选择", 0, "HZK\\Hz16");
	Line_Thick(810, 0, 810, 30, 1, 0x0000);

	//精美图标
	bar1(810, 0, 890, 30, 0xFC00);//白色
	prt_hz16_size(823, 5, 1, 1, "图形元件", 0, "HZK\\Hz16");
	Line_Thick(890, 0, 890, 30, 1, 0x0000);

	//操作说明
	bar1(890, 0, 970, 30, 0xFC00);//白色
	prt_hz16_size(903, 5, 1, 1, "操作说明", 0, "HZK\\Hz16");
	Line_Thick(970, 0, 970, 30, 1, 0x0000);

}
/*****************************颜色表格over*********************
***************************/
void colorform()
{
	int i;
	if (MousePress(730, 0, 810, 30) == 1)
	{
		if (Getpixel64k(862, 84) == 0x7F50)
		{
			bar1(800, 70, 1024, 600, 0x7F50);
			for (i = 0; i < 18; i++)
			{
				bar1(861, 83 + 30 * i, 955, 113 + 30 * i, 0xC618);//灰色
				Line_Thick(861, 113 + 30 * i, 955, 113 + 30 * i, 1, 0x0000);//黑色
			}
			prt_hz16_size(861, 88 + 30 * 0, 1.5, 1.5, "白色", 0x801F, "HZK\\Hz16");//0
			prt_hz16_size(861, 88 + 30 * 1, 1.5, 1.5, "黑色", 0x801F, "HZK\\Hz16");//1
			prt_hz16_size(861, 88 + 30 * 2, 1.5, 1.5, "红色", 0x801F, "HZK\\Hz16");//2
			prt_hz16_size(861, 88 + 30 * 3, 1.5, 1.5, "绿色", 0x801F, "HZK\\Hz16");//3
			prt_hz16_size(861, 88 + 30 * 4, 1.5, 1.5, "蓝色", 0x801F, "HZK\\Hz16");//4
			prt_hz16_size(861, 88 + 30 * 5, 1.5, 1.5, "青色", 0x801F, "HZK\\Hz16");//5
			prt_hz16_size(861, 88 + 30 * 6, 1.5, 1.5, "洋红色", 0x801F, "HZK\\Hz16");//6
			prt_hz16_size(861, 88 + 30 * 7, 1.5, 1.5, "黄色", 0x801F, "HZK\\Hz16");//7
			prt_hz16_size(861, 88 + 30 * 8, 1.5, 1.5, "紫色", 0x801F, "HZK\\Hz16");//8
			prt_hz16_size(861, 88 + 30 * 9, 1.5, 1.5, "粉色", 0x801F, "HZK\\Hz16");//9
			prt_hz16_size(861, 88 + 30 * 10, 1.5, 1.5, "橙色", 0x801F, "HZK\\Hz16");//10
			prt_hz16_size(861, 88 + 30 * 11, 1.5, 1.5, "深灰色", 0x801F, "HZK\\Hz16");//11
			prt_hz16_size(861, 88 + 30 * 12, 1.5, 1.5, "深蓝色", 0x801F, "HZK\\Hz16");//12
			prt_hz16_size(861, 88 + 30 * 13, 1.5, 1.5, "浅蓝色", 0x801F, "HZK\\Hz16");//13
			prt_hz16_size(861, 88 + 30 * 14, 1.5, 1.5, "棕色", 0x801F, "HZK\\Hz16");//14
			prt_hz16_size(861, 88 + 30 * 15, 1.5, 1.5, "青绿色", 0x801F, "HZK\\Hz16");//15
			prt_hz16_size(861, 88 + 30 * 16, 1.5, 1.5, "海军蓝", 0x801F, "HZK\\Hz16");//16
			prt_hz16_size(861, 88 + 30 * 17, 1.5, 1.5, "浅灰色", 0x801F, "HZK\\Hz16");//17



			FillCircle(928, 98 + 30 * 0, 9, 0xFFFF);//白色0
			FillCircle(928, 98 + 30 * 1, 9, 0x0000); //黑色1
			FillCircle(928, 98 + 30 * 2, 9, 0xF800); //红色  2           
			FillCircle(928, 98 + 30 * 3, 9, 0x07E0);//绿色3
			FillCircle(928, 98 + 30 * 4, 9, 0x001F);//蓝色4
			FillCircle(928, 98 + 30 * 5, 9, 0x07FF);//青色5
			FillCircle(928, 98 + 30 * 6, 9, 0xF81F);//洋红色，粉色，紫红色6
			FillCircle(928, 98 + 30 * 7, 9, 0xFFE0);//黄色7
			FillCircle(928, 98 + 30 * 8, 9, 0x801F);//紫色8
			FillCircle(928, 98 + 30 * 9, 9, 0x801F);//粉色9
			FillCircle(928, 98 + 30 * 10, 9, 0xFC00);//橙色10
			FillCircle(928, 98 + 30 * 11, 9, 0x7BEF);//深灰色11
			FillCircle(928, 98 + 30 * 12, 9, 0x000F);//深蓝色12
			FillCircle(928, 98 + 30 * 13, 9, 0x03FF);//浅蓝色13
			FillCircle(928, 98 + 30 * 14, 9, 0x8200);//棕色14
			FillCircle(928, 98 + 30 * 15, 9, 0x07FF);//青绿色15
			FillCircle(928, 98 + 30 * 16, 9, 0x000F);//海军蓝16
			FillCircle(928, 98 + 30 * 17, 9, 0xC618);//浅灰色17
			circle(928, 98 + 30 * 17, 9, 0x0000);
		}

		else
		{
			bar1(861 - 10, 83 - 10, 955 + 10, 113 + 30 * 17 + 10, 0x7F50);
		}
		delay(300);

	}
}
/***************************判断所选颜色并返回颜色over************************
****************************/
int Setcolorm()
{
	int m;
	colorform();
	for (m = 0; m < 18; m++)
	{
		if (MousePress(861, 83 + 30 * m, 955, 113 + 30 * m) == 1)
		{
			break;
		}
	}
	return m;
}
void setcolor1(int m, graphitem* graph0, int* itemx)
{

	if (Getpixel64k(862, 84) != 0x7F50 && MousePress(861, 83 + 30 * m, 955, 113 + 30 * m) == 1)
	{


		//判断颜色
		switch (m)
		{
		case 0:
			graph0[*itemx].color = 0xFFFF;
			break;
		case 1:
			graph0[*itemx].color = 0x0000;
			break;
		case 2:
			graph0[*itemx].color = 0xF800;
			break;
		case 3:
			graph0[*itemx].color = 0x07E0;
			break;
		case 4:
			graph0[*itemx].color = 0x001F;
			break;
		case 5:
			graph0[*itemx].color = 0x07FF;
			break;
		case 6:
			graph0[*itemx].color = 0xF81F;
			break;
		case 7:
			graph0[*itemx].color = 0xFFE0;
			break;
		case 8:
			graph0[*itemx].color = 0x801F;
			break;
		case 9:
			graph0[*itemx].color = 0x801F;
			break;
		case 10:
			graph0[*itemx].color = 0xFC00;
			break;
		case 11:
			graph0[*itemx].color = 0x7BEF;
			break;
		case 12:
			graph0[*itemx].color = 0x000F;
			break;
		case 13:
			graph0[*itemx].color = 0x03FF;
			break;
		case 14:
			graph0[*itemx].color = 0x8200;
			break;
		case 15:
			graph0[*itemx].color = 0x07FF;
			break;
		case 16:
			graph0[*itemx].color = 0x000F;
			break;
		case 17:
			graph0[*itemx].color = 0xC618;
			break;
		}
		
	}
}
/********调整大小的框over******************/
void resize_bar()
{
	bar1(861, 100, 911, 150, 0xF81F);//左1
	bar1(911, 100, 961, 150, 0x801F);//右1
	bar1(861, 150, 911, 200, 0x801F);//左2
	bar1(911, 150, 961, 200, 0xF81F);//右2
	bar1(861, 200, 911, 250, 0xF81F);//左3
	bar1(911, 200, 961, 250, 0x801F);//右3
	prt_hz16_size(861 + 5, 100 + 5, 1, 1, "放大", 0, "HZK\\Hz16");
	prt_hz16_size(861 + 5, 125 + 5, 1, 1, "宽度", 0, "HZK\\Hz16");
	prt_hz16_size(861 + 5, 150 + 5, 1, 1, "放大", 0, "HZK\\Hz16");
	prt_hz16_size(861 + 5, 175 + 5, 1, 1, "高度", 0, "HZK\\Hz16");
	prt_hz16_size(861 + 5, 200 + 5, 1, 1, "同时", 0, "HZK\\Hz16");
	prt_hz16_size(861 + 5, 225 + 5, 1, 1, "放大", 0, "HZK\\Hz16");
	
	prt_hz16_size(911 + 5, 100 + 5, 1, 1, "缩小", 0, "HZK\\Hz16");
	prt_hz16_size(911 + 5, 125 + 5, 1, 1, "宽度",0, "HZK\\Hz16");
	prt_hz16_size(911 + 5, 150 + 5, 1, 1, "缩小", 0, "HZK\\Hz16");
	prt_hz16_size(911 + 5, 175 + 5, 1, 1, "高度", 0, "HZK\\Hz16");
	prt_hz16_size(911 + 5, 200 + 5, 1, 1, "同时", 0, "HZK\\Hz16");
	prt_hz16_size(911 + 5, 225 + 5, 1, 1, "缩小", 0, "HZK\\Hz16");
	
}
/*******************调整大小的显示over*************
****/
void resize(graphitem*graph0,int*item)
{
	if (MousePress(650, 0, 730, 30) == 1)
	{

		bar1(800, 70, 1024, 630, 0x7F50);
		if (Getpixel64k(862, 101) == 0x7F50)
		{
			if (graph0[*item].shape != 1)
			{
				bar1(800, 70, 1024, 600, 0x7F50);
				resize_bar();
			}
			else
			{
				bar1(800, 70, 1024, 630, 0x7F50);
				bar1(861, 100, 960, 150, 0xFC00);
				bar1(861, 150, 960, 200, 0xFC00);
				Line_Thick(861, 150, 960, 150, 1, 0);
				prt_hz24d(861+5, 100+5, "放大我！", 0x0000, "HZK\\Hzk24k");//黑色
				prt_hz24d(861+5, 150+5, "缩小我！", 0x0000, "HZK\\Hzk24k");//黑色
			}
		}
		else
		{
			bar1(861, 100, 961, 250, 0x7F50);
		}
		delay(300);
	}
}

/*****************************对照片进行操控**************
*************************/
void photo_control(graphitem* graph0, int* select, int* presstime, int* itemx)
{

	int i, j;
	int m;
	if (MouseIn(0, 0, 562, 768) == 1)
	{
		if ((MousePress(0, 0, 562, 768) == 1) && (*presstime == 1))
		{

			graph0[*itemx].x0 = MouseX(&mouse);
			graph0[*itemx].y0 = MouseY(&mouse);
			graph0[*itemx].x1 = MouseX(&mouse) + 80;
			graph0[*itemx].y1 = MouseY(&mouse) + 100;
			graph0[*itemx].color = 0xC618;
			if (graph0[*itemx].x1 > 562)
			{
				graph0[*itemx].x1 = 562;
				graph0[*itemx].x0 = 562 - 80;
			}
			if (graph0[*itemx].y1 > 768)
			{
				graph0[*itemx].y1 = 768;
				graph0[*itemx].y0 = 562 - 100;
			}
			MouseOff(&mouse);
			bar1(graph0[*itemx].x0, graph0[*itemx].y0, graph0[*itemx].x1, graph0[*itemx].y1, graph0[*itemx].color);
			prt_hz24d(graph0[*itemx].x0+40-20,graph0[*itemx].y0 + 50 - 4, "照片", 0x0000, "HZK\\Hzk24k");//黑色
			MouseOn(mouse);
			*presstime = 2;
			confirm(select, graph0);
		}
	}
	
	//确认
	if (MousePress(750 + 20, 730, 800 + 20, 760) == 1)//确认
	{
		delay(100);
		(*itemx)++;
		(*select) = 0;
		MouseOff(&mouse);
		bar1(700, 620, 1024, 768, 0x7F50);
		bar1(800, 70, 1024, 660, 0x7F50);
		bar1(680, 600, 760, 700, 0x7F50);
		MouseOn(mouse);
		save_bar();

	}
	//取消680, 600, 760, 700
	if (MousePress(750 + 120, 730, 800 + 120, 760) == 1)//取消
	{
		delay(100);
		(*select) = 0;
		MouseOff(&mouse);
		bar1(761, 620, 1024, 768, 0x7F50);
		bar1(800, 60, 1024, 660, 0x7F50);
		bar1(904, 608, 1024, 768, 0x7F50);
		MouseOn(mouse);
		graph0[*itemx].color = 0xFFFF;
		bar1(graph0[*itemx].x0, graph0[*itemx].y0, graph0[*itemx].x1, graph0[*itemx].y1, graph0[*itemx].color);
		//对结构初始化
		graph0[*itemx].x0 = 0;
		graph0[*itemx].y0 = 0;
		graph0[*itemx].y1 = 0;
		graph0[*itemx].x1 = 0;
		graph0[*itemx].shape = 0;
		save_bar();
	}
}


/*****************************对矩形进行操控**************
*************************/
void bar_control(graphitem*graph0,int *select,int *presstime,int* itemx)
{
	
	int i, j;
	int m,n;
		n = strcmp(graph0[*itemx-1].title, "basic");
		if (n != 0)
		{
			if ((MousePress(0, 0, 562, 768) == 1) && (*presstime == 1))
			{

				graph0[*itemx].x0 = MouseX(&mouse);
				graph0[*itemx].y0 = MouseY(&mouse);
				graph0[*itemx].x1 = MouseX(&mouse) + 150;
				graph0[*itemx].y1 = MouseY(&mouse) + 90;
				graph0[*itemx].color = 0x03FF;
				if (graph0[*itemx].x1 > 562)
				{
					graph0[*itemx].x1 = 562;
					graph0[*itemx].x0 = 562 - 175;
				}
				if (graph0[*itemx].y1 > 768)
				{
					graph0[*itemx].y1 = 768;
					graph0[*itemx].y0 = 768 - 250;
				}
				bar1(graph0[*itemx].x0, graph0[*itemx].y0, graph0[*itemx].x1, graph0[*itemx].y1, graph0[*itemx].color);
				*presstime = 2;
				confirm(select, graph0);
			}

			if (*select == 1)
			{
				resize(graph0, itemx);
				if (Getpixel64k(862, 101) == 0xF81F)
				{
					amplify(graph0, itemx, 5);
					narrow(graph0, itemx, 3);
				}
				delete(graph0, itemx);
				//选择颜色
				m = Setcolorm();
				setcolor1(m, graph0, itemx);
				bar1(graph0[*itemx].x0, graph0[*itemx].y0, graph0[*itemx].x1, graph0[*itemx].y1, graph0[*itemx].color);

			}
		}
	
	else
	{
		if ((MousePress(0, 0, 562, 768) == 1) && (*presstime == 1))
		{
			graph0[*itemx].x0 = MouseX(&mouse);
			graph0[*itemx].y0 = MouseY(&mouse);
			graph0[*itemx].x1 = MouseX(&mouse) + 175;
			graph0[*itemx].y1 = MouseY(&mouse) + 250;
			graph0[*itemx].color = 0x03FF;
			if (graph0[*itemx].x1 > 562)
				graph0[*itemx].x1 = 562;
			if (graph0[*itemx].y1 > 768)
				graph0[*itemx].y1 = 768;
			bar1(graph0[*itemx].x0, graph0[*itemx].y0, graph0[*itemx].x1, graph0[*itemx].y1, graph0[*itemx].color);
			*presstime = 2;
			confirm(select, graph0);
		}
		if (*select == 1)
		{
			
			//选择颜色
			m = Setcolorm();
			setcolor1(m, graph0, itemx);
			bar1(graph0[*itemx].x0, graph0[*itemx].y0, graph0[*itemx].x1, graph0[*itemx].y1, graph0[*itemx].color);
		}
	}
    //确认
	 if (MousePress(750 + 20, 730, 800 + 20, 760) == 1)//确认
	 {
		 delay(100);
		 strcpy(graph0[*itemx].title,graph0[*itemx-1].title);
		 (*itemx)++;
		 (*select) = 0;
		 MouseOff(&mouse);
		 bar1(700, 620, 1024, 768, 0x7F50);
		 bar1(800, 70, 1024, 660, 0x7F50);
		 MouseOn(mouse);
		 save_bar();
	 }
	 //取消
	 if (MousePress(750 + 120, 730, 800 + 120, 760) == 1)//取消
	 {
		 delay(100);
		 (*select) = 0;
		 MouseOff(&mouse);
		 bar1(700, 620, 1024, 768, 0x7F50);
		 bar1(800, 50, 1024, 660, 0x7F50);
		 bar1(904, 608, 1024, 768, 0x7F50);
		 MouseOn(mouse);
		 graph0[*itemx].color = 0xFFFF;
		 bar1(graph0[*itemx].x0, graph0[*itemx].y0, graph0[*itemx].x1, graph0[*itemx].y1, graph0[*itemx].color);
		 //对结构初始化
		 graph0[*itemx].x0 = 0;
		 graph0[*itemx].y0 = 0;
		 graph0[*itemx].y1 = 0;
		 graph0[*itemx].x1 = 0;
		 graph0[*itemx].shape = 0;
		 save_bar();
	 }
}


/****************************对圆进行操控**********************
*********/

void circle_control(graphitem* graph0, int* select, int* presstime,int*itemx)
{
	int i, j;
	int m;

	resize(graph0, itemx);
	if (MousePress(650, 90, 800, 180) == 1)
	{
		*presstime = 1;
		*select = 1;
	}
	
	
		if ((MousePress(0, 0, 562, 768) == 1) && (*presstime == 1))
		{
			graph0[*itemx].x0 = MouseX(&mouse);
			graph0[*itemx].y0 = MouseY(&mouse);
			graph0[*itemx].x1 = 50;
			graph0[*itemx].color = 0x03FF;
			if (graph0[*itemx].x0 + graph0[*itemx].x1 > 562)
				graph0[*itemx].x0 = 562 - 50;
			if (graph0[*itemx].y0 + graph0[*itemx].x1 > 768)
				graph0[*itemx].y0 = 768 - 50;
			FillCircle(graph0[*itemx].x0, graph0[*itemx].y0, graph0[*itemx].x1, graph0[*itemx].color);
			*presstime = 2;
			confirm(select, graph0);
		}
		if (*select == 1)
		{
			resize(graph0, itemx);
			if (Getpixel64k(862, 101) == 0xFC00)
			{
				circle_amplify(graph0, itemx,2);
				circle_narrow(graph0, itemx,2);
			}
			delete(graph0, itemx);

			//选择颜色
			m = Setcolorm();
			setcolor1(m, graph0, itemx);
			FillCircle(graph0[*itemx].x0, graph0[*itemx].y0, graph0[*itemx].x1, graph0[*itemx].color);
		}
		if (MousePress(750 + 20, 730, 800 + 20, 760) == 1)//确认
		{
			delay(100);
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(700, 620, 1024, 768, 0x7F50);
			bar1(800, 70, 1024, 600, 0x7F50);
			MouseOn(mouse);
				save_bar();

		}
		if (MousePress(750 + 120, 730, 800 + 120, 760) == 1)//取消
		{
			delay(100);
			(*select) = 0;
			MouseOff(&mouse);
			bar1(700, 620, 1024, 768, 0x7F50);
			MouseOn(mouse);
			graph0[*itemx].color = 0xFFFF;
			drawitem(&graph0[*itemx]);
			//对结构初始化
			graph0[*itemx].x0 = 0;
			graph0[*itemx].y0 = 0;
			graph0[*itemx].y1 = 0;
			graph0[*itemx].x1 = 0;
			graph0[*itemx].shape = 0;
			if (*itemx != 0)
				save_bar();

		}
	
}

/****************************对椭圆进行控制***********************
*******************/
void ellipse_control(graphitem* graph0, int* select, int* presstime, int* itemx)
{
	int i, j;
	int m,n;
	int mousey;
	if (MouseIn(0, 0, 562, 768) == 1)
	{
		if ((MousePress(0, 0, 562, 768) == 1) && (*presstime == 1))
		{
			graph0[*itemx].x0 = MouseX(&mouse);
			graph0[*itemx].y0 = MouseY(&mouse);
			graph0[*itemx].x1 =  60;
			graph0[*itemx].y1 =  25;
			graph0[*itemx].color = 0x03FF;
			if (graph0[*itemx].x0 + graph0[*itemx].x1 > 562)
				graph0[*itemx].x0 = 562 - 60;
			if (graph0[*itemx].y0 + graph0[*itemx].y1 > 768)
				graph0[*itemx].y0 = 768 - 25;
			Ellipsefill(graph0[*itemx].x0, graph0[*itemx].y0, graph0[*itemx].x1, graph0[*itemx].y1, 3, graph0[*itemx].color);
			*presstime = 2;
			confirm(select, graph0);
		}
	}
	if (*select == 1)
	{
		resize(graph0, itemx);
		if (Getpixel64k(862, 101) == 0xF81F)
		{
			amplify(graph0, itemx,2);
			narrow(graph0, itemx,2);
		}
		delete(graph0, itemx);

		//选择颜色
		m = Setcolorm();
		setcolor1(m, graph0, itemx);
		Ellipsefill(graph0[*itemx].x0, graph0[*itemx].y0, graph0[*itemx].x1, graph0[*itemx].y1,3, graph0[*itemx].color);

	}
	if (MousePress(750 + 20, 730, 800 + 20, 760) == 1)//确认
	{
		delay(100);
		MouseOff(&mouse);
		bar1(700, 620, 1024, 768, 0x7F50);
		bar1(800, 70, 1024, 630, 0x7F50);
		MouseOn(mouse);
		save_bar();
		se_title();
	}
	if (Getpixel64k(832, 102) == 0xC618)
	{
		if (MousePress(830, 140, 985, 190) == 1)
		{
			prt_asc16(graph0[*itemx].x0 - 40, graph0[*itemx].y0 - 4, "objective", 0);
			strcpy(graph0[*itemx].title, "objective");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		if(MousePress(830, 190, 985, 240) == 1)
		{
			prt_asc16(graph0[*itemx].x0 - 40, graph0[*itemx].y0 - 4, "education", 0);
			strcpy(graph0[*itemx].title, "education");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		if (MousePress(830, 240, 985, 290) == 1)
		{
			prt_asc16(graph0[*itemx].x0 - 24, graph0[*itemx].y0 - 4, "honors", 0);
			strcpy(graph0[*itemx].title, "honors");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		if (MousePress(830, 290, 985, 340) == 1)
		{
			prt_asc16(graph0[*itemx].x0 - 32, graph0[*itemx].y0 - 4, "jobskill", 0);
			strcpy(graph0[*itemx].title, "jobskill");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		if (MousePress(830, 340, 985, 390) == 1)
		{
			prt_asc16(graph0[*itemx].x0 - 32, graph0[*itemx].y0 - 4, "evaluate", 0);
			strcpy(graph0[*itemx].title, "evaluate");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		if (MousePress(830, 390, 985, 440) == 1)
		{
			prt_asc16(graph0[*itemx].x0 - 24, graph0[*itemx].y0 - 4, "others", 0);
			strcpy(graph0[*itemx].title, "others");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		if (MousePress(830, 440, 985, 490) == 1)
		{
			prt_asc16(graph0[*itemx].x0 - 24, graph0[*itemx].y0 - 4, "basic", 0);
			strcpy(graph0[*itemx].title, "basic");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		
	}
	if (MousePress(750 + 120, 730, 800 + 120, 760) == 1)//取消
	{
		delay(100);
		(*select) = 0;
		MouseOff(&mouse);
		bar1(700, 620, 1024, 768, 0x7F50);
		MouseOn(mouse);
		graph0[*itemx].color = 0xFFFF;
		drawitem(&graph0[*itemx]);
		//对结构初始化
		graph0[*itemx].x0 = 0;
		graph0[*itemx].y0 = 0;
		graph0[*itemx].y1 = 0;
		graph0[*itemx].x1 = 0;
		graph0[*itemx].shape = 0;
		if (*itemx != 0)
			save_bar();

	}
}

/****************************对梯形1进行操控*********************
**********************/
void ladder1_control(graphitem* graph0, int* select, int* presstime, int* itemx)
{

	int i, j;
	int m;
	if (MouseIn(0, 0, 562, 768) == 1)
	{
		if ((MousePress(0, 0, 562, 768) == 1) && (*presstime == 1))
		{
			graph0[*itemx].x0 = MouseX(&mouse);
			graph0[*itemx].y0 = MouseY(&mouse);
			graph0[*itemx].x1 = 120;
			graph0[*itemx].y1 =  40;
			graph0[*itemx].color = 0x03FF;
			if (graph0[*itemx].x0 + graph0[*itemx].x1 > 562)
				graph0[*itemx].x0 = 562 - 120;
			if (graph0[*itemx].y0 + graph0[*itemx].y1 > 768)
				graph0[*itemx].y0 = 768 - 40;
			ladder1(graph0[*itemx].x0, graph0[*itemx].y0, graph0[*itemx].x1, graph0[*itemx].y1, graph0[*itemx].color);
			*presstime = 2;
			confirm(select, graph0);
		}
	}
	if (*select == 1)
	{
		resize( graph0, itemx);
		if (Getpixel64k(862, 101) == 0xF81F)
		{
			amplify(graph0, itemx,2);
			narrow(graph0, itemx,2);
		}
		delete(graph0, itemx);

		//选择颜色
		m = Setcolorm();
		setcolor1(m, graph0, itemx);
		ladder1(graph0[*itemx].x0, graph0[*itemx].y0, graph0[*itemx].x1, graph0[*itemx].y1, graph0[*itemx].color);

	}
	if (MousePress(750 + 20, 730, 800 + 20, 760) == 1)//确认
	{
		delay(100);
		MouseOff(&mouse);
		bar1(700, 620, 1024, 768, 0x7F50);
		bar1(800, 70, 1024, 600, 0x7F50);
		MouseOn(mouse);
			save_bar();
			se_title();
	}
	if (Getpixel64k(832, 102) == 0xC618)
	{
		if (MousePress(830, 140, 985, 190) == 1)
		{
			prt_asc16(graph0[*itemx].x0 + 10, graph0[*itemx].y0+ graph0[*itemx].y1/2 - 4, "objective", 0);
			strcpy(graph0[*itemx].title, "objective");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		if (MousePress(830, 190, 985, 240) == 1)
		{
			prt_asc16(graph0[*itemx].x0 + 10, graph0[*itemx].y0 + graph0[*itemx].y1 / 2 - 4, "education", 0);
			strcpy(graph0[*itemx].title, "education");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		if (MousePress(830, 240, 985, 290) == 1)
		{
			prt_asc16(graph0[*itemx].x0 + 10, graph0[*itemx].y0 + graph0[*itemx].y1 / 2 - 4, "honors", 0);
			strcpy(graph0[*itemx].title, "honors");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		if (MousePress(830, 290, 985, 340) == 1)
		{
			prt_asc16(graph0[*itemx].x0 + 10, graph0[*itemx].y0 + graph0[*itemx].y1 / 2 - 4, "jobskill", 0);
			strcpy(graph0[*itemx].title, "jobskill");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		if (MousePress(830, 340, 985, 390) == 1)
		{
			prt_asc16(graph0[*itemx].x0 + 10, graph0[*itemx].y0 + graph0[*itemx].y1 / 2 - 4, "evaluate", 0);
			strcpy(graph0[*itemx].title, "evaluate");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		if (MousePress(830, 390, 985, 440) == 1)
		{
			prt_asc16(graph0[*itemx].x0 + 10, graph0[*itemx].y0 + graph0[*itemx].y1/ 2 - 4, "others", 0);
			strcpy(graph0[*itemx].title, "others");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		if (MousePress(830, 440, 985, 490) == 1)
		{
			prt_asc16(graph0[*itemx].x0 + 10, graph0[*itemx].y0 + graph0[*itemx].y1 / 2 - 4, "basic", 0);
			strcpy(graph0[*itemx].title, "basic");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}

	}
	if (MousePress(750 + 120, 730, 800 + 120, 760) == 1)//取消
	{
		delay(100);
		(*select) = 0;
		MouseOff(&mouse);
		bar1(700, 620, 1024, 768, 0x7F50);
		MouseOn(mouse);
		graph0[*itemx].color = 0xFFFF;
		drawitem(&graph0[*itemx]);
		//对结构初始化
		graph0[*itemx].x0 = 0;
		graph0[*itemx].y0 = 0;
		graph0[*itemx].y1 = 0;
		graph0[*itemx].x1 = 0;
		graph0[*itemx].shape = 0;
		if (*itemx != 0)
			save_bar();

	}
}

/****************************对梯形2进行操控*********************
**********************/
void ladder_control(graphitem* graph0, int* select, int* presstime, int* itemx)
{

	int i, j;
	int m;
	if (MouseIn(0, 0, 562, 768) == 1)
	{
		if ((MousePress(0, 0, 562, 768) == 1) && (*presstime == 1))
		{
			graph0[*itemx].x0 = MouseX(&mouse);
			graph0[*itemx].y0 = MouseY(&mouse);
			graph0[*itemx].x1 = 120;
			graph0[*itemx].y1 = 40;
			graph0[*itemx].color = 0x03FF;
			if (graph0[*itemx].x0 + 120+40 > 562)
				graph0[*itemx].x0 = 562 - 120-40;
			if (graph0[*itemx].y0 + 40 > 768)
				graph0[*itemx].y0 = 768 - 40;
			ladder(graph0[*itemx].x0, graph0[*itemx].y0, graph0[*itemx].x1, graph0[*itemx].y1, graph0[*itemx].color);
			*presstime = 2;
			confirm(select, graph0);
		}
	}
	if (*select == 1)
	{
		resize(graph0, itemx);
		if (Getpixel64k(862, 101) == 0xF81F)
		{
			amplify(graph0, itemx,2);
			narrow(graph0, itemx,2);
		}
		delete(graph0, itemx);

		//选择颜色
		m = Setcolorm();
		setcolor1(m, graph0, itemx);
		ladder1(graph0[*itemx].x0, graph0[*itemx].y0, graph0[*itemx].x1, graph0[*itemx].y1, graph0[*itemx].color);

	}
	if (MousePress(750 + 20, 730, 800 + 20, 760) == 1)//确认
	{
		delay(100);
		MouseOff(&mouse);
		bar1(700, 620, 1024, 768, 0x7F50);
		bar1(800, 70, 1024, 600, 0x7F50);
		MouseOn(mouse);
			save_bar();
			se_title();
			
	}
	if (Getpixel64k(832, 102) == 0xC618)
	{
		if (MousePress(830, 140, 985, 190) == 1)
		{
			prt_asc16(graph0[*itemx].x0 + 10, graph0[*itemx].y0 + graph0[*itemx].y1 / 2 - 4, "objective", 0);
			strcpy(graph0[*itemx].title, "objective");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
			
		}
		if (MousePress(830, 190, 985, 240) == 1)
		{
			prt_asc16(graph0[*itemx].x0 + 10, graph0[*itemx].y0 + graph0[*itemx].y1 / 2 - 4, "education", 0);
			strcpy(graph0[*itemx].title, "education");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		if (MousePress(830, 240, 985, 290) == 1)
		{
			prt_asc16(graph0[*itemx].x0 + 10, graph0[*itemx].y0 + graph0[*itemx].y1 / 2 - 4, "honors", 0);
			strcpy(graph0[*itemx].title, "honors");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		if (MousePress(830, 290, 985, 340) == 1)
		{
			prt_asc16(graph0[*itemx].x0 + 10, graph0[*itemx].y0 + graph0[*itemx].y1 / 2 - 4, "jobskill", 0);
			strcpy(graph0[*itemx].title, "jobskill");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		if (MousePress(830, 340, 985, 390) == 1)
		{
			prt_asc16(graph0[*itemx].x0 + 10, graph0[*itemx].y0 + graph0[*itemx].y1 / 2 - 4, "evaluate", 0);
			strcpy(graph0[*itemx].title, "evaluate");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		if (MousePress(830, 390, 985, 440) == 1)
		{
			prt_asc16(graph0[*itemx].x0 + 10, graph0[*itemx].y0 + graph0[*itemx].y1 / 2 - 4, "others", 0);
			strcpy(graph0[*itemx].title, "others");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}
		if (MousePress(830, 440, 985, 490) == 1)
		{
			prt_asc16(graph0[*itemx].x0 + 10, graph0[*itemx].y0 + graph0[*itemx].y1 / 2 - 4, "basic", 0);
			strcpy(graph0[*itemx].title, "basic");
			(*itemx)++;
			(*select) = 0;
			MouseOff(&mouse);
			bar1(830, 100, 985, 500, 0x7F50);
			MouseOn(mouse);
		}

	}
	if (MousePress(750 + 120, 730, 800 + 120, 760) == 1)//取消
	{
		delay(100);
		(*select) = 0;
		MouseOff(&mouse);
		bar1(700, 620, 1024, 768, 0x7F50);
		MouseOn(mouse);
		graph0[*itemx].color = 0xFFFF;
		drawitem(&graph0[*itemx]);
		//对结构初始化
		graph0[*itemx].x0 = 0;
		graph0[*itemx].y0 = 0;
		graph0[*itemx].y1 = 0;
		graph0[*itemx].x1 = 0;
		graph0[*itemx].shape = 0;
		if (*itemx != 0)
			save_bar();

	}
}

/*****************************对直线进行操控**************
*************************/
void line_control(graphitem* graph0, int* select, int* presstime, int* itemx)
{

	int i, j;
	int m;
	if (MouseIn(0, 0, 562, 768) == 1)
	{
		if ((MousePress(0, 0, 562, 768) == 1) && (*presstime == 1))
		{
			graph0[*itemx].x0 = MouseX(&mouse);
			graph0[*itemx].y0 = MouseY(&mouse);
			graph0[*itemx].color = 0x03FF;
			if (graph0[*itemx].x0 > 562)
				graph0[*itemx].x0 = 562;
			if (graph0[*itemx].y0 > 768)
				graph0[*itemx].y0 = 768;
			confirm(select, graph0);
			*presstime = 2;
			delay(100);
		}
		
		
		if ((MousePress(0, 0, 562, 768) == 1) && (*presstime == 2))
		{
			graph0[*itemx].x1 = MouseX(&mouse);
			graph0[*itemx].y1 = MouseY(&mouse);
			graph0[*itemx].color = 0x03FF;
			if (graph0[*itemx].x1 > 562)
				graph0[*itemx].x1 = 562;
			if (graph0[*itemx].y1 > 768)
				graph0[*itemx].y1 = 768;
			if (fabs(graph0[*itemx].x0 - graph0[*itemx].x1) <= 20)
				graph0[*itemx].x1 = graph0[*itemx].x0;
			else  if (fabs(graph0[*itemx].y0 - graph0[*itemx].y1) <= 20)
				graph0[*itemx].y1 = graph0[*itemx].y0;
			else
				graph0[*itemx].x1 = graph0[*itemx].x1;
			Line_Thick(graph0[*itemx].x0, graph0[*itemx].y0, graph0[*itemx].x1, graph0[*itemx].y1, 2, graph0[*itemx].color);
			*presstime = 3;
		}
		
	}
	if (*select == 1&&*presstime==2)
	{
		
		delete(graph0, itemx);

		//选择颜色
		m = Setcolorm();
		setcolor1(m, graph0, itemx);
		//Line_Thick(graph0[*itemx].x0, graph0[*itemx].y0, graph0[*itemx].x1, graph0[*itemx].y1,2, graph0[*itemx].color);

	}
	if (MousePress(750 + 20, 730, 800 + 20, 760) == 1)//确认
	{
		delay(300);
		(*itemx)++;
		(*select) = 0;
		MouseOff(&mouse);
		bar1(700, 620, 1024, 768, 0x7F50);
		bar1(800, 70, 1024, 600, 0x7F50);
		MouseOn(mouse);
			save_bar();

	}
	if (MousePress(750 + 120, 730, 800 + 120, 760) == 1)//取消
	{
		delay(100);
		(*select) = 0;
		MouseOff(&mouse);
		bar1(700, 620, 1024, 768, 0x7F50);
		MouseOn(mouse);
		graph0[*itemx].color = 0xFFFF;
	drawitem(&graph0[*itemx]);
		//对结构初始化
		graph0[*itemx].x0 = 0;
		graph0[*itemx].y0 = 0;
		graph0[*itemx].y1 = 0;
		graph0[*itemx].x1 = 0;
		graph0[*itemx].shape = 0;
		if (*itemx != 0)
			save_bar();
	}

}


/***************************除圆放大over*********************
***********/
void amplify( graphitem* graph0,int* itemx,int m)
{
	int i;
	int j;
	
	
	if (MousePress(816, 100, 911, 150) == 1)
	{
		(graph0[*itemx].x1) = (graph0[*itemx].x1) + m;
		bar1(0, 0, 562, 768, 0xFFFF);
		for (i = 0; i < (*itemx)+1; i++)
		{
			drawitem(&graph0[i]);
		}
		
	}
	
	//发达高度
	
	 if (MousePress(861, 150, 911, 200) == 1)
	{
		(graph0[*itemx].y1) = (graph0[*itemx].y1) + m;
		bar1(0, 0, 562, 768, 0xFFFF);
		for (i = 0; i < (*itemx) + 1; i++)
		{
			drawitem(&graph0[i]);
		}
	}
	
	//同时放大
	 if (MousePress(861, 200, 911, 250) == 1)
	{
		(graph0[*itemx].x1) = (graph0[*itemx].x1) + m;
		(graph0[*itemx].y1) = (graph0[*itemx].y1) + m;
		bar1(0, 0, 562, 768, 0xFFFF);
		for (i = 0; i < (*itemx) + 1; i++)
		{
			drawitem(&graph0[i]);
		}
	}
}

/***************************圆放大over*********************
***********/
void circle_amplify(graphitem* graph0, int* itemx,int m)
{
	int i;
	int j;


	if (MousePress(861, 100, 960, 150) == 1)
	{
		(graph0[*itemx].x1) = (graph0[*itemx].x1) + m;
		bar1(0, 0, 562, 768, 0xFFFF);
		for (i = 0; i < (*itemx) + 1; i++)
		{
			drawitem(&graph0[i]);
		}

	}
}

/***************************圆缩小over*********************
***********/
void circle_narrow(graphitem* graph0, int* itemx,int m)
{
	int i;
	int j;


	if (MousePress(861, 150, 960, 200) == 1)
	{
		(graph0[*itemx].x1) = (graph0[*itemx].x1) - m;
		bar1(0, 0, 562, 768, 0xFFFF);
		for (i = 0; i < (*itemx) + 1; i++)
		{
			drawitem(&graph0[i]);
		}

	}
}

/*******************画组件****************
*********/
void drawitem(graphitem *ap)
{
	switch (ap->shape)
	{
	case 6:
		if (ap->x1 > 562)
			ap->x1 = 562;
		if (ap->y1 > 768)
			ap->y1 = 768;
		bar1(ap->x0, ap->y0, ap->x1, ap->y1, ap->color);
		break;
	case 1:
		if ((ap->x0) + (ap->x1) > 562)
			(ap->x0) = 562 - (ap->x1);
		if ((ap->y0) + (ap->x1) > 768)
			(ap->y0) = 768 - (ap->x1);
		FillCircle(ap->x0, ap->y0, ap->x1, ap->color);
		break;
	case 2:
		if ((ap->x0) + (ap->x1) > 562)
			(ap->x0) = 562 - (ap->x1);
		if ((ap->y0) + (ap->y1) > 768)
			(ap->y0) = 768 - (ap->y1);
		Ellipsefill(ap->x0, ap->y0, ap->x1, ap->y1, 3, ap->color);
		prt_asc16(ap->x0 - 40, ap->y0 - 4, ap->title, 0);
		break;
	case 3:
		if ((ap->x0) + (ap->x1) > 562)
			(ap->x0) = 562 - (ap->x1);
		if ((ap->y0) + (ap->y1) > 768)
			(ap->y0) = 768 - (ap->y1);
		ladder1(ap->x0, ap->y0, ap->x1, ap->y1, ap->color);
		prt_asc16(ap->x0 + 10, ap->y0 + (ap->y1) / 2 - 4, ap->title, 0);

		break;
	case 4:
		if ((ap->x0) + 120 + 40 > 562)
			(ap->x0) = 562 - (ap->x1) - (ap->y1);
		if ((ap->y0) + 40 > 768)
			(ap->y0) = 768 - (ap->y1);
		ladder(ap->x0, ap->y0, ap->x1, ap->y1, ap->color);
		prt_asc16(ap->x0 + 10, ap->y0 + (ap->y1) / 2 - 4, ap->title, 0);
		break;
	case 5:
		if ((ap->x0) > 562)
			(ap->x0) = 562;
		if ((ap->y0) > 768)
			(ap->y0) = 768;
		if ((ap->x1) > 562)
			(ap->x1) = 562;
		if ((ap->y1) > 768)
			(ap->y1) = 768;
		if (fabs(ap->x0 - ap->x1) <= 20)
			Line_Thick(ap->x0, ap->y0, ap->x0, ap->y1, 2, ap->color);
		else  if (fabs(ap->y0 - ap->y1) <= 20)
			Line_Thick(ap->x0, ap->y0, ap->x1, ap->y0, 2, ap->color);
		else
			Line_Thick(ap->x0, ap->y0, ap->x1, ap->y1, 2, ap->color);
		break;
	case 7:
		bar1(ap->x0, ap->y0, ap->x1, ap->y1, ap->color);
		prt_hz24d(ap->x0 + 40 - 20,ap->y0 + 50 - 4, "照片", 0x0000, "HZK\\Hzk24k");//黑色
		break;
	}
}

/***************************矩形缩小*********************
***********/
void narrow(graphitem* graph0,int*itemx,int m)
{
	int i;
	int j;


	if (MousePress(911, 100, 961, 150) == 1)
	{
		(graph0[*itemx].x1) = (graph0[*itemx].x1) - m;
		bar1(0, 0, 562, 768, 0xFFFF);
		for (i = 0; i < (*itemx) + 1; i++)
		{
			drawitem(&graph0[i]);
		}

	}

	//减小高度

	if (MousePress(911, 150, 961, 200) == 1)
	{
		(graph0[*itemx].y1) = (graph0[*itemx].y1) - m;
		bar1(0, 0, 562, 768, 0xFFFF);
		for (i = 0; i < (*itemx) + 1; i++)
		{
			drawitem(&graph0[i]);
		}
	}

	//同时缩小
	if (MousePress(911, 200, 961, 250) == 1)
	{
		(graph0[*itemx].x1) = (graph0[*itemx].x1) - m;
		(graph0[*itemx].y1) = (graph0[*itemx].y1) - m;
		bar1(0, 0, 562, 768, 0xFFFF);
		for (i = 0; i < (*itemx) + 1; i++)
		{
			drawitem(&graph0[i]);
		}
	}
}

/***************************撤回*********************
***********/
 void delete(graphitem* graph0,int*itemx)
{
	 int i;
	 /*
	if (MousePress(730, 0, 810, 30) == 1)
	{
		graph0[*itemx].x0 = 0;
		graph0[*itemx].y0 = 0;
		graph0[*itemx].x1 = 0;
		graph0[*itemx].y1 = 0;
		graph0[*itemx].color = 0;
		bar1(0, 0, 562, 768, 0xFFFF);
		for (i = 0; i < (*itemx) + 1; i++)
		{
			drawitem(&graph0[i]);
		}
		itemx--;
		bar1(700, 620, 1024, 768, 0x7F50);
		delay(100);
	}
	*/
}

void youjiemian()
{
	//显示界面
	bar1(0, 0, 562, 768, 0xFFFF);//白色
	bar1(562, 0, 1024, 768, 0x7F50);//青绿色
	shanglan();
	//退出
	bar1(974, 0, 1024, 30, 0x5D4F);//绿色
	prt_hz24d(976, 2,  "退出", 0x0000, "HZK\\Hzk24k");//黑色
	//主页
	bar1(46 + 510+5, 0, 140 + 510, 30, 0xff00);
	Line_Thick(66 + 510, 0, 50+510, 16, 1, 0);
	Line_Thick(66 + 510, 0, 82 + 510, 16, 1, 0);
	linever(58 + 510, 8, 58 + 510, 27, 1, 0);
	linelevel(58 + 510, 27, 74 + 510, 27, 1, 0);
	linever(74 + 510, 8, 74 + 510, 27, 1, 0);
	prt_hz24(90 + 510, 5, "主页", 0, "HZK\\hzk24k");
	//返回
	bar1(974, 30, 1024, 60, 0x5D4F);//绿色
	prt_hz24d(974+2, 32, "返回", 0x0000, "HZK\\Hzk24k");//黑色
	
}

//保存面框
void save_bar()
{
	bar1(904,668-15,1000, 708-15, 0xC618);
	prt_hz24d(906,670-15, "保存我！", 0x0000, "HZK\\Hzk24k");//黑色
	Ellipsefill(925,688+18,20,10,3,0xFC00);//橙色
	Ellipsefill(970, 688 + 18, 20, 10, 3, 0xFC00);//橙色
	put_asc16_size(914, 673 + 15 + 8, 1, 1, "Yes!", 0);
	put_asc16_size(966, 673 + 15 + 8, 1, 1, "No!", 0);
}

//保存操作
void save_paint(graphitem* graph1,int*itemx,int*savetime)
{
	FILE* file;
	int i;
	file = fopen("C:\\test\\resume_p.dat", "wb");
	if (file == NULL)
	{
		bar1(824, 384, 954, 444, 0xC618);
		prt_hz24d(889, 414, "保存失败！", 0x0000, "HZK\\Hzk24k");//黑色
		bar1(924, 414, 974, 444, 0xFC00);
		Line_Thick(924, 414, 954, 444, 1, 0);
		Line_Thick(954, 414, 924, 444, 1, 0);
	}
	else
	{
		if (MousePress(924, 414, 954, 444) == 1)
		{
			bar1(824, 384, 954, 444, 0x7F50);
		}

		//晶结构数组写入文件
		for (i = 0; i < 20; i++)
		{
			if (graph1[i].shape == 6 || graph1[i].shape == 5)
			{
				graph1[i].x0 = graph1[i].x0 + 228;
				graph1[i].x1 = graph1[i].x1 + 228;
			}
			else if (graph1[i].shape == 1 || graph1[i].shape == 2 || graph1[i].shape == 3 || graph1[i].shape == 4)
			{
				graph1[i].x0 = graph1[i].x0 + 228;

			}
			fwrite(&graph1[i], sizeof(graphitem), 1, file);
		}
		fclose(file);
		bar1(251, 364, 366, 404, 0xFC00);
		prt_hz24d(268, 374, "保存成功！", 0x0000, "HZK\\Hzk24k");//黑色
		*savetime = 1;
		delay(2000);
		bar1(0, 0, 562, 768, 0xFFFF);
		for (i = 0; i < 20; i++)
		{
			graph1[i].x0 = 0;
			graph1[i].y0 = 0;
			graph1[i].x1 = 0;
			graph1[i].y1 = 0;
			graph1[i].color = 0xFFFF;
			graph1[i].shape = 0;
		}
		*itemx = 0;
	}
}

int paint()
{
	int savetime=1;
	int select = 0;
	int itemx = 0;
	int presstime = 0;
	//int a, b, c, d, flag = 0;
	int i, j;
	int* colorp;
	int color[18] = { 0 };
	graphitem graph1[20] = { 0 };
	//graphitem* ap = NULL;
	//ap = graph1;
	itemx = 0;
	for (i = 0; i++; i < 18)
	{
		color[i] = i;
	}
	colorp = &color[0];
	youjiemian();
	for (i = 0; i < 20; i++)
	{
		graph1[i].x0 = 0;
		graph1[i].y0 = 0;
		graph1[i].x1 = 0;
		graph1[i].y1 = 0;
		graph1[i].color = 0xFFFF;
		graph1[i].shape = 0;
	}
	
	


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
		//使用说名
		if (MousePress(890, 0, 970, 30) == 1)
		{
			if (Getpixel64k(978, 388) == 0x7F50)
			{
				//先覆盖
				bar1(650, 80, 1024, 625, 0x7F50);
				bar1(680, 600, 760, 700, 0x7F50);
				//画
				bar1(615, 95, 980, 390, 0xC618);
				bar1(758, 73, 830, 100, 0xC618);
				prt_hz16_size(760, 75, 1, 1, "操作说明", 0x801F, "HZK\\Hz16");
				prt_hz16_size(650, 100, 1, 1, "当您使用本界面制作简历时，请您先绘制照片", 0, "HZK\\Hz16");
				prt_hz16_size(620, 125, 1, 1, "框，当您绘制文本框时，请将文本框与标题框配套", 0, "HZK\\Hz16");
				prt_hz16_size(620, 150, 1, 1, "绘制（即绘制一个文本框紧接着绘制标题框，或者", 0, "HZK\\Hz16");
				prt_hz16_size(620, 175, 1, 1, "先绘制标题框然后绘制文本框），每当您选择一个", 0, "HZK\\Hz16");
				prt_hz16_size(620, 200, 1, 1, "图形元件时，在左侧的绘制框中点击，元件将会在", 0, "HZK\\Hz16");
				prt_hz16_size(620, 225, 1, 1, "绘制框中显示，在右侧操作栏中上方的颜色选择和", 0, "HZK\\Hz16");
				prt_hz16_size(620, 250, 1, 1, "调整大小的按钮可以调整图形元件的属性，当您完", 0, "HZK\\Hz16");
				prt_hz16_size(620, 275, 1, 1, "成对该图形元件的调整时，请按下右侧操作框下方", 0, "HZK\\Hz16");
				prt_hz16_size(620, 300, 1, 1, "的确认按钮，保存对该图形元件的保存，如果您不", 0, "HZK\\Hz16");
				prt_hz16_size(620, 325, 1, 1, "想保存，请点击取消，当您完成了该简历的制作时，", 0, "HZK\\Hz16");
				prt_hz16_size(620, 350, 1, 1, "请点击保存，结束简历制作, 该简历制作给您造成", 0, "HZK\\Hz16");
				prt_hz16_size(620, 375, 1, 1, "的不便，敬请见谅。", 0, "HZK\\Hz16");

			}
			else
				bar1(615, 70, 980, 400, 0x7F50);
			delay(300);
		}
		//图形元件
		if (MousePress(810, 0, 890, 30) == 1)
		{
			if (Getpixel64k(652, 92) == 0x7F50)
			{
				//覆盖
				bar1(650, 80, 1024, 625, 0x7F50);
				bar1(615, 70, 980, 390, 0x7F50);
				//画
				bar1(650, 90, 800, 180, 0x03FF);//浅蓝色
				FillCircle(725, 250, 50, 0x03FF);//浅蓝色
				Ellipsefill(725, 350, 60, 25, 3, 0x03FF);//浅蓝色
				ladder1(665, 400, 120, 40, 0x03FF);//浅蓝
				ladder(665, 470, 80, 40, 0x03FF);//浅蓝
				Line_Thick(670, 580, 770, 580, 1, 0x03FF);//紫红色
				if (itemx == 0)
				{
					bar1(680, 600, 760, 700, 0x03FF);
					prt_hz24d((680 + 760) / 2 - 20, (600 + 700) / 2 - 4, "照片", 0x0000, "HZK\\Hzk24k");//黑色
				}

			}
			else
			{
				bar1(650, 90, 800, 585, 0x7F50);
				bar1(680, 600, 760, 700, 0x7F50);
			}
			delay(300);
		}
		//保存925,688+18  20,10
		if (MousePress(905, 688 + 8, 945, 688 + 28) == 1)
		{
			if (graph1[itemx-1].shape == 2 || graph1[itemx-1].shape == 3 || graph1[itemx-1].shape == 4 || graph1[itemx-1].shape == 7)
			{
				bar1(580, 45, 870, 87, 0xC618);
				prt_hz16_size(600, 45, 1, 1, "您添加的标题框与文本框不匹配或者", 0, "HZK\\Hz16");
				prt_hz16_size(600, 70, 1, 1, "未添加标题框与文本框！", 0, "HZK\\Hz16");
				delay(1000);
				bar1(580, 45, 900, 87, 0x7F50);
			}
			else
			save_paint(graph1, &itemx,&savetime);
		}
		//取消970,688+18,20,10删除
		if (MousePress(950, 688 + 8, 990, 688 + 28) == 1 )
		{
			savetime = -1;
			bar1(0, 0, 562, 768, 0xFFFF);
			itemx = 0;
			for (i = 0; i < 20; i++)
			{
				graph1[i].x0 = 0;
				graph1[i].y0 = 0;
				graph1[i].x1 = 0;
				graph1[i].y1 = 0;
				graph1[i].color = 0xFFFF;
				graph1[i].shape = 0;
			}
		}
		//矩形228
		if (MousePress(650, 90, 800, 180) == 1 && select == 0 && Getpixel64k(652, 92) == 0x03FF && itemx <= 20)
		{
			if ((graph1[itemx - 1].shape == 2 || graph1[itemx - 1].shape == 3 || graph1[itemx - 1].shape == 4)&&itemx > 0)
			{
				bar1(850, 600, 1024, 768, 0x7F50);
				graph1[itemx].shape = 6;
				presstime = 1;
				select = 1;
			}
			else if (itemx == 0)
			{
				bar1(580, 45, 972, 87, 0xC618);
				prt_hz16_size(600, 45, 2, 2, "请你首先选择添加相片框！", 0, "HZK\\Hz16");
				delay(1000);
				bar1(580, 45, 972, 87, 0x7F50);
			}
			else
			{
				bar1(580,45, 870, 87, 0xC618);
				prt_hz16_size(600, 45, 1, 1, "您刚刚选择了标题框，请您选择与之", 0, "HZK\\Hz16");
				prt_hz16_size(600, 70, 1, 1, "对应的文本框。", 0, "HZK\\Hz16");
				delay(1000);
				bar1(580, 45, 900, 87, 0x7F50);
			}
		}
		//原
		if (MousePress(675, 200, 775, 300) == 1 && select == 0 && Getpixel64k(725, 250) == 0x03FF && itemx <= 20)
		{
			if (itemx > 0)
			{
				bar1(850, 600, 1024, 768, 0x7F50);
				graph1[itemx].shape = 1;
				presstime = 1;
				select = 1;
			}
			else if (itemx == 0)
			{
				bar1(580, 45, 972, 87, 0xC618);
				prt_hz16_size(600, 45, 2, 2, "请你首先选择添加相片框！", 0, "HZK\\Hz16");
				delay(1000);
				bar1(580, 45, 972, 87, 0x7F50);
			}
             
		}
		//椭圆
		if (MousePress(665, 325, 725, 375) == 1 && select == 0 && Getpixel64k(725, 350) == 0x03FF && itemx <= 20 )
		{
			if ((graph1[itemx - 1].shape == 6||itemx==1|| graph1[itemx - 1].shape == 1|| graph1[itemx - 1].shape == 5) && itemx > 0)
			{
				bar1(850, 600, 1024, 768, 0x7F50);
				graph1[itemx].shape = 2;
				presstime = 1;
				select = 1;
			}
			else if (itemx == 0)
			{
				bar1(580, 45, 972, 87, 0xC618);
				prt_hz16_size(600, 45, 2, 2, "请你首先选择添加相片框！", 0, "HZK\\Hz16");
				delay(1000);
				bar1(580, 45, 972, 87, 0x7F50);
			}
			else
			{
				bar1(580, 45, 865, 87, 0xC618);
				prt_hz16_size(600, 45, 1, 1, "您刚刚选择了文本框，请您选择下一", 0, "HZK\\Hz16");
				prt_hz16_size(600, 70, 1, 1, "个的标题框。", 0, "HZK\\Hz16");
				delay(1000);
				bar1(580, 45, 900, 87, 0x7F50);
			}
		}
		//梯形1
		if (MousePress(665, 400, 780, 440) == 1 && select == 0 && Getpixel64k(667, 402) == 0x03FF && itemx <= 20 )
		{
			if ((graph1[itemx - 1].shape == 6||itemx==1 ||graph1[itemx - 1].shape == 1 || graph1[itemx - 1].shape == 5) && itemx > 0)
			{
				bar1(850, 600, 1024, 768, 0x7F50);
				graph1[itemx].shape = 3;
				presstime = 1;
				select = 1;
			}
			else if (itemx == 0)
			{
				bar1(580, 45, 972, 87, 0xC618);
				prt_hz16_size(600, 45, 2, 2, "请你首先选择添加相片框！", 0, "HZK\\Hz16");
				delay(1000);
				bar1(580, 45, 972, 87, 0x7F50);
			}
			else
		{
			bar1(580, 45, 865, 87, 0xC618);
			prt_hz16_size(600, 45, 1, 1, "您刚刚选择了文本框，请您选择下一", 0, "HZK\\Hz16");
			prt_hz16_size(600, 70, 1, 1, "个的标题框。", 0, "HZK\\Hz16");
			delay(1000);
			bar1(580, 45, 900, 87, 0x7F50);
		}
		}
		//梯形2
		if (MousePress(665, 470, 780, 510) == 1 && select == 0 && Getpixel64k(667, 472) == 0x03FF && itemx <= 20 )
		{
			if ((graph1[itemx - 1].shape == 6||itemx==1 || graph1[itemx - 1].shape == 1 || graph1[itemx - 1].shape == 5) && itemx > 0)
			{
				bar1(850, 600, 1024, 768, 0x7F50);
				graph1[itemx].shape = 4;
				presstime = 1;
				select = 1;
			}
			else if (itemx == 0)
			{
				bar1(580, 45, 972, 87, 0xC618);
				prt_hz16_size(600, 45, 2, 2, "请你首先选择添加相片框！", 0, "HZK\\Hz16");
				delay(1000);
				bar1(580, 45, 972, 87, 0x7F50);
			}
			else
		{
			bar1(580, 45, 865, 87, 0xC618);
			prt_hz16_size(600, 45, 1, 1, "您刚刚选择了文本框，请您选择下一", 0, "HZK\\Hz16");
			prt_hz16_size(600, 70, 1, 1, "个的标题框。", 0, "HZK\\Hz16");
			delay(1000);
			bar1(580, 45, 900, 87, 0x7F50);
		}
		}
		//直线
		if (MousePress(670, 578, 770, 582) == 1 && select == 0 && itemx <= 20)
		{
			if (itemx > 0)
			{
				bar1(850, 600, 1024, 768, 0x7F50);
				graph1[itemx].shape = 5;
				presstime = 1;
				select = 1;
			}
			else if (itemx == 0)
			{
				bar1(580, 45, 972, 87, 0xC618);
				prt_hz16_size(600, 45, 2, 2, "请你首先选择添加相片框！", 0, "HZK\\Hz16");
				delay(1000);
				bar1(580, 45, 972, 87, 0x7F50);
			}
		}
		//相片狂
		if (MousePress(680, 600, 760, 700) == 1 && Getpixel64k(682,602) == 0x03FF && select == 0 && itemx ==0)
		{
			bar1(850, 600, 1024, 768, 0x7F50);
			graph1[itemx].shape = 7;
			presstime = 1;
			select = 1;
			savetime = 0;
		}

		if (graph1[itemx].shape == 6)
			bar_control(graph1, &select, &presstime, &itemx);
		if (graph1[itemx].shape == 1)
			circle_control(graph1, &select, &presstime, &itemx);
		if (graph1[itemx].shape == 2)
			ellipse_control(graph1, &select, &presstime, &itemx);
		if (graph1[itemx].shape == 3)
			ladder1_control(graph1, &select, &presstime, &itemx);
		if (graph1[itemx].shape == 4)
			ladder_control(graph1, &select, &presstime, &itemx);
		if (graph1[itemx].shape == 5)
			line_control(graph1, &select, &presstime, &itemx);
		if (graph1[itemx].shape == 7)
			photo_control(graph1, &select, &presstime, &itemx);
		if(MousePress(46 + 510 + 5, 0, 140 + 510, 30) == 1)
		{
			if(savetime==1||savetime==-1)    return -2;
			else
			{
				bar1(580, 45, 902, 87, 0xC618);
				prt_hz16_size(600, 45, 2, 2, "您当前简历未保存！", 0, "HZK\\Hz16");
				delay(1000);
				bar1(580, 45, 972, 87, 0x7F50);
			}
		}
		if(MousePress(974, 30, 1024, 60) == 1)
		{
			if (savetime == 1 || savetime == -1)    return -1;
			else
			{
				bar1(580, 45, 902, 87, 0xC618);
				prt_hz16_size(600, 45, 2, 2, "您当前简历未保存！", 0, "HZK\\Hz16");
				delay(1000);
				bar1(580, 45, 972, 87, 0x7F50);
			}
		}

	}
}
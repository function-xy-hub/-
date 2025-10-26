/**********************************************
   ���ļ���ΪһЩͼ����ʾ������������
   ���л�һ��ֱ��line �ͻ�ʵ��Բ����Ϊ�ο����� �������ܴ����� 
   �״α���ʱ��8��23��
   �����ˣ�������

   ��һ�θĶ�ʱ�䣺9��13�� ����0x117��ʾģʽ
***********************************************/

#include"SVGAmode.h"

/*BMP�ļ�ͷ�ṹ*/
typedef struct tagBITMAPFILEHEADER
{
	int	bfType;	         /*  ͨ���� 'BM' �����������ƺ��ж� OS/2 �ı�ʶ����ʲô����*/
	long	 bfSize;	/*  �ļ���С�����ֽ�Ϊ��λ*/
	int	bfReserved1;	/*��������������Ϊ 0*/
	int	bfReserved2;	/*��������������Ϊ 0*/
	long	bfOffBits;
} BITMAPFILEHEADER ;

/*BMP��Ϣͷ�ṹ*/
typedef struct tagBITMAPINFOHEADER
{
	long	biSize;	/* ��Ϣͷ��С */
	long	biWidth;	/* ͼ����� */
	long	biHeight;	/* ͼ��߶� */
	int   	biPlanes;	/*  ����Ϊ 1 */
	int	    biBitCount;	/*  ÿ����λ���������� 1, 4, 8 �� 24 */
	long	biCompression;	/*  ѹ������ */
	long	biSizeImage;	/* ʵ��ͼ���С�������� 4 �ı��� */
	long	biXPelsPerMeter;	/*  ˮƽ����ÿ�������� */
	long	biYPelsPerMeter;	/*  ��ֱ����ÿ��������*/
	long	biClrUsed;	/*  ������ɫ��*/
	long	biClrImportant;	/* ��Ҫ����ɫ�� */
} BITMAPINFOHEADER;

typedef struct tagRGBQUAD
{
	unsigned char B;	/*��ɫ������RED��д*/
	unsigned char G;	/*��ɫ������GREEN��д*/
	unsigned char R;	/*��ɫ������BLUE��д*/
	unsigned char reserved;		/*������*/
} RGBQUAD;


/***********************************************/
/*��dos.h��REGS�Ķ������£�
	struct WORDREGS
	{
		unsigned int ax, bx, cx, dx, si, di, cflag, flags;
	};

	struct BYTEREGS
	{
		unsigned char al, ah, bl, bh, cl, ch, dl, dh;
	};

	union REGS
	{
		struct WORDREGS x;
		struct BYTEREGS h;
	};
**************************************************/

/**************************************************************
����˵�����ӳٺ���
����˵����xΪ�ӳ�ʱ��
�޷���ֵ
**************************************************************/
 void delay0(int x)
 {
 	int i,j,k;
 	for(i=0;i<x;i++)
 	{
		for (j = 0; j < 1100; j++);
		
	}
 } 

/*����SVGA��ʾģʽ 1024*768 256*/
void  SetSVGA256()
{

  union REGS in;
  in.x.ax=0x4f02;
  in.x.bx=0x105;           /*1024*768*256��Ӧ��ģʽ���*/
  int86(0x10,&in,&in);
  if(in.x.ax!=0x004f)     /*(1)���ܵ��óɹ�������AX = 004Fh��
							 (2)��֧�ָù��ܣ�һ�㷵��AX = 4F00h��
							 (3)֧�ָù��ܵ��ù��ܵ���ʧ�ܣ�����AX = 014Fh*/
  {
   printf("There is an error in setting SVGA256,0x%x\n",in.x.ax);
   exit(1);
  }
}



/*����SVGA��ʾģʽ 1024*768 64k*/
void  SetSVGA64k()
{

  union REGS in;
  in.x.ax=0x4f02;
  in.x.bx=0x117;           /*1024*768*64k��Ӧ��ģʽ���*/
  int86(0x10,&in,&in);
  if(in.x.ax!=0x004f)     /*(1)���ܵ��óɹ�������AX = 004Fh��
							 (2)��֧�ָù��ܣ�һ�㷵��AX = 4F00h��
							 (3)֧�ָù��ܵ��ù��ܵ���ʧ�ܣ�����AX = 014Fh*/
  {
   printf("There is an error in setting SVGA256,0x%x\n",in.x.ax);
   exit(1);
  }
}



/***********************************************
  ����˵������õ�ǰSVGA��ʾģʽ����Ϣ
  ���ز���˵�����õ���ʾģʽ��
************************************************/
unsigned int GetSVGA(void)
{
 union REGS out;
 out.x.ax=0x4f03;
 int86(0x10,&out,&out);
 if(out.x.ax!=0x004f)
 {
  printf("there is an error 0x%x\n",out.x.ax);
  exit(1);
 }
 return(out.x.bx);
}
/****************************************************/

/*��ȡSVGA��ʾģʽ��bx��ժ¼���õ�ģʽ�����£�
				ģʽ��		�ֱ���		��ɫ��
				0x101		640*480		256
				0x103		800*600		256
				0x104		1024*768	16
				0x105		1024*768	256
				0x110		640*480		32K
				0x111		640*480		64K
				0x112		640*480		16.8M
				0x113		800*600		32K
				0x114		800*600		64K
				0x115		800*600		16.8M
				0x116		1024*768	32K
				0x117		1024*768	64K
				0x118		1024*768	16.8M
 ******************************************************/


 /******************************************************
 ����˵�����Դ滻ҳ
 ����˵��: page ,ҳ���
 ********************************************************/
unsigned int SelectPage(unsigned char page)
{
	union REGS r;
	static unsigned char old_page = 0;    
	static unsigned char flag = 0;
	r.x.ax = 0x4f05;
	r.x.bx = 0;
	if (flag == 0)
	{
		old_page = page;
		r.x.dx = page;
		int86(0x10, &r, &r);
		flag++;
	}
	if (page != old_page)
	{
		old_page = page;
		r.x.dx = page;
		int86(0x10, &r, &r);
	}

	return 0;
}
 /********************************************************/

 /********************************************************
	����˵�� �����㺯��
	����˵����x,y ��Ҫ����λ�� color ��ɫ
**********************************************************/
   void   putpixel(int x,int y,int color)
 {
  unsigned char far*VideoBuffer=(unsigned char far*)0xa0000000L;
  unsigned long int pos;
  register int Newpage=0;
  /*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ���� */
  pos=((unsigned long int)y<<10)+x;
  Newpage=pos>>16;
  SelectPage(Newpage);
  VideoBuffer[pos]=color;
  }
/**********************************************************
  ����˵�����õ�ĳ�����ɫֵ��
  ����˵����x,yΪ�õ�����ꣻ
  ����ֵ��colorΪ�õ����ɫֵ
***********************************************************/ 

int  getpixel1(int x,int y)
 {
  int color;
  unsigned char far*VideoBuffer=(unsigned char far*)0xa0000000L;
  unsigned long int pos;
  register int Newpage=0;
  /*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ���� */
  pos=((unsigned long int)y<<10)+x;
  Newpage=pos>>15;
  SelectPage(Newpage);
  color=VideoBuffer[pos];
  return color;
  }

  
  
 /*******************************************************
 ����˵����  ��򻭵㺯��
 ����˵����   x,yΪ����λ�ã�color Ϊ������ɫ
 ����ֵ��    ��
/**********************************************************/
void Xorpixel (int x, int y, int color)
{
	/*�Դ�ָ�볣����ָ���Դ��׵�ַ��ָ�뱾���������޸�*/
	unsigned int far * const video_buffer = (unsigned int far *)0xa0000000L;

	/*Ҫ�л���ҳ���*/
	unsigned char newpage = 0;

	unsigned char oldpage;
	/*��Ӧ�Դ��ַƫ����*/
	unsigned long int page;

	/*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ����*/
	page = ((unsigned long int)y << 10) + x;
	newpage = page >> 15;	                          /*32k����һ��ҳ������32k������㷨*/

	
		SelectPage(newpage);


	/*���Դ�д����ɫ����Ӧ�㻭��*/
	video_buffer[page] = video_buffer[page]^color;
}

/*************************************************************
���ܺ�������64k��ģʽ����
����˵���������λ��
����ֵ˵���� �޷���
***************************************************************/
void Putpixel64k(int x, int y,  int color)
{
	if(x>=0&&x<=1024&&y>=0&&y<=768)
	{
	/*�Դ�ָ�볣����ָ���Դ��׵�ַ��ָ�뱾���������޸�*/
	unsigned int far * const video_buffer = (unsigned int far *)0xa0000000L;
	
	/*Ҫ�л���ҳ���*/
	unsigned char newpage=0;
	
//	unsigned char oldpage=0;
	/*��Ӧ�Դ��ַƫ����*/
	unsigned long int page;

	
	/*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ����*/
	page = ((unsigned long int)y << 10) + x;
	newpage = page >> 15;	/*32k����һ��ҳ������32k������㷨*/
	

		SelectPage(newpage);

	
	
	/*���Դ�д����ɫ����Ӧ�㻭��*/
	video_buffer[page] = color;	
    }
}

/***********************************************************
	����˵������Ӳ�̶�ȡ8λBMPֱ�ӵ��Դ�
	����˵����x��y����  name���ļ�·��
	����ֵ˵����
/***********************************************************/

int   Readbmp256(int x,int y,char * path)
{
   FILE *fp;                   //ָ��ͼƬ�ļ����ļ�ָ��
   RGBQUAD * pc01;       //bmp��ɫ���ṹָ��
   unsigned char *buf;         //�����ػ���ָ��
   long int wide,high;         //ͼƬ���ȣ�����
   long int perline;          //һ��������ռ�ֽ�
   unsigned long int clrused;  //ʵ���õ���ɫ��
   int i,j;
   unsigned int bitcount;

   if((fp=fopen(path,"rb"))==NULL)
   {
	printf("there file can't open\n");
	delay(5000);
	exit(1);
	}


	fseek(fp,28L,0);          /*���ж��ǲ���8λBMP*/
	fread(&bitcount,2,1,fp);
	if(bitcount!=8)
	{
	 printf("it is not 8");
	 delay(5000);
	 return 0;
	}


	fseek(fp,18L,0);         /*���ļ�ָ���ƶ���������ȵ�λ�ò���ȡ����*/
	fread(&wide,4,1,fp);
	fread(&high,4,1,fp);

	perline=(wide*8+31)/8;   /*һ��ɨ������ռ���ֽ�����������4�ı���*/
	perline=perline/4*4;

	fseek(fp,46l,0);          /*�õ�ʵ��ʹ����ɫ*/
	fread(&clrused,4,1,fp);

	if(clrused==0)
	{
	 clrused=1U<<8;
	}

	if((pc01=(RGBQUAD*)malloc(4L*clrused))==NULL)   /*����ʹ����ɫ����������ռ�*/
	{
	 printf("the color is wrong");
	 delay(5000); 
	 return 0;
	}
	
	fseek(fp,54L,0);            /*��ȡ��ɫ������*/
	fread(pc01,4L*clrused,1,fp); 
	
	for(i=0;i<clrused;i++,pc01++)
	{
	 outportb(0x3c8,i);
	 outportb(0x3c9,pc01->R>>2);
	 outportb(0x3c9,pc01->G>>2);
	 outportb(0x3c9,pc01->B>>2);
	}
	free(pc01);

	buf=(unsigned char *)malloc(perline);
	if(buf==NULL)  /*���䶯̬���������ݴ���ռ�*/
	{
	 return 0;
	}
	
	fseek(fp,54L+4L*clrused,0);              /*��ÿ�е�������Ϣ����ʾ����*/
	for(i=high;i>-1;i--)
	{
	 fread(buf,perline,1,fp);
	  for(j=0;j<wide;j++)
	  {
	   putpixel(x+j,i+y,buf[j]);
	   }
	}
  free(buf);
  fclose(fp);
  return 1;
 }

 /******************************************************************/

  /******************************************************************
   ����˵������ˮƽ�ߺ���
   ����˵����x0,y0 ��ʼ����   x1,y1��ֹ����  thick ���  color ��ɫ
   �޷���ֵ
 *******************************************************************/
  void linelevel(int x0,int y0,int x1,int y1,int thick,int color)
  {
   int i,j,k;
   if(x0>x1)                                       /*ȷ��x0Ϊ��С��һ��*/
   {
	k=x0;
	x0=x1;
	x1=k;
   }

   if(x1<=0||x1>=1024||y1<=0||y1>=768||x1>=1024)  /*ȷ����������Ļ��Χ֮��*/
	{
		printf("the line is beyond the screen!");
		return;
	}

   for(i=0;i<thick;i++)
   {
	for(j=0;j<x1-x0;j++)
	{
		Putpixel64k(x0+j,y0+i,color);
	}
   }
 }

/**************************************************************/



/***************************************************************
   ����˵���������ߺ���
   ����˵����x0,y0 ��ʼ����   x1,y1��ֹ����  thick ���  color ��ɫ
   �޷���ֵ
***************************************************************/
void linever(int x0,int y0,int x1,int y1,int thick,int color)
  {
	int   i = 0;
	int   j = 0;
	int   k=0;
   int high;
   high = y1 - y0;
  /* if(y0>y1)                                       ȷ��y0Ϊ��С��һ��
   {
	k=y0;
	y0=y1;
	y1=k;
   }  
   */
   if(x1<=0||x1>=1024||y1<=0||y1>=768||x1>=1024)  /*ȷ����������Ļ��Χ֮��*/
	{
		printf("the line is beyond the screen!");
		return;
	}

   for(i=0;i<thick;i++)
   {
	for(j=0;j<high;j++)
	{
		Putpixel64k(x0+i,y0+j,color);
	}
   }
 }


/**********************************************************/


/**********************************************************
Function��		Horizline

Description��	��ˮƽ�ߺ���
���Խ��ճ�����Ļ��Χ�����ݣ�ֻ��������Ļ�ڲ���
��Ϊû�з�ֹ���ͱ���������жϣ���������Ļ����ʱӦ��ֹ�����ش�����

Calls��			Selectpage

Called By��		Line
Bar
Circlefill

Input��			int x					��ʼ������꣬���������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
int y					��ʼ�������꣬���ϵ������ӣ�0Ϊ��Сֵ����Ļ�ο�ϵ��
int width				ˮƽ���ȣ�Ϊ���������죬Ϊ����������
unsigned char color		��ɫ��������256��

Output��		��Ļ�ϻ���ˮƽ��

Return��		None
Others��		None
**********************************************************/
void Horizline(int x, int y, int width, int  color)
{
	/*�Դ�ָ�볣����ָ���Դ��׵�ַ��ָ�뱾���������޸�*/
	unsigned int  far * const video_buffer = (unsigned int  far *)0xa0000000L;

	/*Ҫ�л���ҳ���*/
	unsigned char new_page = 0;

//	unsigned char old_page = 0;
	/*��Ӧ�Դ��ַƫ����*/
	unsigned long int page;

	/*i��x����ʱ����������ѭ������*/
	int i;

	/*�ж����췽������ʼ�㿿��*/
	if (width < 0)
	{
		x = x + width;
		width = -width;
	}

	i = x;

	/*ʡ�Գ�����Ļ��߲���*/
	if (x < 0)
	{
		x = 0;
		width += i;
	}

	/*����������Ļ��ʱ�˳�*/
	if (x >= 1024)
	{
		return;
	}

	/*����������Ļ��ʱ�˳�*/
	if (y < 0 || y >= 768)
	{
		return;
	}

	/*ʡ�Գ�����Ļ�ұ߲���*/
	if (x + width > 1024)
	{
		width = 1024 - x;
	}

	/*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ����*/
	page = ((unsigned long int)y << 10) + x;
	new_page = page >> 15;
	
		SelectPage(new_page);
	


	/*���Դ�д����ɫ��ˮƽ�߻���*/
	for (i = 0; i < width; i++)
	{
		*(video_buffer + page + i) = color;
	}
}


/************************************************************
   ����˵������ˮƽ���κ���
   ����˵��: x0,y0 ���Ͻ�����   x1,y1���½����� color ��ɫ
************************************************************/
void bar(int x0, int y0, int x1, int y1, int color)
{

	int i;

	int wide;                /*������εĳ��Ϳ�*/
	wide = x1 - x0;


	for (i = y0; i <= y1; i++)
	{
		Horizline(x0, i, wide, color);
	}
}


/**************************************************************
 ����˵������(x,y)��ΪԲ�ģ���radiusΪ�뾶��Բ��û�з�ֹ������Ļ���жϣ�
 ���Խ�û�г����Ĳ��ֻ�����
 ����˵����x,yΪԲ�㣬radius Ϊ�뾶��colorΪ��ɫ��
 �޷���ֵ��
 **************************************************************/
 void circle1(int x0,int y0,int radius,int color)
 {
  
	int x, y, d;
	y = radius;
	d = 3 - radius << 1;
	
	for (x = 0; x <= y; x++)
	{
		Putpixel64k(x0 + x, y0 + y, color);
		Putpixel64k(x0 + x, y0 - y, color);
		Putpixel64k(x0 - x, y0 - y, color);
		Putpixel64k(x0 - x, y0 + y, color);
		Putpixel64k(x0 + y, y0 + x, color);
		Putpixel64k(x0 + y, y0 - x, color);
		Putpixel64k(x0 - y, y0 - x, color);
		Putpixel64k(x0 - y, y0 + x, color);
		
		if (d < 0)
		{
			d += x * 4 + 6;
		}
		
		else
		{
			d += (x - y) * 4 + 10;
			y--;
		}
	}
}






/**************************************************************************
      ����˵������ʵ��Բ
      ����˵����x,yΪԲ��
     �޷���ֵ
**************************************************************************/
 void FillCircle(int x, int y, int r, int color)
{
	int tx = 0, ty = r, d = 3 - 2 * r, i;

	while( tx < ty)
	{
		// ��ˮƽ��������(<45��)
		for (i = x - ty; i <= x + ty; i++)
		{
			Putpixel64k(i, y - tx, color);
			if (tx != 0)	// ��ֹˮƽ���ظ�����
				Putpixel64k(i, y + tx, color);
		}

		if (d < 0)			// ȡ����ĵ�
			d += 4 * tx + 6;
		else				// ȡ����ĵ�
		{
			// ��ˮƽ��������(>45��)
			for (i = x - tx; i <= x + tx; i++)
			{
				Putpixel64k(i, y - ty, color);
				Putpixel64k(i, y + ty, color);
			}

			d += 4 * (tx - ty) + 10, ty--;
		}

		tx++;
	}

	if (tx == ty)			// ��ˮƽ��������(=45��)
		for (i = x - ty; i <= x + ty; i++)
		{
			Putpixel64k(i, y - tx, color);
			Putpixel64k(i, y + tx, color);
		}
}


/*************************************************/


 unsigned int Getpixel64k(int x, int y)
 {
	 /*�Դ�ָ�볣����ָ���Դ��׵�ַ��ָ�뱾���������޸�*/
	 unsigned int far * const video_buffer = (unsigned int far *)0xa0000000L;

	 /*Ҫ�л���ҳ���*/
	 unsigned char new_page;

	 /*��Ӧ�Դ��ַƫ����*/
	 unsigned long int page;

	 /*�жϵ��Ƿ�����Ļ��Χ�ڣ����ھ��˳�*/
	 if (x < 0 || x >(1024 - 1) || y < 0 || y >(768 - 1))
	 {
		 return 0;
	 }

	 /*�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ����*/
	 page = ((unsigned long int)y << 10) + x;
	 new_page = page >> 15;	/*32k����һ��ҳ������32k������㷨*/
	 SelectPage(new_page);

	 /*������ɫ*/
	 return video_buffer[page];
 }

/**********************************************************************
   ����˵������ȡ24λͼƬ
   ����˵����X,Y ͼƬλ�� ��name Ϊ·��
   ����ֵ�� ����0Ϊʧ�ܣ�1Ϊ�ɹ�
************************************************************************/ 
int Putbmp64k(int x, int y, const char * path)
{
	/*ָ��ͼƬ�ļ����ļ�ָ��*/
	FILE * fpbmp;

	/*�����ػ���ָ��*/
	WESHEN * buffer;

	/*ͼƬ�Ŀ��ȡ��߶ȡ�һ��������ռ�ֽ�������������ֽڣ�*/
	long int width, height, linebytes;

	/*ѭ������*/
	int i, j;

	/*ͼƬλ��*/
	unsigned int bit;

	/*ѹ��������*/
	unsigned long int compression;

	/*���ļ�*/
	if ((fpbmp = fopen(path, "rb")) == NULL)
	{
		return -1;
	}

	/*��ȡλ��*/
	fseek(fpbmp, 28L, 0);
	fread(&bit, 2, 1, fpbmp);

	/*��24λͼ���˳�*/
	if (bit != 24U)
	{
		return -1;
	}

	/*��ȡѹ������*/
	fseek(fpbmp, 30L, 0);
	fread(&compression, 4, 1, fpbmp);

	/*����ѹ���㷨���˳�*/
	if (compression != 0UL)
	{
		return -1;
	}

	/*��ȡ���ȡ��߶�*/
	fseek(fpbmp, 18L, 0);
	fread(&width, 4, 1, fpbmp);
	fread(&height, 4, 1, fpbmp);


	/*����һ������ռ�ֽ�������������Ŀ��ֽ�*/
	linebytes = (3 * width) % 4;

	if(!linebytes)
	{
		linebytes = 3 * width;
	}
	else
	{
		linebytes = 3 * width + 4 - linebytes;
	}

	/*�������������ݶ�̬����ռ�*/
	if ((buffer = (WESHEN *)malloc(linebytes)) == 0)
	{
		return -1;
	}

	/*��ɨ����ʽ��ȡͼƬ���ݲ���ʾ*/
	fseek(fpbmp, 54L, 0);
	for (i = height - 1; i > -1; i--)
	{
		fread(buffer, linebytes, 1, fpbmp);	/*��ȡһ����������*/

		/*һ�����ص����ݴ����ͻ���*/
		for (j = 0; j < width; j++)
		{
			/*0x117ģʽ�£�ԭͼ��������8λ�ֱ����Ϊ5λ��6λ��5λ*/
			buffer[j].R >>= 3;
			buffer[j].G >>= 2;
			buffer[j].B >>= 3;
			Putpixel64k(j + x, i + y,
			((((unsigned int)buffer[j].R) << 11)
			| (((unsigned int)buffer[j].G) << 5)
			| ((unsigned int)buffer[j].B)));	/*����������ɫ���������Ӹ�λ����λ����*/
		}
	}

	free(buffer);
	fclose(fpbmp);
	return 0;
}




int Putbmp64k00(int x, int y, const char * path)
{
	/*ָ��ͼƬ�ļ����ļ�ָ��*/
	FILE * fpbmp;

	/*�����ػ���ָ��*/
	WESHEN * buffer;

	/*ͼƬ�Ŀ��ȡ��߶ȡ�һ��������ռ�ֽ�������������ֽڣ�*/
	long int width, height, linebytes;

	/*ѭ������*/
	int i, j;

	/*ͼƬλ��*/
	unsigned int bit;

	/*ѹ��������*/
	unsigned long int compression;

	/*���ļ�*/
	if ((fpbmp = fopen(path, "rb")) == NULL)
	{
		return -1;
	}

	/*��ȡλ��*/
	fseek(fpbmp, 28L, 0);
	fread(&bit, 2, 1, fpbmp);

	/*��24λͼ���˳�*/
	if (bit != 24U)
	{
		return -1;
	}

	/*��ȡѹ������*/
	fseek(fpbmp, 30L, 0);
	fread(&compression, 4, 1, fpbmp);

	/*����ѹ���㷨���˳�*/
	if (compression != 0UL)
	{
		return -1;
	}

	/*��ȡ���ȡ��߶�*/
	fseek(fpbmp, 18L, 0);
	fread(&width, 4, 1, fpbmp);
	fread(&height, 4, 1, fpbmp);


	/*����һ������ռ�ֽ�������������Ŀ��ֽ�*/
	linebytes = (3 * width) % 4;

	if(!linebytes)
	{
		linebytes = 3 * width;
	}
	else
	{
		linebytes = 3 * width + 4 - linebytes;
	}

	/*�������������ݶ�̬����ռ�*/
	if ((buffer = (WESHEN *)malloc(linebytes)) == 0)
	{
		return -1;
	}

	/*��ɨ����ʽ��ȡͼƬ���ݲ���ʾ*/
	fseek(fpbmp, 54L, 0);
	for (i = height - 1; i > -1; i--)
	{
		fread(buffer, linebytes, 1, fpbmp);	/*��ȡһ����������*/

		/*һ�����ص����ݴ����ͻ���*/
		for (j = 0; j < width; j++)
		{
			/*0x117ģʽ�£�ԭͼ��������8λ�ֱ����Ϊ5λ��6λ��5λ*/
			buffer[j].R >>= 3;
			buffer[j].G >>= 2;
			buffer[j].B >>= 3;
			if(((((unsigned int)buffer[j].R) << 11)
			| (((unsigned int)buffer[j].G) << 5)
			| ((unsigned int)buffer[j].B))!=0xffff)
			{
			
			Putpixel64k(j + x, i + y,
			((((unsigned int)buffer[j].R) << 11)
			| (((unsigned int)buffer[j].G) << 5)
			| ((unsigned int)buffer[j].B)));
			}	/*����������ɫ���������Ӹ�λ����λ����*/
		}
	}

	free(buffer);
	fclose(fpbmp);
	return 0;
}



/**************************************************
                9��26�ձ�д
function:       get_image

description:     �õ�һƬ�����ͼ����Ϣ

Input:          x0,y0,���Ͻ���ʼ���꣬X1,Y2���½����꣬save ָ��洢��Ϣ������

out:              �����
**************************************************************/

void    get_image(int x0,int y0,int x1,int y1,unsigned int far *save)
{
	
	int i=0;                                   /*ѭ������*/
	int j=0;
	int wide=x1-x0;
    int high=y1-y0;	
	
	unsigned   int far *VideoBuffer=(unsigned int far *)0xa0000000L  ;
	
	long int newpage=0;
//    long int oldpage=0;
	
	unsigned long pos;

	for(i=0;i<high;i++)
	{
		for(j=0;j<x1-x0;j++)
		{

		   pos=((unsigned long)(y0+i)<<10)+x0+j;

		   newpage=pos>>15 ;                         /*����32k������㷨*/

			
			 SelectPage(newpage);
			
			save[i*wide+j]=VideoBuffer[pos];

		}
	}

}



/**************************************************
				9��26�ձ�д
function:       put_image

description:     ��ʾ���洢�ռ��ͼ����Ϣ

Input:          x0,y0,���Ͻ���ʼ���꣬X1,Y2���½����꣬save ָ��洢��Ϣ������

out:              �����
**************************************************************/

void    put_image(int x0,int y0,int x1,int y1,unsigned int far *save)
{

	int i=0;                                   /*ѭ������*/
	int j=0;

	int wide=x1-x0;
	int high=y1-y0;

	unsigned   int far *VideoBuffer=(unsigned int far *)0xa0000000L ;

	long int newpage=0;
//	long int  oldpage=0;

	unsigned long pos;

	for(i=0;i<high;i++)
	{
		for(j=0;j<x1-x0;j++)
		{   
	        
	      pos=((unsigned long)(y0+i)<<10)+x0+j;
	
	      newpage=pos>>15 ;                         /*����32k������㷨*/
	
	      
			  SelectPage(newpage);
			

			VideoBuffer[pos]=save[i*wide+j];
		
		}
	}


}


/**************************************************
10��26�ձ�д
function:       save_image

description:    ��ʾ���洢�ռ��ͼ����Ϣ

Input:          x0,y0,���Ͻ���ʼ���꣬X1,Y2���½�����,��ͼ����Ϣ�浽�ļ�����

out:            
**************************************************************/
void save_image(int x0, int y0, int x1, int y1)
{
	FILE * fp;                            /*�����ļ�ָ��*/
     
	int i = 0;                                   /*ѭ������*/
	int j = 0;
	int wide = x1 - x0;
	int high = y1 - y0;


	int save = 0;



	char fg[20] = "saveim";
	fp = fopen(fg, "wb");                  /*�������汳�����ļ�*/
	if (fp == NULL)
	{
		printf("the file cant creat\n");
		exit(1);
	}


	for (i = 0; i<high; i++)
	{
		for (j = 0; j<wide; j++)
		{

			save = Getpixel64k(x0+j,y0+i);
			fwrite(&save,sizeof(int),1,fp);

		}
	}

	fclose(fp);

}


/**************************************************
10��26�ձ�д
function:       printf_image

description:    ���ļ��ж�ȡ�����������

Input:          x0,y0,���Ͻ���ʼ���꣬X1,Y2���½�����,��ͼ����Ϣ���ǵ�������

out:
**************************************************************/

void  printf_image(int x0, int y0, int x1, int y1)
{
	FILE * fpo;                            /*�����ļ�ָ��*/

	int i = 0;                                   /*ѭ������*/
	int j = 0;
	int wide = x1 - x0;
	int high = y1 - y0;

	unsigned   int save = 0;

	char  fas[20]="saveim";
	fpo = fopen(fas, "rb");                  /*�������汳�����ļ�*/
	if (fpo == NULL)
	{
		printf("the file cant creat\n");
		exit(1);
	}


	for (i = 0; i<high; i++)
	{
		for (j = 0; j<wide; j++)
		{

		 
			fread(&save,sizeof(int),1,fpo);
			Putpixel64k(x0 + j, y0 + i, save);

		}
	}

	fclose(fpo);

}


/**************************************************
10��26�ձ�д
function:       save_image

description:    ��ʾ���洢�ռ��ͼ����Ϣ

Input:          x0,y0,���Ͻ���ʼ���꣬X1,Y2���½�����,��ͼ����Ϣ�浽�ļ�����

out:            
**************************************************************/
void save_image0(int x0, int y0, int x1, int y1)
{
	FILE * fp;                            /*�����ļ�ָ��*/
     
	int i = 0;                                   /*ѭ������*/
	int j = 0;
	int wide = x1 - x0;
	int high = y1 - y0;


	int save = 0;



	char fg[20] = "saveim0.dat";
	fp = fopen(fg, "wb+");                  /*�������汳�����ļ�*/
	if (fp == NULL)
	{
		printf("the file cant creat\n");
		exit(1);
	}


	for (i = 0; i<high; i++)
	{
		for (j = 0; j<wide; j++)
		{

			save = Getpixel64k(x0+j,y0+i);
			fwrite(&save,sizeof(unsigned int),1,fp);

		}
	}

	fclose(fp);

}


/**************************************************
10��26�ձ�д
function:       printf_image

description:    ���ļ��ж�ȡ�����������

Input:          x0,y0,���Ͻ���ʼ���꣬X1,Y2���½�����,��ͼ����Ϣ���ǵ�������

out:
**************************************************************/

void  printf_image0(int x0, int y0, int x1, int y1)
{
	FILE * fpo;                            /*�����ļ�ָ��*/

	int i = 0;                                   /*ѭ������*/
	int j = 0;
	int wide = x1 - x0;
	int high = y1 - y0;

	unsigned   int save = 0;

	char  fas[20]="saveim0.dat";
	fpo = fopen(fas, "rb+");                  /*�������汳�����ļ�*/
	if (fpo == NULL)
	{
		printf("the file cant creat\n");
		exit(1);
	}


	for (i = 0; i<high; i++)
	{
		for (j = 0; j<wide; j++)
		{

		 
			fread(&save,sizeof(unsigned int),1,fpo);
			Putpixel64k(x0 + j, y0 + i, save);

		}
	}

	fclose(fpo);

}










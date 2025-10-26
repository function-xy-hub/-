#ifndef _CONTENT_H_
#define _CONTENT_H_



#include <stdio.h>
#include"hz.h"
#include"mouse.h"
#include"tpl.h"
#include"SVGAmode.h" 
#include"ulist.h"
#include"mainpage.h"
#include<string.h>




void content(int p,int num,struct BASIC *basic);
int con_tent(int p,int num,struct BASIC *basic);
int putput1(int x,int y,int xsize,int ysize,char *s,unsigned int color,int x1,int d,unsigned int bkcolor) ;
void inset();
void ppaagg1(int y1);
void ppaagg2(int x1,int y1,int x2,int y2);
void txtlook(int p,int num,struct BASIC *basic);
int txt_look(int p,int num,struct BASIC *basic);
void txtout(int p,int num,struct BASIC *basic);
int txt_out (int p,int num,struct BASIC *basic);
void txtpage(struct BASIC *basic);
int putput2(int x,int y,int xsize,int ysize,char *s,unsigned int color,int x1,unsigned int bkcolor,int xx,int yy,int *hh,int *dd,int *tt);


#endif


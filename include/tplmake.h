#ifndef	_TPLMAKE_H_
#define	_TPLMAKE_H_


#include <stdio.h>
#include<string.h>
#include <dos.h>
#include <conio.h>
#include <stdlib.h>
#include<math.h>
#include"hz.h"
#include"mouse.h"
#include"draw.h"
#include"SVGAmode.h"
#include"tpl.h"
#include"mainpage.h" 


void display_tplpage(int p,int num,struct BASIC basic);
int create_tpl(struct BASIC *basic,graphitem*graph);
void mtpl_page(struct BASIC basic,graphitem*graph);
void drawitem1(graphitem *ap,struct BASIC basic);
void txtlook1(int p,int num, struct BASIC *basic,graphitem*graph );
int txt_look1(int p,int num,struct BASIC *basic);
void txtout1(int p,int num,struct BASIC *basic,graphitem*graph);
int txt_out1 (int p,int num,struct BASIC *basic,graphitem*graph);
void txtpage1(struct BASIC *basic);
void mtpl_page1(struct BASIC basic,graphitem*graph);

 #endif

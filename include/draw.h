#ifndef	_DRAW_H_
#define	_DRAW_H_


#include <stdio.h>
#include<string.h>
#include <dos.h>
#include <conio.h>
#include <stdlib.h>
#include<math.h>
#include"hz.h"
#include"mouse.h"
#include"login.h"
#include"SVGAmode.h"
#include"bepage.h"

typedef  struct graphitem
{
	int shape;
	int x0;
	int y0;
	int x1;
	int y1;
	int color;
	char title[15];
}graphitem;

void se_title();
void setcolor1(int m, graphitem* graph0, int* itemx);
void draw_(int p,int num);
int draw();
void youjiemian();
void colorform();
int Setcolorm();

void resize(graphitem* graph0, int* itemx);
void bar_control(graphitem* graph0,int *select,int *presstime,int* itemx);
void circle_control(graphitem* graph0, int* select, int* presstime, int* itemx);
void circle_control(graphitem* graph0, int* select, int* presstime, int* itemx);
void ladder1_control(graphitem* graph0, int* select, int* presstime, int* itemx);
void ladder_control(graphitem* graph0, int* select, int* presstime, int* itemx);
void photo_control(graphitem* graph0, int* select, int* presstime, int* itemx);
void line_control(graphitem* graph0, int* select, int* presstime, int* itemx);
void resize_bar();
void amplify(graphitem* graph0,int* itemx,int m);
void circle_amplify(graphitem* graph0, int* itemx,int m);
void circle_narrow(graphitem* graph0, int* itemx,int m);
void narrow(graphitem* graph0, int* itemx,int m);
void delete(graphitem* ap,int*itemx);
void shanglan();
void confirm(int *select, graphitem* ap);
void drawitem(graphitem *ap);
void save_bar();
void save_paint(graphitem* graph1,int*itemx,int*savetime);

 #endif

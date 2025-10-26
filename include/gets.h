#ifndef _GETS_H_
#define _GETS_H_

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<bios.h>
#include<dos.h>
#include<conio.h>
#include"SVGAmode.h"
#include"MOUSE.h"
#include"HZ.h"


#define ENTER   0x1c0d

/***�û���Ϣ�ṹ��***/
typedef struct person
{
	char user[10];
	char password[10];
	struct person *next;
}person;


/***����꺯��***/ 
void show_gb(int x,int y);
/***��Ϣ����ʱ��������ͬ����***/
void Getinfo(int x1,int y1,char *pm,int num);
/***��������ʱ��������ͬ����***/
void Getcode(int x1,int y1,char *code,int num);

void Getinfo1(int x1,int y1,char *name,int num,int xx,int yy,unsigned int bkcolor);
#endif

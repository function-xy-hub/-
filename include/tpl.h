#ifndef _TPL_H_
#define _TPL_H_

#include <stdio.h>
#include"hz.h"
#include"mouse.h"
#include"SVGAmode.h" 
#include"mainpage.h"
#include"selfin.h" 
#include"content.h"

typedef struct 
{

	char photo[20];
	
	char name[21];
	char sex[3];
	char age[3];
    char city[11];
	char zzmm[9];
	char mar[5];
	char phone[12];	
	char email[25];
	char txpp[20];
    int a;
    int edu; 
	int honor;
	int other;
    int object;
    int selfpj;
    int jobskill;
	int mod;
	char pa[25];
	int ap;
} BASIC;

 
 
 
void tpl1(int p,int num, BASIC basic);
int tpl_1( int p,int m,BASIC basic);
void tplpage1( BASIC basic);
void tpl2(int p,int num,BASIC basic);
int tpl_2(int p,int num,BASIC basic);
void tplpage2(BASIC basic);
void tpl3(int p,int num,BASIC basic);
int tpl_3(int p,int num,BASIC basic);
void tplpage3(BASIC basic);
int readput(int x1,int y1,int x2,char*path ,int *d,struct BASIC basic);
void amend(int xx,int yy,int *hh,int x1,int y1,int x2,char*path,struct BASIC basic,int *dd,int *tt,int *bb,int *aa);
void addin(int bb,int hh,struct BASIC *basic);
void delate(int bb,int hh,struct BASIC *basic);
#endif

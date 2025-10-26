#ifndef _DOUC_H_
#define _DOUC_H_

#include <stdio.h>
#include"hz.h"
#include"mouse.h"
#include"SVGAmode.h"

#include"mainpage.h"
#include<stdlib.h>
#include"tpl.h"

typedef struct
{
	char name[20];
	long time;
	int year;
	int month;
	int day;
	int hour;
	int min;
	int second;
	int size;
 } BmpFile;
 
int Document(int flag,BmpFile(*pbmpfile)[20]);
int FileListShow(int flag,int number,BmpFile bmpfile[20]);

void FindAllFile(int* number,int flag,BmpFile(*pbmpfile)[20]);



#endif

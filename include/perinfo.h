#ifndef _PERINFO_H_
#define __PERINFO_H


#include <stdio.h>
#include"hz.h"
#include"mouse.h"
#include"SVGAmode.h" 
#include"ulist.h"
#include"mainpage.h"
#include<stdlib.h>
#include"settings.h"
#include"tplmake.h"
#include"tpl.h" 
 
void perinfo(int p,int num,struct BASIC basic);
int sperinfo(int p);
void perpage(int p);
void jlck(int p,int num);
int ckjl();
#endif

//项目的主入口文件，负责初始化图形模式并启动应用程序。
#include<conio.h>

#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include "mouse.h"
#include "tpl.h"
#include "login.h"
#include "SVGAmode.h"



void main()
 {
   
    GetSVGA();
	SetSVGA64k();
    login_system();
	CloseSVGA();
 	exit(0);
	getchar();
  
}

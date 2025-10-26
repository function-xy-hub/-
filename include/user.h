#ifndef _USER_H
#define _USER_H


#include <stdio.h>
#include"hz.h"
#include"mouse.h"

#include"SVGAmode.h" 
#include"ulist.h"
#include"mainpage.h"

void user_opt();
int manage_user(int *p,int *usernum);
void user_page();
void UpdataUser(USER user);
void ReadAllUser(UserList *UL);
int Check_info(UserList UL,char name[10],char code[10]);


#endif

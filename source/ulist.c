/**********************************************
该文件主要完成用户线性表的一系列操作 
Function list : void InitUList(UserList*UL);
                void UListInsert(UserList*UL,struct USER e);
                void UListDelete(UserList*L,int i);
                void DestroyUList(UserList*UL);	
                int Userposition(UserList UL,USER e);
Attention:
Author:郑时涛
***********************************************/
#include "ulist.h"       // 确保头文件名大写且存在
#include <stdlib.h>      // 包含 malloc/realloc/free
#include <stdio.h>       // 包含 printf/exit
#include <string.h>      // 包含 strcmp
#include <conio.h>       // 包含 getch

/****************************
功能说明：建立一个线性表 
参数说明：线性表地址
返回值：  无  
****************************/
void InitUList(UserList *UL)  
{
    UL->elem = (USER *)malloc(U_LIST_INIT_SIZE * sizeof(USER));
    if (UL->elem == NULL) 
    {
        CloseSVGA();     // 假设 CloseSVGA 在外部定义
        printf("No enough memory!\n");
        exit(-1);
    }
    UL->length = 0;
    UL->listsize = U_LIST_INIT_SIZE;
}

/****************************
功能说明：在线性表L末尾插入元素 
参数说明：线性表地址，要插入的元素
返回值：  无  
****************************/
void UListInsert(UserList *UL, USER e) 
{
    USER *newbase = NULL;
    if (UL->length >= UL->listsize) 
    {
        newbase = (USER *)realloc(UL->elem, (UL->listsize + U_LIST_INCREMENT) * sizeof(USER));
        if (newbase == NULL) 
        {
            CloseSVGA();
            printf("No enough memory!\n");
            exit(-1);
        }
        UL->elem = newbase;
        UL->listsize += U_LIST_INCREMENT;
    }
    UL->elem[UL->length] = e;  // 使用数组下标替代指针运算
    UL->length++;
}

/****************************
功能说明：在线性表L中删除第i个元素
参数说明：线性表地址，要删除的元素位置
返回值：无 
****************************/
void UListDelete(UserList *L, int i) 
{
    USER *p = NULL;
    USER *q = NULL;
    if (i < 0 || i >= L->length) 
    {
        CloseSVGA();
        printf("ListDelete Wrong!");
        getch();
        exit(1);
    }
    p = L->elem + i;        // 被删除元素位置
    q = L->elem + L->length - 1; // 表尾元素
    for (p++; p <= q; p++) 
    {
        *(p - 1) = *p;      // 元素左移
    }
    L->length--;
}

/****************************
功能说明：销毁线性表L
参数说明：线性表地址
返回值：无 
****************************/
void DestroyUList(UserList *UL) 
{
    free(UL->elem);
    UL->listsize = 0;
    UL->length = 0;
}

/****************************
功能说明：得到元素E在线性表中的位置
参数说明：线性表，元素e 
返回值：元素位置（从0开始），未找到返回-1 
****************************/
int Userposition(UserList UL, USER e) 
{
    int i;
    for (i = 0; i < UL.length; i++) 
    {
        if (strcmp(e.name, UL.elem[i].name) == 0) 
        {
            return i;
        }
    }
    return -1;
}
#ifndef _ULIST_H_
#define _ULIST_H_

#include <conio.h>    // 控制台输入输出
#include <dos.h>      // DOS 相关函数
#include <bios.h>     // BIOS 功能
#include <stdlib.h>   // 标准库函数（malloc/realloc/free）
#include <stdio.h>    // 输入输出函数
#include <string.h>   // 字符串操作
#include "SVGAmode.H" // 图形模式头文件（确保路径正确）

/* 线性表初始容量 */
#define U_LIST_INIT_SIZE   10  // 初始用户容量
#define U_LIST_INCREMENT    1  // 容量不足时的增量

/* 用户信息结构体 */
typedef struct USER 
{
    char name[10];   // 用户名（最大10字符）
    char code[10];   // 用户密码
    char honesty;    // 信用等级（A-F，E/F为禁用状态）
    char state;      // 用户状态（F:冻结，T:正常）
    float wallet;    // 账户余额
}USER;

/* 用户线性表结构体 */
typedef struct UserList
{
    struct USER* elem;      // 用户数据动态数组指针
    int length;      // 当前用户数量
    int listsize;    // 线性表总容量
}UserList;

/* 函数声明 */
void InitUList(UserList *UL);                // 初始化线性表
void UListInsert(UserList *UL, USER e);      // 插入用户
void UListDelete(UserList *L, int i);        // 删除用户
void DestroyUList(UserList *UL);             // 销毁线性表
int Userposition(UserList UL, USER e);       // 查询用户位置

#endif
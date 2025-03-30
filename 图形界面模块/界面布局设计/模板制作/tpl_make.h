#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

// 定义常量
#define MAX_ITEMS 10
#define INPUT_LEN 50

// 数据结构定义
typedef struct 
{
    char name[INPUT_LEN];
    char phone[12];
    char email[INPUT_LEN];
    char gender[6];
} PersonalInfo;

typedef struct 
{
    char position[INPUT_LEN];
    char salary[INPUT_LEN];
} JobIntention;

typedef struct 
{
    char start_date[11];
    char end_date[11];
    char major[INPUT_LEN];
    char degree[INPUT_LEN];
} Education;
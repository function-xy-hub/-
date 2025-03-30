#ifndef RESUME_H
#define RESUME_H

#define MAX_SECTION 10
#define MAX_CONTENT 200

typedef enum 
{
    PERSONAL_INFO,
    EDUCATION,
    WORK_EXP,
    SKILLS
} SectionType;

typedef struct 
{
    SectionType type;
    char title[50];
    char content[MAX_CONTENT];
} ResumeSection;

typedef struct 
{
    ResumeSection sections[MAX_SECTION];
    int count;
} Resume;

// 初始化简历对象
void init_resume(Resume *resume);

// 添加简历段落
int add_section(Resume *resume, SectionType type, 
               const char* title, const char* content);

#endif
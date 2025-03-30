#include "resume.h"
#include <string.h>

void init_resume(Resume *resume) 
{
    memset(resume, 0, sizeof(Resume));
}

int add_section(Resume *resume, SectionType type, 
               const char* title, const char* content) 
{
    if(resume->count >= MAX_SECTION) return -1;
    
    ResumeSection *sec = &resume->sections[resume->count];
    sec->type = type;
    strncpy(sec->title, title, 49);
    strncpy(sec->content, content, MAX_CONTENT-1);
    resume->count++;
    return 0;
}
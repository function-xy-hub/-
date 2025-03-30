#include "template.h"
#include <stdio.h>
#include <stdlib.h>

char* load_template(TemplateType tpl_type) 
{
    const char* filename = (tpl_type == MODERN_STYLE) ? 
        "tpl/modern.tpl" : "tpl/classic.tpl";
    
    FILE* fp = fopen(filename, "r");
    if(!fp) return NULL;
    
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);
    
    char* buffer = malloc(size+1);
    fread(buffer, 1, size, fp);
    fclose(fp);
    
    buffer[size] = '\0';
    return buffer;
}

void apply_template(const Resume *resume, 
                   char* template, 
                   char* output_buf) 
{
    // 实现模板标签替换逻辑
    // 示例：替换{{personal_info}}等标签
}
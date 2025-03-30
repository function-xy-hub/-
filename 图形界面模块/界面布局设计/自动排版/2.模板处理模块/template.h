#ifndef TEMPLATE_H
#define TEMPLATE_H

#include "../model/resume.h"

// 模板类型枚举
typedef enum 
{
    MODERN_STYLE,
    CLASSIC_STYLE
} TemplateType;

// 加载模板文件
char* load_template(TemplateType tpl_type);

// 应用模板到简历数据
void apply_template(const Resume *resume, 
                   char* template, 
                   char* output_buf);

#endif
#include <stdio.h>
#include "model.h"
#include "template.h"
#include "parser.h"
#include "output.h"

int main() 
{
    Resume resume;
    init_resume(&resume);
    
    // 1. 解析输入文件
    if(parse_input_file("input.txt", FORMAT_TEXT, &resume) != 0) 
    {
        printf("解析输入文件失败！\n");
        return 1;
    }
    
    // 2. 加载模板
    char* template = load_template(MODERN_STYLE);
    if(!template) 
    {
        printf("加载模板失败！\n");
        return 2;
    }
    
    // 3. 应用模板
    char output_buf[4096];
    apply_template(&resume, template, output_buf);
    
    // 4. 生成输出
    if(generate_output(output_buf, OUTPUT_HTML, "resume.html") != 0) 
    {
        printf("生成输出文件失败！\n");
        return 3;
    }
    
    free(template);
    return 0;
}
#ifndef OUTPUT_H
#define OUTPUT_H

// 输出格式选项
typedef enum 
{
    OUTPUT_TEXT,
    OUTPUT_HTML,
    OUTPUT_PDF
} OutputFormat;

// 生成最终文件
int generate_output(const char* content, 
                   OutputFormat format,
                   const char* filename);

#endif
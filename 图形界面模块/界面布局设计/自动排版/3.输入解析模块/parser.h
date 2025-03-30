#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include "../model/resume.h"

// 支持的输入格式
typedef enum 
{
    FORMAT_JSON,
    FORMAT_TEXT
} InputFormat;

// 解析输入文件
int parse_input_file(const char* filename, 
                    InputFormat format,
                    Resume *resume);

#endif
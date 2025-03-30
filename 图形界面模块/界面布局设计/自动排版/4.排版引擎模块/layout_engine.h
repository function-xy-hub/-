#ifndef LAYOUT_ENGINE_H
#define LAYOUT_ENGINE_H

#include "model.h"

// 自动换行算法
void text_wrap(const char* input, 
              int max_width,
              char* output);

// 段落对齐处理
void align_section(char* content, 
                  int total_width,
                  char align_mode);

#endif
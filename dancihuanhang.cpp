//单词换行实现
int RenderTextWithWordWrap(int x, int y, const char* text, int max_width, int line_height) {
    char word[100]; // 假设单词不会超过 99 个字符
    const char* ptr = text;
    int current_line_width = 0;
    int word_width;
    int space_width = textwidth(" ");
    int current_x = x;

    while (sscanf(ptr, "%99s", word) == 1) {
        word_width = textwidth(word);

        // 检查单词是否超过了行宽
        if (word_width > max_width) {
            if (current_line_width > 0) { // 如果有内容，换行
                y += line_height;
                current_x = x;
                current_line_width = 0;
            }
            outtextxy(current_x, y, word);
            y += line_height; // 输出后直接换行
            current_x = x;
            current_line_width = 0;
        }
        else {
            // 检查加上这个单词（和可能的前导空格）是否会超出行宽
            int potential_width = current_line_width + (current_line_width > 0 ? space_width : 0) + word_width;

            if (potential_width <= max_width) {
                // 可以放在当前行
                if (current_line_width > 0) {
                    outtextxy(current_x + current_line_width, y, " "); // 输出空格
                    current_line_width += space_width;
                }
                outtextxy(current_x + current_line_width, y, word);
                current_line_width += word_width;
            }
            else {
                // 需要换行
                y += line_height;
                current_x = x;
                outtextxy(current_x, y, word);
                current_line_width = word_width;
            }
        }

        // 移动指针到下一个单词的开始位置
        ptr = strstr(ptr, word);
        if (ptr) {
            ptr += strlen(word);
            // 跳过单词后的所有空格
            while (*ptr == ' ' || *ptr == '\t') {
                ptr++;
            }
            if (*ptr == '\0') break; // 到达字符串尾
        }
        else {
            break; // sscanf 失败
        }
    }
    // 移动到下一行的起始位置
    return y + line_height;
}
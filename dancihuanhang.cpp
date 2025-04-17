//���ʻ���ʵ��
int RenderTextWithWordWrap(int x, int y, const char* text, int max_width, int line_height) {
    char word[100]; // ���赥�ʲ��ᳬ�� 99 ���ַ�
    const char* ptr = text;
    int current_line_width = 0;
    int word_width;
    int space_width = textwidth(" ");
    int current_x = x;

    while (sscanf(ptr, "%99s", word) == 1) {
        word_width = textwidth(word);

        // ��鵥���Ƿ񳬹����п�
        if (word_width > max_width) {
            if (current_line_width > 0) { // ��������ݣ�����
                y += line_height;
                current_x = x;
                current_line_width = 0;
            }
            outtextxy(current_x, y, word);
            y += line_height; // �����ֱ�ӻ���
            current_x = x;
            current_line_width = 0;
        }
        else {
            // ������������ʣ��Ϳ��ܵ�ǰ���ո��Ƿ�ᳬ���п�
            int potential_width = current_line_width + (current_line_width > 0 ? space_width : 0) + word_width;

            if (potential_width <= max_width) {
                // ���Է��ڵ�ǰ��
                if (current_line_width > 0) {
                    outtextxy(current_x + current_line_width, y, " "); // ����ո�
                    current_line_width += space_width;
                }
                outtextxy(current_x + current_line_width, y, word);
                current_line_width += word_width;
            }
            else {
                // ��Ҫ����
                y += line_height;
                current_x = x;
                outtextxy(current_x, y, word);
                current_line_width = word_width;
            }
        }

        // �ƶ�ָ�뵽��һ�����ʵĿ�ʼλ��
        ptr = strstr(ptr, word);
        if (ptr) {
            ptr += strlen(word);
            // �������ʺ�����пո�
            while (*ptr == ' ' || *ptr == '\t') {
                ptr++;
            }
            if (*ptr == '\0') break; // �����ַ���β
        }
        else {
            break; // sscanf ʧ��
        }
    }
    // �ƶ�����һ�е���ʼλ��
    return y + line_height;
}
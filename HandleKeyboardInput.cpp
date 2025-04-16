void HandleKeyboardInput(int key, char* active_field_buffer, int buffer_size, int* cursor_pos) {
    
    if (active_field_buffer != NULL && cursor_pos != NULL) {
        int len = strlen(active_field_buffer);

        if (key == 8 && *cursor_pos > 0) { // Backspace ��
            // �ӹ��λ��ɾ���ַ�
            memmove(&active_field_buffer[*cursor_pos - 1],
                &active_field_buffer[*cursor_pos],
                len - *cursor_pos + 1); // +1 ���� null ��ֹ��
            (*cursor_pos)--;
            LogMessage("���̣����� Backspace");
        }
        else if (key >= 32 && key <= 126) { // �ɴ�ӡ�ַ�
            if (len < buffer_size - 1) {
                memmove(&active_field_buffer[*cursor_pos + 1],
                    &active_field_buffer[*cursor_pos],
                    len - *cursor_pos + 1); // +1 ���� null ��ֹ��
                active_field_buffer[*cursor_pos] = (char)key;
                (*cursor_pos)++;
                LogMessage("���̣�����ɴ�ӡ�ַ�");
            }
        }
    else {
        if (key == 0) {
            int extended_key = getch();
            if (extended_key == 59) { // F1 ��
                LogMessage("���̣���⵽ F1 (���ð���)");
                // ���� ShowHelp() ���� (������ help_b.c ����)
            }
        }
        else if (key == 27) { // Esc ��
            LogMessage("���̣����� Esc �� (ȫ��)");
            // ���ܴ����˳�����򷵻����˵����߼�
        }
    }
}
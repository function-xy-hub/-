void HandleKeyboardInput(int key, char* active_field_buffer, int buffer_size, int* cursor_pos) {
    
    if (active_field_buffer != NULL && cursor_pos != NULL) {
        int len = strlen(active_field_buffer);

        if (key == 8 && *cursor_pos > 0) { // Backspace 键
            // 从光标位置删除字符
            memmove(&active_field_buffer[*cursor_pos - 1],
                &active_field_buffer[*cursor_pos],
                len - *cursor_pos + 1); // +1 包含 null 终止符
            (*cursor_pos)--;
            LogMessage("键盘：处理 Backspace");
        }
        else if (key >= 32 && key <= 126) { // 可打印字符
            if (len < buffer_size - 1) {
                memmove(&active_field_buffer[*cursor_pos + 1],
                    &active_field_buffer[*cursor_pos],
                    len - *cursor_pos + 1); // +1 包含 null 终止符
                active_field_buffer[*cursor_pos] = (char)key;
                (*cursor_pos)++;
                LogMessage("键盘：处理可打印字符");
            }
        }
    else {
        if (key == 0) {
            int extended_key = getch();
            if (extended_key == 59) { // F1 键
                LogMessage("键盘：检测到 F1 (调用帮助)");
                // 调用 ShowHelp() 函数 (定义在 help_b.c 部分)
            }
        }
        else if (key == 27) { // Esc 键
            LogMessage("键盘：处理 Esc 键 (全局)");
            // 可能触发退出程序或返回主菜单的逻辑
        }
    }
}
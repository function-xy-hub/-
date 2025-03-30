//将输入字符串在页面居中输出
void print_centered(const char* str) 
{
    int padding = (WIDTH - strlen(str)) / 2;
    printf("%*s%s%*s\n", padding, "", str, padding, "");
}
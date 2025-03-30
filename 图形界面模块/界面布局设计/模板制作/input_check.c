// 输入验证函数
int validate_phone(const char* phone) 
{
    if(strlen(phone) != 11) return 0;
    for(int i=0; i<11; i++)
    {
        if(!isdigit(phone[i])) return 0;
    }
    return 1;
}

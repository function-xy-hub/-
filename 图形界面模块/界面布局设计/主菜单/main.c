int main() 
{
    char input[INPUT_BUFFER_SIZE];
    int choice = 0;
    
    while(1)
    {
        welcome_page();
        fflush(stdin);  // 清空输入缓冲区
        if(gets(input) == NULL)
        {//处理输入错误
            printf("\n输入错误，请重新选择！\n");
            continue;  
        }
        
        //输入验证
        if(sscanf(input, "%d", &choice) !=1)
        {
            printf("\n请输入数字！\n");
            Sleep(1000);  // 等待1秒
            continue;
        }

        switch(choice)
        {
            case 1:
                printf("\n进入自动排版模块...\n");
                Sleep(1000);
                break;
            case 2:
                printf("\n进入模板制作模块...\n");
                Sleep(1000);
                break;
            case 3:
                printf("\n进入模板选择模块...\n");
                Sleep(1000);
                break;
            case 4:
                printf("\n感谢使用！\n");
                return 0;
            default:
                printf("\n输入错误，请重新选择！\n");
                Sleep(1000);
        }
    }
    return 0;
}
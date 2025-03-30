//模块管理窗口
int tpl_manage() 
{
    draw_box("简历设计系统");
    printf("1. 个人信息\n");
    printf("2. 求职意向\n");
    printf("3. 教育经历\n");
    printf("4. 工作经历\n");
    printf("5. 项目经历\n");
    printf("6. 自我评价\n");
    printf("7. 保存简历\n");
    printf("8. 退出系统\n");
    printf("请选择操作：");

    int choice;
    char input[10];
    fgets(input, 10, stdin);
    sscanf(input, "%d", &choice);
    return choice;
}

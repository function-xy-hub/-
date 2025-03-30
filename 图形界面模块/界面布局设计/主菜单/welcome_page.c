void welcome_page() 
{
    system("cls");
    system("color 9F"); // 蓝底白字

    // 绘制界面边框
    printf("\n");
    for(int i=0; i<WIDTH+4; i++) printf("#");
    printf("\n#%*s#\n", WIDTH+2, "");

    print_centered("简历辅助设计系统");
    
    printf("#%*s#\n", WIDTH+2, "");
    for(int i=0; i<WIDTH+4; i++) printf("#");
    
    printf("\n\n");
    print_centered("1. 自动排版");
    print_centered("2. 模板制作"); 
    print_centered("3. 模板选择");
    print_centered("4. 退出系统");
    
    printf("\n");
    for(int i=0; i<WIDTH+4; i++) printf("#");
    printf("\n请选择操作：");
}
//个人信息输入模块
void input_personal_info(PersonalInfo *info) 
{
    draw_box("个人信息录入");
    
    printf("姓名：");
    fgets(info->name, INPUT_LEN, stdin);
    info->name[strcspn(info->name, "\n")] = '\0';

    do 
    {
        printf("电话（11位）：");
        fgets(info->phone, 12, stdin);
        info->phone[strcspn(info->phone, "\n")] = '\0';
    } while(!validate_phone(info->phone));

    printf("邮箱：");
    fgets(info->email, INPUT_LEN, stdin);
    info->email[strcspn(info->email, "\n")] = '\0';

    printf("性别：");
    fgets(info->gender, 6, stdin);
    info->gender[strcspn(info->gender, "\n")] = '\0';
}
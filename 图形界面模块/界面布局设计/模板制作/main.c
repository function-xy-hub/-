//主函数
int main() 
{
    PersonalInfo personal_info;
    JobIntention job_intention;
    Education educations[MAX_ITEMS];
    int edu_count = 0;

    while(1) 
    {
        int choice = tpl_manage();
        
        switch(choice) 
        {
            case 1:
                input_personal_info(&personal_info);
                break;
            case 2:
                // 求职意向输入
                break;
            case 3:
                // 教育经历输入
                break;
            case 7:
                // 保存功能
                break;
            case 8:
                printf("\n感谢使用简历设计系统！\n");
                return 0;
            default:
                printf("\n无效选项，请重新选择！\n");
                Sleep(1000);
        }
    }
    return 0;
}
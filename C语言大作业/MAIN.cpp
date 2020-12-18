#include"MAIN.h"
void printTitle(void)
{
	printf("%6s %6s %3s %4s %8s %25s %23s %20s %15s  %s %6s  %6s %s %s\n", "学号", "姓名", "年龄", "性别", "出生年月", "地址", "电话", "E-mail", "高等数学", "线性代数", "英语", "程序设计", "体育","平均分");
}
void printContent(const student* stu)
{
	printf("%08d %3s %3d %4s %s %30s %20s %22s %9.2f %8.2f %8.2f %6.2f %6.2f %6.2f\n", stu->number, stu->name, stu->age, stu->sex, stu->birth, stu->address, stu->tel, stu->email, stu->math, stu->algebra, stu->english, stu->programming, stu->PE,stu->ave);
}
void abandon()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}
int main()
{
	system("mode con cols=160 lines=40");
	student * head = NULL;
	FILE* fp;
	printf("数据加载中...请稍后\n");
	if ((fp = fopen("abc", "rb")) == NULL)
	{
		printf("未检测到数据文件，要现在创建吗？输入Y并回车即可创建，输入回车直接退出：");
		char ch = getchar();		
		if (ch == '\n')
			return 0;
		abandon();
	}
	else
	{
		head = read(fp);
		if(head!=NULL)
		printf("加载成功！\n");
		else
		{
			printf("请按以下菜单添加数据或退出。\n");
		}
	}
	while (1)
	{
		printf("-------------------------欢迎使用学生信息管理系统--------------------------\n请按菜单提示操作！\n");
		printf("1.录入信息                                  2.已录入学生信息显示\n");
		printf("3.按某课程成绩排名                          4.按学号查询学生信息\n");
		printf("5.按姓名查询学生信息                        5.修改学生信息\n");
		printf("6.学生信息删除\n请直接输入序号并回车，输入-1并回车即可保存。重要提示：请勿在保存前将程序关闭！\n");
		int n;
		scanf("%d", &n);
		abandon();
		if (n == 1)
		{
			n=get(&head);
			if (n == 0)
			{
				printf("出错了，请重试！\n");
				continue;
			}
		}
		else if (n == 2)
		{
			printAll(head);
		}
		else if (n == 3)
		{
			sort(head);/*sort(const head);*/
		}
		else if (n == 4)
		{
			searchByNumber(head);/*searchByName(head);*/
		}
		else if (n == 5)
		{
			/*revise(head);*/
		}
		else if (n == 6)
		{
			Delete(&head);/*delete(head);*/
		}
		else if (n == -1)
		{
			if(fp!=NULL)
				fclose(fp);
				fp = fopen("abc", "w+b");
			write(fp, head);
			printf("是否退出？输入Y并回车即可退出，直接回车则回到菜单页:");
			char ch;
			ch=getchar();
			if (ch == 'Y'||ch=='y')
			{
				fclose(fp);
				return 0;
				
			}
		}
	}	
}

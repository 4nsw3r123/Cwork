#include"MAIN.h"
#include<string.h>
void sort(student* head)
{
	while (1)
	{
		int choice;
		printf("请选择需要排名的课程（输入课程前的编号）：\n1.高等数学\n2.线性代数\n3.英语\n4.程序设计\n5.体育\n6.平均分\n");
		scanf("%d", &choice);
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)/*处理特殊输出值*/
		{
			printf("不存在此课程！即将返回主菜单......\n");
			return;
		}

		student* current, * prev;
		student_rank* p, t;
		int count = 0, i = 0, j;
		p = (student_rank*)malloc(sizeof(student_rank) * count);
		for (current = head; current != NULL; current = current->next, i++, count++)/*对新的数据结构赋值，count即为人数*/
		{
			p[i].number = current->number;
			strcpy(p[i].name, current->name);
			p[i].score[0] = current->math;
			p[i].score[1] = current->algebra;
			p[i].score[2] = current->english;
			p[i].score[3] = current->programming;
			p[i].score[4] = current->PE;
			p[i].score[5] = current->ave;
		}		
		sortByCourse(p,count,1);
		printf("  学号    姓名  高等数学   线性代数   英语   程序设计  体育   平均分\n");
		for (i = 0; i < count; i++)
		{
			printf("%08d  %s      %.2f       %.2f     %.2f      %.2f    %.2f    %.2f\n", p[i].number, p[i].name, p[i].score[0],p[i].score[1],p[i].score[2],p[i].score[3],p[i].score[4],p[i].score[5]);
		}
		printf("排名结束，重新选择课程请按回车，退出请输入“Y”.\n");
		char ch = getchar();
		if (ch == '\n')
			continue;
		else if (ch == 'Y' || ch == 'y')
		{
			abandon();
			return;
		}
	}
}
int Delete(student** head)
{
	while (1)
	{
		printf("请输入需要删除学生的学号：\n");
		int number_delet;
		int flag = 0;
		scanf("%d", &number_delet);
		abandon();
		printf("信息删除中，请稍后......\n");
		struct student* current, * prev;
		for (current = (*head)->next,prev=*head; ; current = current->next)
		{
			if ((*head)->number == number_delet)
			{
				*head = (*head)->next;
				flag = 1;
				break;
			}
			if (current->number == number_delet)
			{
				prev->next = current->next;
				flag = 1;
				free(current);
				break;
			}
			if (current->next == NULL)
			{
				if (current->number == number_delet)
				{
					prev->next = NULL;
					flag = 1;
				}
				break;
			}
			prev = current;
			
		}
		if (flag == 1)
			{
				printf("删除成功，继续删除请按回车，退出请输入“Y”\n");
				char ch = getchar();
				if (ch == '\n')
					break;
				else if (ch == 'Y' || ch == 'y')
				{
					abandon();
					return 1;
				}
			}
		else if (flag == 0)
		{
			printf("不存在该学号对应的学生，重新输入请按回车，退出请输入“Y”\n");
			char ch = getchar();
			if (ch == '\n')
				continue;
			else if (ch == 'Y' || ch == 'y')
			{
				abandon();
				return 1;
			}
		}
	}
}
void sortByCourse(student_rank p[], int count,int choice)
{
	int flag;
	student_rank t;
	switch (choice)
	{
	case 1:flag = 0; break;
	case 2:flag = 1; break;
	case 3:flag = 2; break;
	case 4:flag = 3; break;
	case 5:flag = 4; break;
	case 6:flag = 5; break;
	}
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (p[i].score[flag] < p[j].score[flag])
			{
				t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
		}
	}
}
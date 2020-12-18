#include"MAIN.h"
#include<string.h>
void sort(student* head)
{
	while (1)
	{
		int choice;
		printf("��ѡ����Ҫ�����Ŀγ̣�����γ�ǰ�ı�ţ���\n1.�ߵ���ѧ\n2.���Դ���\n3.Ӣ��\n4.�������\n5.����\n6.ƽ����\n");
		scanf("%d", &choice);
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)/*�����������ֵ*/
		{
			printf("�����ڴ˿γ̣������������˵�......\n");
			return;
		}

		student* current, * prev;
		student_rank* p, t;
		int count = 0, i = 0, j;
		p = (student_rank*)malloc(sizeof(student_rank) * count);
		for (current = head; current != NULL; current = current->next, i++, count++)/*���µ����ݽṹ��ֵ��count��Ϊ����*/
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
		printf("  ѧ��    ����  �ߵ���ѧ   ���Դ���   Ӣ��   �������  ����   ƽ����\n");
		for (i = 0; i < count; i++)
		{
			printf("%08d  %s      %.2f       %.2f     %.2f      %.2f    %.2f    %.2f\n", p[i].number, p[i].name, p[i].score[0],p[i].score[1],p[i].score[2],p[i].score[3],p[i].score[4],p[i].score[5]);
		}
		printf("��������������ѡ��γ��밴�س����˳������롰Y��.\n");
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
		printf("��������Ҫɾ��ѧ����ѧ�ţ�\n");
		int number_delet;
		int flag = 0;
		scanf("%d", &number_delet);
		abandon();
		printf("��Ϣɾ���У����Ժ�......\n");
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
				printf("ɾ���ɹ�������ɾ���밴�س����˳������롰Y��\n");
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
			printf("�����ڸ�ѧ�Ŷ�Ӧ��ѧ�������������밴�س����˳������롰Y��\n");
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
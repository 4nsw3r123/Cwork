#include"MAIN.h"
student* read(FILE* fp)
{
	student* current, * prev, * head = NULL;
	int ch;

	current = (student*)malloc(size);
	ch = fread(current, size, 1, fp);
	if (ch == 0)
	{
		printf("��ȡ��������ݿ�Ϊ�գ�\n");
		return head;
	}
	head = current;
	if (current->next == NULL)
	{
		return head;
	}
	current->next = NULL;
	prev = current;
	while (1)
	{
		current = (student*)malloc(size);
		prev->next = current;
		ch = fread(current, size, 1, fp);
		if (ch == 0)
			break;
		if (current->next == NULL)
		{
			prev->next = current;
			break;
		}
		current->next = NULL;
		prev = current;
	}
	return head;
}
void write(FILE* fp, student* head)
{
	student* current, * prev;
	printf("���ڱ����У��벻Ҫ�رճ���\n");
	for (current = head; current != NULL; current = current->next)
	{
		fwrite(current, size, 1, fp);
	}
	printf("������ɣ�\n");
}
int get(student** head)
{
	student* prev, * current,*p;
	printf("������ѧ����Ϣ��\n");
	printf("%6s %6s %3s %4s %8s %25s %23s %20s %15s  %s %6s  %6s %s \n", "ѧ��", "����", "����", "�Ա�", "��������", "��ַ", "�绰", "E-mail", "�ߵ���ѧ", "���Դ���", "Ӣ��", "�������", "����");
	while (1)
	{
		current = (student*)malloc(size);
		if (current == NULL)
			return 0;
		scanf("%d %s %d %s %s %s %s %s %lf %lf %lf %lf %lf", &current->number, current->name, &current->age, current->sex, current->birth, current->address, current->tel, current->email, &current->math, &current->algebra, &current->english, &current->programming, &current->PE);
		current->ave = (current->english + current->algebra + current->math + current->PE + current->programming) / 5;
		current->next = NULL;
		abandon();
		if (*head == NULL)
		{
			*head = current;			
			printf("¼��ɹ�������¼���밴�س����˳�������Y���س���");
			char ch = getchar();
			if (ch == '\n')
				continue;
			else if (ch == 'Y'||ch=='y')
			{
				abandon();
				return 1;
			}
		}
		else
		{
			for (p = *head; p != NULL; p = p->next)
			{
				if (p->number == current->number)
				{
					printf("ѧ���ظ������������룡\n");
					break;
				}
				int n = 0;
				if (p->number > current->number)
				{
					if (p == *head)
					{
						current->next = *head;
						*head = current;
					}
					else
					{
						current->next = p;
						prev->next = current;
					}
					n = 1;
				}
				else if (p->next == NULL)
				{
					p->next = current;
					n = 1;
				}
				prev = p;
				if (n == 1)
				{
					printf("¼��ɹ�������¼���밴�س����˳�������Y���س���");
					char ch = getchar();
					if (ch == '\n')
						break;
					else if (ch == 'Y'||ch=='y')
					{
						abandon();
						return 1;
					}
				}
			}
		}
	}
	return 1;
}
student* searchByNumber(student* head)
{
	student* p;
	int i;
	scanf("%d", &i);
	for (p = head; p != NULL; p = p->next)
	{
		if (p->number == i)
		{
			printTitle();
			printContent(p);
			return p;
		}
	}
	if (p == NULL)
		printf("δ�ҵ���ѧ����\n");
}
void printAll(student* head)
{
	printTitle();
	for (student* current = head; current != NULL; current = current->next)
	{		
		printContent(current);
	}
}
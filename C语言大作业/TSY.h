void sort(student* head);
int Delete(student** head);
typedef struct student_rank/*���������ݽṹ�Խ�������*/
{
	int number;
	char name[80];
	double score[6];
}student_rank;
void sortByCourse(student_rank p[], int count,int choice);
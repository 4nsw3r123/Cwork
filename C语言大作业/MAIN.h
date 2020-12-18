#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct student {
	int number;
	char name[80];
	int age = 0;
	char sex[3];
	char birth[12];
	char address[80];
	char tel[12];
	char email[80];
	double math;
	double algebra;
	double english;
	double programming;
	double PE;
	double ave;
	struct student* next;
}student;
#include"LSY.h"
//#include<HCM.h>
#include"TSY.h"
const int size = sizeof(student);
void abandon();
void printTitle();
void printContent(const student* stu);
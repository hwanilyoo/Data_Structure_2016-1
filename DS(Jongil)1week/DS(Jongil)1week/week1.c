#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct student {
	char name[30];
	int studentID;
	char major[30];
}student;
void swap(int *a, int *b);
int main() {
	// 1¹ø
	
	/*char input[30] ;
	printf("enter your name : ");
	//scanf("%[^\n]s", input);
	gets(input);
	printf("your name is %s\n",input);
	*/

	/* 2¹ø
	int i;
	int input[6] = { 1,2,3,4,5,6 };
	for (i = 0; i < 6; i++)
		printf("%d ",input[i]);
	
	printf("\n\n");

	swap(&input[0], &input[5]);
	
	for (i = 0; i < 6; i++)
		printf("%d ", input[i]);
	printf("\n");
	*/

	/*
	char *name = (char*)malloc(sizeof(char) * 30);
	printf("enter your name : ");
	scanf("%[^\n]s", name);
	printf("your name is %s\n", name);
	*/
	
	
	int a,i;
	FILE * file;
	file = fopen("studentID.txt", "r");
	fscanf(file, "%d", &a);
	
	student *stu;
	
	stu= (student*)malloc(sizeof(student) * a);
	
	
	for (i = 0; i < a; i++) {
		fscanf(file, "%s %d %s\n", stu[i].name, &(stu[i].studentID), stu[i].major);
	}
	

	for (i = 0; i < a; i++) {
		printf("%s %d %s\n", stu[i].name, stu[i].studentID, stu[i].major);
	}
	
	return 0;
}

/*
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
*/
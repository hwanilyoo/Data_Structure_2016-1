#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct goRating_ {
	char *name;
	int Elo;
}goRating;
int main() {
	int a,i,input2,input3;
	char input;
	char * chname;
	FILE * file;
	file = fopen("Rank.txt", "r");
	fscanf(file, "%d", &a);
	
	chname= (char*)malloc(sizeof(char) * 30);
	goRating *goRate = (goRating*)malloc(sizeof(goRating)*a);
	
	for (i = 0; i < a; i++) {
		goRate[i].name = (char*)malloc(sizeof(char) * 30);
		fscanf(file, "%s %d\n", goRate[i].name, &goRate[i].Elo);

	}
	
	printf("i : 안내\n");
	printf("p : 출력\n");
	printf("n : 이름변경\n");
	printf("e : Elo 변경\n");
	printf("q : 종료\n");
	scanf("%c", &input);

	while (input != 'q') {
		
		switch (input) {
			case 'i':
				printf("i : 안내\n");
				printf("p : 출력\n");
				printf("n : 이름변경\n");
				printf("e : Elo 변경\n");
				printf("q : 종료\n");
				scanf("%c", &input);
				break;
			case 'p':
				printf("순번, 이름, Elo\n");
				for (i = 0; i < a; i++) {
					printf("%d : %s %d\n", i + 1, goRate[i].name, goRate[i].Elo);
				}
				break;
			case 'n':
				printf("변경할 순번을 입력하세요.\n");
				scanf("%d",&input2);
				printf("변경할 이름을 입력하세요\n");
				scanf("%s", chname);
				strcpy(goRate[input2 - 1].name, chname);
				break;
			case 'e':
				printf("변경할 순번을 입력하세요.\n");
				scanf("%d", &input2);
				printf("변경할 elo를 입력하세요\n");
				scanf("%d", &input3);
				goRate[input2 - 1].Elo = input3;
				
				break;
			
				
		}
		scanf("%c", &input);
	} 
	
	for (i = 0; i < a; i++) {
		free(goRate[i].name);
		
		
	}
	free(goRate);
	

	
	return 0;

}
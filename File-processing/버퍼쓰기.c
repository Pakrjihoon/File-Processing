#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define REC_SIZE sizeof(struct student)
#define BF 2
#define NAME_SIZE 16

struct student{
	char name[NAME_SIZE];
	int age;
};

int main(){
	struct student std;
	struct student *sp = NULL;
	FILE *fp = NULL;
	FILE *fp2 = NULL;
	int read_count = 0;
	char buf[16] = { 0 };
	char block[REC_SIZE*BF] = { 0 };
	int i, flag;
	/*fp = fopen("std.txt", "wb");
	
	printf("input Name and Age, Press ^Z for Quit\n");

	while (1){
		i = 0;
		sp = (struct student *)block;
		while ((i++) < BF){
			printf("Name : ");
			if (fgets(std.name, sizeof(std.name), stdin) == NULL){
				flag = 1;
				break;
			}
			std.name[strlen(std.name) - 1] = 0;
			printf("Age : ");
			fgets(buf, sizeof(buf), stdin);
			std.age = atoi(buf);
			*sp = std;
			sp++;
		}
		if (flag == 1)
		{
			if (*block == NULL){
				break;
			}
			fwrite(block, REC_SIZE, (i - 1), fp);
			printf("잔여레코드를 처리하였습니다.");
			break;
		}
		fwrite(block, REC_SIZE, BF, fp);
		printf("버퍼를 디스크에 기록하였습니다.\n");
	}*/

}


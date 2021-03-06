// 첫번째--------------------------------------------
#include<stdio.h>


int main()
{
	int data = 65;
	FILE *fp;

	int i, bit = 0x8000;
	// 만약 4자리 발생하려면, 0x8
	for (i = 0; i < 16; i++){
		if ((data & bit)){
			printf("1");
		}
		else{
			printf("0");
		}
		data = data << 1;
	}
	printf("\n");
	data = 65;
	fp = fopen("text.txt","w");
	fprintf(fp,"%d",data);
	fclose(fp);

	fp = fopen("char.txt", "w");
	fputc(data,fp);
	fclose(fp);

	fp = fopen("binary.txt", "wb");
	fwrite(&data,sizeof(data),1,fp);
	fclose(fp);

	return 0;
}

------------------------------------------------------

// 두번째---------------------------------------------
#include<stdio.h>


int main()
{
	int buffer[] = { 100000, 200000, 300000, 400000 };
	FILE *fp = NULL;
	int i, size, count;

	fp = fopen("binary.txt", "wb");
	size = sizeof(buffer[0]);
	count = sizeof(buffer) / sizeof(buffer[0]);

	i = fwrite(buffer, size, count, fp);
	fclose(fp);

	fp = fopen("ascii.txt", "w");
	fprintf(fp, "%d%d%d%d", buffer[0], buffer[1], buffer[2], buffer[3]);
	fclose(fp);
	return 0;
}

------------------------------------------------------

// 세번째

#include<stdio.h>
#define SIZE 5

int main()
{
	int buffer[SIZE], i, read_data;
	FILE *fp1, *fp2 = NULL;
	int size;

	fp1 = fopen("binary.txt", "rb");
	if (fp1 == NULL){
		fprintf(stderr,"파일 오픈 오류");
	}
	
	fp2 = fopen("ascii.txt", "r");
	if (fp2 == NULL){
		fprintf(stderr, "파일 오픈 오류");
	}

	size = fread(buffer, sizeof(int), SIZE, fp1);
	if (size == NULL){
		fprintf(stderr, "읽기 동작 오류");
		fclose(fp1);
		return 1;
	}
	// binary.txt 출력
	for (i = 0; i < SIZE; i++){
		printf("%d ", buffer[i]);
	}
	printf("\n");
	// ascii.txt 출력
	for (i = 0; i < SIZE; i++){
		fscanf(fp2, "%6d", &read_data);
		printf("%d ", read_data);
	}
	printf("\n");
	return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN sizeof(struct student)
typedef struct student
{
	int num;
	char name[10];
	char sex;
	int grade;
	int old;
}stu;
int main()
{
	FILE *fp;
	int i;
	stu arr[10];
	fp=fopen("file.txt","rb");
	if(fp==NULL)
	{
		printf("Error\n");
		exit(0);
	}
	for(i=0;i<10;i+=2)
	{
		fseek(fp,i*LEN,0);
		fread(&arr[i],LEN,1,fp);
		printf("NO:%d num:%d name:%s sex:%c grade:%d old:%d\n",i,arr[i].num,arr[i].name,arr[i].sex,arr[i].grade,arr[i].old);
	}
	fclose(fp);
	return 0;
}

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
	stu arr[3];
	int i;
	/*char filename[10]
	printf("Enter the file name:\n");
	scanf("%s",filename);*/
    FILE *fp = fopen("123.dat","wb");
	if(fp==NULL)
	{
		printf("Error");
		exit(0);
	}
	printf("Num  |Name |Sex  |Grade|Old |\n");
	for(i=0;i<3;i++)
	{  
		char name[10]; 
		scanf("%d %s %c %d %d",&arr[i].num,arr[i].name,&arr[i].sex,&arr[i].grade,&arr[i].old);
//	    strcpy(arr[i].name,name);
	/*	if(arr[i].num==000)
		{
			printf("End writing\n");
			break;
		}*/
		fwrite(&arr[i],LEN,1,fp);
	}
	fclose(fp);
	return 0;
}

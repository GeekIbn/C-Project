#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(stu)
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
	char filename[30];
//	printf("Enter the filename:\n");
//	scanf("%s",filename);
    FILE * fp = fopen("123.dat","rb");
	if(fp==NULL)
	{
	/*	if(strcmp(filename,"000")==0)
		{
			exit(0);
		}*/
		printf("Error\n");
		
	}
	for(i=0;i<3;i++)
	{
		fread(&arr[i],LEN,1,fp);
	/*	if(fread(&arr[i],LEN,1,fp)==EOF)
		{
			break;
		}*/
		printf("%d %s %c %d %d\n",arr[i].num,arr[i].name,arr[i].sex,arr[i].grade,arr[i].old);
	}
	fclose(fp);
	return 0;
}

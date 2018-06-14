#include<stdio.h>
#define LEN sizeof(stu)
typedef struct student
{
	int num;
	char name[10];
	float score;
}stu;
int main()
{
	int i;
	stu arr[3];
	FILE *fp;
	fp=fopen("123.dat","wb");
	if(ferror(fp)!=0)
	printf("Error\n");
	for(i=0;i<3;i++)
	{
		scanf("%d %s %f",&arr[i].num,arr[i].name,&arr[i].score);
		fwrite(&arr[i],LEN,1,fp);
	}
	fclose(fp);
	return 0;
}

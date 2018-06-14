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
	fp=fopen("123.dat","rb");
	if(ferror(fp)!=0)
	printf("Error\n");
	for(i=0;i<3;i++)
	{
		fread(&arr[i],LEN,1,fp);
		printf("%-6d %-6s %-6.2f\n",arr[i].num,arr[i].name,arr[i].score);
	}
	fclose(fp);
	return 0;
}

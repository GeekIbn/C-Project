#include<stdio.h>
struct infor
{
	int num;
	char name[20];
	char sex;
	char job;
	union
	{
		int clas;
		char position[10];
	}category;
}person[2];
int main()
{
	int i;
	for(i=0;i<2;i++)
	{
		scanf("%d %s %c %c",&person[i].num,&person[i].name,&person[i].sex,&person[i].job);
		if(person[i].job=='s')
		scanf("%d",&person[i].category.clas);
		else if(person[i].job=='t')
		scanf("%s",&person[i].category.position);
		else
		printf("Error!");
	}
	for(i=0;i<2;i++)
	{
		printf("\nNo:%d Name:%s Sex:%c Job:%c",person[i].num,person[i].name,person[i].sex,person[i].job);
		if(person[i].job=='s')
		printf(" Clas:%d",person[i].category.clas);
		else
		printf(" Position:%s",person[i].category.position);
	}
	return 0;
}

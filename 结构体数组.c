#include<stdio.h>
struct student
{
	int num;
	char name[20];
	float score;
};
int main()
{
	struct student stu[10];
	struct student temp;
	int i,
		n,
		j;
	n=0;
	for(i=0;;i++)
	{
		printf("������ѧ�ţ�"); 
		scanf("%d",&stu[i].num);
		if(stu[i].num==999)
		{
			break;
		}
		printf("������������"); 
		scanf("%s",&stu[i].name);
		printf("�����������"); 
		scanf("%f",&stu[i].score);
		n++;
	}
	for(i=1;i<n;i++)
	{
		for(j=n-1;j>=i;j--)
		{
			if(stu[j].score>stu[j-1].score)
			{
				temp=stu[j];
				stu[j]=stu[j-1];
				stu[j-1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("ѧ�ţ�%3d ������%6s ������%.2f\n",stu[i].num,stu[i].name,stu[i].score);
	}
}

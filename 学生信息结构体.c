#include<stdio.h>
struct student
{
	int num;
	char name[10];
	float grade[3];
	float aver;
}; 
int main()
{
	int i,j,k;
	printf("Enter number name grades of students\n");
	struct student stu[3];
	struct student *p;
	p=stu;
	for(i=0;i<3;i++,p++)
	{
		scanf("%d %s %f %f %f",&p->num,(*p).name,&(*p).grade[0],&(*p).grade[1],&(*p).grade[2]);
	}
	p=stu;
	for(i=0;i<3;i++,p++)
	{
		p->aver=(p->grade[0]+p->grade[1]+p->grade[2])/3;
	}
	p=stu;
	for(i=0;i<3;i++,p++)
	{
		printf("%d |%s |%.2f %.2f %.2f |%.2f\n",(*p).num,(*p).name,(*p).grade[0],(*p).grade[1],(*p).grade[2],p->aver);
	}
}

#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct person)
struct person
{
	int num;
	char name[10];
	char sex;
	char job;
	struct person *next;
	union
	{
		int clas;
		char position[10];
	}info;
	
};
int main()
{
	int n;
	struct person *head,*p1,*p2,*pt;
	head=NULL;
	p1=p2=(struct person *)malloc(LEN);
	n=0;
	printf("Number Name Sex Job\n");
	scanf("%d %s %c %c",&p1->num,&p1->name,&p1->sex,&p1->job);
	while(p1->num!=0)
	{
		if(p1->job=='s')
		{
			printf("Class");
			scanf("%d",&p1->info.clas);	
		}
		else if(p1->job=='t')
		{
			printf("Position");
			scanf("%s",&p1->info.position);
		}
		else
		printf("Error!");
		
		n=n+1;
		
		if(n==1)
		{
			head=p1;
		}
		else
		{
			p2->next=p1;
			p2=p1;
		}
		p1=(struct person *)malloc(LEN);
		printf("Number Name Sex Job\n");
		scanf("%d %s %c %c",&p1->num,&p1->name,&p1->sex,&p1->job);		
	}
	p2->next=NULL;
	
	pt=head;
	printf("Number  Name  Sex  Job  Class/Position\n");
	while(pt->num!=0)
	{
		printf("%-7d",n);
		printf("%-7d %-7s %-7c %-7c ",pt->num,pt->name,pt->sex,pt->job);
		if(pt->job=='s')
		printf("%-7d\n",pt->info.clas);
		else if(pt->job=='t')
		printf("%-7s\n",pt->info.position);
		else
		printf("NULL");
		pt=pt->next;
	}
}

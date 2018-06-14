#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct student)
struct student
{
	int num;
	float score;
	struct student *next;
};
int n;
struct student *creat(void)
{
	struct student *head;
	struct student *p1,*p2;
	n=0;
	p1=p2=(struct student *)malloc(LEN);
	scanf("%d,%f",&p1->num,&p1->score);
	head=NULL;
	while(p1->num!=0)
	{
		n=n+1;
		if(n==1)
		{
			head=p1;
		}
		else
		{
			p2->next=p1;
		}
		p2=p1;
		p1=(struct student *)malloc(LEN);
		scanf("%d,%f",&p1->num,&p1->score);		
	}
	p2->next=NULL;
	return(head);
}
int main()
{
	int i;
	struct student *pt;
	pt=creat();
	for(i=0;i<=n-1;i++)
	{
		printf("\nnum:%d\nscore:%f",pt->num,pt->score);	
		pt=pt->next;
	}
	return 0;
 } 

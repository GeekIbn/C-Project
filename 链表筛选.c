#include<stdio.h>
struct person
{
	int num;
	int seq;
	struct person *next;
}arr[13];
int main()
{
	struct person *p;
	int i;
	int sign;
	struct person *temp;
	p=arr;
	for(i=0;i<13;i++)
	{
		arr[i].num=i+1;
	}
	for(i=0;i<13;i++)
	{
		if(p->num==13)
		{
			arr[12].next=arr;
			break;
		}
		p->next=p+1;
		p+=1;
	}
	p=arr;
	i=1;
	while(p!=p->next)
	{
		p->seq=i;
		i+=1;
		if(i==3)
		{
			temp=p->next;
			p->next=temp->next;
			temp->next=NULL;
			i=1;
		}
		sign=p->num;
		p=p->next;		
	}
	printf("The num is:%d",sign);
	return 0;
}

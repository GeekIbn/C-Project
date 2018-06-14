#include<stdio.h>
struct student
{
	int num;
	float score;
	struct student *next;
};
int main()
{
	struct student a, b, c, *head, *p;
	a.num=101;a.score=99;
	b.num=102;b.score=97;
	c.num=103;c.score=96;
	head=&a;
	a.next=&b;
	b.next=&c;
	c.next=NULL;
	p=head;
	do
	{
		printf("%ld %f \n",p->num,p->score);
		p=p->next;
	}
	while(p!=NULL);
	return 0;
}

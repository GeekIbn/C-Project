#include<stdio.h>
#include<string.h>
#define SIZE 100
char buf[SIZE];
char *p=buf;
char *alloc(int n)
{
	char *begin;
	if(p+n<=buf+SIZE)
	{
		begin=p;
		p=p+n;
		return begin;
	}
	else return(NULL);
}
void main()
{
	char *p1,*p2;
	int i;
	p1=alloc(10);
	strcpy(p1,"123456789");
	p2=alloc(5);
	strcpy(p2,"abcd");
	printf("buf=%p\n",buf);
	printf("p1=%p\n",p1);
	printf("p2=%p\n",p2);
	puts(p1);
	puts(p2);
	for(i=0;i<=15;i++)
	{
		printf("%c",buf[i]);
	}
}

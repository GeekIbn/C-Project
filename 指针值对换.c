#include<stdio.h>
void main()
{
	void change(int *pointer1,int *pointer2);
	int *p1,
		*p2,
		a,
		b;
	printf("Enter your number:");
	scanf("%d %d",&a,&b);
	p1=&a;
	p2=&b;
	change(p1,p2);
	printf("%d %d",a,b);
}
void change(int *pointer1,int *pointer2)
{
	int temp;
	temp=*pointer1;
	*pointer1=*pointer2;
	*pointer2=temp;
}

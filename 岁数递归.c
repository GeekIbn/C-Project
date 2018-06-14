#include<stdio.h>
int extern sum1(int n)
{
	int s;
	if(n==1)
	{
		return 10;
	}
	else
	{
		s=sum1(n-1)+2;
		printf("The %d person is %d years old\n",n,s);
		return s;
	}
}
static int main()
{
	int x;
	x=sum1(5);
	return 0;
}


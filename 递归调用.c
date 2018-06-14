#include<stdio.h>
int num(n)
{	
	int s;
	if(n==10)
	{
			return 1;
	}
	else
	{
		s=(num(n+1)+1)*2;
		printf("The %d day has %d peaches.\n",n,s);
	}
	return s;
}
int main()
{
	int x;
	x=num(1);
	return 0;
}

#include <stdio.h>
void main()
{
	void output(int n);
	int n;
	printf("Enter the number:\n");
	scanf("%d",&n);
	output(n);
}
void output(int n)
{
	int i,
		a;
	if((i=n/10)!=0)
	{
		output(i);
	}
	printf("%c",n%10+'0');
}

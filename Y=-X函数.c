#include <stdio.h>
int main()
{
	int i,
		j,
		y;
	for(i=1;i>=-10;i--)
	{
		for(j=-10;j<=10;j++)
		{
			y=(-j);
			if(y==i)
			{
				printf(".");
			}
			else
			{
				printf(" ");
			}
			/*if(j==0)
			{
				printf("|");
			}
			if(i==0)
			{
				printf("-");
			}*/ 
			if(j==10)
			{
				printf("\n");
			}
		}
	}
}

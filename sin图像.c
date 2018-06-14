#include<stdio.h>
#include<math.h>
void main()
{
	float i,j,y;
	for(i=sin(M_PI_2);i>=-sin(M_PI_2);i=i-sin(M_PI/180))
	{
		for(j=0;j<=2*M_PI;j=j+M_PI/180)
		{
			y=sin(j);
			if(y==i)
			{
				printf("¡¤");
			}
			else
			{
				printf(" ");
			}
			if(j==2*M_PI)
			{
				printf("\n");
			}
		}
	}
} 

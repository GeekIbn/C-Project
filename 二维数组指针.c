#include <stdio.h>
int arry(int x,int y)
{
	int arr[x][y],
		(*p)[y],
		i,
		j;
	p=arr;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			*(*(p+i)+j)=j+i+1;
			printf("%d ",*(*(p+i)+j));
			if(j==(y-1))
			{
				printf("\n");
			}
		}
	}
	return 0;
}
int main()
{
	int x,
		y;
	printf("Enter the row & line of the arry:\n");
	scanf("%d %d",&x,&y);
	arry(x,y);
}

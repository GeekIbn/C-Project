#include<stdio.h>
void change(/*int n,int m*/)
{
	int arr[/*n*/3][/*m*/4]/*;*/={1,2,3,4,5,6,7,8,9,10,11,12};
	int (*p)[/*m*/4],
		i,
		j,
		temp;
	p=arr;
	for(i=(/*m*/4-1);i>=1;i--)
	{
		for(j=0;j<=/*n*/3-1;j++)
		temp=*(*(p+i)+j);
		*(*(p+i)+j)=*(*(p+i-1)+j);
		*(*(p+i-1)+j)=temp;
	}
	for(i=0;i<=/*n*/2;i++)
	{
		for(j=0;j<=/*m*/3;j++)
		{
			printf("%d",arr[i][j]);
			if(j==/*m-1*/4-1)
			{
				printf("\n");
			}
		}
	}
}
int main()
{
	int x,
		y; 
	/*printf("Enter X&Y of arry:");*/
	/*scanf("%d %d",&x,&y);*/
	change(/*x,y*/);
	return 0;
}

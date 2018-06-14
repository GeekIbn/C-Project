#include<stdio.h>
int main()
{
	int arr[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int (*p)[4],
		i,
		j,
		k,
		l, 
		temp;
	p=arr;
	for(i=3;i>=1;i--)
	{
		for(j=0;j<3;j++)
		{
			temp=*(*(p+j)+i);
			*(*(p+j)+i)=*(*(p+j)+i-1);
			*(*(p+j)+i-1)=temp;
		}
	}
	for(k=0;k<3;k++)
	{
		for(l=0;l<4;l++)
		{
			printf("%d ",arr[k][l]);
			if(l==3)
			{
				printf("\n");
			}
		}
	}
	return 0;
}


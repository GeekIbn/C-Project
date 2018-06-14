#include<stdio.h>
int main()
{	
	void sequence(int **pointer,int n);
	int n,
		i,
		j;
	int **pointer,
		arr[20],
		*p[20];
	pointer=p;
	printf("输入数据个数:\n");
	scanf("%d",&n);
	printf("分别输入%d个数据:\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",arr+i);
	}
	for(i=0;i<n;i++)
	{
		p[i]=&arr[i];
	}
	sequence(pointer,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",*pointer[i]);
	}
}
void sequence(int **pointer,int n)
{
	int *temp,
		i,
		j;
	for(i=1;i<n;i++)
	{
		for(j=n-1;j>=i;j--)
		{
			
			if(*(pointer+j)>*(pointer+j-1))
			{
				temp=pointer[j];
				pointer[j]=pointer[j-1];
				pointer[j-1]=temp;
			}
		}
	}
}

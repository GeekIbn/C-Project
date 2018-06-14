#include<stdio.h>
int *p;
void arry(int x)
{
	int arr[x],i,result;
	p=arr;
	for(i=0;i<x;i++)
	{
		*(p+i)=i+1;
		printf("%d ",*(p+i));
	}
}
int main()
{
	int i;
	arry(7); 
	return 0;
}

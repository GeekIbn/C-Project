#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int i,j;
	int n=3;
	char arr[3][10]={"ibn","lily","sam"};
	for(i=1;i<n;i++)
	{
		for(j=n-1;j>=i;j--)
		{
			if(arr[j]>arr[j-1])
			{
				char temp[10];
				strcpy(temp,arr[j]);
				strcpy(arr[j],arr[j-1]);
				strcpy(arr[j-1],temp);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n%s\n",arr[i]);
	}
}

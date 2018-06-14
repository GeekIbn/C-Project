#include<stdio.h>
float main()
{
	float arr[]={1.35,1.45,0.25,2.54,7.89,4.55,5.62,2.21,1.22,1.11};
	int i,j; 
	for(i=0;i<=9;i++)
	{
		printf("%.2f ",arr[i]);
	}
	printf("\nÅÅÐòºó£º\n");
	for(i=1;i<=9;i++)
	{
		for(j=9;j>=i;j--)
		{
			if(arr[j]>arr[j-1])
			{
				float temp;
				temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
				
			}
		}
	}
	for(i=0;i<=9;i++)
	{
		printf("%.2f ",arr[i]);
	}
	return 0;
}

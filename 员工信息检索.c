#include<stdio.h>
int main()
{
	void sequence(int *pointer1,char (*pointer2)[10]);
	int staffnumber[10],
		*pointer1,
		i,
		j,
		number;
	char staffname[10][10],
		(*pointer2)[10];
	pointer1=staffnumber;
	pointer2=staffname;
	for(i=0;i<=9;i++)
	{
		printf("Enter the NO.%d staff's number and name:\n",i+1);
		for(j=0;j<=1;j++)
		{
			if(j==0)
			{
				scanf("%d",pointer1+i);
				continue;
			}
			else
			{
				scanf("%s",pointer2[i]);
				continue;
			}
		}
	}
	for(j=0;j<=9;j++)
	{
		printf("%8d",*(pointer1+j));
		if(j==9)
		{
		printf("\n");
		}
	}
	for(j=0;j<=9;j++)
	{
		printf("%8s",pointer2[j]);
		if(j==9)
		{
			printf("\n");
		}
	}
	sequence(pointer1,pointer2);
	printf("The staffs list after sequencing is:\n");
	for(j=0;j<=9;j++)
	{
		printf("%8d",*(pointer1+j));
		if(j==9)
		{
		printf("\n");
		}
	}
	for(j=0;j<=9;j++)
	{
		printf("%8s",pointer2[j]);
		if(j==9)
		{
			printf("\n");
		}
	}
	printf("Enter the staff's number to search its name:\n");
	scanf("%d",&number);
	printf("NO.%d staff's name is %s",number,pointer2[number-1]);
	return 0;
}
void sequence(int *pointer1,char (*pointer2)[10])
{
	int i,
		j,
		max1;
	char (*max2)[10];
	for(i=8;i>=0;i--)
	{
		for(j=0;j<=i;j++)
		{
			if(pointer1[j]>pointer1[j+1])
			{
				max1=pointer1[j];
				pointer1[j]=pointer1[j+1];
				pointer1[j+1]=max1;
				max2=*(*(pointer2+j));
				*(*(pointer2+j))=*(*(pointer2+j+1));
				*(*(pointer2+j+1))=*(max2);
			}
		}
	}
}


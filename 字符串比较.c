#include<stdio.h>
int main()
{
	void cmp(char *p1,char *p2);
	char str1[20],
		 str2[20],
	     *p1,
	     *p2;
	printf("Enter two strings to compare:\n");
	scanf("%s %s",str1,str2);
	p1=str1;
	p2=str2;
	cmp(p1,p2);
	main();
}
void cmp(char *p1,char *p2)
{
	int i,
		d;
	for(i=0;;i++)
	{
		if(p1[i]==p2[i])
		{
			continue;
		}
		else
		{
			printf("The %d chars %c %c aren't corresponding.\n",i+1,p1[i],p2[i]);
			d=p1[i]-p2[i];
			if(d>0)
			printf("The consequence is  1\n");
			else
			{
			printf("The consequence is -1\n");
			printf("---------------------\n");
			}
			break;
		}
	}
}

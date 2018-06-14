#include<stdio.h>
int main()
{
	char string[100];
	char c;
	int i;
	int num=0;
	int word=0;
	gets(string);
	for(i=0;(c=string[i])!='\0';i++)
	{
		if(c==' ')
		word=0;
		else if(c!=' '&&word==0)
		{
			word=1;
			num++;
		}
	}
	printf("%d chars",num);
	return 0;
}


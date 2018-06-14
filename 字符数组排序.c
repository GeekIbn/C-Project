#include<stdio.h>
#include<string.h>
int main()
{
	void sequence(char **pointer,char *p[]);
	char *p[]={"I ","am ","a ","slim ","boy "};
	char **pointer;
	pointer=p;
	sequence(pointer,p);
}
void sequence(char **pointer,char *p[])
{
	char *ptemp;
	pointer=p;
	int i,
		k,
		j;
	for(i=1;i<5;i++)
	{
		for(j=4;j>=i;j--)
		{
			if(*(pointer[j])>*(pointer[j-1]))
			{
				ptemp=pointer[j];
				pointer[j]=pointer[j-1];
				pointer[j-1]=ptemp;
			}
			else
			continue;
			
		} 		
	}
	for(i=0;i<5;i++)
	{
		printf("%s",p[i]);
	}
	for(i=0;i<5;i++)
	{
		printf("%d ",p[i]);
	}
}

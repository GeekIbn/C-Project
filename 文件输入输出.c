#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch,filename[10];
	printf("Enter file's name:");
	scanf("%s",filename);
	if((fp=fopen(filename,"w"))==NULL)
	{
		printf("Error\n");
		exit(0);
	}
	ch=getchar();
	printf("Enter string to save in Disk:\n");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		putchar(ch);
		ch=getchar();
	}
	fclose(fp);
	putchar(10);
	return 0;
}

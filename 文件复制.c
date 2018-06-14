#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *in,*out;
	char ch,infile[10],outfile[10];
	printf("Enter the source file name:\n");
	scanf("%s",infile);
	if((in=fopen(infile,"r"))==NULL)
	{
		printf("Error");
		exit(0);
	printf("Enter the output file name:\n");
	scanf("%s",outfile);
	
	}
	if((out=fopen(outfile,"w"))==NULL)
	{
		printf("Error");
		exit(0);
	}
	while(!feof(in))
	{
		ch=fgetc(in);
		fputc(ch,out);
		putchar(ch);
	}
	putchar(10);
	fclose(in);
	fclose(out);
	return 0;
}

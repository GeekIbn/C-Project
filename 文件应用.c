#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct S)
typedef
struct S
{
	char str[10];
	struct S *next;
}string;
string *head,*p1,*p2;
int n;
int main()
{
	FILE *fp;
	int i;
	char filename[10];
	string *input();
	void sequent();
	
	string *pt;
	pt=input();
	sequent();
	
	printf("Enter file name:\n");
	scanf("%s",filename);
	fp=fopen(filename,"w");
	if((fp=fopen(filename,"w"))==NULL)
	{
		printf("Error");
		exit(0);
	}
	pt=head;
	for(i=0;i<n;i++)
	{
		fputs(pt->str,fp);
		fputs("\n",fp);
		pt=pt->next;
	}
	fclose(fp);
	pt=head;
	for(i=0;i<n;i++)
	{
		printf("%s\n",pt->str);
		pt=pt->next;
	}
}
string *input()
{
	n=0;
	p1=p2=(struct S *)malloc(LEN);
	printf("Enter some strings:\n");
	scanf("%s",p1->str);
	head=NULL;
	while(strcmp(p1->str,"END")!=0)
	{
		n+=1;
		if(n==1)
		{
			head=p1;
		}
		else
		{
			p2->next=p1;
			p2=p1;
		}
		p1=(struct S *)malloc(LEN);
		printf("Enter some strings:\n");
		scanf("%s",p1->str);
	}
	p2->next=NULL;
	return(head);
}
void sequent()
{
	int i,j;
	char arr[n][10];
	string *pt1;
	pt1=head;
	for(i=0;i<n;i++)
	{
		strcpy(arr[i],pt1->str);
		pt1=pt1->next;
	}
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
	pt1=head;
	for(i=0;i<n;i++)
	{
		strcpy(pt1->str,arr[i]);
		pt1=pt1->next;
	}
}

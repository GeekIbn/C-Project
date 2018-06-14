#include<stdio.h>
#include<string.h>
#define LEN sizeof (struct map)

struct map
{
	char name[20];
	int price;
	int buildings;
	int empty;
	int onehouse;
	int twohouses;
	int threehouses;
	int pledge;
	int build;
	char owner[10];
}real_estate[30];

int main()
{
	int i;
	
	FILE *fp;
	fp=fopen("estate.dat","wb");
	for(i=0;i<30;i++)
	{
		scanf("%s",real_estate[i].name);
		if(strcmp(real_estate[i].name,"END")==0)
		{
			break;
		}
		scanf("%d,%d,%d,%d,%d,%d,%d,%d",&real_estate[i].price,&real_estate[i].buildings,&real_estate[i].empty,&real_estate[i].onehouse,&real_estate[i].twohouses,&real_estate[i].threehouses,&real_estate[i].pledge,&real_estate[i].build);
		scanf("%s",real_estate[i].owner);
		fwrite(&real_estate[i],LEN,1,fp);
	}
	fclose(fp);
	
	FILE *fp1;
	fp1=fopen("estate.dat","rb");
	for(i=0;i<30;i++)
	{
		fread(&real_estate[i],LEN,1,fp1);
		printf("%s %d %d %d %d %d %d %d %d %s\n",real_estate[i].name,real_estate[i].price,real_estate[i].buildings,real_estate[i].empty,real_estate[i].onehouse,real_estate[i].twohouses,real_estate[i].threehouses,real_estate[i].pledge,real_estate[i].build,real_estate[i].owner);
	}
	fclose(fp1);

}

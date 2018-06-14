#include<stdio.h>
int score[10]={67,98,75,63,82,79,81,91,66,84};
int sum()
{
	int result;int i,x;
	for(i=0;i<=9;i++)
	{
		result+=score[i];
	}
	return result;
}
int max()
{
	int compare=0;int i;
	for (i=0;i<=9;i++)
	{
		if(score[i]>compare)
		{
			compare=score[i];
		}
	}
	return compare;
}
int average()
{
	int averagenum;
	averagenum=sum()/10;
	return averagenum;
}
int main()
{
	int x,y,z;
	x=sum();
	y=max();
	z=average();
	printf("和为%d\n最大值为%d\n平均值为%d\n",x,y,z);
	return 0;
}

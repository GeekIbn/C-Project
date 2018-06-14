#include<stdio.h>
#include<math.h> 
float distance(int x,int y,int z)
{
	int gougu;
	float dis;
	if(z>=0)
	{
	if(x>=0&&y>=0)
	{
		gougu=(x-2)*(x-2)+(y-2)*(y-2)+(z-2)*(z-2);
		dis=sqrt(gougu);
		return dis;
	}
	else if(x<0&&y>=0)
	{
		gougu=(x+2)*(x+2)+(y-2)*(y-2)+(z-2)*(z-2);
		dis=sqrt(gougu);
		return dis;
	}
	else if(x<0&&y<0)
	{
		gougu=(x+2)*(x+2)+(y+2)*(y+2)+(z-2)*(z-2);
		dis=sqrt(gougu);
		return dis;
	}
	else if(x>0&&y<0)
	{
		gougu=(x-2)*(x-2)+(y+2)*(y+2)+(z-2)*(z-2);
		dis=sqrt(gougu);
		return dis;
	}
	}
	if(z<0)
	{
	if(x>=0&&y>=0)
	{
		gougu=(x-2)*(x-2)+(y-2)*(y-2)+(z+2)*(z+2);
		dis=sqrt(gougu);
		return dis;
	}
	else if(x<0&&y>=0)
	{
		gougu=(x+2)*(x+2)+(y-2)*(y-2)+(z+2)*(z+2);
		dis=sqrt(gougu);
		return dis;
	}
	else if(x<0&&y<0)
	{
		gougu=(x+2)*(x+2)+(y+2)*(y+2)+(z+2)*(z+2);
		dis=sqrt(gougu);
		return dis;
	}
	else if(x>0&&y<0)
	{
		gougu=(x-2)*(x-2)+(y+2)*(y+2)+(z+2)*(z+2);
		dis=sqrt(gougu);
		return dis;
	}	
	}
}
int main(int x,int y,int z)
{
	float temp;
	printf("输入空间中的点的坐标\n");
	scanf("%d %d %d",&x,&y,&z);
	temp=distance(x,y,z);
	if(temp<=1)
	{
		printf("occupy");
	}
	else
	{
		printf("empty");
	}
	return 0;
}

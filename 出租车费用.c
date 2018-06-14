#include<stdio.h>
float time(float x,float y)
{
	float m=0;
	if((x>=23.0&&x<=24.0)||(x>=0&&x<=5.0))
	{
		if(y>3.0)
		m=14.0+2.3*1.2*(y-3.0);
		else
		m=14.0;
	}
	else
	{
		if(y>3.0)
		m=14.0+2.3*(y-3.0);
		else
		m=14.0;
	}
	return m;
}
float main()
{
	float x,y;
	x=time(9.0,12.0);
	y=time(18.0,12.0);
	printf("%f",x+y);
	return 0;
}

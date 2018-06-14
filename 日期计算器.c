#include<stdio.h>
int countday(int year,int month,int day)
{
	int days=0;
	if (year%4==0)
	{
		switch (month)
		{
		case 1:
			days+=day;
			break;
		case 2:
			days+=day+31;
			break;
		case 3:
			days+=day+60;
			break;
		case 4:
			days+=day+91;	
			break;
		case 5:
			days+=day+121;
			break;
		case 6:
			days+=day+152;
			break;
		case 7:
			days+=day+182;
			break;
		case 8:
			days+=day+213;
			break;
		case 9:
			days+=day+244;
			break;
		case 10:
			days+=day+274;
			break;
		case 11:
			days+=day+305;
			break;
		case 12:
			days+=day+335;
			break;
		}
	}
	else
	{
		switch (month)
		{
		case 1:
			days+=day;
			break;
		case 2:
			days+=day+31;
			break;
		case 3:
			days+=day+59;
			break;
		case 4:
			days+=day+90;	
			break;
		case 5:
			days+=day+120;
			break;
		case 6:
			days+=day+151;
			break;
		case 7:
			days+=day+181;
			break;
		case 8:
			days+=day+212;
			break;
		case 9:
			days+=day+243;
			break;
		case 10:
			days+=day+273;
			break;
		case 11:
			days+=day+304;
			break;
		case 12:
			days+=day+334;
			break;
		}
	}
	return days;
} 
int countyear(int start,int end)
{
	int year;int years;
	years=0;
	for(year=start;year<end;year++)
	{
		if(year%4==0)
		{
		years+=366;
	    }
		else 
		{
		years+=365;
		}
	}
	return years;
}
int main()
{
	int st,y,m,d,en,X,Y,sum,ym,mm,dm,M;
	printf("请输入开始日期：（格式：年/月/日）\n"); 
	scanf("%d/%d/%d",&ym,&mm,&dm); 
	printf("请输入结束日期：（格式：年/月/日）\n");
	scanf("%d/%d/%d",&y,&m,&d);
	en=y;st=ym; 
	M=countday(ym,mm,dm);
	X=countday(y,m,d);
	Y=countyear(st,en);
	sum=X+Y-M;
	printf("天数为：%d",sum);
	return 0;
}

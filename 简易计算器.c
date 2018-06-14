#include<stdio.h>
int main()
{
	int X, Y;
	int Z, R;
	printf("请输入两位数字：\n");
	scanf("%d %d", &X, &Y);
	printf("请选择需要的运算方式：1:+；2:-；3:*；4:/\n");
	scanf("%d", &Z);
	if(Z==1)
	{printf("结果为：%d\n", X+Y);}
	else if(Z==2)
	 {printf("结果为：%d\n", X-Y);}
	 else if(Z==3)
	  {printf("结果为：%d\n", X*Y);}
	   else if(Z==4)
	   {printf("结果为：%d\n", X/Y);}
	return 0;
}

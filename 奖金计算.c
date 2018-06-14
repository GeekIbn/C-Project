#include<stdio.h>
int main()
{
 long int m, bonus10, bonus20, bonus40, bonus60, bonus100, bonus;
 printf("输入利润额：\n");
 scanf("%ld",&m);
 bonus10=100000*0.1;bonus20=bonus10+100000*0.75;bonus40=bonus20+200000*0.05;bonus60=bonus40+200000*0.03;bonus100=bonus60+400000*0.015;
 if (m<=100000)
 bonus=m*0.1;
 else if (m<=200000)
 bonus=bonus10+(m-100000)*0.075;
 else if (m<=400000)
 bonus=bonus20+(m-200000)*0.05;
 else if (m<=600000)
 bonus=bonus40+(m-400000)*0.03;
 else if (m<=1000000)
 bonus=bonus60+(m-600000)*0.015;
 else if (m>1000000)
 bonus=bonus100+(m-1000000)*0.01;
 printf("%ld\n", bonus);
 return 0;
}

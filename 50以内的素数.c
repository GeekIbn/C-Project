#include<stdio.h>
int main()
{
 int m,n,c;
 for (m=2;m<=50;m++)
 {
  for (n=2;n<=m;n++)
  {
   c=m%n;
   if (c==0)
   break;
  }
  if (m==n)
  printf("%d\n", m);
 }
 return 0;
}

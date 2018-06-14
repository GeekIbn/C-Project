#include<stdio.h>
int main()
{
 int x,y,z,s,m;
 for (x=0;x<=9;x++)
 {for (y=0;y<=9;y++)
  {for (z=0;z<=9;z++)
  { s=x*x*x+y*y*y+z*z*z;
    m=x*100+y*10+z*1;
   if (s==m)
   printf("%d%d%d\n",x,y,z);
  }
  }
 }
 return 0;
}

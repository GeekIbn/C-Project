#include<stdio.h>
int main()
{
 long int x, y, z, w, a;
 for(x=1;x<=4;x=x+1)
  {for(y=1;y<=4;y=y+1)
   {for(z=1;z<=4;z=z+1)
    {for(w=1;w<=4;w=w+1)
    /* {for(a=1;a<=4;a=a+1)*/
     { if(x!=y&&x!=w&&x!=z&&/*x!=a&&y!=a&&*/y!=z&&y!=w&&z!=w/*&&z!=a&&w!=a*/)
      printf("%ld%ld%ld%ld\n", x,y,z,w);
     } 
     }
    }
   }
  
 return 0;
}

#include<stdio.h>
#include<math.h>
void move(int n,char one,char two,char three)  
{  
    if(n==1)  
        printf("%c->%c\n",one,three);   
    else  
    {     
        move(n-1,one,three,two);            
        printf("%c->%c\n",one,three);    
        move(n-1,two,one,three);           
    }     
}  
   
int main()  
{  
    int n,
    	m;
    printf("storey of hanoi:");   
    scanf("%d",&n);  
    m=pow(2,n)-1;
    printf("Moving %d storeies needs %d times movement:",n,m);
    move(n,'a','b','c');  
}  

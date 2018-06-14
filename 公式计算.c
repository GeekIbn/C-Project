#include<stdio.h>
int main()
{
float F, W, M, S;
F=1.0;W=1.0;M=2.0;S=1.0;
	do
	{	
	F=(-1)*F;
	W=F*(1/M);
	S=S+W;
	M=M+1;
	}
	while(M<=100);
	
	printf("%f\n", S);

return 0;
}

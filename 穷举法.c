#include<stdio.h>
int main()
{
	int man, woman, kid;
	for (man=1;man<=28;man++)
	for (woman=1;woman<=28;woman++)
	for (kid=1;kid<=28;kid++)
	{
	if ((man*3+woman*2+kid)==50&&man+woman+kid==30)
	printf("man=%d,woman=%d,kid=%d\n", man, woman, kid);
    }
	return 0;
}

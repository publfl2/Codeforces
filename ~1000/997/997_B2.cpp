#include <stdio.h>

int main()
{
	int a;
	long long int s;
	scanf("%d",&a);
	s = (long long int)(a+3)*(a+2)*(a+1)/6; // 4Ha = a+3Ca = a+3C3
	/*if(a>=9)
	{
		if(a>=105) s -= (104-8);
		else s -= (a-8);
	}
	if(a>=10)
	{
		if(a>=106) s -= (105-9);
		else s -= (a-9);
	}*/
	printf("%lld",s);
}

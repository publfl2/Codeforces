#include <stdio.h>

int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	if(2*a-1<b)
	{
		printf("0");
		return 0;
	}
	else
	{
		int min = 1>a-b?1:a-b;
	}
}

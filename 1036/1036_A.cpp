#include <stdio.h>

int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	printf("%lld",((b-1)/a)+1);
}

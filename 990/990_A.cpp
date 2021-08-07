#include <stdio.h>

int main()
{
	long long int a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	long long int e = (b-a%b)*c;
	long long int f = (a%b)*d;
	printf("%lld",e<f?e:f);
}

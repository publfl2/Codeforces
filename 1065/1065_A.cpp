#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		long long int n = a/d;
		long long int k = n/b;
		printf("%lld\n",k*(c+b)+(n-k*b));
	}
}

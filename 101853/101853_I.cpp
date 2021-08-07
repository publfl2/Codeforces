#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(c%2==0) printf("%lld\n",(c*c)/2);
		else printf("%lld.50000\n",(c*c)/2);
	}
	
}

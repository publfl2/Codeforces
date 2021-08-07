#include <stdio.h>

int main()
{
	long long int a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	
	long long int s = 0;
	s += a/c, a%=c;
	s += b/c, b%=c;
	if(a+b>=c) printf("%lld %lld",s+1,c-a<c-b?c-a:c-b);
	else printf("%lld 0",s);
}

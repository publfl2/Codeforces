#include <stdio.h>

int main()
{
	long long int a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	if(a>c)
	{
		printf("1 %lld\n",c+1);
		return 0;
	}
	else
	{
		long long int k = (c-a);
		long long int s = k/(b-1);
		long long int t = k%(b-1);
		if(s%2==0) printf("%lld %lld\n",a-s,2+t);
		else printf("%lld %lld\n",a-s,b-t);
	}
}

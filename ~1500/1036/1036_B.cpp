#include <stdio.h>

long long int max(long long int a, long long int b)
{
	return a>b?a:b;
}
long long int ans(long long int a,long long int b, long long int c)
{
	if((c-a)%2==0) return c;
	else return c-2;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(max(a,b)>c)
		{
			printf("-1\n");
			continue;
		}
		if(a<b)
		{
			long long int d = a;
			a = b;
			b = d;
		}
		if((a-b)%2==0)
		{
			printf("%lld\n",ans(a,b,c));
		}
		else
		{
			long long int x1 = ans(a-1,b,c-1);
			long long int x2 = ans(a,b-1,c-1);
			printf("%lld\n",x1>x2?x1:x2);
		}
	}
}

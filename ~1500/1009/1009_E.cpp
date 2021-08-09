#include <stdio.h>
#define MOD 998244353

int x[1000010];
long long int y[1000010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) y[i] = y[i-1]+x[i],y[i]%=MOD;
	
	long long int sum1 = 0;
	long long int sum2 = 0;
	
	for(int i=1;i<a;i++)
	{
		long long int s = sum1 + sum2 + y[i];
		s%=MOD;
		
		sum1 += s;
		sum1 %= MOD;
		sum2 *= 2;
		sum2 += y[i];
		sum2 %= MOD;
	}
	printf("%lld",(sum1+sum2+y[a])%MOD);
}



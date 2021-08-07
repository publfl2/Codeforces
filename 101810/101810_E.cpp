#include <stdio.h>
#define MOD 1000000007

long long int getInverse(long long int k)
{
	long long int p = MOD-2;
	long long int ans = 1;
	long long int s = k;
	while(p>0)
	{
		if(p%2==1) ans*=s,ans%=MOD;
		p/=2;
		s*=s,s%=MOD;
	}
	return ans;
}


long long int x[1000010];
long long int table[1000010];
int main()
{
	for(int i=1;i<=100000;i++) table[i] = getInverse(i);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		
		long long int t = 1;
		for(int i=1;i<=a;i++) t*=x[i],t%=MOD;
		long long int sum1 = (a*t)%MOD;
		
		long long int sum2 = 0;
		for(int i=1;i<=a;i++) sum2 += table[x[i]],sum2%=MOD;
		sum2 = (sum2*t)%MOD;
		printf("%lld\n",(sum1-sum2+MOD)%MOD);
	}
}

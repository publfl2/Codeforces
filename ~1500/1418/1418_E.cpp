#include <stdio.h>
#include <algorithm>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int s = a;
	while(b)
	{
		if(b%2==1) ans*=s, ans%=MOD;
		b/=2;
		s*=s, s%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int x[200010],sum[200010];
long long int fact[200010];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=200000;i++)
	{
		fact[i] = fact[i-1]*i;
		fact[i] %= MOD;
	}
	
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	std::sort(x+1,x+a+1);
	for(int i=1;i<=a;i++) sum[i] = sum[i-1]+x[i];
	
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		int min = 1, max = a;
		int ind = a+1;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(x[h]>=d)
			{
				ind = h;
				max = h-1;
			}
			else min = h+1;
		}
		int s = ind-1;
		int t = a-ind+1;
		long long int sum2 = sum[ind-1]%MOD;
		long long int sum1 = (sum[a]-sum[ind-1])%MOD;
		
		if(t<c) printf("0\n");
		else
		{
			long long int ans = 0;
			
			if(t>c)
			{
				long long int S1 = fact[t-1];
				S1 *= inv(fact[t-1-c]), S1%=MOD;
				S1 *= fact[s], S1%=MOD;
				S1 *= fact[t-c], S1 %= MOD;
				ans += S1*sum1, ans%=MOD;
			}
			
			if(s>0)
			{
				long long int S2 = (t+1-c);
				S2 *= fact[t+s], S2%=MOD;
				S2 *= inv(fact[t+1]), S2%=MOD;
				S2 *= fact[t], S2 %= MOD;
				ans += S2*sum2, ans%=MOD;
			}
			
			ans *= inv(fact[a]), ans%=MOD;
			printf("%lld\n",ans);
		}
	}
}

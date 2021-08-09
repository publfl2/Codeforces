#include <stdio.h>
#include <map>
#define MOD 1000000007

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k =a;
	while(b)
	{
		if(b%2==1) ans*=k, ans %=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[200010];
std::map<int,int> count;
int x[100010];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=200000;i++) fact[i] = (i*fact[i-1])%MOD;
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	long long int sum = 0;
	for(int i=1;i<=a;i++) sum += x[i];
	if(sum%a!=0)
	{
		printf("0");
		return 0;
	}
	sum/=a;
	
	int R = 0, L = 0, M =0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]>sum) R++;
		else if(x[i]<sum) L++;
		else M++;
	}
	if(R<=1 || L<=1) printf("%lld\n",fact[a]);
	else
	{
		long long int ans = 2*fact[a];
		ans *= fact[L], ans %= MOD;
		ans *= fact[R], ans %= MOD;
		ans *= inv(fact[M]), ans %= MOD;
		ans *= inv(fact[L+R]), ans %= MOD;
		
		for(int i=1;i<=a;i++) count[x[i]]++;
		for(std::map<int,int> ::iterator it = count.begin();it!=count.end();it++)
		{
			if((it->first)!=sum) ans *= inv(fact[it->second]), ans %= MOD;
		}
		printf("%lld\n",ans);
	}
}
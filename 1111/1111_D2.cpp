#include <stdio.h>
#include <string.h>
#define MOD 1000000007
long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans *=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[100010];
long long int comb(int s, int t)
{
	long long int ans = fact[s];
	ans *= inv(fact[t]), ans %= MOD;
	ans *= inv(fact[s-t]), ans %= MOD;
	return ans;
}

int hash(char c)
{
	if('a'<=c&&c<='z') return c-'a';
	if('A'<=c&&c<='Z') return c-'A'+26;
}

int count[110];
char x[100010];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=100000;i++) fact[i] = fact[i-1]*i, fact[i] %= MOD;
	
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++) count[hash(x[i])]++;
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(x[c]==x[d])
		{
			if(count[hash(x[c])] <= a/2)
			{
				long long int ans = 2*comb(a/2,count[hash(x[c])]);
				ans %= MOD;
				for(int j=0;j<52;j++)
				{
					if(hash(x[c])==j) continue;
					ans *= inv(fact[count[j]]);
					ans %= MOD;
				}
				ans *= fact[a-count[hash(x[c])]];
				ans %= MOD;
				printf("%lld\n",ans%MOD);
			}
			else printf("0\n");
		}
		else
		{
			if(count[hash(x[c])]+count[hash(x[d])] <= a/2)
			{
				long long int ans = 2*comb(a/2,count[hash(x[c])]);
				ans %= MOD;
				ans *= comb(a/2-count[hash(x[c])],count[hash(x[d])]);
				ans %= MOD;
				for(int j=0;j<52;j++)
				{
					if(hash(x[d])==j) continue;
					if(hash(x[c])==j) continue;
					ans *= inv(fact[count[j]]);
					ans %= MOD;
				}
				ans *= fact[a-count[hash(x[c])]-count[hash(x[d])]];
				ans %= MOD;
				printf("%lld\n",ans%MOD);
			}
			else printf("0\n");
		}
	}
}

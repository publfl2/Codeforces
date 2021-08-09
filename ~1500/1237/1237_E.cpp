#include <stdio.h>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int s = a;
	while(b)
	{
		if(b%2==1) ans*=s, ans%=MOD;
		s*=s, s%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[1000010];
long long int comb(int a, int b)
{
	long long int ans = fact[a];
	ans *= inv(fact[a-b]), ans%=MOD;
	ans *= inv(fact[b]), ans%=MOD;
	return ans;
}

int main()
{
	fact[0] = 1;
	for(int i=1;i<=1000000;i++) fact[i] = fact[i-1]*i, fact[i]%=MOD;
	
	int a;
	scanf("%d",&a);
	
	int C = 0;
	int k = 0;
	for(int i=0;;i++)
	{
		C += (1<<i);
		if(C+(1<<(i+1))>a)
		{
			k = (1<<i);
			break;
		}
	}
	
	int type1 = C/2;
	int type2 = (C+1)/2;
	int odd = (a+1)/2;
	int even = (a/2);
	
	long long int ans = 0;
	
	if(a%2==0)
	{
		int L1 = odd - type1;
		int R1 = even - type2;
		if(L1==R1+1||L1==R1) ans += comb(k-1,R1);
	}
	else
	{
		int L2 = odd - type2;
		int R2 = even - type1;
		if(R2==L2+1||R2==L2) ans += comb(k-1,L2);
	}
	
	printf("%lld",ans);
}

#include <stdio.h>
#define MOD 1000000007

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans %= MOD;
		k*=k;
		b/=2, k%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[3000010];
long long int comb(int a, int b)
{
	if(a<b) return 0;
	long long int ans = fact[a];
	ans *=inv(fact[b]), ans %= MOD;
	ans *= inv(fact[a-b]), ans %= MOD;
	return ans;
}

int main()
{
	fact[0] = 1;
	for(int i=1;i<=3000000;i++) fact[i] = (i*fact[i-1])%MOD;
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		long long int s1 = comb(3*a+1,c+1);
		long long int s2 = comb(3*a,c);
		long long int s3 = comb(3*a-1,c);
		printf("%lld %lld %lld!!\n",s1,s2,s3);
		long long int sum = (s1+s2+s3)%MOD;
		//sum *= inv(3), sum %= MOD;
		printf("%lld\n",sum);
	}
}
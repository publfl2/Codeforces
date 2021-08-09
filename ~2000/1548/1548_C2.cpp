#include <stdio.h>
#include <vector>
#define MOD 1000000007




long long int fact[3000010];
long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans %= MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int comb(int a, int b)
{
	if(a<b) return 0;
	long long int ans = fact[a];
	ans *= inv(fact[b]), ans %= MOD;
	ans *= inv(fact[a-b]), ans %= MOD;
	return ans;
}

std::vector<long long int> poly(int k)
{
	std::vector<long long int> temp;
	for(int i=0;i<=k;i++) temp.push_back((long long int)comb(k,i));
	return temp;
}

std::vector<long long int> func(int k)
{
	if(k==0)
	{
		std::vector<long long int> temp;
		temp.push_back(1);
		return temp;
	}
	
	// 0 ~ k
	if(k%2==1)
	{
		std::vector<long long int> temp = func((k-1)/2);
		std::vector<long long int> P = poly(3*((k+1)/2));
		P[0]++;
		return atcoder::convolution<MOD>(temp,P);
	}
	else
	{
		std::vector<long long int> temp = func(k-1);
		std::vector<long long int> P = poly(3);
		std::vector<long long int> temp2 = atcoder::convolution<MOD>(temp,P);
		temp2[0]++;
		return temp2;
	}
}

std::vector<long long int> ans;
int main()
{
	fact[0] = 1;
	for(int i=1;i<=3000000;i++) fact[i] = (i*fact[i-1])%MOD;
	
	int a,b;
	scanf("%d%d",&a,&b);
	ans = func(a);
	for(int i=0;i<ans.size();i++) printf("%lld ",ans[i]);
	printf("!!\n");
	
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		printf("%lld\n",ans[c]);
	}
}
#include <stdio.h>
#include <vector>
#define MOD 998244353

long long int inv(long long int k)
{
	int t = MOD-2;
	long long int ans = 1;
	long long int s = k;
	while(t)
	{
		if(t%2==1) ans*=s,ans%=MOD;
		s*=s, s%=MOD;
		t/=2;
	}
	return ans;
}

int x[1000010];
long long int count1[1000010],count2[1000010];
long long int z[1000010];
std::vector<int> y[1000010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&x[i]);
		for(int j=0;j<=x[i]+1;j++) y[i].push_back(0);
		for(int j=1;j<=x[i];j++) scanf("%d",&y[i][j]);
		for(int j=1;j<=x[i];j++) count2[y[i][j]]++;
	}
	long long int k = 1;
	for(int i=1;i<=a;i++) k*=x[i],k%=MOD;
	for(int i=1;i<=a;i++) z[i] = k*inv(x[i])%MOD;
	
	for(int i=1;i<=a;i++) for(int j=1;j<=x[i];j++) count1[y[i][j]]+=z[i], count1[y[i][j]]%=MOD;
	
	long long int s = 0;
	for(int i=1;i<=1000000;i++) s += count1[i]*count2[i]%MOD, s%=MOD;
	long long int t = a*a%MOD;
	t*=k, t%=MOD;
	
	printf("%lld %lld\n",s,t);
	// ans = s/t
	s%=MOD, t%=MOD;
	printf("%lld",s*inv(t)%MOD);
	
}

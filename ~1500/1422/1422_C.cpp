#include <stdio.h>
#include <string.h>
#define MOD 1000000007
char x[100010];
int y[100010];
long long int DP[100010],DP2[100010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++) y[i] = x[i]-'0';
	DP[0] = 1;
	for(int i=1;i<=a;i++)
	{
		DP[i] = 10*DP[i-1]+1;
		DP[i] %= MOD;
	}
	DP2[0] = 1;
	for(int i=1;i<=a;i++)
	{
		DP2[i] = 10*DP2[i-1];
		DP2[i] %= MOD;
	}
	
	long long int ans = 0;
	long long int S = 0;
	for(int i=1;i<a;i++)
	{
		S*=10;
		S += y[i];
		S%=MOD;
		
		ans += (S*DP[a-i-1]);
		ans += MOD;
	}
	S = 0;
	for(int i=a;i>=2;i--)
	{
		S += DP2[a-i]*y[i];
		S%=MOD;
		
		ans += (S*(i-1));
		ans %= MOD;
	}
	printf("%lld",ans);
}

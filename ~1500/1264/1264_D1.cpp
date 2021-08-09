#include <stdio.h>
#include <string.h>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[2000010];
long long int comb(int a, int b)
{
	if(a<b) return 0;
	if(b<0) return 0;
	
	long long int ans = fact[a];
	ans *= inv(fact[b]), ans %= MOD;
	ans *= inv(fact[a-b]), ans %= MOD;
	return ans;
}

char x[1000010];
int left[1000010],right[1000010],left2[1000010],right2[1000010];
long long int check1[2000010],check2[2000010];

int main()
{
	fact[0] = 1;
	for(int i=1;i<=2000000;i++) fact[i] = (fact[i-1]*i)%MOD;
	
	scanf("%s",x+1);
	int a = strlen(x+1);
	
	for(int i=1;i<=a;i++) if(x[i]=='(') left[i] = 1;
	for(int i=1;i<=a;i++) if(x[i]==')') right[i] = 1;
	for(int i=1;i<=a;i++) if(x[i]=='?') left2[i] = right2[i] = 1;
	for(int i=1;i<=a;i++) left[i] += left[i-1];
	for(int i=1;i<=a;i++) left2[i] += left2[i-1];
	for(int i=a;i>=1;i--) right[i] += right[i+1];
	for(int i=a;i>=1;i--) right2[i] += right2[i+1];
	
	for(int i=0;i<=left2[a];i++) check1[i] = comb(left2[a],i);
	for(int i=1;i<=left2[a];i++) check1[i] += check1[i-1], check1[i] %= MOD;
	for(int i=0;i<left2[a];i++) check2[i] = comb(left2[a]-1,i);
	for(int i=1;i<left2[a];i++) check2[i] += check2[i-1], check2[i] %= MOD;
 	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int s1 = left[i-1], s2 = left2[i-1];
		int t1 = right[i+1], t2 = right2[i+1];
		int m = s2+t2<t2+t1-s1-1?s2+t2:t2+t1-s1-1;
		if(m<0) continue;
		if(s2+t2==left2[a]) ans += check1[m], ans %= MOD;
		else ans += check2[m], ans %= MOD;
	}
	printf("%lld",ans);
}
#include <stdio.h>
#define MOD 1000000007
long long int x[1000010],y[1000010];
int a,b;
long long int power(int a, int b)
{
	//a^b
	long long int ans = 1;
	long long int s = a;
	long long int t = b;
	while(t)
	{
		if(t%2==1) ans *= s, ans %= MOD;
		s *= s, s %= MOD;
		t /= 2;
	}
	return ans;
}
long long int func(int k)
{
	if(k>b) return 0;
	else return power(k,b-k);
	//k^(b-k)
	//s1 + ... + sk = b
}
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=2;i<=a;i++)
	{
		x[i] = func(i-1);
		for(int j=1;j<=i-2;j++) x[i] *= (a-1-j);
		y[i] = power(b,a-i); // b^(a-i)
	}
	
	long long int sum = 0;
	for(int i=1;i<=a;i++) printf("%lld ",x[i]);
	printf("\n");
	for(int i=1;i<=a;i++) printf("%lld ",y[i]);
	//for(int i=1;i<=a;i++) sum += (x[i]*y[i])%MOD, sum %= MOD;
	//printf("%lld",sum);
}

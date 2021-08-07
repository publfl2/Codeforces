#include <stdio.h>
#define MOD 1000000007
int a,b;
int x[2010][2010];
long long int check[2010][2010];
long long int func(int s, int t)
{
	if(s>a)
	{
		if(t==(1<<b)-1) return 1;
		else return 0;
	}
	if(check[s][t]!=-1) return check[s][t];
	long long int ans = 0;
	for(int i=s-b;i<=s+b;i++)
	{
		if(i<1) continue;
		if(i>a) continue;
		if((t&(1<<(i-s+b)))>0) continue;
		if(x[s][i]) continue;
		ans += func(s+1,(t+(1<<(i-s+b)))/2);
		ans %= MOD;
	}
	return check[s][t] = ans;
}

int main()
{
	int c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<=a+1;i++) for(int j=0;j<=(1<<10);j++) check[i][j] = -1;
	for(int i=1;i<=c;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		x[d][e] = 1;
	}
	printf("%lld",func(1,0));
}

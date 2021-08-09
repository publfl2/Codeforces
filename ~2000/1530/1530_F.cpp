#include <stdio.h>
#define MOD 31607

int power(int a, int b)
{
	int ans = 1;
	int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans %= MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}
int inv(int k)
{
	return power(k,MOD-2);
}

int x[110][110],check[110][110],y[110];
int DP[110][3];
int ans[3];
int a;

void func(int k, int parity, int C)
{
	if(k>a)
	{
		DP[0][0] = 1;
		DP[0][1] = 0;
		for(int i=1;i<=a;i++)
		{
			DP[i][0] = DP[i-1][0], DP[i][1] = DP[i-1][1];
			DP[i][0] += (DP[i-1][1] * y[i])%MOD, DP[i][0] % MOD;
			DP[i][1] += (DP[i-1][0] * y[i])%MOD, DP[i][1] % MOD;
		}
		ans[parity%2] += (DP[a][0]*C)%MOD;
		ans[(parity+1)%2] += (DP[a][1]*C)%MOD;
		ans[0] %= MOD, ans[1] %= MOD;
		
		return;
	}
	
	func(k+1,parity,C);
	int C2 = 1;
	for(int j=1;j<=a;j++)
	{
		if(check[k][j]==1) continue;
		C2 *= x[k][j], C2 %= MOD;
		y[j] *= inv(x[k][j]), y[j] %= MOD;
	}
	func(k+1,parity+1,(C*C2)%MOD);
	for(int j=1;j<=a;j++)
	{
		if(check[k][j]==1) continue;
		y[j] *= x[k][j], y[j] %= MOD;
	}
}

void init(int parity, int type)
{
	for(int j=1;j<=a;j++)
	{
		y[j] = 1;
		for(int i=1;i<=a;i++) if(check[i][j]==0) y[j] *= x[i][j], y[j] %= MOD;
	}
	func(1,parity,type);
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) scanf("%d",&x[i][j]);
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) x[i][j] *= inv(10000), x[i][j] %= MOD;
	
	int C;
	//0 0
	init(0,1);
	
	// 1 0
	C = 1;
	for(int i=1;i<=a;i++) check[i][i] = 1, C *= x[i][i], C %= MOD;
	init(1,C);
	for(int i=1;i<=a;i++) check[i][i] = 0;
	
	// 0 1
	C = 1;
	for(int i=1;i<=a;i++) check[i][a-i+1] = 1, C *= x[i][a-i+1], C %= MOD;
	init(1,C);
	
	// 1 1
	for(int i=1;i<=a;i++)
	{
		if(check[i][i]==0)
		{
			check[i][i] = 1;
			C *= x[i][i], C %= MOD;
		}
	}
	init(0,C);
	ans[0]+= (MOD-1), ans[0] %= MOD;
	printf("%d",(ans[1]-ans[0]+MOD)%MOD);
}
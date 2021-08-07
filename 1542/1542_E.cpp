#include <stdio.h>

long long int MOD;

long long int check1[150010],check2[150010],sum[150010],sum2[150010];
long long int DP[510];

int main()
{
	int a;
	scanf("%d%lld",&a,&MOD);
	if(a==1)
	{
		printf("0");
		return 0;
	}
	
	check1[0] = 1;
	DP[1] = 0;
	for(int i=2;i<=a;i++)
	{
		int SIZE = i*(i+1)/2;
		
		sum[0] = check1[0];
		for(int k=1;k<=SIZE;k++) sum[k] = (sum[k-1]+check1[k])%MOD;
		sum2[0] = sum[0];
		for(int k=1;k<=SIZE;k++) sum2[k] = (sum2[k-1]+sum[k])%MOD;
		
		for(int k=2;k<=SIZE;k++)
		{
			if(k-i-1<0)
			{
				long long int t = sum2[k-2];
				t %= MOD;
				long long int t2 = i*sum[k-2];
				t2 %= MOD;
				t = (t2+MOD-t)%MOD;
				t *= check1[k], t %= MOD;
				DP[i] += t, DP[i] %= MOD;
			}
			else
			{
				long long int t = sum2[k-2] + (MOD-sum2[k-i-1]);
				t %= MOD;
				long long int t2 = i*(sum[k-2]+MOD-sum[k-i-1]);
				t2 %= MOD;
				t = (t2+MOD-t)%MOD;
				t *= check1[k], t %= MOD;
				DP[i] += t, DP[i] %= MOD;
			}
		}
		
		long long int S2 = 1;
		for(int k=i-1;k>=1;k--)
		{
			S2 *= (k+1), S2 %= MOD;
			long long int t = (S2*DP[k])%MOD;
			DP[i] += t, DP[i] %= MOD;
		}
		
		SIZE += i;
		long long int S = 0;
		for(int k=0;k<i;k++)
		{
			S += check1[k], S %= MOD;
			check2[k] = S;
		}
		for(int k=i;k<=SIZE;k++)
		{
			S += (MOD-check1[k-i]), S %= MOD;
			S += check1[k], S %= MOD;
			check2[k] = S;
		}
		for(int k=0;k<=SIZE;k++) check1[k] = check2[k];
	}
	printf("%lld",DP[a]);
}
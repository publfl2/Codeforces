#include <stdio.h>
#define MOD 998244353

long long int check[510][510];
int parent1[510],parent2[510],check2[510];
int x[510];
int main()
{
	int a,b; // a=b
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			if(x[j]<x[i])
			{
				parent1[x[i]] = x[j];
				check2[x[j]] = 1;
				break;
			}
		}
		for(int j=i+1;j<=a;j++)
		{
			if(x[j]<x[i])
			{
				parent2[x[i]] = x[j];
				check2[x[j]] = 1;
				break;
			}
		}
	}
	
	check[1][1] = 1;
	for(int i=2;i<=a;i++)
	{
		if(parent1[i]>0&&parent2[i]>0)
		{
			if(parent1[i]>parent2[i])
			{
				int s = parent1[i];
				for(int j=1;j<=a;j++)
				{
					for(int k=1;k<=j+1;k++)
					{
						check[i][k] += check[s][j];
						check[i][k] %= MOD;
					}
				}
				
			}
			if(parent2[i]>parent1[i])
			{
				int s = parent2[i];
				for(int j=1;j<=a;j++)
				{
					for(int k=1;k<=j+1;k++)
					{
						check[i][k] += check[s][j];
						check[i][k] %= MOD;
					}
				}
				
			}
		}
		else
		{
			if(parent1[i]>0)
			{
				int s = parent1[i];
				for(int j=1;j<=a;j++)
				{
					for(int k=1;k<=j+1;k++)
					{
						check[i][k] += check[s][j];
						check[i][k] %= MOD;
					}
				}
			}
			if(parent2[i]>0)
			{
				int s = parent2[i];
				for(int j=1;j<=a;j++)
				{
					for(int k=1;k<=j+1;k++)
					{
						check[i][k] += check[s][j];
						check[i][k] %= MOD;
					}
				}
			}
		}
	}
	
	long long int ans = 1;
	for(int i=1;i<=a;i++)
	{
		if(check2[i]==0)
		{
			long long int sum = 0;
			for(int j=1;j<=a;j++)
			{
				sum += check[i][j];
				sum%=MOD;
			}
			ans *= sum;
		}
	}
	printf("%lld",ans);
}

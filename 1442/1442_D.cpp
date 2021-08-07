#include <stdio.h>
#include <vector>

long long int DP[3010][3010];
int opt[3010][3100];
std::vector<int> V[3010];
std::vector<long long int> sum[3010];
long long int MIN = -1;
int gap = 20;
int main()
{
	for(int i=1;i<=13;i++) MIN*=10;
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		V[i].push_back(0);
		for(int j=1;j<=c;j++)
		{
			int d;
			scanf("%d",&d);
			V[i].push_back(d);
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		sum[i].push_back(0);
		for(int j=1;j<V[i].size();j++)
		{
			sum[i].push_back(sum[i].back()+V[i][j]);
		}
	}
	
	for(int i=0;i<b;i++) DP[a+1][i] = MIN;
	DP[a+1][b] = 0;
	for(int i=a;i>=1;i--)
	{
		//DP[i][b];
		DP[i][b] = DP[i+1][b];
		opt[i][b] = 0;
		for(int j=b-1;j>=0;j--)
		{
			DP[i][j] = DP[i+1][j];
			opt[i][j] = 0;
			for(int k=opt[i][j+1]-gap;k<=opt[i][j+1]+gap;k++)
			{
				if(k<0) continue;
				if(k>V[i].size()) continue;
				if(j+k>b) continue;
				
				if(DP[i][j]<DP[i+1][j+k]+sum[i][k])
				{
					DP[i][j] = DP[i+1][j+k]+sum[i][k];
					opt[i][j] = k;
				}
			}
		}
	}
	printf("%lld",DP[1][0]);
}

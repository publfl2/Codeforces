#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}

long long int DP[4][4][4][4][5010];
int x2[5010],y2[5010];
int x[5010],y[4][5010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x2[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y2[i]);
		int p = 1;
		x[p] = x2[1];
		y[0][p] = y2[1];
		y[1][p] = y2[1];
		
		for(int i=2;i<=a;i++)
		{
			if(x2[i]==x2[i-1])
			{
				y[0][p] = y[0][p]<y2[i]?y[0][p]:y2[i];
				y[1][p] = y[1][p]>y2[i]?y[1][p]:y2[i];
			}
			else
			{
				p++;
				x[p] = x2[i];
				y[0][p] = y2[i];
				y[1][p] = y2[i];
			}
		}
		a = p;
		
		for(int i=1;i<=a;i++) for(int j=0;j<=1;j++) for(int k=0;k<=1;k++) DP[1][0][j][k][i] = DP[1][1][j][k][i] = 0;
		for(int j=2;j<=a;j++)
		{
			for(int i=1;i+j-1<=a;i++)
			{
				for(int L=0;L<=1;L++)
				{
					for(int R=0;R<=1;R++)
					{
						long long int temp1;
						long long int s1 = 0;
						if(i+j-2!=i)
						{
							for(int k=0;k<=1;k++)
							{
								temp1 = DP[1-j%2][1][L][k][i] + abs(y[k][i+j-2]-y[R][i+j-1]) + (x[i]==x[i+j-1]?0:abs(y[L][i]-y[R][i+j-1]));
								s1 = s1>temp1?s1:temp1;
							}
						}
						long long int s2 = 0;
						for(int k=0;k<=1;k++)
						{
							temp1 = DP[1-j%2][1][k][R][i+1] + (x[i]==x[i+j-1]?0:abs(y[L][i]-y[R][i+j-1]));
							s2 = s2>temp1?s2:temp1;
						}
						long long int val = s1;
						val = val>s2?val:s2;
						DP[j%2][0][L][R][i] = val;
						
						s1 = 0;
						for(int k=0;k<=1;k++)
						{
							temp1 = DP[1-j%2][0][L][k][i] + (x[i]==x[i+j-1]?0:abs(y[L][i]-y[R][i+j-1]));
							s1 = s1>temp1?s1:temp1;
						}
						s2 = 0;
						for(int k=0;k<=1;k++)
						{						
							temp1 = DP[1-j%2][1][k][R][i] + abs(y[k][i+j-2]-y[R][i+j-1]);
							s2 = s2>temp1?s2:temp1;
						}
						val = s1;
						val = val>s2?val:s2;
						DP[j%2][1][L][R][i] = val;
					}
				}
			}
		}
		
		long long int ans = 0;
		for(int i=0;i<=1;i++)
		{
			for(int j=0;j<=1;j++)
			{
				for(int k=0;k<=1;k++)
				{
					ans = ans>DP[a%2][i][j][k][1]?ans:DP[a%2][i][j][k][1];
				}
			}
		}
		printf("%lld\n",ans);
	}
}
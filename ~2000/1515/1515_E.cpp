#include <stdio.h>
#include <atcoder/convolution>

std::vector<long long int> DP[5][410];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	for(int k=0;k<=a;k++)
	{
		for(int type=1;type<=3;type++)
		{
			printf("%d %d??\n",k,type);
			DP[type][k].resize(a+1);
			if(type==1)
			{
				if(k==0) DP[type][k][0] = 1;
				else if(k==1) DP[type][k][0] = 1;
				else if(k==2) DP[type][k][1] = 2;
				else if(k==3)
				{
					DP[type][k][1] = 1;
					DP[type][k][2] = 4;
				}
				else
				{
					for(int j=0;j<DP[type][k-1].size();j++) DP[type][k][j+1] += 2*DP[type][k-1][j], DP[type][k][j+1] %= b;
					for(int j=0;j<DP[type][k-2].size();j++) DP[type][k][j+1] += 2*DP[type][k-2][j], DP[type][k][j+1] %= b;
					for(int j=2;j<=k-3;j++)
					{
						std::vector<long long int> temp = atcoder::convolution(DP[type][j],DP[type][k-j-1]);
						for(int i=0;i<temp.size();i++) DP[type][k][i+1] += temp[i], DP[type][k][i+1] %= b;
					}
				}
			}
			else if(type==2)
			{
				if(k==0) DP[type][k][0] = 1;
				else if(k==1) DP[type][k][1] = 1;
				else if(k==2) DP[type][k][2] = 2;
				else
				{
					for(int j=0;j<DP[type][k-1].size();j++) DP[type][k][j+1] += 2*DP[type][k-1][j], DP[type][k][j+1] %= b;
					for(int j=0;j<DP[type][k-2].size();j++) DP[type][k][j+1] += 2*DP[type][k-2][j], DP[type][k][j+1] %= b;
					for(int j=2;j<=k-1;j++)
					{
						std::vector<long long int> temp = atcoder::convolution(DP[1][j],DP[type][k-j-1]);
						for(int i=0;i<temp.size();i++) DP[type][k][i+1] += temp[i], DP[type][k][i+1] %= b;
					}
				}
			}
			else
			{
				if(k==0) DP[type][k][0] = 1;
				else if(k==1) DP[type][k][1] = 1;
				else
				{
					for(int j=0;j<=k-1;j++)
					{
						std::vector<long long int> temp = atcoder::convolution(DP[2][j],DP[2][k-j-1]);
						for(int i=0;i<temp.size();i++) DP[type][k][i+1] += temp[i], DP[type][k][i+1] %= b;
					}
				}
			}
			while(!DP[type][k].empty()&&DP[type][k].back()==0) DP[type][k].pop_back();
		}
	}
	for(int i=0;i<DP[3][a].size();i++) printf("%d ",DP[3][a][i]);
}
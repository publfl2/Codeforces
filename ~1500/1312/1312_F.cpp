#include <stdio.h>
#include <vector>
#include <algorithm>
#define SIZE 1000
int x[5];

int check[SIZE+10][2][2];
int func(int s, int t1, int t2)
{
	if(s<=0) return 0;
	if(check[s][t1][t2]!=-1) return check[s][t1][t2];
	std::vector<int> V;
	V.push_back(-1);
	
	V.push_back(func(s-x[1],1,1)); // 1
	if(t1==1) V.push_back(func(s-x[2],0,1));
	if(t2==1) V.push_back(func(s-x[3],1,0)); // 1
	
	std::sort(V.begin(),V.end());
	for(int i=1;i<V.size();i++)
	{
		if(V[i]==V[i-1]) continue;
		if(V[i]!=V[i-1]+1) return check[s][t1][t2] = V[i-1]+1;
	}
	return check[s][t1][t2] = V[V.size()-1]+1;
}

int ans[5][300010];
long long int y[300010];

int P[5][6][6][6];
int z[5][SIZE+10][6][6][6];

int func2(int type, long long int s)
{
	s %= P[type][x[1]][x[2]][x[3]];
	s += P[type][x[1]][x[2]][x[3]];
	return z[type][s][x[1]][x[2]][x[3]];
}
int main()
{
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			for(int k=1;k<=5;k++)
			{
				for(int l=0;l<=SIZE;l++) check[l][1][1] = check[l][1][0] = check[l][0][1] = -1;
				
				x[1] = i, x[2] = j, x[3] = k;
				for(int l=0;l<=SIZE;l++)
				{
					z[1][l][i][j][k] = func(l,1,1);
					z[2][l][i][j][k] = func(l,0,1);
					z[3][l][i][j][k] = func(l,1,0);
				}
				
				for(int t=1;t<=3;t++)
				{
					for(int l=SIZE/3;l>=2;l--)
					{
						P[t][i][j][k] = 12345678;
						for(int l2=0;l2<=l;l2++)
						{
							if(z[t][l2+l][i][j][k]!=z[t][l2+2*l][i][j][k]) goto u;
						}
						P[t][i][j][k] = l;
						break;
						u:;
					}
				}
				
			}
		}
	}
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d%d%d%d",&a,&x[1],&x[2],&x[3]);
		for(int i=1;i<=a;i++) scanf("%lld",&y[i]);
		for(int i=1;i<=a;i++)
		{
			ans[0][i] = func2(1,y[i]);
			ans[1][i] = func2(1,y[i]-x[1]);
			ans[2][i] = func2(2,y[i]-x[2]);
			ans[3][i] = func2(3,y[i]-x[3]);
		}
		
		int G = 0;
		for(int i=1;i<=a;i++) G^=ans[0][i];
		
		int count = 0;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if((G^(ans[0][i]^ans[j][i]))==0) count++;
			}
		}
		printf("%d\n",count);
	}
}

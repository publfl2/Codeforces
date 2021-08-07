#include <stdio.h>
#include <vector>
#include <queue>
 
struct str{
	int first;
	int second;
	int dist;
};
std::queue<str> Q;
 
std::vector<char> x[1000010];
char y[1000010];
std::vector<int> check[1000010],check2[1000010];
int direX[9]={0,1,1,1,0,-1,-1,-1};
int direY[9]={1,1,0,-1,-1,-1,0,1};
 
std::vector< std::pair<int,int> > V[1000010];
std::queue< std::pair<int,int> > Q2;
int func(int s, int t)
{
	check2[s][t] = 1;
	int ans = check[s][t];
	for(int i=0;i<8;i++)
	{
		int s0 = s+direX[i];
		int t0 = t+direY[i];
		if(x[s0][t0]=='X' && check2[s0][t0]==0)
		{
			int k = func(s0,t0);
			ans = ans>k?ans:k;
		}
	}
	return ans;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<=a+1;i++)
	{
		for(int j=0;j<=b+1;j++)
		{
			x[i].push_back('.');
			check[i].push_back(0);
			check2[i].push_back(0);
		}
	}
	for(int i=1;i<=a;i++)
	{
		scanf("%s",y+1);
		for(int j=1;j<=b;j++) x[i][j] = y[j];
	}
	
	for(int i=0;i<=a+1;i++)
	{
		for(int j=0;j<=b+1;j++)
		{
			if(x[i][j]=='.')
			{
				check[i][j] = 1;
				Q.push({i,j,1});
			}
		}
	}
	
	while(!Q.empty())
	{
		str A = Q.front();
		Q.pop();
		
		for(int i=0;i<8;i++)
		{
			int s = A.first + direX[i];
			int t = A.second + direY[i];
			if(s<1 || s>a) continue;
			if(t<1 || t>b) continue;
			if(check[s][t]==0)
			{
				check[s][t] = A.dist + 1;
				Q.push({s,t,A.dist+1});
			}
		}
	}
	
	int ans = 0;
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) ans = ans>check[i][j]?ans:check[i][j];
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='X')
			{
				V[check[i][j]].push_back(std::make_pair(i,j));
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(check[i][j]>=ans)
			{
				check2[i][j] = 1;
				Q2.push(std::make_pair(i,j));
			}
		}
	}
	
	for(int i=ans-1;i>=2;i--)
	{
		std::queue< std::pair<int,int> > Q3;
		while(!Q2.empty())
		{
			int s = Q2.front().first;
			int t = Q2.front().second;
			Q2.pop();
			for(int j=0;j<8;j++)
			{
				int s0 = s+direX[j];
				int t0 = t+direY[j];
				if(check2[s0][t0]==0)
				{
					Q3.push(std::make_pair(s0,t0));
					check2[s0][t0] = 1;
				}
			}
		}
		Q2 = Q3;
		
		for(int j=0;j<V[i].size();j++)
		{
			if(check2[V[i][j].first][V[i][j].second]==0)
			{
				ans = i;
				Q2.push(V[i][j]);
			}
		}
	}
	
	printf("%d\n",ans-2);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(check[i][j]>=ans) printf("X");
			else printf(".");
		}
		printf("\n");
	}
}

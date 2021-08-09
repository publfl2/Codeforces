#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1234578

struct str{
	int x0;
	int y0;
	int z0;
	int prev;
}check[17000];
bool operator<(str a, str b)
{
	return a.z0>b.z0;
}
std::priority_queue<str> Q;

int dist[15][17000][15],prev[15][17000][15];
std::vector<int> V[15];
int type[17000];
std::vector< std::pair<int,int> > ans;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	
	for(int i=1;i<=a;i++) for(int j=0;j<(1<<a);j++) for(int k=1;k<=a;k++) dist[i][j][k] = MAX;
	for(int i=1;i<=a;i++)
	{
		Q.push({1<<(i-1),i,0,0});
		while(!Q.empty())
		{
			str A = Q.top();
			Q.pop();
			if(dist[i][A.x0][A.y0]!=MAX) continue;
			dist[i][A.x0][A.y0] = A.z0;
			prev[i][A.x0][A.y0] = A.prev;
			
			for(int i=0;i<V[A.y0].size();i++)
			{
				if(V[A.y0][i]==A.prev) continue;
				if((A.x0&(1<<(V[A.y0][i]-1)))==0) Q.push({A.x0+(1<<(V[A.y0][i]-1)),V[A.y0][i],A.z0+1,A.y0});
			}
		}
	}
	
	for(int i=0;i<(1<<a);i++) type[i] = MAX;
	for(int i=0;i<(1<<a);i++)
	{
		for(int j=1;j<=a;j++)
		{
			for(int k=1;k<=a;k++)
			{
				if(type[i]>dist[j][i][k])
				{
					type[i] = dist[j][i][k];
					check[i] = {j,i,k,0};
				}
			}
		}
	}
	
	int min = MAX;
	int X1 = 1, X2 = 1;
	for(int i=0;i<(1<<a);i++)
	{
		for(int j=1;j<=a;j++)
		{
			for(int k=1;k<=a;k++)
			{
				if(j==k) continue;
				if((i&(1<<(j-1)))==0) continue;
				if((i&(1<<(k-1)))==0) continue;
				int t = (1<<a)-1-i + (1<<(j-1)) + (1<<(k-1));
				if(min>type[i]+type[t])
				{
					min = type[i] + type[t];
					X1 = i, X2 = t;
				}
			}
		}
	}
	
	int sx,sy,sz;
	sx = check[X1].x0, sy = check[X1].y0, sz = check[X1].z0;
	while(prev[sx][sy][sz]!=0)
	{
		ans.push_back(std::make_pair(prev[sx][sy][sz],sz));
		int temp = prev[sx][sy][sz];
		sy -= (1<<(sz-1));
		sz = temp;
	}
	sx = check[X2].x0, sy = check[X2].y0, sz = check[X2].z0;
	while(prev[sx][sy][sz]!=0)
	{
		ans.push_back(std::make_pair(prev[sx][sy][sz],sz));
		int temp = prev[sx][sy][sz];
		sy -= (1<<(sz-1));
		sz = temp;
	}
	
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
}

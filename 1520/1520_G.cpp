#include <stdio.h>
#include <vector>
#include <queue>

long long int dist[2010][2010];
int x[2010][2010];

struct str{
	int first;
	int second;
	long long int value;
};
bool operator<(str a, str b)
{
	return a.value>b.value;
}

std::priority_queue<str> Q;
std::vector<str> V[2010][2010];
int direX[5]={1,0,-1,0},direY[5]={0,1,0,-1};

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) x[i][j] = -1;
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]==-1) continue;
			for(int k=0;k<4;k++)
			{
				if(x[i+direX[k]][j+direY[k]]!=-1)
				{
					V[i][j].push_back({i+direX[k],j+direY[k],c});
				}
			}
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]>=1)
			{
				V[i][j].push_back({0,0,x[i][j]});
				V[0][0].push_back({i,j,x[i][j]});
			}
		}
	}
	
	Q.push({1,1,1});
	while(!Q.empty())
	{
		str A = Q.top();
		Q.pop();
		if(dist[A.first][A.second]!=0) continue;
		dist[A.first][A.second] = A.value;
		
		for(int i=0;i<V[A.first][A.second].size();i++)
		{
			if(dist[V[A.first][A.second][i].first][V[A.first][A.second][i].second]!=0) continue;
			Q.push({V[A.first][A.second][i].first,V[A.first][A.second][i].second,V[A.first][A.second][i].value+A.value});
		}
	}
	
	if(dist[a][b]==0) printf("-1");
	else printf("%lld",dist[a][b]-1);
}
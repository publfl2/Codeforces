#include <stdio.h>
#include <algorithm>
#include <queue>

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
std::vector< std::pair<int,int> > V[100010];
long long int dist[100010][60];
long long int MAX = 1;
long long int square(long long int k)
{
	return k*k;
}

int main()
{
	for(int i=1;i<=16;i++) MAX*=10;
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		V[c].push_back(std::make_pair(d,e));
		V[d].push_back(std::make_pair(c,e));
	}
	
	for(int i=1;i<=a;i++) for(int j=0;j<=50;j++) dist[i][j] = MAX;
	
	Q.push({1,0,0});
	while(!Q.empty())
	{
		str A = Q.top();
		Q.pop();
		if(A.value >= dist[A.first][A.second]) continue;
		dist[A.first][A.second] = A.value;
		if(A.second>0)
		{
			for(int i=0;i<V[A.first].size();i++)
			{
				if(dist[V[A.first][i].first][0]!=MAX) continue;
				Q.push({V[A.first][i].first,0,A.value + square(A.second+V[A.first][i].second)});
			}
		}
		else
		{
			for(int i=0;i<V[A.first].size();i++)
			{
				if(dist[V[A.first][i].first][V[A.first][i].second]!=MAX) continue;
				Q.push({V[A.first][i].first,V[A.first][i].second,A.value});
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		if(dist[i][0]==MAX) printf("-1 ");
		else printf("%lld ",dist[i][0]);
	}
}
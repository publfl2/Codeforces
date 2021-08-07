#include <stdio.h>
#include <vector>
#include <queue>

struct str{
	int first;
	int second;
	int index;
};
struct str2{
	int x0;
	int value;
};
bool operator<(str2 a, str2 b)
{
	return a.value>b.value;
}

std::vector<str> V[300010];
std::vector<int> V2;
std::priority_queue<str2> Q;
std::queue<int> Q2;

long long int dist[300010];
int check[300010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		int d,e,f;
		scanf("%d%d%d",&d,&e,&f);
		V[d].push_back({e,f,i});
		V[e].push_back({d,f,i});
	}
	
	Q.push({1,1});
	while(!Q.empty())
	{
		int x0 = Q.top().x0;
		int value = Q.top().value;
		Q.pop();
		if(dist[x0]>0) continue;
		dist[x0] = value;
		for(int i=0;i<V[x0].size();i++) Q.push({V[x0][i].first,value+V[x0][i].second});
	}
	
	Q2.push(1);
	check[1] = 1;
	while(!Q2.empty())
	{
		int x0 = Q2.front();
		Q2.pop();
		for(int i=0;i<V[x0].size();i++)
		{
			if(dist[x0]+V[x0][i].second==dist[V[x0][i].first]&&check[V[x0][i].first]==0)
			{
				check[V[x0][i].first] = 1;
				V2.push_back(V[x0][i].index);
				Q2.push(V[x0][i].first);
			}
		}
	}
	if(V2.size()<c)
	{
		printf("%d\n",V2.size());
		for(int i=0;i<V2.size();i++) printf("%d ",V2[i]);
	}
	else
	{
		printf("%d\n",c);
		for(int i=0;i<c;i++) printf("%d ",V2[i]);
	}
}

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

long long int MAX = 1;
struct segTree{
	struct Edge{
		int v1;
		int v2;
		int capacity;
		int cost;
	};
	
	std::vector<Edge> V;
	std::vector<int> edge[100010];
	int source, sink;
	
	void addEdge(int v1, int v2, int capacity, int cost)
	{
		V.push_back({v1,v2,capacity,cost});
		V.push_back({v2,v1,0,-cost});
		int s1 = V.size()-2, s2 = V.size()-1;
		edge[v1].push_back(s1);
		edge[v2].push_back(s2);
	}
	
	long long int dist[100010];
	int prev[100010],check[100010];
	void SPFA()
	{
		for(int i=1;i<=sink;i++) dist[i] = MAX;
		
		std::queue<int> Q;
		Q.push(source);
		check[source] = 1;
		dist[source] = 0;
		while(!Q.empty())
		{
			int v = Q.front();
			check[v] = 0;
			Q.pop();
			
			for(int i=0;i<edge[v].size();i++)
			{
				if(V[edge[v][i]].capacity==0) continue;
				if(V[edge[v][i]].cost+dist[v] < dist[V[edge[v][i]].v2])
				{
					if(check[V[edge[v][i]].v2]==0)
					{
						check[V[edge[v][i]].v2] = 1;
						Q.push(V[edge[v][i]].v2);
					}
					dist[V[edge[v][i]].v2] = dist[v] + V[edge[v][i]].cost;
					prev[V[edge[v][i]].v2] = edge[v][i];
				}
			}
		}
	}
	
	long long int getFlow()
	{
		long long int sum = 0;
		while(1)
		{
			SPFA();
			if(dist[sink]==MAX) return sum;
			
			int v = sink;
			long long int f = MAX;
			long long int S = 0;
			while(v!=source) f = f<V[prev[v]].capacity?f:V[prev[v]].capacity, v = V[prev[v]].v1;
			v = sink;
			while(v!=source) S += f*V[prev[v]].cost, v = V[prev[v]].v1;
			v = sink;
			while(v!=source) V[prev[v]].capacity -= f,V[prev[v]^1].capacity += f, v = V[prev[v]].v1;
			sum += S;
		}
	}
	
}F;

int main()
{
	for(int i=1;i<=18;i++) MAX*=10;
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
	F.source = 1, F.sink = a+b+3;
	for(int i=1;i<=a;i++) F.addEdge(1,i+1,1,0);
	for(int i=a+2;i<=a+b+1;i++) F.addEdge(i,a+b+3,1,0);
	F.addEdge(a+b+2,a+b+3,c,0);
	
	
	for(int i=1;i<=a;i++)
	{
		int d;
		scanf("%d",&d);
		F.addEdge(i+1,a+b+2,1,-d);
	}
	
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			int d;
			scanf("%d",&d);
			F.addEdge(i+1,a+1+j,1,-d);
		}
	}
	
	long long int ans = F.getFlow();
	printf("%lld",-ans);
}

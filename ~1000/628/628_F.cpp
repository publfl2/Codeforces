#include <stdio.h>
#include <algorithm>
#include <vector>
#include <atcoder/maxflow>

std::pair<int,int> query[10010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=c;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		query[i]={d,e};
	}
	std::sort(query+1,query+c+1);
	for(int i=1;i<c;i++)
	{
		if(query[i+1].first==query[i].first)
		{
			if(query[i+1].second!=query[i].second)
			{
				printf("unfair");
				return 0;
			}
		}
		if(query[i+1].second<query[i].second)
		{
			printf("unfair");
			return 0;
		}
	}
	
	atcoder::mf_graph<int> G(30000);
	for(int i=1;i<=b;i++) G.add_edge(b+1+(i%5),i,1);
	for(int i=b+1;i<=b+5;i++) G.add_edge(b+6,i,a/5);
	
	int source = b+6, sink = b+7;
	int start = b+8;
	
	for(int j=1;j<=query[1].first;j++) G.add_edge(j,start,1);
	G.add_edge(start,sink,query[1].second);
	start++;
	
	for(int i=2;i<=c;i++)
	{
		for(int j=query[i-1].first+1;j<=query[i].first;j++) G.add_edge(j,start,1);
		G.add_edge(start,sink,query[i].second-query[i-1].second);
		start++;
	}
	
	for(int j=query[c].first+1;j<=b;j++) G.add_edge(j,start,1);
	G.add_edge(start,sink,a-query[c].second);
	start++;
	
	int f = G.flow(source,sink);
	if(f==a) printf("fair");
	else printf("unfair");
}
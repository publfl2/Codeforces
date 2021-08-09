#include <stdio.h>
#include <atcoder/mincostflow>

int x[5010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int source = a+1, sink = a+2;
	atcoder::mcf_graph<int,int> G(a+4);
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]==1) G.add_edge(source,i,1,0);
		else G.add_edge(i,sink,1,0);
	}
	
	for(int i=1;i<a;i++)
	{
		G.add_edge(i,i+1,10000,1);
		G.add_edge(i+1,i,10000,1);
	}
	
	std::pair<int,int> P = G.flow(source,sink);
	printf("%d",P.second);
}
#include <stdio.h>
#include <atcoder/mincostflow>

int x[3010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	atcoder::mcf_graph<int,int> G(2*a+8);
	
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			if(x[i]==x[j]+1) G.add_edge(2*i,2*j-1,1,0);
			else if(x[i]==x[j]-1) G.add_edge(2*i,2*j-1,1,0);
			else if((x[i]-x[j]+777777)%7==0) G.add_edge(2*i,2*j-1,1,0);
		}
	}
	
	for(int i=2*a+1;i<=2*a+4;i++) for(int j=1;j<=a;j++) G.add_edge(i,2*j-1,1,0);
	for(int i=2*a+1;i<=2*a+4;i++) G.add_edge(2*a+5,i,1,0);
	for(int i=1;i<=a;i++) G.add_edge(2*i,2*a+6,1,1);
	for(int i=1;i<=a;i++) G.add_edge(2*i-1,2*i,1,1);
	
	std::pair<int,int> P = G.flow(2*a+5,2*a+6);
	printf("%d %d??\n",P.first,P.second);
	printf("%d",-P.second);
}
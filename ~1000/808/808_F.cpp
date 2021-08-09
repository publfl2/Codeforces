#include <stdio.h>
#include <atcoder/maxflow>
#define MAX 100000000

int check[200010];
int x[110];
std::vector< std::pair<int,int> > V[110];
int main()
{
	for(int i=2;i<=200000;i++)
	{
		if(check[i]==0)
		{
			for(int j=2*i;j<=200000;j+=i) check[j] = 1;
		}
	}
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		V[e].push_back({c,d});
		x[i] = d;
	}
	
	atcoder::mf_graph<int> G(100000+3);
	int source = 0;
	int sink = 100001;
	int one = 100002;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(x[i]==x[j]) continue;
			int t = x[i]+x[j];
			if(check[t]==0)
			{
				if(x[i]%2==0) G.add_edge(x[i],x[j],MAX);
				else G.add_edge(x[j],x[i],MAX);
			}
		}
	}
	G.add_edge(one,sink,MAX);
	
	int last = 0;
	long long int S1 = 0, S2 = 0, S3 = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<V[i].size();j++)
		{
			if(V[i][j].second%2==0)  G.add_edge(source,V[i][j].second,V[i][j].first);
			else
			{
				if(V[i][j].second==1)
				{
					if(last<V[i][j].first)
					{
						G.add_edge(V[i][j].second,one,V[i][j].first-last);
						last = V[i][j].first;
					}
				}
				else G.add_edge(V[i][j].second,sink,V[i][j].first);
			}
		}
		for(int j=0;j<V[i].size();j++)
		{
			if(V[i][j].second==1) S3 = S3>V[i][j].first?S3:V[i][j].first;
			if(V[i][j].second!=1) S2 += V[i][j].first;
		}
		
		S1 += G.flow(source,sink);
		if(S2+S3-S1>=b)
		{
			printf("%d",i);
			return 0;
		}
	}
	printf("-1");
}
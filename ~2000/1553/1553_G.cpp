#include <stdio.h>
#include <vector>
#include <atcoder/mincostflow>

int x[150010];
int check[1010],hash[1000010];
std::vector<int> prime;
std::vector<int> V[1000010];

int main()
{
	for(int i=2;i<=1000;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=1000;j+=i) check[j] = 1;
		}
	}
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int source = 1, sink = 2;
	atcoder::mcf_graph<int,int> G(400010);
	
	for(int i=1;i<=a;i++)
	{
		int t = x[i];
		for(int j=0;j<prime.size();j++)
		{
			if(t%prime[j]==0)
			{
				G.add_edge(2+i,2+a+1+j,1,0);
				G.add_edge(2+a+1+j,2+i,1,0);
				while(t%prime[j]==0) t/=prime[j];
			}
		}
		if(t>1) V[t].push_back(i);
	}
	
	int p = 2+a+1+prime.size();
	for(int i=1000;i<=1000000;i++)
	{
		if(V[i].size()>0)
		{
			for(int j=0;j<V[i].size();j++)
			{
				G.add_edge(2+V[i][j],p,1,0);
				G.add_edge(p,2+V[i][j],1,0);
				hash[i] = p;
				p++;
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		int t = x[i]+1;
		for(int j=0;j<prime.size();j++)
		{
			if(t%prime[j]==0)
			{
				G.add_edge(2+i,2+a+1+j,1,1);
				G.add_edge(2+a+1+j,2+i,1,1);
				while(t%prime[j]==0) t/=prime[j];
			}
		}
		if(t>1)
		{
			if(hash[t]==0)
			{
				G.add_edge(2+i,p,1,1);
				G.add_edge(p,2+i,1,1);
				hash[t] = p;
				p++;
			}
			else
			{
				G.add_edge(2+i,hash[t],1,1);
				G.add_edge(hash[t],2+i,1,1);
			}
		}
	}
	
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		printf("%d\n",G.flow(2+c,2+d,1).second);
	}
}
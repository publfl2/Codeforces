#include <stdio.h>
#include <map>
#include <vector>
#include <string.h>
#include <atcoder/maxflow>
#define MOD 99999971

char x[100010];
std::map<long long int,int> M;
atcoder::mf_graph<int> g(110000);

std::vector< std::pair<int,long long int> > query;
std::vector<long long int> index;
std::map<long long int,int> hash;
std::vector<long long int> save;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		if(c==1) query.push_back(std::make_pair(c,0));
		else
		{
			scanf("%s",x+1);
			int d = strlen(x+1);
			long long int sum = 0;
			for(int j=1;j<=d;j++)
			{
				sum *= MOD;
				sum += x[j];
			}
			query.push_back(std::make_pair(d,sum));
			index.push_back(sum);
		}
	}
	query.push_back(std::make_pair(1,0));
	
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
	
	for(int i=1;i<query.size();i++)
	{
		if(query[i].first==1)
		{
			for(int j=0;j<save.size();j++) g.add_edge(b+i,hash[save[j]],1);
			save.clear();
		}
		else save.push_back(query[i].second);
	}
	
	int source = (a+1)+b+1;
	int sink = (a+1)+b+2;
	for(int i=b+1;i<=b+a+1;i++) g.add_edge(source,i,1);
	for(int i=1;i<=b;i++) g.add_edge(i,sink,1);
	printf("%d",g.flow(source,sink));
}
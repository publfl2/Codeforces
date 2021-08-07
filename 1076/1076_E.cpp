#include <stdio.h>
#include <map>
#include <vector>

int height[300010];
std::vector<int> V[300010];
std::vector< std::pair<int,long long int> > query[300010];
void init(int k, int h)
{
	height[k] = h;
	for(int i=0;i<V[k].size();i++) if(height[V[k][i]]==0) init(V[k][i],h+1);
}


std::map<int,long long int> M;
long long int ans[300010];
void func(int k, long long int sum)
{
	for(int i=0;i<query[k].size();i++)
	{
		sum += query[k][i].second;
		M[query[k][i].first] += query[k][i].second;
	}
	sum -= M[height[k]];
	ans[k] = sum;
	for(int i=0;i<V[k].size();i++)
	{
		if(height[V[k][i]]>height[k])
		{
			func(V[k][i],sum);
		}
	}
	for(int i=0;i<query[k].size();i++) M[query[k][i].first] -= query[k][i].second;
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	init(1,1);
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		query[c].push_back(std::make_pair(height[c]+d+1,e));
	}
	func(1,0);
	for(int i=1;i<=a;i++) printf("%lld ",ans[i]);
}

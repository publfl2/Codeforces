#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
int x[300010];
int c;
std::vector<int> V[300010];
std::stack<int> St;
std::pair<int,int> func(int k,int h)
{
	// up , max
	std::vector< std::pair<int,int> > V2;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==h) continue;
		V2.push_back(func(V[k][i],k));
	}
	if(V2.empty())
	{
		if(x[k]==1) return std::make_pair(c-1,0);
		else return std::make_pair(-1,0);
	}
	int up = V2[0].first;
	int down = V2[0].first;
	for(int i=0;i<V2.size();i++) up = up>V2[i].first?up:V2[i].first;
	for(int i=0;i<V2.size();i++) down = down<V2[i].first?down:V2[i].first;
	int count = 0;
	for(int i=0;i<V2.size();i++) count+=V2[i].second;
	if(up>0)
	{
		for(int i=0;i<V2.size();i++) if(V2[i].first>0) count++;
		count--;
	}
	for(int i=0;i<V2.size();i++) if(V2[i].first==0) count++;
	if(x[k]==1) return std::make_pair(c-1,count+(up>0?1:0));
	else if(up+down>=0) return std::make_pair(up-1,count);
	else return std::make_pair(down-1,count);
}
int main()
{
	int a,b,d,e;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		scanf("%d",&d);
		x[d] = 1;
	}
	for(int i=1;i<a;i++)
	{
		scanf("%d%d",&d,&e);
		V[d].push_back(e);
		V[e].push_back(d);
	}
	printf("%d",func(1,0).second);
}

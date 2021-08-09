#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> ans;
std::vector<int> V[100010];
int size[100010],heavy[100010];

void init(int k)
{	
	for(int i=0;i<V[k].size();i++) init(V[k][i]);
	
	size[k] = 1;
	for(int i=0;i<V[k].size();i++) size[k] += size[V[k][i]];
	if(V[k].size()==0) heavy[k] = -1;
	else
	{
		heavy[k] = V[k][0];
		for(int i=1;i<V[k].size();i++) if(size[V[k][i]]>size[heavy[k]]) heavy[k] = V[k][i];
	}
}

void move(int s, int t)
{
	ans.push_back(s);
	if(heavy[t]==-1)
	{
		V[t].push_back(s);
		size[t] += size[s];
	}
	else
	{
		move(s,heavy[t]);
		size[t] += size[s];
	}
}

int next[100010];
void func(int k)
{
	if(V[k].size()==0) return;
	
	int ans = 1;
	std::vector< std::pair<int,int> > temp;
	for(int i=0;i<V[k].size();i++)
	{
		int s = size[V[k][i]];
		ans += s;
		temp.push_back(std::make_pair(s,V[k][i]));
	}
	std::sort(temp.begin(),temp.end());
	
	for(int i=temp.size()-1;i>=1;i--) move(temp[i].second,temp[i-1].second);
	
	next[k] = temp[0].second;
	
	func(temp[0].second);
	return;
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=0;i<=a;i++) next[i] = -1;
	for(int i=1;i<a;i++)
	{
		int b;
		scanf("%d",&b);
		V[b].push_back(i);
	}
	init(0);
	func(0);
	
	int s = 0;
	while(1)
	{
		printf("%d ",s);
		if(next[s]==-1) break;
		s = next[s];
	}
	
	printf("\n");
	printf("%d\n",ans.size());
	if(ans.size()>0) for(int i=ans.size()-1;i>=0;i--) printf("%d ",ans[i]);
}
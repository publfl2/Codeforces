#include <stdio.h>
#include <algorithm>
#include <vector>

struct str{
	int first;
	int second;
	int index;
}x[100010];
bool cmp(str a, str b)
{
	return a.first<b.first;
}
bool cmp2(str a, str b)
{
	return a.first+a.second>b.first+b.second;
}

std::vector<str> V;

int prev[100010],next[100010],limit[100010],check[100010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		x[i]={b,c,i};
	}
	std::sort(x+1,x+a+1,cmp);
	
	for(int i=1;i<=a;i++)
	{
		int min = i, max = a;
		int pivot = i;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(x[h].first-x[i].first<=x[i].second)
			{
				pivot = h;
				min = h+1;
			}
			else max = h-1;
		}
		prev[i] = pivot;
	}
	
	int max = 0;
	for(int i=1;i<=a;i++)
	{
		max = max>prev[i]?max:prev[i];
		next[i] = max;
	}
	
	int p;
	for(int i=a;i>=1;i--)
	{
		if(next[i]==i) p = i;
		limit[i] = p;
	}
	
	int start = 0;
	for(int i=1;i<=a;i++) if(x[i].index==1) start = i;
	
	for(int i=1;i<start;i++) V.push_back({x[i].first,x[i].second,i});
	std::sort(V.begin(),V.end(),cmp2);
	
	int p2 = start;
	for(int i=0;i<V.size();i++)
	{
		if(limit[V[i].index]>=p2) continue;
		else
		{
			p2 = V[i].index;
			check[p2] = 1;
		}
	}
	
	V.clear();
	for(int i=start;i<=a;i++) V.push_back({x[i].first,x[i].second,i});
	std::sort(V.begin(),V.end(),cmp2);
	
	p2 = a;
	for(int i=0;i<V.size();i++)
	{
		if(limit[V[i].index]>=p2) continue;
		else
		{
			p2 = V[i].index;
			check[p2] = 1;
		}
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		if(check[i]==1) ans += (x[limit[i]+1].first-x[i].first);
		else ans += x[i].second;
	}
	
	printf("%lld",ans);
}
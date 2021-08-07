#include <stdio.h>
#include <set>
#include <vector>
struct str{
	int first;
	int second;
};
bool operator<(str a, str b)
{
	return a.first<b.first;
}

std::vector<int> V[200010];
int size[200010],count[200010],isLeaf[200010];
std::set<str> S;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) count[i] = 0;
		for(int i=1;i<=a;i++) isLeaf[i] = 0;
		S.clear();
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<a;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[c].push_back(d);
			V[d].push_back(c);
		}
		if(b==1)
		{
			printf("%d\n",a-1);
			continue;
		}
		
		for(int i=1;i<=a;i++) size[i] = V[i].size();
		for(int i=1;i<=a;i++) if(V[i].size()==1) count[V[i][0]]++, isLeaf[i] = 1;
		for(int i=1;i<=a;i++) if(count[i]>=b) S.insert({count[i],i});
		
		int ans = 0;
		while(!S.empty())
		{
			std::set<str> ::iterator it = S.begin();
			int value = (it->first);
			int index = (it->second);
			ans++;
			S.erase(it);
			
			size[index] -= b;
			count[index] -= b;
			if(count[index]>=b) S.insert({count[index],index});
			if(size[index]==1)
			{
				for(int i=0;i<V[index].size();i++)
				{
					if(isLeaf[V[index][i]]==0)
					{
						count[V[index][i]]++;
						if(count[V[index][i]]>=b+1)
						{
							S.erase({count[V[index][i]]-1,V[index][i]});
							S.insert({count[V[index][i]],V[index][i]});
						}
						else if(count[V[index][i]]==b) S.insert({count[V[index][i]],V[index][i]});
					}
				}
				isLeaf[index] = 1;
			}
		}
		printf("%d\n",ans);
	}
}

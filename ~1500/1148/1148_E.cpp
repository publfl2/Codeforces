#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
struct str{
	int x0;
	int y0;
	int z0;
};

std::vector<str> ans;
int abs(int k)
{
	return k>0?k:-k;
}

std::multimap<int,int> M;
int x[300010],y[300010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	for(int i=1;i<=a;i++) M.insert(std::make_pair(x[i],i));
	
	std::sort(y+1,y+a+1);
	
	int s = 1, t = a;
	while(s<t)
	{
		std::multimap<int,int> ::iterator it;
		it = M.begin();
		int value1 = it->first;
		int p1 = it->second;
		
		it = M.end(); it--;
		int value2 = it->first;
		int p2 = it->second;
		
		if(y[s]<value1)
		{
			printf("NO");
			return 0;
		}
		if(y[t]>value2)
		{
			printf("NO");
			return 0;
		}
		int dist1 = abs(value1-y[s]);
		int dist2 = abs(value2-y[t]);
		if(dist1<dist2)
		{
			if(dist1==0)
			{
				it = M.begin(); M.erase(it);
				s++;
				continue;
			}
			else
			{
				ans.push_back({p1,p2,dist1});
				it = M.begin(); M.erase(it);
				it = M.end(); it--, M.erase(it);
				M.insert(std::make_pair(value1+dist1,p1));
				M.insert(std::make_pair(value2-dist1,p2));
			}
		}
		else
		{
			if(dist2==0)
			{
				it = M.end(); it--, M.erase(it);
				t--;
				continue;
			}
			else
			{
				ans.push_back({p1,p2,dist2});
				it = M.begin(); M.erase(it);
				it = M.end(); it--, M.erase(it);
				M.insert(std::make_pair(value1+dist2,p1));
				M.insert(std::make_pair(value2-dist2,p2));
			}
		}
	}
	std::multimap<int,int> ::iterator it = M.begin();
	if(it->first!=y[s])
	{
		printf("NO");
		return 0;
	}
	printf("YES\n");
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d %d\n",ans[i].x0,ans[i].y0,ans[i].z0);
}

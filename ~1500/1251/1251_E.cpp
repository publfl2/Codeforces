#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>

std::queue<int> save;
std::pair<int,int> P[200010];
int check[200010];
std::set< std::pair<int,int> > S;

int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		S.clear();
		while(!save.empty()) save.pop();
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=1;i<=a;i++) scanf("%d%d",&P[i].first,&P[i].second);
		std::sort(P+1,P+a+1);
		for(int i=1;i<=a;i++) S.insert(std::make_pair(P[i].second,i));
		
		int s = 0, t= 0;
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			if(check[i]==1)
			{
				save.push(i);
			}
			else
			{
				std::multiset< std::pair<int,int> > ::iterator it;
				while(t<P[i].first)
				{
					if(check[i]==1) break;
					std::multiset< std::pair<int,int> > ::iterator it = S.begin();
					ans += (it->first);
					check[it->second] = 1;
					S.erase(it);
					s++,t++;
					
					while(!save.empty())
					{
						int k = save.front();
						if(P[k].first <=(s-1)+(k-1))
						{
							ans -= P[k].second;
							s--;
							save.pop();
						}
						else break;
					}
				}
				
				if(check[i]==0)
				{
					t++;
					it = S.find(std::make_pair(P[i].second,i));
					S.erase(it);
				}
				else
				{
					save.push(i);
				}
			}
		}
		
		printf("%lld\n",ans);
	}
}

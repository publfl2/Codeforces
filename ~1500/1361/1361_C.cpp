#include <stdio.h>
#include <vector>
#include <set>

std::multiset<int> S[1100000];
std::vector<int> save[1100000];
std::pair<int,int> x[500010],y[500010];
int ansV[1000010],tempV[1000010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		x[i]=std::make_pair(b,c);
	}
	
	int min = 1, max = 20;
	int ans = 0;
	for(int i=1;i<=2*a;i++) ansV[i] = i;
	
	while(min<=max)
	{
		int h = (min+max)/2;
		int C = (1<<h);
		for(int i=1;i<=a;i++) y[i] = std::make_pair(x[i].first%C,x[i].second%C);
		
		for(int i=2;i<=a;i++)
		{
			if(y[i].first==y[i].second) save[y[i].first].push_back(i);
			else
			{
				S[y[i].first].insert(i);
				S[y[i].second].insert(i);
			}
		}
		
		tempV[1] = 1, tempV[2] = 2;
		for(int i=3;i<=2*a;i+=2)
		{
			int prev;
			if(tempV[i-1]%2==0) prev = y[tempV[i-1]/2].second;
			else prev = y[(tempV[i-1]+1)/2].first;
			
			//printf("%d %d!!\n",i,prev);
			if(save[prev].size()>0)
			{
				//printf("??\n");
				int D = save[prev][save[prev].size()-1];
				tempV[i] = 2*D-1;
				tempV[i+1] = 2*D;
				save[prev].pop_back();
				continue;
			}
			
			if(S[prev].begin()==S[prev].end())
			{
				max = h-1;
				goto u;
			}
			
			std::multiset<int> ::iterator it;
			int C;
			for(it = S[prev].begin();it!=S[prev].end();it++)
			{
				C = (*it);
				if(y[C].first==prev)
				{
					if(S[y[C].second].size()>=2)
					{
						tempV[i] = 2*C-1, tempV[i+1] = 2*C;
						goto v;
					}
					else continue;
				}
				else
				{
					if(S[y[C].first].size()>=2)
					{
						tempV[i] = 2*C, tempV[i+1] = 2*C-1;
						goto v;
					}
					else continue;
				}
			}
			
			it = S[prev].begin();
			C = (*it);
			if(y[C].first==prev) tempV[i] = 2*C-1, tempV[i+1] = 2*C;
			else tempV[i] = 2*C, tempV[i+1] = 2*C-1;
			
			v:;
			it = S[y[C].first].find(C);
			S[y[C].first].erase(it);
			it = S[y[C].second].find(C);
			S[y[C].second].erase(it);
			
		}
		
		int s1, s2;
		if(tempV[2*a]%2==0) s1 = y[tempV[2*a]/2].second;
		else s1 = y[(tempV[2*a]+1)/2].first;
		if(tempV[1]%2==0) s2 = y[tempV[1]/2].second;
		else s2 = y[(tempV[1]+1)/2].first;
		if(s1==s2)
		{
			ans = h;
			for(int i=1;i<=2*a;i++) ansV[i] = tempV[i];
			min = h+1;
		}
		else max = h-1;
		
		u:;
		printf("%d!!\n",h);
		for(int i=1;i<=2*a;i++) printf("%d ",tempV[i]);
		printf("!!\n");
		
		for(int i=2;i<=a;i++)
		{
			if(y[i].first==y[i].second) save[y[i].first].clear();
			else
			{
				S[y[i].first].clear();
				S[y[i].second].clear();
			}
		}
		
	}
	printf("%d\n",ans);
	for(int i=1;i<=2*a;i++) printf("%d ",ansV[i]);
}

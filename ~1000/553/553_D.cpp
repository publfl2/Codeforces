#include <stdio.h>
#include <set>
#include <vector>

struct str{
	double first;
	int second;
};
bool operator<(str a, str b)
{
	if(a.first==b.first) return a.second<b.second;
	return a.first<b.first;
}
std::set<str> S;
int check[100010],check2[100010];
int sum[100010];
std::vector<int> V[100010];
std::vector<int> T;

void func(int k, double limit)
{
	if(check[k]==1) return;
	if((double)sum[k]/V[k].size() <= limit)
	{
		T.push_back(k);
		check[k] = 1;
		S.erase({(double)sum[k]/V[k].size(),k});
		for(int i=0;i<V[k].size();i++)
		{
			if(check[V[k][i]]==0)
			{
				S.erase({(double)sum[V[k][i]]/V[V[k][i]].size(),V[k][i]});
				sum[V[k][i]]--;
				S.insert({(double)sum[V[k][i]]/V[V[k][i]].size(),V[k][i]});
				func(V[k][i],limit);
			}
		}
	}
}

int main()
{
	//freopen("input.txt","r",stdin);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=c;i++)
	{
		int d;
		scanf("%d",&d);
		check2[d] = 1;
		check[d] = 1;
	}
	for(int i=1;i<=b;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		V[d].push_back(e);
		V[e].push_back(d);
	}
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0)
		{
			for(int j=0;j<V[i].size();j++) sum[i] += (1-check[V[i][j]]);
			S.insert({(double)sum[i]/V[i].size(),i});
		}
	}
	
	std::set<str> ::iterator it = S.begin();
	double limit = (*it).first;
	while(!S.empty())
	{
		it = S.begin();
		int ind = (*it).second;
		func(ind,limit);
		if(S.empty()) break;
		for(int i=0;i<T.size();i++) check2[T[i]] = 1;
		T.clear();
		
		it = S.begin();
		limit = (*it).first;
	}
	
	int ans = 0;
	for(int i=1;i<=a;i++) ans += (1-check2[i]);
	printf("%d\n",ans);
	for(int i=1;i<=a;i++) if(check2[i]==0) printf("%d ",i);
}

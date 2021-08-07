#include <stdio.h>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

std::set<int> S,S2[510];
std::pair<int,int> getQuery()
{
	printf("? ");
	for(std::set<int> ::iterator it = S.begin();it!=S.end();it++)
	{
		printf("%d ",*it);
	}
	printf("\n");
	fflush(stdout);
	
	std::pair<int,int> P;
	scanf("%d%d",&P.first,&P.second);
	return P;
}

std::vector<int> V,V2;
int check[510];
std::map<int,int> pos;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(b==1)
	{
		printf("! 1");
		fflush(stdout);
		return 0;
	}
	
	for(int i=1;i<b;i++) S.insert(i);
	for(int i=b;i<=a;i++)
	{
		S.insert(i);
		std::pair<int,int> P = getQuery();
		pos[P.second] = P.first;
		check[P.first] = 1;
		S2[P.first] = S;
		S.erase(P.first);
		V.push_back(P.second);
	}
	std::sort(V.begin(),V.end());
	int s = pos[V[0]];
	int t = pos[V.back()];
	std::set<int> ::iterator it;
	
	for(it=S2[s].begin();it!=S2[s].end();it++) if(check[*it]==0) V2.push_back(*it);
	for(it=S2[t].begin();it!=S2[t].end();it++) if(check[*it]==0) V2.push_back(*it);
	std::sort(V2.begin(),V2.end());
	V2.erase(std::unique(V2.begin(),V2.end()),V2.end());
	for(int i=0;i<V2.size();i++)
	{
		if(V2[i]>V[0])
		{
			printf("! %d\n",i);
			fflush(stdout);
			return 0;
		}
	}
	printf("! %d\n",V2.size());
	fflush(stdout);
}

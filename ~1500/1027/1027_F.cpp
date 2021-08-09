#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define MAX 123456789

std::vector<int> save;
std::map<int,int> hash;
int inverseHash[2000010];

std::vector<int> V[2000010];
int color[2000010];
void coloring(int k, int c)
{
	if(color[k]>0) return;
	color[k] = c;
	for(int i=0;i<V[k].size();i++) coloring(V[k][i],c);
}

int vN[2000010];
int eN[2000010];

std::pair<int,int> P[2000010];
std::set< int > S[2000010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		P[i] = std::make_pair(b,c);
		save.push_back(b);
		save.push_back(c);
	}
	std::sort(save.begin(),save.end());
	hash[save[0]] = 1;
	inverseHash[1] = save[0];
	int p = 1;
	for(int i=1;i<save.size();i++)
	{
		if(save[i]!=save[i-1])
		{
			hash[save[i]] = ++p;
			inverseHash[p] = save[i];
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		V[hash[P[i].first]].push_back(hash[P[i].second]);
		V[hash[P[i].second]].push_back(hash[P[i].first]);
	}
	for(int i=1;i<=p;i++) if(color[i]==0) coloring(i,i);
	for(int i=1;i<=p;i++)
	{
		vN[color[i]]++;
		eN[color[i]]+=V[i].size();
		S[color[i]].insert(i);
	}
	
	int ans = 0;
	for(int i=1;i<=p;i++)
	{
		if(eN[color[i]]/2 >= vN[color[i]]+1)
		{
			printf("-1");
			return 0;
		}
		else if(eN[color[i]]/2 == vN[color[i]])
		{
			std::set< int > ::iterator it = S[color[i]].end();
			it--;
			int value = (*it);
			ans = ans>value?ans:value;
		}
		else
		{
			std::set< int > ::iterator it = S[color[i]].end();
			it--;
			it--;
			int value = (*it);
			ans = ans>value?ans:value;
		}
	}
	printf("%d",inverseHash[ans]);
}

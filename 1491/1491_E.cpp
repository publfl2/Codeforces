#include <stdio.h>
#include <set>
#include <map>
#include <queue>
#include <vector>

std::vector<int> Fibb;
std::map<int,int> hashFibb;

struct str{
	int first;
	int second;
};
bool operator<(str a, str b)
{
	return a.second>b.second;
}
std::priority_queue<str> Q;

int count[200010];
std::vector<int> V[200010];
int next[200010],size[200010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

int main()
{
	Fibb.push_back(0);
	Fibb.push_back(1);
	for(int i=2;;i++)
	{
		int t = Fibb[i-1]+Fibb[i-2];
		if(t>200000) break;
		Fibb.push_back(t);
	}
	for(int i=0;i<Fibb.size();i++) hashFibb[Fibb[i]] = i;
	
	int a;
	scanf("%d",&a);
	
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	for(int i=1;i<=a;i++) count[i] = V[i].size();
	for(int i=1;i<=a;i++) if(count[i]==1) Q.push({i,1});
	for(int i=1;i<=a;i++) size[i] = 1;
	for(int i=1;i<=a;i++) next[i] = i;
	
	while(!Q.empty())
	{
		int t = Q.top().first;
		Q.pop();
		t = find(t);
		
		for(int i=0;i<V[t].size();i++)
		{
			int s = find(V[t][i]);
			if(s!=t)
			{
				if(hashFibb.find(size[s]+size[t])!=hashFibb.end())
				{
					size[s] += size[t];
					next[t] = s;
					count[s]--;
					count[t]--;
					if(count[s]==1) Q.push({s,size[s]});
				}
				else if(count[s]!=1) Q.push({s,size[s]});
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		if(find(i)!=find(1))
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}
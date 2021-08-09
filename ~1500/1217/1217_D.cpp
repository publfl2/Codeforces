#include <stdio.h>
#include <map>
#include <vector>

std::map< std::pair<int,int> , int> M;
std::vector<int> V[5010];
int check[5010],parent[5010][5010],height[5010];
void func(int k, int prev, int h)
{
	check[k] = 1;
	height[k] = h;
	int t = prev;
	int C = 1;
	while(t)
	{
		parent[k][C++] = t;
		t = parent[t][1];
	}
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		if(check[V[k][i]])
		{
			if(height[k]>height[V[k][i]]&&parent[k][height[k]-height[V[k][i]]]==V[k][i])
			{
				M[std::make_pair(k,V[k][i])] = 1;
			}
		}
		else func(V[k][i],k,h+1);
	}
}

std::pair<int,int> edge[5010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		edge[i] = std::make_pair(c,d);
	}
	for(int i=1;i<=a;i++) if(check[i]==0) func(i,0,1);
	if(M.size()==0)
	{
		printf("1\n");
		for(int i=1;i<=b;i++) printf("1 ");
	}
	else
	{
		printf("2\n");
		for(int i=1;i<=b;i++) printf("%d ",M[edge[i]]+1);
	}
}

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

std::vector<int> V[500010],check[500010];
std::vector<int> V2;
int x[500010],y[500010];
std::queue<int> Q;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++)
	{
		V2.clear();
		for(int j=0;j<V[i].size();j++) V2.push_back(x[V[i][j]]);
		std::sort(V2.begin(),V2.end());
		
		for(int j=0;j<V2.size();j++)
		{
			if(V2[j]==x[i])
			{
				printf("-1");
				return 0;
			}
			else if(V2[j]>x[i])
			{
				if(j>0 && V2[j-1]!=x[i]-1)
				{
					printf("-1");
					return 0;
				}
				else break;
			}
			
			if(j>=1 && V2[j]>=V2[j-1]+2)
			{
				printf("-1");
				return 0;
			}
		}
		
		check[x[i]].push_back(i);
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<check[i].size();j++) printf("%d ",check[i][j]);
	}
}

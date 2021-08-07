#include <stdio.h>
#include <vector>
#define MAX 123456789
std::vector<int> V[300010];
std::vector<int> V2;
int check[300010];
int ans[300010];

int main()
{
	for(int i=1;i<=300000;i++) V[i].push_back(0);
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V2.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) ans[i] = MAX;
		
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			V[b].push_back(i);
			V2.push_back(b);
		}
		for(int i=0;i<V2.size();i++)
		{
			if(check[V2[i]]==0)
			{
				check[V2[i]] = 1;
				V[V2[i]].push_back(a+1);
			}
		}
		
		for(int i=0;i<V2.size();i++)
		{
			if(check[V2[i]]==2) continue;
			
			int min = 0;
			for(int j=1;j<V[V2[i]].size();j++)
			{
				min = min>(V[V2[i]][j]-V[V2[i]][j-1])?min:(V[V2[i]][j]-V[V2[i]][j-1]);
			}
			ans[min] = ans[min]<V2[i]?ans[min]:V2[i];
			check[V2[i]] = 2;
		}
		for(int i=2;i<=a;i++) ans[i] = ans[i] < ans[i-1]?ans[i]:ans[i-1];
		
		for(int i=1;i<=a;i++)
		{
			if(ans[i]==MAX) printf("-1 ");
			else printf("%d ",ans[i]);
		}
		printf("\n");
		
		for(int i=0;i<V2.size();i++)
		{
			check[V2[i]] = 3;
			V[V2[i]].clear();
		}
		for(int i=0;i<V2.size();i++)
		{
			if(check[V2[i]]==3)
			{
				check[V2[i]] = 0;
				V[V2[i]].push_back(0);
			}
		}
	}
}

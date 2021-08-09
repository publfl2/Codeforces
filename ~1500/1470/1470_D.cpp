#include <stdio.h>
#include <queue>
#include <vector>

int height[300010];
std::vector<int> V[300010];
void func(int k, int prev, int h)
{
	height[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		if(height[V[k][i]]==0) func(V[k][i],k,h+1);
	}
}

int check[300010];
std::queue<int> Q;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) height[i] = 0;
		for(int i=1;i<=a;i++) check[i] = 0;
		
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[c].push_back(d);
			V[d].push_back(c);
		}
		func(1,0,1);
		
		int sum = 0;
		for(int i=1;i<=a;i++)
		{
			if(height[i]==0)
			{
				printf("NO\n");
				goto u;
			}
		}
		
		Q.push(1);
		while(!Q.empty())
		{
			int k = Q.front();
			Q.pop();
			
			int control = 1;
			for(int i=0;i<V[k].size();i++) if(height[V[k][i]]<height[k] && check[V[k][i]]==1) control = 0;
			check[k] = control;
			for(int i=0;i<V[k].size();i++) if(height[V[k][i]]>height[k]) Q.push(V[k][i]);
		}
		
		printf("YES\n");
		for(int i=1;i<=a;i++) sum += check[i];
		printf("%d\n",sum);
		for(int i=1;i<=a;i++) if(check[i]==1) printf("%d ",i);
		printf("\n");
		
		u:;
	}
}

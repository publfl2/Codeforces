#include <stdio.h>
#include <vector>
#include <queue>
 
struct str{
	int x0;
	int dist;
};
std::queue<str> Q;
std::vector<int> V[200010],V2[200010];
int check[200010],ans[200010];
int check2[200010];

void func(int s, int t)
{
	if(t==3)
	{
		check[s]++;
		return;
	}
	for(int i=0;i<V[s].size();i++) func(V[s][i],t+1);
}

void func2(int s, int t)
{
	if(ans[s]==1) return;
	if(check[s]>0)
	{
		ans[s] = 1;
		return;
	}
	
	for(int i=0;i<V[s].size();i++) func2(V[s][i],t+1);
}

void func3(int s, int t)
{
	if(t==3)
	{
		check[s]--;
		return;
	}
	for(int i=0;i<V[s].size();i++) func3(V[s][i],t+1);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) check[i] = ans[i] = 0;
		
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[c].push_back(d);
		}
		
		for(int i=1;i<=a;i++) func(i,1);
		
		for(int i=1;i<=a;i++)
		{
			func2(i,1);
			func3(i,1);
		}
		
		int count = 0;
		for(int i=1;i<=a;i++) if(ans[i]==1) count++;
		printf("%d\n",count);
		for(int i=1;i<=a;i++) if(ans[i]==1) printf("%d ",i);
		printf("\n");
	}
}

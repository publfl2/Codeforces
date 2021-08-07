#include <stdio.h>
#include <vector>
#include <algorithm>
struct str{
	int x0;
	int rank;
	int index;
}x[200010];
bool cmp1(str a, str b)
{
	return a.x0<b.x0;
}
bool cmp2(str a, str b)
{
	return a.index<b.index;
}
std::vector<int> V[200010];
int up[200010],down[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a+1;i++) V[i].clear();
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i].x0);
		for(int i=1;i<=a;i++) x[i].rank = 0, x[i].index = i;
		for(int i=1;i<=a;i++) down[i] = up[i] = 0;
		
		std::sort(x+1,x+a+1,cmp1);
		x[0].x0 = -1;
		
		int C = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i].x0!=x[i-1].x0) C++;
			x[i].rank = C;
		}
		std::sort(x+1,x+a+1,cmp2);
		
		for(int i=1;i<=a;i++) V[x[i].rank].push_back(i);
		
		for(int j=0;j<V[C].size();j++) up[V[C][j]] = 1;
		for(int i=C-1;i>=1;i--)
		{
			int p = V[i+1].size()-1;
			int count = up[V[i+1][p]];
			for(int j=V[i].size()-1;j>=0;j--)
			{
				if(V[i][j]>V[i+1][V[i+1].size()-1]) up[V[i][j]] = 1;
				else
				{
					while(p>0 && V[i][j]<V[i+1][p-1])
					{
						p--;
						count = count>up[V[i+1][p]]?count:up[V[i+1][p]];
					}
					up[V[i][j]] = count + 1;
				}
				
				if(j!=V[i].size()-1) up[V[i][j]] = up[V[i][j+1]]+1;
			}
		}
		
		for(int j=0;j<V[1].size();j++) down[V[1][j]] = 1;
		for(int i=2;i<=C;i++)
		{
			int p = 0;
			int count = down[V[i-1][p]];
			for(int j=0;j<V[i].size();j++)
			{
				if(V[i][j]<V[i-1][0]) down[V[i][j]] = 1;
				else
				{
					while(p<V[i].size()-1 && V[i][j]>V[i-1][p+1])
					{
						p++;
						count = count>down[V[i-1][p]]?count:down[V[i-1][p]];
					}
					down[V[i][j]] = count + 1;
				}
				
				if(j!=0) down[V[i][j]] = down[V[i][j-1]]+1;
			}
		}
		
		int ans = a;
		ans = ans<a-up[1]?ans:a-up[1];
		ans = ans<a-down[a]?ans:a-down[a];
		
		for(int i=1;i<a;i++)
		{
			if(V[x[i].rank+1].size()==0) continue;
			int min = 0, max = V[x[i].rank+1].size()-1;
			int M = V[x[i].rank+1].size();
			while(min<=max)
			{
				int h = (min+max)/2;
				if(V[x[i].rank+1][h]>i)
				{
					M = h;
					max = h-1;
				}
				else min = h+1;
			}
			if(M>=1)
			{
				ans = ans<a-down[i]-(V[x[i].rank+1].size()-M)?ans:a-down[i]-(V[x[i].rank+1].size()-M);
				printf("%d %d??\n",ans,i);
			}
			else
			{
				ans = ans<a-down[i]-up[V[x[i].rank+1][M]]?ans:a-down[i]-up[V[x[i].rank+1][M]];
				printf("%d %d : %d %d\n",i,V[x[i].rank+1][M],down[i],up[V[x[i].rank+1][M]]);
				printf("%d %d?\n",ans,i);
			}
		}
		printf("%d!!\n",ans);
	}
}

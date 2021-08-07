#include <stdio.h>
#include <queue>
#include <vector>
#include <set>

std::vector<int> V[200010];
std::set< std::pair<int,int> > edge;
int degree[200010],check[200010];
std::vector<int> ans;
std::queue<int> Q;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		edge.clear();
		while(!Q.empty()) Q.pop();
		
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) degree[i] = check[i] = 0;
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<=b;i++)
		{
			int d,e;
			scanf("%d%d",&d,&e);
			V[d].push_back(e);
			V[e].push_back(d);
			edge.insert(std::make_pair(d,e));
			edge.insert(std::make_pair(e,d));
			degree[d]++;
			degree[e]++;
		}
		
		if(c==1)
		{
			printf("2\n1\n");
			continue;
		}
		long long int d = c-1;
		if(d*d>2*b)
		{
			printf("-1\n");
			continue;
		}
		
		for(int i=1;i<=a;i++)
		{
			if(degree[i]<c-1)
			{
				check[i] = 1;
				Q.push(i);
			}
		}
		while(!Q.empty())
		{
			int k = Q.front();
			Q.pop();
			check[k] = 2;
			degree[k] = 0;
			for(int i=0;i<V[k].size();i++)
			{
				if(check[V[k][i]]<=1)
				{
					edge.erase(std::make_pair(k,V[k][i]));
					edge.erase(std::make_pair(V[k][i],k));
					degree[V[k][i]]--;
					if(check[V[k][i]]==0&&degree[V[k][i]]<c-1)
					{
						check[V[k][i]] = 1;
						Q.push(V[k][i]);
					}
				}
			}
		}
		
		
		for(int i=1;i<=a;i++)
		{
			if(degree[i]==c-1)
			{
				for(int j=0;j<V[i].size();j++)
				{
					if(check[V[i][j]]!=0) continue;
					for(int k=j+1;k<V[i].size();k++)
					{
						if(check[V[i][k]]!=0) continue;
						if(edge.find(std::make_pair(V[i][j],V[i][k]))==edge.end()) goto u;
					}
				}
				printf("2\n");
				printf("%d ",i);
				for(int j=0;j<V[i].size();j++) if(check[V[i][j]]==0) printf("%d ",V[i][j]);
				printf("\n");
				goto v;
				u:;
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			if(degree[i]<c)
			{
				check[i] = 1;
				Q.push(i);
			}
		}
		while(!Q.empty())
		{
			int k = Q.front();
			Q.pop();
			check[k] = 2;
			degree[k] = 0;
			for(int i=0;i<V[k].size();i++)
			{
				if(check[V[k][i]]<=1)
				{
					edge.erase(std::make_pair(k,V[k][i]));
					edge.erase(std::make_pair(V[k][i],k));
					degree[V[k][i]]--;
					if(check[V[k][i]]==0&&degree[V[k][i]]<c)
					{
						check[V[k][i]] = 1;
						Q.push(V[k][i]);
					}
				}
			}
		}
		
		ans.clear();
		for(int i=1;i<=a;i++) if(check[i]==0) ans.push_back(i);
		if(ans.size()==0) printf("-1\n");
		else
		{
			printf("1 %d\n",ans.size());
			for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
			printf("\n");
		}
		v:;
	}
}

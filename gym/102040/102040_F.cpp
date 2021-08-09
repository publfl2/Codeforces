#include <stdio.h>
#include <vector>

int height[10010];
int sparse[10010][20];
std::vector<int> V[10010];
std::pair<int,int> x[10010];

void func(int s, int prev, int h)
{
	height[s] = h;
	sparse[s][0] = prev;
	for(int i=0;i<V[s].size();i++)
	{
		if(V[s][i]==prev) continue;
		func(V[s][i],s,h+1);
	}
}

int LCA(int s, int t)
{
	if(height[s]>height[t])
	{
		int h = height[s]-height[t];
		for(int i=0;i<=14;i++)
		{
			if(h%2==1) s = sparse[s][i];
			h/=2;
		}
	}
	else if(height[s]<height[t])
	{
		int h = height[t]-height[s];
		for(int i=0;i<=14;i++)
		{
			if(h%2==1) t = sparse[t][i];
			h/=2;
		}
	}
	if(s==t) return s;
	
	for(int i=14;i>=0;i--) if(sparse[s][i]!=sparse[t][i]) s = sparse[s][i], t = sparse[t][i];
	return sparse[s][0];
}

int main()
{
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		printf("Case %d:\n",T);
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			V[b].push_back(c);
			V[c].push_back(b);
		}
		func(1,0,1);
		for(int j=1;j<=14;j++) for(int i=1;i<=a;i++) sparse[i][j] = sparse[sparse[i][j-1]][j-1];
		
		int b;
		scanf("%d",&b);
		
		int ans1,ans2;
		for(int i=1;i<=b;i++)
		{
			int c;
			scanf("%d",&c);
			for(int j=1;j<=c;j++) scanf("%d%d",&x[j].first,&x[j].second);
			int L = LCA(x[1].first,x[1].second);
			for(int j=2;j<=c;j++)
			{
				if(L!=LCA(x[j].first,x[j].second))
				{
					goto u;
				}
			}
			
			//type 1
			
			ans1 = x[1].first,ans2 = x[1].second;
			for(int j=2;j<=c;j++)
			{
				int s = LCA(x[1].first,x[j].first);
				int t = LCA(x[1].first,x[j].second);
				int temp = height[s]>height[t]?s:t;
				ans1 = height[ans1]<height[temp]?ans1:temp;
				
				s = LCA(x[1].second,x[j].first);
				t = LCA(x[1].second,x[j].second);
				temp = height[s]>height[t]?s:t;
				ans2 = height[ans2]<height[temp]?ans2:temp;
			}
			printf("%d\n",height[ans1]+height[ans2]-2*height[L]+1);
			continue;			
			u:
			
			
			int s1 = x[1].first, s2 = L, t1 = x[1].second, t2 = L;
			for(int j=2;j<=c;j++)
			{
				int s = LCA(x[1].first,x[j].first);
				s1 = height[s1]<height[s]?s1:s;
				s2 = height[s2]>height[s]?s2:s;
				s = LCA(x[1].first,x[j].second);
				s1 = height[s1]<height[s]?s1:s;
				s2 = height[s2]>height[s]?s2:s;
				
				int t = LCA(x[1].second,x[j].first);
				t1 = height[t1]<height[t]?t1:t;
				t2 = height[t2]>height[t]?t2:t;
				t = LCA(x[1].second,x[j].second);
				t1 = height[t1]<height[t]?t1:t;
				t2 = height[t2]>height[t]?t2:t;
			}
			
			for(int j=2;j<=c;j++) if(LCA(x[j].first,L)!=L && LCA(x[j].second,L)!=L) goto v;
			for(int j=2;j<=c;j++) if(LCA(L,LCA(x[j].first,x[j].second))!=LCA(x[j].first,x[j].second)) goto v;
			
			//type 2
			if(height[t1]>height[t2]) printf("%d\n",height[t1]-height[t2]+1);
			else if(height[s1]>height[s2]) printf("%d\n",height[s1]-height[s2]+1);
			else printf("1\n");
			continue;
			
			v:;
			//type 3
			
			if(height[s1]>height[s2]) printf("%d\n",height[s1]-height[s2]+1);
			else if(height[t1]>height[t2]) printf("%d\n",height[t1]-height[t2]+1);
			else
			{
				if(s1!=L || t1!=L) printf("1\n");
				else printf("0\n");
			}
		}
	}
}

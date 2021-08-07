#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

struct str{
	int value;
	int x0;
	int y0;
};
bool operator<(str a, str b)
{
	return a.value<b.value;
}
std::priority_queue<str> Q;

struct str2{
	int x1;
	int y1;
	int x0;
	int y0;
};
std::vector<str2> interval;

int x[310][310],max1[310],max2[310];
int ans[310][310];
int check[100010];
std::vector<int> save;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) max1[i] = max1[i]>x[i][j]?max1[i]:x[i][j];
	for(int j=1;j<=b;j++) for(int i=1;i<=a;i++) max2[j] = max2[j]>x[i][j]?max2[j]:x[i][j];
	
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) Q.push({x[i][j],i,j});
	
	int s = a, t = b;
	while(!Q.empty())
	{
		int val = Q.top().value;
		int x0 = Q.top().x0;
		int y0 = Q.top().y0;
		Q.pop();
		if(max1[x0]==val && max2[y0]==val)
		{
			ans[s][t] = val;
			std::vector<int> V;
			for(int i=1;i<=a;i++)
			{
				if(i==x0) continue;
				if(max1[i]==x[i][y0]) V.push_back(x[i][y0]);
			}
			if(s-V.size()-1<0)
			{
				printf("-1");
				return 0;
			}
			std::sort(V.begin(),V.end());
			for(int i=V.size()-1;i>=0;i--) ans[s-(V.size()-i)][t] = V[i];
			int s2 = s-V.size()-1;
			V.clear();
			
			for(int j=1;j<=b;j++)
			{
				if(j==y0) continue;
				if(max2[j]==x[x0][j]) V.push_back(x[x0][j]);
			}
			if(t-V.size()-1<0)
			{
				printf("-1");
				return 0;
			}
			std::sort(V.begin(),V.end());
			for(int i=V.size()-1;i>=0;i--) ans[s][t-(V.size()-i)] = V[i];
			int t2 = t-V.size()-1;
			
			interval.push_back({s,t,s-V.size(),t-V.size()});
			s = s2, t = t2;
		}
	}
	
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) check[ans[i][j]] = 1;
	
	int C = a*b;
	for(int k=0;k<interval.size();k++)
	{
		save.clear();
		int count = 0;
		for(int i=interval[k].x0;i<=interval[k].x1;i++) for(int j=interval[k].y0;j<=interval[k].y1;j++) if(ans[i][j]==0) count++;
		for(int i=a*b;i>=1;i--)
		{
			if(save.size()==count) break;
			if(check[i]==0)
			{
				check[i] = 1;
				save.push_back(i);
			}
		}
		
		int p = save.size()-1;
		for(int i=interval[k].x0+interval[k].y0;i<=interval[k].x1+interval[k].y1;i++)
		{
			for(int j=interval[k].y0;j<=interval[k].y1;j++)
			{
				if(i-j<interval[k].x0) continue;
				if(i-j>interval[k].x1) continue;
				if(ans[i-j][j]!=0) continue;
				ans[i-j][j] = save[p--];
			}
		}
	}
	
	save.clear();
	for(int i=1;i<=a*b;i++) if(check[i]==0) save.push_back(i);
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++) printf("%d ",ans[i][j]);
		printf("\n");
	}
	
	for(int i=0;i<save.size();i++)
	{
		printf("%d??\n",save[i]);
	}
	
	int p = 0;
	for(int j=b;j>=1;j--)
	{
		for(int i=1;i<=a;i++)
		{
			if(ans[i][j]!=0) break;
			ans[i][j] = save[p++];
		}
	}
	for(int i=a;i>=1;i--)
	{
		for(int j=1;j<=b;j++)
		{
			if(ans[i][j]!=0) break;
			ans[i][j] = save[p++];
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++) printf("%d ",ans[i][j]);
		printf("\n");
	}
}

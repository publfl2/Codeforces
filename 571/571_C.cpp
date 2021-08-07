#include <stdio.h>
#include <vector>
#include <algorithm>

int abs(int k)
{
	return k>0?k:-k;
}
bool cmp(int a, int b)
{
	return abs(a)<abs(b);
}

std::vector<int> V[200010];
std::vector<int> event[200010];
int ans[200010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		for(int j=1;j<=c;j++)
		{
			int d;
			scanf("%d",&d);
			V[i].push_back(d);
		}
		std::sort(V[i].begin(),V[i].end(),cmp);
	}
	for(int i=1;i<=a;i++)
	{
		int k = abs(V[i].back());
		event[k].push_back(i);
	}
	
	for(int i=1;i<=b;i++)
	{
		ans[i] = 1;
		for(int j=0;j<event[i].size();j++)
		{
			int ind = event[i][j];
			int control = 0;
			for(int k=0;k<V[ind].size();k++)
			{
				if(V[ind][k]<0 && ans[-V[ind][k]]==0) control = 1;
				if(V[ind][k]>0 && ans[V[ind][k]]==1) control = 1;
			}
			if(control==0) goto u1;
		}
		continue;
		u1:;
		ans[i] = 0;
		for(int j=0;j<event[i].size();j++)
		{
			int ind = event[i][j];
			int control = 0;
			for(int k=0;k<V[ind].size();k++)
			{
				if(V[ind][k]<0 && ans[-V[ind][k]]==0) control = 1;
				if(V[ind][k]>0 && ans[V[ind][k]]==1) control = 1;
			}
			if(control==0) goto u2;
		}
		continue;
		u2:;
		printf("NO");
		return 0;
	}
	printf("YES\n");
	for(int i=1;i<=b;i++) printf("%d",ans[i]);
}

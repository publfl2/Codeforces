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
std::vector<str> V1,V2,V3;

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
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(max1[i]==x[i][j]&&x[i][j]==max2[j])
			{
				V1.push_back({x[i][j],i,j});
			}
			else if(max1[i]==x[i][j])
			{
				V2.push_back({x[i][j],i,j});
			}
			else if(max2[j]==x[i][j])
			{
				V3.push_back({x[i][j],i,j});
			}
		}
	}
	std::sort(V1.begin(),V1.end());
	std::sort(V2.begin(),V2.end());
	std::sort(V3.begin(),V3.end());
	int s = a, t = b;
	
	for(int j=0;j<V3.size();j++) ans[s][t-j] = V3[j].value;
	t -= V3.size();
	ans[s][t] = V1[V1.size()-1].value;
	for(int i=0;i<V2.size();i++) ans[s-(V2.size()-i)][t] = V2[i].value;
	s -= (V2.size()+1);
	t--;
	for(int i=0;i<V1.size()-1;i++) ans[s][t] = V1[(V1.size()-i-2)].value, s--, t--;
	
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) check[ans[i][j]] = 1;
	
	for(int i=1;i<=a*b;i++) if(check[i]==0) save.push_back(i);
	
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
		for(int j=1;j<=b;j++)
		{
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
}

#include <stdio.h>
#include <algorithm>
#define MAX 1000000
std::pair<int,int> P[100010];
int ans[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		P[i] = std::make_pair(b,c);
	}
	ans[1] = 1;
	int xSum = P[1].first;
	int ySum = P[1].second;
	
	for(int i=2;i<=a;i++)
	{
		if(-MAX<=xSum+P[i].first&&xSum+P[i].first<=MAX&&-MAX<=ySum+P[i].second&&ySum+P[i].second<=MAX)
		{
			ans[i] = 1;
			xSum += P[i].first;
			ySum += P[i].second;
		}
		else
		{
			ans[i] = -1;
			xSum -= P[i].first;
			ySum -= P[i].second;
		}
	}
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}

#include <stdio.h>
#include <algorithm>

std::pair<int,int> P[110];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		P[i] = std::make_pair(d,e);
	}
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			int s = P[i].first*P[i].second+P[j].first*P[j].second;
			if(P[i].first+P[j].first<=b&&P[i].second<=c&&P[j].second<=c) ans = ans>s?ans:s;
			if(P[i].first+P[j].second<=b&&P[i].second<=c&&P[j].first<=c) ans = ans>s?ans:s;
			if(P[i].second+P[j].first<=b&&P[i].first<=c&&P[j].second<=c) ans = ans>s?ans:s;
			if(P[i].second+P[j].second<=b&&P[i].first<=c&&P[j].first<=c) ans = ans>s?ans:s;
			if(P[i].first+P[j].first<=c&&P[i].second<=c&&P[j].second<=b) ans = ans>s?ans:s;
			if(P[i].first+P[j].second<=c&&P[i].second<=c&&P[j].first<=b) ans = ans>s?ans:s;
			if(P[i].second+P[j].first<=c&&P[i].first<=c&&P[j].second<=b) ans = ans>s?ans:s;
			if(P[i].second+P[j].second<=c&&P[i].first<=c&&P[j].first<=b) ans = ans>s?ans:s;
		}
	}
	printf("%d",ans);
}

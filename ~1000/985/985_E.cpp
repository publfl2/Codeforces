#include <stdio.h>
#include <algorithm>

std::pair<int,int> P[500010];
int p = 1;
int x[500010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	int pivot = 1;
	for(int i=2;i<=a;i++)
	{
		if(x[i]-x[pivot]>c)
		{
			P[p++] = std::make_pair(pivot,i-1);
			pivot = i;
		}
	}
	P[p] = std::make_pair(pivot,a);
	
	for(int i=p;i>=1;i--)
	{
		if(P[i].second-P[i].first+1>=b) continue;
		else
		{
			if(P[i].second-b+1<=0)
			{
				printf("NO");
				return 0;
			}
			else if(x[P[i].second]-x[P[i].second-b+1]>c)
			{
				printf("NO");
				return 0;
			}
			else
			{
				P[i].first = P[i].second-b+1;
				P[i-1].second = P[i].first-1;
			}
		}
	}
	if(P[1].second-P[1].first+1>=b) printf("YES");
	else printf("NO");
}

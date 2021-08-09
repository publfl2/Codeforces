#include <stdio.h>
#include <algorithm>

std::pair<int,int> P[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		P[i]=std::make_pair(b,c);
	}
	std::sort(P+1,P+a+1);
	int s1=-1, s2=-1;
	for(int i=1;i<=a;i++)
	{
		if(s1<P[i].first) s1 = P[i].second;
		else if(s2<P[i].first) s2 = P[i].second;
		else
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}

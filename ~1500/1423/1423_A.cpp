#include <stdio.h>
#include <algorithm>

struct str{
	int first;
	int second;
	int value;
}P[100010];
bool cmp(str a, str b)
{
	return a.value<b.value;
}

int check1[100010],check2[100010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		P[i]={c,d,e};
	}
	std::sort(P+1,P+b+1,cmp);
	for(int i=1;i<=b;i++)
	{
		if(check1[P[i].first]>0) continue;
		if(check2[P[i].second]>0) continue;
		check1[P[i].first] = P[i].value;
		check2[P[i].second] = P[i].value;
	}
	for(int i=1;i<=a;i++)
	{
		if(check1[i]==0)
		{
			printf("-1");
			return 0;
		}
	}
	
	int ans = check1[1];
	for(int i=2;i<=a;i++) ans = ans>check1[i]?ans:check1[i];
	printf("%d",ans);
}

#include <stdio.h>
#include <queue>

struct str{
	int first;
	int second;
};
bool operator<(str a, str b)
{
	return a.first<b.first;
}
std::priority_queue<str> Q;

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		Q.push({b,c});
	}
	
	int count = 0;
	int ans = 0;
	int min1 = 0, min2 = 12345678;
	while(!Q.empty())
	{
		int b = Q.top().first;
		int c = Q.top().second;
		Q.pop();
		count++;
		if(count>=1000000)
		{
			printf("-1");
			return 0;
		}
		
		if(min1>b)
		{
			printf("-1");
			return 0;
		}
		min1 = b;
		if(min2<c) ans++,Q.push({c,b});
	}
	printf("%d",ans<a-ans?ans:a-ans);
}
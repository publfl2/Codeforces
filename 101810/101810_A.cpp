#include <stdio.h>
#include <algorithm>
#define MAX 2000000009
struct str{
	int x0;
	int value;
}s[200010];

bool cmp(str a, str b)
{
	if(a.x0==b.x0) return a.value<b.value;
	return a.x0<b.x0;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		int p = 1;
		for(int i=1;i<=a;i++)
		{
			int c,d,e;
			scanf("%d%d%d",&c,&d,&e);
			s[p].x0 = c, s[p].value = e, p++;
			s[p].x0 = d+1, s[p].value = -e, p++;
		}
		std::sort(s+1,s+p,cmp);
		for(int i=1;i<p;i++)
		{
			printf("%d %d!!\n",s[i].x0,s[i].value);
		}
		s[p].x0 = MAX, s[p].value = 0;
		long long int ans = 0;
		long long int sum = 0;
		long long int S = s[1].value;
		int T = 1;
		for(int i=1;i<p;i++)
		{
			while(1)
			{
				if(s[T+1].x0<s[i].x0+b)
				{
					sum+=S*(s[T+1].x0-s[T].x0);
					T++;
					S += s[T].value;
				}
				else
				{
					long long int t = sum + S*(s[i].x0+b-s[T].x0);
					ans = ans>t?ans:t;
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
}

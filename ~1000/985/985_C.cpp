#include <stdio.h>
#include <algorithm>
#include <set>

struct str{
	int value;
	int size;
};
bool operator<(str a, str b)
{
	return a.value<b.value;
}
std::multiset<str> S;
std::multiset<int> T;
int x[100010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a*b;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a*b+1);
	
	int limit;
	for(int i=a*b;i>=1;i--)
	{
		if(x[i]-x[1]<=c)
		{
			limit = i;
			break;
		}
	}
	if(limit<a)
	{
		printf("0");
		return 0;
	}
	else
	{
		long long int sum = 0;
		for(int i=1+b*(a-1);i>=1;i-=b)
		{
			if(i>limit)
			{
				sum += x[limit];
				limit--;
			}
			else sum += x[i];
		}
		printf("%lld",sum);
	}
}

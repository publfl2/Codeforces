#include <stdio.h>
#include <algorithm>
#include <set>
struct str{
	int first;
	int second;
}x[500010];

bool cmp(str a, str b)
{
	return a.first<b.first;
}

std::set<int> S;
std::set<int> ::iterator it;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		x[i]={b,c};
	}
	std::sort(x+1,x+a+1,cmp);
	
	int p = 1;
	int count = 0;
	
	for(int j=1;j<=a;j++)
	{
		while(p<=a)
		{
			if(x[p].first<=x[j].second) S.insert(x[p].second),p++;
			else break;
		}
		S.erase(x[j].second);
		
		it = S.end();
		for(;it!=S.begin();)
		{
			it--;
			if((*it)>x[j].second)
			{
				printf("%d %d!\n",(*it),x[j].second);
				count++;
			}
			else break;
			
			if(count>=a)
			{
				printf("NO");
				return 0;
			}
		}
	}
	printf("%d??\n",count);
	if(count==a-1) printf("YES");
	else printf("NO");
}

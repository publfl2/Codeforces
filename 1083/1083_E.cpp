#include <stdio.h>
#include <algorithm>
#include <vector>

struct str{
	long long int first;
	long long int second;
	long long int value;
}x[1000010];
bool cmp(str a, str b)
{
	if(a.first==b.first) return a.second<b.second;
	return a.first<b.first;
}

std::vector< std::pair<long long int, long long int> > V;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		long long int b,c;
		long long int d;
		scanf("%lld%lld%lld",&b,&c,&d);
		x[i]={b,c,d};
	}
	std::sort(x+1,x+a+1,cmp);
	
	V.push_back({0,0});
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int min = 1, max = V.size()-1, pivot = 0;
		while(min<=max)
		{
			int h = (min+max)/2;
			long long int s1 = V[h].first, t1 = V[h].second;
			long long int s2 = V[h-1].first, t2 = V[h-1].second;
			if(t1-t2 <= x[i].second * (s2-s1))
			{
				pivot = h;
				min = h+1;
			}
			else max = h-1;
		}
		long long int val = -(V[pivot].first * x[i].second + V[pivot].second) + x[i].first*x[i].second-x[i].value;
		
		ans = ans>val?ans:val;
		long long int s1 = x[i].first, t1 = val;
		while(V.size()>=2)
		{
			long long int s2 = V.back().first;
			long long int t2 = V.back().second;
			V.pop_back();
			long long int s3 = V.back().first;
			long long int t3 = V.back().second;
			
			if((s2-s1)*(t3-t1)>(s1-s3)*(t2-t1))
			{
				V.push_back({s2,t2});
				break;
			}
		}
		V.push_back({s1,-t1});
	}
	
	printf("%lld",ans);
}
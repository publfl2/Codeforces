#include <stdio.h>
#include <vector>
#include <algorithm>
#include <atcoder/math>

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}
long long int lcm(long long int a, long long int b)
{
	return (a/gcd(a,b))*b;
}

int x[500010],y[500010];
int check[1000010];
std::vector<long long int> V;
int main()
{
	int a,b;
	long long int c;
	scanf("%d%d%lld",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	
	for(int i=1;i<=a;i++) check[x[i]] = i;
	for(int j=1;j<=b;j++)
	{
		if(check[y[j]]!=0)
		{
			std::vector<long long int> r,m;
			r.push_back(check[y[j]]), r.push_back(j);
			m.push_back(a),m.push_back(b);
			std::pair<long long int, long long int> P = atcoder::crt(r,m);
			if(P.second==0) continue;
			if(P.first==0) V.push_back(P.second);
			else V.push_back(P.first);
		}
	}
	std::sort(V.begin(),V.end());
	
	long long int size = lcm(a,b);
	
	long long int min = 0, max = (long long int)1e18;
	long long int ans = max;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		long long int C = h/size;
		long long int sum = C*(size-V.size());
		long long int d = h%size;
		
		int L = 0, R = V.size()-1;
		int ans2 = 0;
		while(L<=R)
		{
			int h2 = (L+R)/2;
			if(V[h2]<=d)
			{
				ans2 = h2+1;
				L = h2+1;
			}
			else R = h2-1;
		}
		sum += (d-ans2);
		
		if(sum>=c)
		{
			ans = h;
			max = h-1;
		}
		else min = h+1;
	}
	printf("%lld",ans);
}
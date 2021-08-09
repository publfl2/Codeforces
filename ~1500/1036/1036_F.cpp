#include <stdio.h>
#include <vector>
#include <cmath>
#define MAX 1000000

long long int root(long long int n, int k)
{
	long long int min = 1, max = n;
	long long int ans = 1;
	if(k==2) return (long long int)std::sqrt(n);
	if(k==3) return (long long int)std::cbrt(n);
	if(k==4) return (long long int)std::sqrt(std::sqrt(n));
	else max = 4100<n?4100:n;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		long long int s = 1;
		for(int i=1;i<=k;i++)
		{
			if(s>(n/h))
			{
				max = h-1;
				goto u;
			}
			else if(s*h>n)
			{
				max = h-1;
				goto u;
			}
			s*=h;
		}
		ans = h;
		min = h+1;
		u:;
	}
	return ans;
}


long long int check[MAX+10];
long long int func(long long int k)
{
	if(k<=1000000&&check[k]>0) return check[k];
	long long int ans = k-1;
	for(int i=2;i<=60;i++)
	{
		long long int s = root(k,i);
		if(s==1) break;
		ans -= func(s);
	}
	if(k<=1000000) check[k] = ans;
	return ans;
}

int main()
{
	for(int i=1000000;i>=2;i--) func(i);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		printf("%lld\n",func(a));
	}
}

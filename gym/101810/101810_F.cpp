#include <stdio.h>
#include <algorithm>
#include <set>
#define MAX 1000000


std::multiset<int> S;
int x[100010];
int y[1000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		for(int i=1;i<=a;i++) y[x[i]]++;
		
		long long int sum = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]==x[i-1]) continue;
			for(int j=x[i];j<=x[a];j+=x[i])
			{
				if(y[j]>0)
				{
					sum += (long long int)y[j]*x[i];
					y[j] = 0;
				}
			}
		}
		printf("%lld\n",sum);
	}
}

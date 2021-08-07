#include <stdio.h>
#include <vector>
#define MAX 10000000

int check[4010];
std::vector<int> prime;


int main()
{
	for(int i=2;i<=4000;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=4000;j+=i) check[j] = 1;
		}
	}
	
	for(int i=0;i<prime.size();i++)
	{
		long long int S = 1;
		long long int T = 1;
		while(1)
		{
			T*=prime[i];
			S*=prime[i];
			S++;
			if(S>MAX) break;
			for(int j=S;j<=MAX;j+=S) if(check2[j]==0) check2[j] = S, check3[j] = T;
		}
	}
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%d",&a);
		long long int ans = 1;
		while(a>1)
		{
			if(check2[a]==0)
			{
				printf("-1\n");
				goto u;
			}
			ans *= check3[a];
			a /= check2[a];
		}
		printf("%lld\n",ans);
		u:;
	}
}
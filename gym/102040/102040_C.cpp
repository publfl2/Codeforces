#include <stdio.h>
#define MOD 10000007

int prime[1000010],p=1;
int check[1000010];

int main()
{
	for(int i=2;i<=1000000;i++)
	{
		if(check[i]==0)
		{
			prime[p++] = i;
			for(int j=i;j<=1000000;j+=i) check[j] = 1;
		}
	}
	
	while(1)
	{
		int a;
		scanf("%d",&a);
		if(a==0) return 0;
		
		long long int ans = 1;
		for(int i=1;i<p;i++)
		{
			if(prime[i]>a) break;
			long long int b = a;
			long long int sum = 1;
			while(b)
			{
				sum += b/prime[i];
				b/=prime[i];
			}
			ans*=(sum+1)*sum/2, ans%=MOD;
		}
		printf("%lld\n",ans);
	}
}

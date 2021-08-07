#include <stdio.h>
#include <algorithm>
#define MOD 7901

int x[100010];

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
		
		
		int p = x[1];
		int n = 1;
		int ans = 1;
		for(int i=2;i<=a;i++)
		{
			if(x[i]!=p)
			{
				p = x[i];
				while(n>1) ans*=n,ans%=MOD,n--;
			}
			else n++;
		}
		int c = 1;
		while(n>1) ans*=n,ans%=MOD,n--;
		printf("%d\n",ans);
	}
}

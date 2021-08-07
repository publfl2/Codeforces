#include <stdio.h>

long long int x[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		int b;
		scanf("%lld%d",&a,&b);
		if(b==1)
		{
			printf("%lld\n",a);
			continue;
		}
		for(int i=1;i<=b;i++) x[i] = 0;
		int c = 2*b-2;
		long long int d = a/c;
		int e = a%c;
		for(int i=1;i<=b;i++) x[i] += d;
		for(int i=2;i<b;i++) x[i] +=d;
		for(int i=1;i<=b;i++)
		{
			if(e==0) break;
			else
			{
				x[i]++;
				e--;
			}
		}
		for(int i=b-1;i>=1;i--)
		{
			if(e==0) break;
			else
			{
				x[i]++;
				e--;
			}
		}
		for(int i=1;i<=b;i++) printf("%lld " ,x[i]);
		printf("\n");
	}
}

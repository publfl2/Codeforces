#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		if(a<b)
		{
			int t = a;
			a = b;
			b = t;
		}
		
		long long int sum = 0;
		int c = (a+1)/2;
		for(int i=1;i<=b;i++)
		{
			sum += c;
			c = (a+1) - c;
		}
		printf("%lld\n",sum);
	}
}

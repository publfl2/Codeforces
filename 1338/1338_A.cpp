#include <stdio.h>

long long int x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		
		for(int i=31;i>=0;i--)
		{
			for(int j=1;j<=a;j++) y[j] = x[j];
			long long int limit = (1<<(i))-1;
			y[a] = x[a]+limit;
			for(int j=a-1;j>=1;j--)
			{
				if(y[j]>y[j+1])
				{
					printf("%d\n",i+1);
					goto u;
				}
				else y[j] = y[j+1]<y[j]+limit?y[j+1]:y[j]+limit;
			}
		}
		printf("0\n");
		u:;
	}
}

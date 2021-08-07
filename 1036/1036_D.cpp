#include <stdio.h>

int x[300010],y[300010];
int main()
{
	int a,b;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	scanf("%d",&b);
	for(int i=1;i<=b;i++) scanf("%lld",&y[i]);
	
	int s = 1, t = 1;
	long long int sum1 = 0, sum2 = 0;
	for(int i=1;i<=a;i++) sum1+= x[i];
	for(int i=1;i<=b;i++) sum2 += y[i];
	if(sum1!=sum2)
	{
		printf("-1");
		return 0;
	}
	sum1 = sum2 = 0;
	sum1 += x[s++];
	
	int count = 0;
	while(1)
	{
		if(sum1==sum2)
		{
			count++;
			if(s>a&&t>b)
			{
				printf("%d",count);
				return 0;
			}
			sum1 = 0;
			sum2 = 0;
			sum1 += x[s++];
		}
		else if(sum1>sum2) sum2 += y\
		[t++];
		else sum1 += x[s++];
	}
}

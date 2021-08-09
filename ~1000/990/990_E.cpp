#include <stdio.h>
long long int MAX = 1;

int x[1000010],prev[2000010],check[1000010];
int main()
{
	for(int i=1;i<=15;i++) MAX*=10;
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		int d;
		scanf("%d",&d);
		if(d==0)
		{
			printf("-1");
			return 0;
		}
		check[d] = 1;
	}
	for(int i=1;i<=a;i++)
	{
		if(check[i]==1) prev[i] = prev[i-1];
		else prev[i] = i;
	}
	for(int i=a+1;i<=2000000;i++) prev[i] = a;
	
	for(int i=1;i<=c;i++) scanf("%d",&x[i]);
	
	long long int ans = MAX;
	for(int i=1;i<=c;i++)
	{
		int start = 0;
		int count = 0;
		long long int value;
		while(start<a)
		{
			//printf("%d!!\n",start);
			if(prev[start+i]==start) goto u;
			else
			{
				start = prev[start+i];
				count++;
			}
		}
		value = (long long int)count*x[i];
		ans = ans<value?ans:value;
		u:;
	}
	if(ans==MAX) printf("-1");
	else printf("%lld",ans);
}

#include <stdio.h>

int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	if(a>=100)
	{
		printf("1");
		return 0;
	}
	
	for(int i=1;i<a;i++)
	{
		int S = x[i]^x[i+1];
		if(i-1>=1 && x[i-1]>S)
		{
			printf("1");
			return 0;
		}
		if(i+2<=a&&x[i+2]<S)
		{
			printf("1");
			return 0;
		}
	}
	
	int ans = 12345678;
	for(int i=a;i>=1;i--)
	{
		int S = x[i];
		int count = 0;
		for(int j=i-1;j>=2;j--)
		{
			S ^= x[j];
			count++;
			if(S<x[j-1])
			{
				ans = ans<count?ans:count;
				break;
			}
		}
	}
	if(ans==12345678) printf("-1");
	else printf("%d",ans);
}

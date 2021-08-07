#include <stdio.h>

int main()
{
	int a;
	int b = 0, c = 0;
	scanf("%d",&a);
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		if(b<c)
		{
			if(c<=d)
			{
				int f = d<e?d:e;
				ans += (f-c+1);
			}
		}
		else if(c<b)
		{
			if(b<=e)
			{
				int f = d<e?d:e;
				ans += (f-b+1);
			}
		}
		else
		{
			int f = d<e?d:e;
			ans += (f-b);
		}
		b = d, c = e;
	}
	printf("%d",ans+1);
}

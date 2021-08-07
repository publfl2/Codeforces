#include <stdio.h>

int x[2010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=2*a;i++) scanf("%d",&x[i]);
		
		int max = x[1] + x[2*a];
		for(int i=2;i<=a;i++)
		{
			int t = x[i]+x[2*a-i+1];
			max = max>t?max:t;
		}
		printf("%d\n",max);
	}
}

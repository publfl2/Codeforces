#include <stdio.h>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int max = 0;
		for(int i=1;i<=a;i++) max = max>x[i]?max:x[i];
		
		long long int ans = 0;
		for(int i=1;i<=a;i++) if(x[i]<x[i-1]) ans += (x[i-1]-x[i]);
		printf("%lld\n",ans);
	}
}

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
		for(int i=1;i<=a;i++) if(x[i]!=i) goto u;
		printf("0\n");
		continue;
		u:;
		
		for(int i=1;i<=a;i++) if(x[i]==i) goto v;
		
		printf("1\n");
		continue;
		v:;
		printf("2\n");
	}
}

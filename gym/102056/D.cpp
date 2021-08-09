#include <stdio.h>

int main()
{
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		long long int s=0,t=0;
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
		}
		for(int i=1;i<=b;i++)
		{
			int c;
			scanf("%d",&c);
		}
		printf("%s\n",a<=b?"Yes":"No");
	}
}

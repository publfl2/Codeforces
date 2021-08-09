#include <stdio.h>
#define MIN -1234567890
int main()
{
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		int max = MIN;
		for(int i=1;i<=a;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			if(d<=b) max = max>c?max:c;
			else max = max>c-(d-b)?max:c-(d-b);
		}
		printf("Case #%d: %d\n",T,max);
	}
}

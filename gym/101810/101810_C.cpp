#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		int count = 0;
		while(1)
		{
			count++;
			if(a%2==1)
			{
				printf("%d\n",count);
				goto u;
			}
			a/=2;
		}
		u:;
	}
}

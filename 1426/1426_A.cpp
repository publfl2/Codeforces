#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a<=2) printf("1\n");
		else
		{
			printf("%d\n",(a-3)/b+2);
		}
	}
}

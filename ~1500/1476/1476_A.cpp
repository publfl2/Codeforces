#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>=b)
		{
			if(b%a==0) printf("1\n");
			else printf("2\n");
		}
		else
		{
			if(b%a==0) printf("%d\n",b/a);
			else printf("%d\n",b/a+1);
		}
	}
	
}

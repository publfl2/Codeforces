#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%I64d%I64d",&a,&b);
		if(a*a>2*b*b) printf("1\n");
		else printf("2\n");
	}
}

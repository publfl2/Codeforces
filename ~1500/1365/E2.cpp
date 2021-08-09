#include <stdio.h>

int main()
{
	freopen("input.txt","w",stdout);
	printf("%d\n",59);
	for(int i=1;i<=59;i++)
	{
		long long int C = 1;
		for(int j=1;j<=i;j++) C*=2;
		printf("%lld ",C);
	}
}

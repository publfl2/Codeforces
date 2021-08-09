#include <stdio.h>

int main()
{
	freopen("input.txt","w",stdout);
	printf("%d %d\n",35,35);
	for(int i=1;i<=35;i++)
	{
		long long int s = 1;
		for(int j=1;j<i;j++) s *=2;
		printf("%lld ",s);
	}
}

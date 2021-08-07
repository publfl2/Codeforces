#include <stdio.h>

int main()
{
	freopen("input.txt","w",stdout);
	printf("%d %d\n",2000,0);
	for(int i=1;i<=2000;i++)
	{
		for(int j=1;j<=2000;j++)
		{
			printf("z");
		}
		printf("\n");
	}
}

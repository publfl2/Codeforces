#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	freopen("input.txt","w",stdout);
	srand(time(NULL));
	printf("50 2450\n");
	for(int i=1;i<=50;i++)
	{
		for(int j=1;j<=50;j++)
		{
			if(i==j) continue;
			printf("%d %d %d\n",i,j,rand());
		}
	}
}

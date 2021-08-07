#include <stdio.h>

int main()
{
	freopen("input.txt","w",stdout);
	printf("1\n");
	int a;
	scanf("%d",&a);
	printf("%d %d %d\n",a,a*(a-1)/2,a+1);
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			printf("%d %d\n",i,j);
		}
	}
}

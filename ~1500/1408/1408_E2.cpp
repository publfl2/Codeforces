#include <stdio.h>

int main()
{
	freopen("input.txt","w",stdout);
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d %d\n",a,b);
	for(int i=1;i<=a;i++) printf("%d ",1000000000);
	printf("\n");
	for(int j=1;j<=b;j++) printf("%d ",1000000000);
	printf("\n");
	for(int i=1;i<=a;i++)
	{
		printf("2 ");
		for(int j=1;j<=2;j++) printf("%d ",j);
		printf("\n");
	}
}

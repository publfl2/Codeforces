#include <stdio.h>

int main()
{
	freopen("input.txt","w",stdout);
	int a = 10000;
	int b = 10000 - 1;
	int c = 10000 - 1;
	printf("%d %d %d\n",a,b,c);
	for(int i=1;i<=c;i++) printf("%d ",i);
	printf("\n");
	for(int i=1;i<=b;i++) printf("%d %d\n",i,i+1);
}

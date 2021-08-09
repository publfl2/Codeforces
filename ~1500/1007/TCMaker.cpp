#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	freopen("input.txt","w",stdout);
	int a;
	scanf("%d",&a);
	printf("%d\n",a);
	for(int i=1;i<=a;i++) printf("%d %d %d\n",rand()+50000,rand()+50000,rand()+50000);
}

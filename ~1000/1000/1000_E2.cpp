#include <stdio.h>

int main()
{
	freopen("input.txt","w",stdout);
	int a;
	scanf("%d",&a);
	printf("%d %d\n",a,a-1);
	for(int i=1;i<=a-1;i++) printf("%d %d\n",i,i+1);
}
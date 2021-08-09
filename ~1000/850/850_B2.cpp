#include <stdio.h>

int main()
{
	freopen("input.txt","w",stdout);
	printf("500000 1 1\n");
	for(int i=1;i<=500000;i++) printf("%d ",1000000-i);
	
}

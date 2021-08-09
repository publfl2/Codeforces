#include <stdio.h>

int main()
{
	freopen("input.txt","w",stdout);
	printf("1000001\n");
	for(int i=1;i<=500000;i++) printf("a");
	printf(" ");
	for(int i=1;i<=500000;i++) printf("a");
}
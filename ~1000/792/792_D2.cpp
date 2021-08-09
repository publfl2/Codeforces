#include <stdio.h>

int main()
{
	freopen("input.txt","w",stdout);
	long long int a = 1;
	for(int i=1;i<=60;i++) a*=2;
	a--;
	printf("%lld 1\n",a);
	printf("12345\n");
	for(int i=1;i<=100000;i++) printf("R");
}

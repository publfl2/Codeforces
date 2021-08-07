#include <stdio.h>

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int e = a>c?a:c;
	printf("%d",2*(e+b+d+2));
}

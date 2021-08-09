#include <stdio.h>
#include <math.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		printf("%d\n",(int)sqrt((double)a/6+0.1));
	}
}

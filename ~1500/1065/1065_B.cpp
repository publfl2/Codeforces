#include <stdio.h>

int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	if(2*b>=a) printf("0 ");
	else printf("%lld ",a-(2*b));
	
	if(b==0)
	{
		printf("%lld",a);
		return 0;
	}
	int control = 0;
	for(long long int i=2;i<=a;i++)
	{
		long long int c = i*(i-1)/2;
		if(c>=b)
		{
			printf("%lld",a-i);
			return 0;
		}
	}
}

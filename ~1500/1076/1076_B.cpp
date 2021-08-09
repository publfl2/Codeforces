#include <stdio.h>

int main()
{
	long long int a;
	int count = 0;
	scanf("%lld",&a);
	if(a%2==0) printf("%lld",a/2);
	else
	{
		for(int i=2;i<=123456;i++)
		{
			if(a%i==0)
			{
				printf("%lld",(a-i)/2+1);
				return 0;
			}
		}
		printf("1");
	}
}

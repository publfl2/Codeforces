#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		long long int b,c;
		scanf("%lld%lld",&b,&c);
		long long int s1 = (b<c?b:c)-1;
		
		long long int s2 = b - s1;
		long long int s3 = c - s1;
		printf("%lld %lld %lld\n",s1,s2,s3);
	}
}

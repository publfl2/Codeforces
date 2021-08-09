#include <stdio.h>

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}
long long int lcm(long long int a, long long int b)
{
	return (a/gcd(a,b))*b;
}

long long int x[150010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		long long int b,c;
		scanf("%lld%lld",&b,&c);
		x[i] = lcm(b,c);
	}
	
	long long int s = x[1];
	for(int i=2;i<=a;i++) s = gcd(s,x[i]);
	if(s==1)
	{
		printf("-1");
		return 0;
	}
	for(int i=2;i<=50000;i++)
	{
		if(s%i==0)
		{
			printf("%d",i);
			return 0;
		}
	}
	printf("%lld",s);
	return 0;
}

#include <stdio.h>
long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

long long int func(long long int s, long long int t)
{
	for(long long int i=0;i*i<=s;i++)
	{
		if(t==i) break;
		if(gcd(s,t-i)>1)
		{
			long long int c = gcd(s,t-i);
			return func(s/c,(t-i)/c-1)+i+1;
		}
	}
	
	long long int i;
	for(i=2;i*i<=s;i++) while(s%i==0) s/=i;
	if(s>=i)
	{
		long long int k = s*(t/s);
		if(k>0) return func(s,t/s)+(t-s*(t/s));
		else return t;
	}
	else return t;
}
int main()
{
	long long int a,b;
	scanf("%I64d%I64d",&a,&b);
	printf("%I64d",func(a,b));
}

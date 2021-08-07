#include <stdio.h>
#include <vector>

int a,b;
int power(int value, int k, int prime)
{
	int s = 1;
	int p = k;
	while(k)
	{
		if(k%2==0)
		{
			s *= p;
			s %= prime;
		}
		p*=p;
		p%=prime;
		k/=2;
	}
	return s;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int c;
		scanf("%d%d%d",&a,&b,&c);
		
		int phi = 1;
		for(int i=2;i*i<=c;i++)
		{
			int count = 0;
			while(c%i==0)
			{
				count++;
				c/=i;
			}
			while(--count) phi *= i;
			phi *= (i-1);
		}
		if(c>1) phi *= (c-1);
	}
}

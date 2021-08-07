#include <stdio.h>

int comb(int a, int b)
{
	if(a<b) return 0;
	if(a==b) return 1;
	if(b==0) return 1;
	return comb(a-1,b)+comb(a-1,b-1);
}
int x[30];
long long int y[30];
long long int func(int s, int t)
{
	if(t==0) return 1;
	if(s==0) return 1;
	
	if(x[s]==0) return func(s-1,t);
	else
	{
		long long int sum = 0;
		for(int i=0;i<=t;i++) sum += comb(s-1,i)*y[i];
		
		long long int s1 = sum;
		
		sum = 0;
		for(int i=0;i<=t-1;i++) sum += comb(s-1,i)*y[i];
		long long int s2 = (x[s]-1)*sum;
		long long int s3 = func(s-1,t-1);
		return s1+s2+s3;
	}
}
int main()
{
	y[0] = 1;
	for(int i=1;i<=20;i++) y[i] = y[i-1]*9;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int b,c;
		scanf("%lld%lld",&b,&c);
		for(int i=1;i<=19;i++)
		{
			x[i] = c%10;
			c/=10;
		}
		long long int s1 = func(20,3);
		
		b--;
		for(int i=1;i<=19;i++)
		{
			x[i] = b%10;
			b/=10;
		}
		long long int s2 = func(20,3);
		printf("%lld\n",s1-s2);
	}
}

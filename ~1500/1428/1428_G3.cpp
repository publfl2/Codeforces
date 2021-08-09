#include <stdio.h>
#include <algorithm>
 
int a;
long long int MIN = -1;
int priority[10];
long long int power[10];
long long int F[10];
bool cmp(int a, int b)
{
	long long int s = F[a]*power[b];
	long long int t = F[b]*power[a];
	return s>t;
}
 
long long int func(long long int val, int p)
{
	if(val<0) return MIN;
	if(p>=6)
	{
		long long int S = 0;
		for(int i=0;i<=5;i++)
		{
			int k = val%10;
			if(k==3) S += F[i];
			if(k==6) S += 2*F[i];
			if(k==9) S += 3*F[i];
			val/=10;
		}
		return S;
	}
	
	int k = val/(3*power[priority[p]])<3*a-3?val/(3*power[priority[p]]):3*a-3;
	long long int s2 = func(val-k*3*power[priority[p]],p+1) + k*F[priority[p]];
	return s2;
}
int main()
{
	for(int i=1;i<=17;i++) MIN*=10;
	power[0] = 1;
	for(int i=1;i<=5;i++) power[i] = power[i-1]*10;
	scanf("%d",&a);
	for(int i=0;i<=5;i++) scanf("%lld",&F[i]);
	for(int i=0;i<=5;i++) priority[i] = i;
	std::sort(priority,priority+6,cmp);
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		long long int c;
		scanf("%lld",&c);
		printf("%lld\n",func(c,0));
	}
}

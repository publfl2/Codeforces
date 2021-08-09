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
	if(s==t) return a>b;
	return s>t;
}

int check[10];
long long int func(long long int val, int p)
{
	if(val<0) return MIN;
	if(p>=6)
	{
		int S = 0;
		for(int i=5;i>=0;i--)
		{
			S*=10;
			S += (val/power[i])%10;
			if(9*check[i]>=S) S = 0;
			else S -= 9*check[i];
		}
		if(S==0) return 0;
		else return MIN;
	}
	
	int k = val/(3*power[priority[p]])<3*a-3?val/(3*power[priority[p]]):3*a-3;
	check[priority[p]] = a-((k+2)/3);
	long long int s1 = func(val-k*3*power[priority[p]],p+1) + k*F[priority[p]];
	k = 3*a-2;
	check[priority[p]] = a-((k+2)/3);
	long long int s2 = func(val-k*3*power[priority[p]],p+1) + k*F[priority[p]];
	k = 3*a-1;
	check[priority[p]] = a-((k+2)/3);
	long long int s3 = func(val-k*3*power[priority[p]],p+1) + k*F[priority[p]];
	k = 3*a;
	check[priority[p]] = a-((k+2)/3);
	long long int s4 = func(val-k*3*power[priority[p]],p+1) + k*F[priority[p]];
	long long int M1 = s1>s2?s1:s2;
	long long int M2 = s3>s4?s3:s4;
	return M1>M2?M1:M2;
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

#include <stdio.h>
#include <algorithm>
#include <map>
long long int x[200010];
std::map<long long int, long long int> M;

long long int s1;
long long int s2;
long long int MOD = 1;
int main()
{
	for(int i=1;i<=9;i++) MOD*=10;
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%I64d",&x[i]);
	
	for(int i=1;i<=a;i++)
	{
		long long int k = i*x[i];
		s1 += (k/MOD), s2 += k%MOD;
	}
	for(int i=1;i<=a;i++)
	{
		long long int k = (a-i+1)*x[i];
		s1 -= (k/MOD), s2 -= (k%MOD);
	}
	for(int i=1;i<=a;i++)
	{
		if(M.find(x[i]-1)!=M.end()) s2 -= M[x[i]-1];
		if(M.find(x[i]+1)!=M.end()) s2 += M[x[i]+1];
		M[x[i]]++;
	}
	while(s2<0) s2 += MOD, s1--;
	s1 += (s2/MOD);
	s2 %= MOD;
	if(s1==0) printf("%lld",s2);
	else if(s1<0)
	{
		if(s1==-1) printf("-%lld",MOD-s2);
		else
		{
			printf("%lld",s1+1);
			printf("%010lld",MOD-s2);
		}
	}
	else
	{
		printf("%lld",s1);
		printf("%010lld",s2);
	}
}

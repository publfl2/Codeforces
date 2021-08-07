#include <stdio.h>
#include <map>
#define MOD (long long int)1e16

std::map<int,long long int> M;

int main()
{
	int a;
	scanf("%d",&a);
	
	long long int S1 = 0, S2 = 0;
	long long int ans1 = 0, ans2 = 0;
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		
		long long int T1 = (S1-M[b]-M[b-1]-M[b+1])*b;
		long long int T2 = (S2 - M[b]*b - M[b-1]*(b-1) - M[b+1]*(b+1));
		long long int T = T1-T2;
		
		ans1--;
		ans2 += (MOD+T);
		ans1 += (ans2/MOD);
		ans2 %= MOD;
		
		M[b]++;
		S1++;
		S2+=b;
	}
	
	if(ans1<0)
	{
		ans1++;
		ans2-=MOD;
		long long int temp = -ans2;
		if(ans1!=0) printf("%lld%016lld",ans1,temp);
		else printf("%lld",ans2);
	}
	else
	{
		if(ans1!=0) printf("%lld%016lld",ans1,ans2);
		else printf("%lld",ans2);
	}
	
}
#include <stdio.h>
#include <vector>

std::pair<long long int, long long int> P[10];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		long long int b,c;
		scanf("%lld%lld",&b,&c);
		P[i]=std::make_pair(b,c);
	}
	long long int s1 = (P[2].first-P[1].first);
	long long int t1 = (P[2].second-P[1].second);
	long long int s2 = (P[3].first-P[2].first);
	long long int t2 = (P[3].second-P[2].second);
	printf("%lld %lld %lld %lld!!\n",s1,s2,t1,t2);
	printf("%lld",s1*s2+t1*t2);
}

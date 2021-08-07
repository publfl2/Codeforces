#include <stdio.h>
#include <map>

std::map<long long int,int> M;

long long int ans[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		long long int b,c;
		scanf("%lld%lld",&b,&c);
		M[b]++;
		M[c+1]--;
	}
	
	std::map<long long int,int> ::iterator it = M.begin();
	
	long long int s = it->first;
	int t = it->second;
	it++;
	for(;it!=M.end();it++)
	{
		ans[t] += (it->first-s);
		t += it->second;
		s = it->first;
	}
	for(int i=1;i<=a;i++) printf("%lld ",ans[i]);
}

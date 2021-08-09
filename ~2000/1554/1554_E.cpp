#include <stdio.h>
#include <vector>
#define MOD 998244353

std::vector<int> V[100010];
std::pair<long long int, long long int> func(int k, int prev, int g)
{
	std::vector<long long int> temp,temp2;
	temp.push_back(1);
	for(int i=0;i<=g;i++) temp.push_back(0);
	for(int i=0;i<=g;i++) temp2.push_back(0);
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		std::pair<long long int,long long int> P = func(V[k][i],k,g);
		
		for(int j=0;j<=g;j++) temp2[j] = 0;
		for(int j=0;j<g;j++) temp2[j] += temp[j]*P.second, temp2[j] %= MOD;
		for(int j=0;j<g;j++) temp2[j+1] += temp[j]*P.first, temp2[j+1] %= MOD;
		temp2[0] += temp2[g], temp2[0] %= MOD;
		for(int j=0;j<g;j++) temp[j] = temp2[j];
	}
	return std::make_pair(temp[0],temp[g-1]);
}

long long int ans[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			V[b].push_back(c);
			V[c].push_back(b);
		}
		
		int min = 500;
		for(int i=1;i<=min&&i<=a;i++)
		{
			std::pair<long long int, long long int> P = func(1,0,i);
			ans[i] = P.first;
		}
		for(int i=min+1;i<=a;i++) ans[i] = 0;
		for(int i=a;i>=1;i--) for(int j=2*i;j<=a;j+=i) ans[i] += (MOD-ans[j]), ans[i] %= MOD;
		
		for(int i=1;i<=a;i++) printf("%lld ",ans[i]);
		printf("\n");
	}
}
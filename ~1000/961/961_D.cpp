#include <stdio.h>
#include <algorithm>
#include <vector>

std::pair<long long int,long long int> P[100010];
int a;

int check[100010];
std::vector<int> V;
bool func2(int s, int t)
{
	for(int i=1;i<=a;i++)
	{
		if(check[i]==1) continue;
		if((P[i].first-P[s].first)*(P[i].second-P[t].second)!=(P[i].second-P[s].second)*(P[i].first-P[t].first)) return false;
	}
	return true;
}
bool func(int s, int t)
{
	V.clear();
	for(int i=1;i<=a;i++) check[i] = 0;
	for(int i=1;i<=a;i++) if((P[i].first-P[s].first)*(P[i].second-P[t].second)==(P[i].second-P[s].second)*(P[i].first-P[t].first)) check[i] = 1;
	for(int i=1;i<=a;i++) if(check[i]==0) V.push_back(i);
	if(V.size()<=1) return true;
	else return func2(V[0],V[1]);
}
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld%lld",&P[i].first,&P[i].second);
	if(a<=2)
	{
		printf("YES");
		return 0;
	}
	if(func(1,2)) printf("YES");
	else if(func(2,3)) printf("YES");
	else if(func(1,3)) printf("YES");
	else printf("NO");
}

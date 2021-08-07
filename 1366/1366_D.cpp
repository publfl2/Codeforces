#include <stdio.h>
#include <vector>
#define MAX 10000000
std::pair<int,int> ans[10000010];
std::vector<int> prime;
int check[10000010];
int x[500010];
int main()
{
	for(int i=2;i<=MAX;i++) ans[i] = std::make_pair(-1,-1);
	for(int i=2;i<=MAX;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=MAX;j+=i) check[j] = 1;
			for(int j=i;j<=MAX;j+=i) ans[j] = std::make_pair(i,j/i);
		}
	}
	for(int i=0;i<prime.size();i++)
	{
		long long int C = 1;
		while(1)
		{
			C*=prime[i];
			if(C>MAX) break;
			ans[C] = std::make_pair(-1,-1);
		}
	}
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) printf("%d ",ans[x[i]].first);
	printf("\n");
	for(int i=1;i<=a;i++) printf("%d ",ans[x[i]].second);
}

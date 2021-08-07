#include <stdio.h>
#include <vector>

std::vector<int> V[10];
int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		V[0].clear();
		V[1].clear();
		for(int i=1;i<=2*a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=2*a;i++) V[x[i]%2].push_back(i);
		
		for(int i=0;i+1<(int)V[0].size()-1;i+=2) printf("%d %d\n",V[0][i],V[0][i+1]);
		for(int i=0;i+1<(int)V[1].size()-1;i+=2) printf("%d %d\n",V[1][i],V[1][i+1]);
	}
}

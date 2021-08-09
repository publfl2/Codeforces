#include <stdio.h>
#include <vector>

std::vector<int> V;
int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int max = x[1];
		for(int i=1;i<=a;i++) max = max>x[i]?max:x[i];
		for(int i=1;i<=a;i++) if(x[i]==max) V.push_back(i);
		if(V.size()<=2) printf("NO\n");
		else
		{
			printf("YES\n");
			printf("%d %d %d\n",V[0],V[1]-V[0],a-V[1]);
		}
	}
}

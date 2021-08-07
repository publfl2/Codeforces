#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > check[5000010];
int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	if(a>=5000) a = 5000;
	
	for(int i=a;i>=1;i--)
	{
		for(int j=1;j<i;j++)
		{
			if(check[x[i]+x[j]].size()>=1)
			{
				printf("YES\n");
				printf("%d %d %d %d",j,i,check[x[i]+x[j]][0].first,check[x[i]+x[j]][0].second);
				return 0;
			}
		}
		for(int j=i+1;j<=a;j++) check[x[i]+x[j]].push_back({i,j});
	}
	printf("NO");
}
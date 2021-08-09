#include <stdio.h>
#include <vector>

std::pair<int,int> index[100010];
std::vector<int> St;
std::vector<int> V[100010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		for(int j=1;j<=c;j++)
		{
			int d;
			scanf("%d",&d);
			V[i].push_back(d);
			index[d] = std::make_pair(i,j-1);
		}
	}
	
	int ans = 0;
	for(int i=1;i<=b;i++)
	{
		St.clear();
		St.push_back(V[i][0]);
		for(int j=1;j<V[i].size();j++)
		{
			if(V[i][j]!=V[i][j-1]+1)
			{
				ans++;
				St.push_back(V[i][j]);
			}
		}
		ans += St.size();
	}
	printf("%d",ans-1);
}

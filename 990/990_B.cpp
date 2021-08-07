#include <stdio.h>
#include <queue>
#include <algorithm>

std::queue<int> Q;
int x[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		while(!Q.empty())
		{
			int k = Q.front();
			if(k+b<x[i])
			{
				ans++;
				Q.pop();
			}
			else if(k<x[i]) Q.pop();
			else break;
		}
		Q.push(x[i]);
	}
	printf("%d",ans+Q.size());
}

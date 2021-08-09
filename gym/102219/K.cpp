#include <stdio.h>
#include <algorithm>
int x[100010];
int main()
{
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		
		long long int s = 0;
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			if(s<=x[i])
			{
				ans++;
				s += x[i];
			}
		}
		printf("Case #%d: %d\n",T,ans);
	}
}

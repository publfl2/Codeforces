#include <stdio.h>
#include <queue>
std::priority_queue<long long int> Q;

int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	if(a==1) printf("0");
	else if(a<=3)
	{
		long long int S = 0;
		for(int i=1;i<=a;i++) S += x[i];
		printf("%lld",S);
		return 0;
	}
	else
	{
		for(int i=1;i<=a;i++) Q.push(-x[i]);
		long long int ans = 0;
		long long int x0,y0,z0;
		if(a%2==0)
		{
			x0 = Q.top();
			Q.pop();
			y0 = Q.top();
			Q.pop();
			ans -= (x0+y0);
			Q.push(x0+y0);
		}
		while(Q.size()>1)
		{
			x0 = Q.top();
			Q.pop();
			y0 = Q.top();
			Q.pop();
			z0 = Q.top();
			Q.pop();
			ans -= (x0+y0+z0);
			Q.push(x0+y0+z0);
		}
		printf("%lld",ans);
		return 0;
	}
}

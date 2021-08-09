#include <stdio.h>

struct str{
	int x0;
	int y0;
}x[200010];

bool cmp(str a, str b)
{
	return a.y0<b.y0;
}
int main()
{
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		for(int i=1;i<=a;i++) scanf("%d",&x[i].x0);
		for(int i=1;i<=a;i++) scanf("%d",&x[i].y0);
		std::sort(x+1,x+a+1,cmp);
		
		long long int s = 0;
		for(int i=1;i<=a;i++)
		{
			while(x[i].x0==x[i+1].x0)
			{
				s += type[x[i].x0];
			}
		}
	}
}

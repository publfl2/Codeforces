#include <stdio.h>
#include <algorithm>
struct str{
	int x0;
	int y0;
}x[200010];
bool cmp(str a, str b)
{
	return a.x0<b.x0;
}

int y[200010];
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=1;i<=a;i++) scanf("%d%d",&x[i].x0, &x[i].y0);
	std::sort(x+1,x+a+1,cmp);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	y[0] = 0;
	y[b+1] = c;
	
	for(int t=1;t<=a;t++)
	{
		long long int s = 0;
		for(int i=1;i<=b+1;i++)
		{
			int f = y[i]-y[i-1];
			if(f>x[t].y0) goto u;
			if(2*f<=x[t].y0) s += f;
			else s += (x[t].y0-f) + 2*(x[t].y0-2*(x[t].y0-f));
			//s += (3*f-x[t].y0);
		}
		if(s>d) continue;
		
		printf("%d",x[t].x0);
		return 0;
		u:;
	}
	printf("-1");
}

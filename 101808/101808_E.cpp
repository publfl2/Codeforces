#include <stdio.h>
#include <algorithm>
#include <queue>
struct str{
	int x0;
	int y0;
}x[100010];

struct segTree{
	
	int x[1000010];
	
};
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d%d",&x[i].x0,&x[i].y0);
	}
}

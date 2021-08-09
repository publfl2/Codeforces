#include <stdio.h>
#include <algorithm>

int x[10010],y[10010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(c>d) d+=a;
		x[c]++, x[d+1]--;
	}
	for(int i=1;i<=2*a;i++)
	{
		y[i] = y[i-1] + x[i];
	}
	for(int i=1;i<=2*a;i++) printf("%d " ,y[i]);
}

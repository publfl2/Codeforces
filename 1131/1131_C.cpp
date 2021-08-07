#include <stdio.h>
#include <algorithm>

int x[110],y[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	int s = 1, t = a;
	int p = 1;
	while(1)
	{
		y[s++] = x[p++];
		if(p>a) break;
		y[t--] = x[p++];
		if(p>a) break;
	}
	for(int i=1;i<=a;i++) printf("%d ",y[i]);
}

#include <stdio.h>
#include <algorithm>
int x[5010];
int y[5010];
int p = 1;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	y[p++] = x[1];
	for(int i=2;i<=a;i++)
	{
		for(int j=1;j<p;j++)
		{
			if(y[j]<x[i])
			{
				y[j] = x[i];
				goto u;
			}
		}
		y[p++] = x[i];
		u:;
	}
	printf("%d",p-1);
}

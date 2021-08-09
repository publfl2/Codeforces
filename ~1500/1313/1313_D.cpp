#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		x[i] = {d,e};
	}
	std::sort(x+1,x+a+1,cmp);
}

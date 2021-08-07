#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		x[i] = std::make_pair(b,c);
	}
	
	std::sort(x+1,x+a+1,cmp1);
	for(int i=1;i<=a;i++)
	{
		
	}
}

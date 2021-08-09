#include <stdio.h>


int main()
{
	int a;
	scanf("%d",&a);
	for(int i=2;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		V[b].push_back(i);
	}
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	func(1,0);
}

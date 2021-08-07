#include <stdio.h>

int x[1010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		x[c]++;
	}
	
	int min = x[1];
	for(int i=1;i<=a;i++) min = min<x[i]?min:x[i];
	printf("%d",min);
}

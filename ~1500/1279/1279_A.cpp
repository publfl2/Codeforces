#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		if(b-1<=c+d&&c-1<=b+d&&d-1<=b+c) printf("Yes\n");
		else printf("No\n");
	}
}

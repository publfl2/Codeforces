#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=1000;i++)
	{
		if(i*i>=a)
		{
			printf("%d",i);
			return 0;
		}
	}
}
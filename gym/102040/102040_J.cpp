#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		double price;
		scanf("%lf",&price);
		double output = price*1.15;
		printf("%.2lf\n",output);
	}
}

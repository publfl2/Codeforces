#include <stdio.h>

int x[1010];
int main()
{
	for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) x[3*i+7*j] = 1;
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		printf("%s\n",x[b]==1?"YES":"NO");
	}
}

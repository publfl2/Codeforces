#include <stdio.h>

int main()
{
	int a,b,c,d,e;
	scanf("%d",&a);
	printf("YES\n");
	for(int i=1;i<=a;i++)
	{
		scanf("%d%d%d%d",&b,&c,&d,&e);
		c%=2,c+=10,c%=2;
		b%=2,b+=10,b%=2;
		printf("%d\n",2*c+b+1);
	}
}

#include <stdio.h>
int x[110];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		if(b<=(86400-x[i]))
		{
			printf("%d",i);
			return 0;
		}
		else b-=(86400-x[i]);
	}
}

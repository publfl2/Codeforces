#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=2*a;i++)
	{
		int b;
		scanf("%d",&b);
		if(b<a) printf("? %d %d\n",0,b);
		else printf("? %d %d\n",a-1,b^(a-1));
	}
	printf("!\n1\n");
	for(int i=1;i<=a;i++) printf("%d ",i-1);
	fflush(stdout);
}

#include <stdio.h>

char x[300010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	for(int i=1;i<a;i++)
	{
		if(x[i]>x[i+1])
		{
			printf("YES\n");
			printf("%d %d",i,i+1);
			return 0;
		}
	}
	printf("NO");
}

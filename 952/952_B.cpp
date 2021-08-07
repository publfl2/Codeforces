#include <stdio.h>
int x[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&x[i]);
	}
	for(int i=1;i<a;i++)
	{
		if(x[i]>x[i+1])
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}

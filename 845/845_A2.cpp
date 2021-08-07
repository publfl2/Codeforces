#include <stdio.h>
#include <algorithm>

int x[110];
int count[1010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=2*a;i++)
	{
		int b;
		scanf("%d",&b);
		count[b]++;
	}
	for(int i=1;i<=1000;i++)
	{
		if(count[i]>a)
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}
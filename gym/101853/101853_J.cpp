#include <stdio.h>
#include <algorithm>

int x[10010];
int check[10010];
int check2[10010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=0;i<=10000;i++) check[i] = 0;
		for(int i=0;i<=10000;i++) check2[i] = 0;
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			check2[b] = 1;
			check[b]++;
			check[b-1]++;
		}
		
		int ans = 0;
		int max = 0;
		for(int i=1;i<=10000;i++)
		{
			max = max>check[i]?max:check[i];
		}
		printf("%d\n",max);
	}
}

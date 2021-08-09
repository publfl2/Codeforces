#include <stdio.h>

int x[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a<b)
		{
			printf("-1\n");
			continue;
		}
		int c = a/b;
		int d = a%b;
		for(int i=1;i<=b;i++) x[i] = c;
		for(int i=b;i>=b-d+1;i--) x[i]++;
		for(int i=1;i<=b;i++) printf("%d ",x[i]);
		printf("\n");
	}
}

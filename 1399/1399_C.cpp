#include <stdio.h>

int x[110],count[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) count[i] = 0;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) count[x[i]]++;
		
		int ans = 0;
		for(int i=1;i<=2*a;i++)
		{
			int C = 0;
			for(int j=1;j<i;j++)
			{
				if(j<i-j) C += (count[j]<count[i-j]?count[j]:count[i-j]);
				else if(j==i-j) C += (count[j]/2);
				else break;
			}
			ans = ans>C?ans:C;
		}
		printf("%d\n",ans);
	}
}

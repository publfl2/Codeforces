#include <stdio.h>

long long int x[1010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	if(a==1) printf("%lld",x[1]);
	else if(a==2) printf("%lld",x[1]|x[2]);
	else
	{
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			for(int j=i+1;j<=a;j++)
			{
				for(int k=j+1;k<=a;k++)
				{
					long long int C = ((x[i]|x[j])|x[k]);
					ans = ans>C?ans:C;
				}
			}
		}
		printf("%lld",ans);
	}
	
}

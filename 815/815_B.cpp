#include <stdio.h>
#include <complex>
#include <vector>

long long int x[110];
long long int y[110][110];

int main()
{
	int a;
	scanf("%d",&a);
	//for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	
	for(int l=1;l<=a;l++)
	{
		for(int k=1;k<=a;k++) y[1][k] = 0;
		y[1][l] = 1;
		
		int sign = 1;
		for(int j=2;j<=a;j++)
		{
			for(int k=1;k<=a-j+1;k++)
			{
				y[j][k] = y[j-1][k] + sign*y[j-1][k+1];
				sign*=-1;
			}
		}
		printf("%lld ",y[a][1]);
	}
}

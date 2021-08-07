#include <stdio.h>
#define MOD 1000000007

long long int check[2000010][3];
int main()
{
	// 2f(n-2) + f(n-1)
	// 4f(n-4) + 2f(n-3) + f(n-2) + 2f(n-3) + 1
	// 4f(n-4) + 4f(n-3) + f(n-2) + 1
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a<=2)
		{
			printf("0\n");
			continue;
		}
		
		for(int i=0;i<=a;i++) check[i][0] = check[i][1] = 0;
		
		for(int i=3;i<=a;i++)
		{
			long long int s = 0;
			s += 2*(check[i-2][0]>check[i-2][1]?check[i-2][0]:check[i-2][1]);
			s += (check[i-1][0]>check[i-1][1]?check[i-1][0]:check[i-1][1]);
			check[i][0] = s%MOD;
			
			s = 2*check[i-2][0] + check[i-1][0] + 4;
			check[i][1] = s%MOD;
			printf("%lld %lld\n",check[i][0], check[i][1]);
		}
		if(a%4==3) printf("%lld\n",check[a][1]);
		else printf("%lld\n",check[a][0]);
	}
}

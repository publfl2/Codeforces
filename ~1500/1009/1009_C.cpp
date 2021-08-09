#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	long long int ans = 0;
	for(int i=1;i<=b;i++)
	{
		long long int c,d;
		scanf("%I64d%I64d",&c,&d);
		
		// 0 ~ s-1
		long long int s1 = c*a + d*a*(a-1)/2;
		// a-1 ~ 1or 0
		long long int s2;
		if(a%2==1) s2 = c*a + d*(a-1)*(a+1)/4;
		else s2 = c*a + d*a*(a)/4;
		ans += s1>s2?s1:s2;
	}
	printf("%.12lf",(double)ans/a);
}

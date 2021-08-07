#include <stdio.h>
long long int MAX = 1;
int main()
{
	for(int i=1;i<=9;i++) MAX*=10;
	MAX *= 2;
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	
	long long int min = 1, max = MAX;
	long long int ans = MAX;
	while(min<=max)
	{
		long long int h =(min+max)/2;
		long long int sum;
		if(h<=b) sum = h*(h+1)/2;
		else sum = (h+b-1)*(h-b)/2+h*(h+1)/2;
		if(sum>a) max = h-1;
		else if(sum==a)
		{
			if(h<=b) ans = ans<h?ans:h;
			else ans = ans<2*h-b?ans:2*h-b;
			min = h+1;
		}
		else
		{
			if(h<=b) ans = ans<h+((a-sum-1)/h+1)?ans:h+((a-sum-1)/h+1);
			else ans = ans<2*h-b+((a-sum-1)/h+1)?ans:2*h-b+((a-sum-1)/h+1);
			min = h+1;
		}
	}
	printf("%lld",ans);
}

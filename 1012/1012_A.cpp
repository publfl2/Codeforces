#include <stdio.h>
#include <algorithm>

long long int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=2*a;i++) scanf("%lld",&x[i]);
	std::sort(x+1,x+2*a+1);
	long long int min1 = x[1];
	long long int max1 = x[a];
	long long int min2 = x[a+1];
	long long int max2 = x[2*a];
	printf("%lld",(max1-min1)*(max2-min2));
}



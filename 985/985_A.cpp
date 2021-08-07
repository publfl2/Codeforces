#include <stdio.h>
#include <algorithm>

int abs(int k)
{
	return k>0?k:-k;
}

int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a/2;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a/2+1);
	
	int sum1 = 0;
	for(int i=1;i<=a/2;i++) sum1 += abs(x[i]-(2*i-1));
	int sum2 = 0;
	for(int i=1;i<=a/2;i++) sum2 += abs(x[i]-(2*i));
	printf("%d",sum1<sum2?sum1:sum2);
}

#include <stdio.h>
#include <algorithm>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}
int x[3000010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	t = x[a];
	for(int i=a-1;i>=1;i--) t = gcd(t,x[i]);
	for(int i=1;i<=a;i++) x[i] /= t;
	
}

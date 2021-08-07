#include <stdio.h>
int x[100010];
int min[100010],max[100010];
int abs(int k)
{
	return k>0?k:-k;
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	min[a-1] = max[a-1] = abs(x[a-1]-x[a]);
	for(int i=a-2;i>=1;i--)
	{
		long long int min1 = -max[i+1]<0?-max[i+1]:0;
		long long int max1 = -min[i+1]>0?-min[i+1]:0;
		min[i] = min1+abs(x[i]-x[i+1]);
		max[i] = max1+abs(x[i]-x[i+1]);
	}
	long long ans = max[1];
	for(int i=2;i<=a-1;i++) ans = ans>max[i]?ans:max[i];
	printf("%I64d",ans);
}

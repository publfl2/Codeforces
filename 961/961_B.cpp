#include <stdio.h>
int x[100010],y[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	
	int sum = 0;
	for(int i=1;i<=a;i++) sum += x[i]*y[i];
	
	int ans = 0;
	int s = 0;
	for(int i=1;i<=b;i++) s += x[i]*(1-y[i]);
	ans = s;
	for(int i=b+1;i<=a;i++)
	{
		s += x[i]*(1-y[i]);
		s -= x[i-b]*(1-y[i-b]);
		ans = ans>s?ans:s;
	}
	printf("%d",ans+sum);
}

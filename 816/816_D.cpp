#include <stdio.h>
#define MOD 1000000007
int x[200010],a;
long long int check[2010][2010];
long long int func(int s, int t)
{
	if(s==t) return x[s];
	if(check[s][t]) return check[s][t];
	int c = (2*(a-1)-(t-s-1)+1)*(t-s-1)/2+s , d;
	if(c%2==0) d = -1;
	else d = 1;
	//return check[s][t] = (func(s,t-1)+d*func(s+1,t)+2*MOD)%MOD;
	return check[s][t] = func(s,t-1)+d*func(s+1,t);
}
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<a;i++)
	{
		for(int j=1;j+i<=a;j++) printf("%lld ",func(j,j+i));
		printf("\n");
	}
	//printf("%I64d",func(1,a));
}

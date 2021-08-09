#include <stdio.h>
#define MOD 998244353

int x[1010];
int a;
long long int check[1010][1010];
long long int func(int s, int t)
{
	if(s>a)
	{
		if(t==0) return 1;
		else return 0;
	}
	if(check[s][t]!=-1) return check[s][t];
	
	int s1 = func(s+1,t);
	int s2 = 0;
	if(t==0&&0<x[s]&&x[s]+1<=a-s+1) s2 = func(s+1,x[s]);
	int s3 = 0;
	if(t>0) s3 = func(s+1,t-1);
	return check[s][t] = (s1+s2+s3)%MOD;
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) for(int j=0;j<=a;j++) check[i][j] = -1;
	printf("%lld",func(1,0)-1);
}

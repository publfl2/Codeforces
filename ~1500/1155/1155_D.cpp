#include <stdio.h>

int a,b;
long long int x[300010];
long long int check[300010][3];

long long int func(int k, int type)
{
	if(k>a) return 0;
	if(check[k][type]!=-1) return check[k][type];
	
	if(type==0)
	{
		long long int s1 = func(k,1);
		long long int s2 = func(k+1,0) + x[k];
		long long int s3 = x[k];
		return check[k][type] = s1>s2?s1>s3?s1:s3:s2>s3?s2:s3;
	}
	if(type==1)
	{
		long long int s1 = func(k,2);
		long long int s2 = func(k+1,1) + x[k]*b;
		long long int s3 = x[k]*b;
		return check[k][type] = s1>s2?s1>s3?s1:s3:s2>s3?s2:s3;
	}
	if(type==2)
	{
		long long int s1 = func(k+1,2) + x[k];
		long long int s2 = x[k];
		return check[k][type] = s1>s2?s1:s2;
	}
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) for(int j=0;j<=2;j++) check[i][j] = -1;
	
	long long int ans = 0;
	for(int i=1;i<=a;i++) for(int j=0;j<=2;j++) ans = ans>func(i,j)?ans:func(i,j);
	printf("%lld",ans);
}

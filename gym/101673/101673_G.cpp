#include <stdio.h>

int x[110];
int y[110];
int a;

int check[110][110];
int func(int s, int t)
{
	if(t<=0) return func(s,1);
	if(s>a) return 0;
	if(check[s][t]!=-1) return check[s][t];
	int s1 = func(s+1,t+1)+ (x[s]<y[t]?x[s]:y[t]);
	int s2 = func(s+1,t-1);
	int s3 = func(s+2,1);
	return check[s][t] = s1>s2?s1>s3?s1:s3:s2>s3?s2:s3;
}

int main()
{
	int b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	y[1] = b;
	for(int i=2;i<=a;i++) y[i] = (y[i-1]*2)/3;
	for(int i=0;i<=a;i++) for(int j=0;j<=a;j++) check[i][j] = -1;
	printf("%d",func(1,1));
}

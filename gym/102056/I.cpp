#include <stdio.h>
#include <vector>

long long int x[110],y[110],z[110];
long long int MIN;

std::vector<long long int> check[101][101];

int a;
long long int func(int s, int t, int k)
{
	if(s>a)
	{
		if(t==0&&k==0) return 0;
		else return MIN;
	}
	if(s+t-1>a) return MIN;
	if(t*(2*a-t+1)<2*k) return MIN;
	if(check[s][t][k] != -1) return check[s][t][k];
	
	long long int s1,s2,s3;
	if(t>=1&&k>=s) s1 = func(s+1,t-1,k-s) + x[s];
	else s1 = MIN;
	if(k>=t*s) s2 = func(s+1,t,k) + y[s]*(k-t*s);
	else s2 = MIN;
	s3 = func(s+1,t,k) + z[s]*t;
	
	return check[s][t][k] = s1>s2?s1>s3?s1:s3:s2>s3?s2:s3;
}

int main()
{
	MIN = -1;
	for(int i=1;i<=17;i++) MIN*=10;
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
		long long int ans = MIN;
		
		for(int i=1;i<=a;i++) for(int j=0;j<=(a+1)-i;j++) for(int k=0;k<=j*(2*a-j+1)/2;k++) check[i][j].push_back(0);
		for(int i=1;i<=a;i++) for(int j=0;j<=(a+1)-i;j++) for(int k=0;k<=j*(2*a-j+1)/2;k++) check[i][j][k] = -1;
		for(int i=0;i<=a;i++) for(int j=0;j<=a*(a+1)/2;j++) ans = ans>func(1,i,j)?ans:func(1,i,j);
		printf("%lld\n",ans);
	}
}

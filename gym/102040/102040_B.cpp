#include <stdio.h>

long long int d[20],n[20];
int check[20],p;
long long int func(long long int k)
{
	p = 1;
	while(k)
	{
		check[p++] = k%10;
		k/=10;
	}
	p--;
	
	int p2 = p;
	long long int ans = -d[p-1];
	long long int sum = 0;
	for(int i=1;i<=p;i++) for(int j=i+1;j<=p;j++) if(check[i]>check[j]) ans++;
	while(p>1)
	{
		ans += check[p]*d[p-1];
		ans += sum * n[p-1];
		sum += (9-check[p]);
		p--;
	}
	
	return ans;
}

int main()
{
	n[0] = 0, n[1] = 1;
	for(int i=2;i<20;i++)
	{
		long long int t = 1;
		for(int j=1;j<=i-2;j++) t*=10;
		n[i] -= (i-1)*t;
		t*=10;
		n[i] += i*t;
	}
	d[0] = 0, d[1] = 0;
	for(int i=2;i<20;i++) d[i] = 9*d[i-1]+36*n[i-1];
	
	
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		printf("Case %d: %lld\n",T,func(b)-func(a-1));
	}
}

#include <stdio.h>
#include <vector>

struct segTree{
	long long int value[1600010];
	void add(int ind, int val, int l=1, int r=400000, int v=1)
	{
		if(l==r) value[v] += val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) add(ind,val,l,h,2*v);
			else add(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]+value[2*v+1];
		}
	}
	long long int getSum(int L, int R, int l=1, int r=400000 ,int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 0;
		else if(r<L) return 0;
		else
		{
			int h = (l+r)/2;
			return getSum(L,R,l,h,2*v) + getSum(L,R,h+1,r,2*v+1);
		}
	}
}T,T2,T3;

long long int MAX = 1;
int x[200010],y[200010];
int main()
{
	for(int i=1;i<=17;i++) MAX*=10;
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		y[b] = i;
	}
	for(int i=1;i<=a;i++) x[i] = y[i] - (i-1);
	
	for(int i=1;i<=a;i++) printf("%d ",y[i]);
	printf("!!\n");
	
	for(int i=1;i<=a;i++)
	{
		x[i] += T.getSum(y[i],a);
		T.add(y[i],1);
	}
	
	for(int i=1;i<=a;i++) printf("%d ",x[i]);
	printf("!!\n");
	
	long long int count1 = 0;
	long long int count2 = 0;
	for(int i=1;i<=a;i++)
	{
		T2.add(x[i]+200000,x[i]);
		T3.add(x[i]+200000,1);
		int min = 1, max = (a-i+1);
		long long int ans = MAX;
		while(min<=max)
		{
			int h = (min+max)/2;
			long long int S = T2.getSum(h+1+200000,a+200000) - T2.getSum(-a+200000,h-1+200000);
			S += (-T3.getSum(h+1+200000,a+200000)+T3.getSum(-a+200000,h-1+200000))*h;
			
			ans = ans<S?ans:S;
			if(T3.getSum(h+1+200000,a+200000)<=T3.getSum(-a+200000,h-1+200000)) max = h-1;
			else min = h+1;
		}
		printf("%lld ",ans);
	}
}

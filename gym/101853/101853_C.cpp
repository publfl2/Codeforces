#include <stdio.h>

struct segTree{
	int value[1000010];
	void update(int k)
	{
		value[k] = value[2*k] + value[2*k+1];
	}
	void insert(int index, int val, int l = 1, int r = 100000, int v = 1)
	{
		if(l==r)
		{
			value[v] = val;
			return;
		}
		int h = (l+r)/2;
		if(index<=h) insert(index,val,l,h,2*v);
		else insert(index,val,h+1,r,2*v+1);
		update(v);
	}
	int getSum(int left, int right, int l = 1, int r = 100000, int v= 1)
	{
		if(left<=l&&r<=right) return value[v];
		else if(right<l) return 0;
		else if(r<left) return 0;
		else
		{
			int h = (l+r)/2;
			return getSum(left,right,l,h,2*v) + getSum(left,right,h+1,r,2*v+1);
		}
	}
}S;

int save[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			save[b] = i;
		}
		
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			ans += S.getSum(save[b]+1,100000);
			S.insert(save[b],1);
		}
		for(int i=1;i<=a;i++) S.insert(i,0);
		printf("%lld\n",ans);
	}
}

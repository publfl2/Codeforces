#include <stdio.h>
#include <queue>

struct SegTree{
	int value[1000010];
	void update(int v)
	{
		value[v] = value[2*v]+value[2*v+1];
	}
	void insert(int index, int val, int l = 1, int r = 200000, int v = 1)
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
	int getSum(int left, int right, int l = 1, int r = 200000, int v = 1)
	{
		if(left>right) return 0;
		if(left<=l&&r<=right) return value[v];
		else if(right<l) return 0;
		else if(r<left) return 0;
		else
		{
			int h = (l+r)/2;
			return getSum(left,right,l,h,2*v)+getSum(left,right,h+1,r,2*v+1);
		}
	}
}T;

struct str{
	int value;
	int index;
};
bool operator<(str a, str b)
{
	return a.value>b.value;
}
std::priority_queue<str> Q;

int main()
{
	int a,b;
	scanf("%d",&a);
	
	long long int sum = 0;
	for(int i=1;i<=a;i++)
	{
		while(!Q.empty())
		{
			if(Q.top().value<i)
			{
				T.insert(Q.top().index,0);
				Q.pop();
			}
			else break;
		}
		
		scanf("%d",&b);
		if(b>=i)
		{
			sum += T.getSum(1,i-1);
			T.insert(i,1);
			Q.push({b,i});
		}
		else sum += T.getSum(1,b);
	}
	printf("%lld",sum);
}

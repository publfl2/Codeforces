#include <stdio.h>

struct segTree{
	int value[400010];
	int lazy[400010];
	void setValue(int L, int R, int val, int l=1, int r=100000, int v=1)
	{
		if(L<=l&&r<=R)
		{
			value[v] = (r-l+1)*val;
			lazy[v] = val;
		}
		else if(R<l) return;
		else if(r<L) return;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] = (h-l+1)*lazy[v], value[2*v+1] = (r-h)*lazy[v];
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = 0;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	int getSum(int L, int R, int l=1, int r=100000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 0;
		else if(r<L) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] = (h-l+1)*lazy[v], value[2*v+1] = (r-h)*lazy[v];
				lazy[2*v] = lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = 0;
			}
			int s1 = getSum(L,R,l,h,2*v);
			int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T[40];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		for(int j=0;j<30;j++)
		{
			if(e%2==0)
			{
				if(T[j].getSum(c,d)==(d-c+1))
				{
					printf("NO");
					return 0;
				}
			}
			else T[j].setValue(c,d,1);
			e/=2;
		}
	}
	
	printf("YES\n");
	for(int i=1;i<=a;i++)
	{
		long long int s = 0;
		for(int j=29;j>=0;j--)
		{
			s*=2;
			s+=T[j].getSum(i,i);
		}
		printf("%lld ",s);
	}
}

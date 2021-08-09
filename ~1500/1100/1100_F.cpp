#include <stdio.h>

struct segTree{
	int value[2000010];
	int lazy[2000010];
	void XORValue(int L, int R, int val, int l=1, int r=500000, int v=1)
	{
		if(L<=l&&r<=R) value[v] ^= val, lazy[v] ^= val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] ^= lazy[v], value[2*v+1] ^= lazy[v];
				lazy[2*v] ^= lazy[v], lazy[2*v+1] ^= lazy[v];
				lazy[v] = 0;
			}
			XORValue(L,R,val,l,h,2*v);
			XORValue(L,R,val,h+1,r,2*v+1);
			value[v] = (value[2*v]^value[2*v+1]);
		}
	}
	int getValue(int ind, int l=1, int r=500000, int v=1)
	{
		if(l==r) return value[v];
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] ^= lazy[v], value[2*v+1] ^= lazy[v];
				lazy[2*v] ^= lazy[v], lazy[2*v+1] ^= lazy[v];
				lazy[v] = 0;
			}
			if(ind<=h) return getValue(ind,l,h,2*v);
			else return getValue(ind,h+1,r,2*v+1);
		}
	}
}T;

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) x[i] ^= x[i-1];
	for(int i=1;i<=a;i++) T.XORValue(i,i,x[i]);
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		query[i] = {c,d,i};
	}
	std::sort(query+1,query+b+1,cmp);
	
	int start = 1;
	for(int i=1;i<=b;i++)
	{
		while(start<query[i].first)
		{
			int t = T.getValue(start);
			T.XORValue(start,a,t);
			start++;
		}
		
	}
}
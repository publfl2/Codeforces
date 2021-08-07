#include <stdio.h>
#define MOD 1000000

struct segTree{
	long double value[4000010];
	void setValue(int L, int R, long double val, int l=1, int r=1000000, int v=1)
	{
		if(l>r) return;
		if(L<=l&&r<=R) value[v] = val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(value[v]!=-1)
			{
				value[2*v] = value[v], value[2*v+1] = value[v];
				value[v] = -1;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
		}
	}
	long double getValue(int ind, int l=1, int r=1000000, int v=1)
	{
		if(value[v]!=-1) return value[v];
		else
		{
			int h = (l+r)/2;
			if(ind<=h) return getValue(ind,l,h,2*v);
			else return getValue(ind,h+1,r,2*v+1);
		}
	}
}T;

struct segTree2{
	long double value[4000010];
	void setValue(int ind, long double val, int l=1, int r=1000000, int v=1)
	{
		if(l==r) value[v] = value[v]>val?value[v]:val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	long double getMax(int L, int R, int l=1, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			long double s1 = getMax(L,R,l,h,2*v);
			long double s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T2;

int main()
{
	long long int a;
	long long int b;
	scanf("%d%lld",&a,&b);
	
	long long int last = 0;
	for(int i=1;i<=a;i++)
	{
		long long int c,d,e;
		scanf("%lld%lld%lld",&c,&d,&e);
		d = (d+last)%MOD + 1;
		e = (e+last)%MOD + 1;
		if(c==1)
		{
			long double t = (long double)b/e;
			int min = 1, max = d;
			int p = d+1;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(T.getValue(h)>=t) min = h+1;
				else
				{
					max = h-1;
					p = h;
				}
			}
			
			T.setValue(p,d,t);
			T2.setValue(d,d*t);
		}
		else
		{
			last = i;
			int min = 1, max = MOD;
			int p = 0;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(T.getValue(h)>=d)
				{
					p = h;
					min = h+1;
				}
				else max = h-1;
			}
			
			long long int s1 = (long long int)p*d;
			long double s2 = T2.getMax(p+1,MOD);
			if(s1>=e || s2>=e) printf("YES\n");
			else printf("NO\n");
		}
	}
}
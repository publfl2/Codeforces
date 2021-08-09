#include <stdio.h>

struct SegTree{
	int type;
	int value[1000010];
	void update(int k)
	{
		if(type==1) // left side
		{
			if(value[2*k]==0) value[k] = value[2*k+1];
			value[k] = value[2*k];
		}
		else if(type==2)
		{
			if(value[2*k+1]==0) value[k] = value[2*k];
			value[k] = value[2*k+1];
		}
	}
	void insert(int index, int val, int l=1, int r=100000,int v=1)
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
	
	int getValue(int left, int right, int l=1, int r=100000, int v=1)
	{
		if(left<=l&&r<=right) return value[v];
		else if(right<l) return 0;
		else if(r<left) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getValue(left,right,l,h,2*v);
			int s2 = getValue(left,right,h+1,r,2*v+1);
			if(type==1)
			{
				if(s1==0) return s2;
				else return s1;
			}
			else if(type==2)
			{
				if(s2==0) return s1;
				else return s2;
			}
		}
	}
};

SegTree S[21],T[21];

int main()
{
	for(int i=0;i<=20;i++)
	{
		S[i].type = 1;
		T[i].type = 2;
	}
	
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	
}

#include <stdio.h>
#define MAX 12345678

struct segTree{
	int value[12010];
	int max[12010];
	int lazy[12010];
	void addValue(int L, int R, int val, int l=1, int r=3000, int v=1)
	{
		if(L<=l&&r<=R) value[v] += (r-l+1)*val, max[v] += val, lazy[v] += val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += (h-l+1)*lazy[v], value[2*v+1] += (r-h)*lazy[v];
				max[2*v] += lazy[v], max[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
			max[v] = max[2*v]<max[2*v+1]?max[2*v]:max[2*v+1];
		}
	}
	
	int getValue(int L, int R, int l=1, int r=3000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += (h-l+1)*lazy[v], value[2*v+1] += (r-h)*lazy[v];
				max[2*v] += lazy[v], max[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			
			int s1 = getValue(L,R,l,h,2*v);
			int s2 = getValue(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
	
	int getMin(int L, int R, int l=1, int r=3000, int v=1)
	{
		if(L<=l&&r<=R) return max[v];
		else if(r<L) return MAX;
		else if(R<l) return MAX;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += (h-l+1)*lazy[v], value[2*v+1] += (r-h)*lazy[v];
				max[2*v] += lazy[v], max[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			
			int s1 = getMin(L,R,l,h,2*v);
			int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
	
	void clear(int l=1, int r=3000, int v=1)
	{
		value[v] = 0;
		lazy[v] = 0;
		max[v] = 0;
		if(l==r) return;
		int h = (l+r)/2;
		clear(l,h,2*v);
		clear(h+1,r,2*v+1);
	}
	
}T1,T2;

int DP[3010][3010];
int x[3010],y[3010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) DP[i][j] = MAX;
		for(int j=1;j<=a;j++) DP[a][j] = 0;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) y[i] = x[i]+i;
		for(int i=a-1;i>=1;i--)
		{
			int L = i+1;
			int R = y[i];
			T1.clear();
			T2.clear();
			
			for(int j=R;j>=L;j--)
			{
				T2.addValue(j,j,T1.getValue(y[j],a)+DP[j][y[i]]);
				T2.addValue(j+1,y[j],1);
				T1.addValue(y[j],y[j],1);
				DP[i][j] = T2.getMin(j,R);
			}
			for(int j=L-1;j>=1;j--) DP[i][j] = DP[i][j+1];
		}
		
		/*for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++) printf("%d ",DP[i][j]);
			printf("\n");
		}*/
		printf("%d\n",DP[1][1]);
	}
}

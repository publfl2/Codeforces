#include <stdio.h>

struct segTree{
	int value[1200010];
	int lazy[1200010];
	void setValue(int L, int R, int val, int l=0, int r=300000, int v=1)
	{
		if(L<=l&&r<=R)
		{
			value[v] = val;
			lazy[v] = val;
		}
		else if(R<l) return;
		else if(r<L) return;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]>-123456)
			{
				value[2*v] = lazy[2*v] = lazy[v];
				value[2*v+1] = lazy[2*v+1] = lazy[v];
				lazy[v] = -123456;
			}
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	
	int getMax(int L, int R, int l=0, int r=300000 ,int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return -123456;
		else if(r<L) return -123456;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]>-123456)
			{
				value[2*v] = lazy[2*v] = lazy[v];
				value[2*v+1] = lazy[2*v+1] = lazy[v];
				lazy[v] = -123456;
			}
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T;

int x[100010],s[100010],u[100010];

int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		if(a==1)
		{
			if(x[1]==b) printf("yes\n");
			else printf("no\n");
			continue;
		}
		
		s[0] = 0, u[0] = 0;
		for(int i=1;i<=a;i++) s[i] = s[i-1] + (x[i]<b?1:0);
		for(int i=1;i<=a;i++) s[i] = 2*s[i]-i+a;
		for(int i=1;i<=a;i++) u[i] = u[i-1] + (x[i]>b?1:0);
		for(int i=1;i<=a;i++) u[i] = 2*u[i] - i+a;
		s[0] = a, u[0] = a;
		
		//for(int i=1;i<=a;i++) printf("%d %d\n",s[i],u[i]);
		
		T.setValue(0,3*a,-1);
		
		for(int i=1;i<=a;i++)
		{
			int s1 = T.getMax(s[i]+1,3*a);
			if(u[i]<=s1)
			{
				printf("yes\n");
				goto u;
			}
			int s2 = T.getMax(s[i-1],s[i-1]);
			if(u[i-1]>s2) T.setValue(s[i-1],s[i-1],u[i-1]);
		}
		
		printf("no\n");
		u:;
	}
}

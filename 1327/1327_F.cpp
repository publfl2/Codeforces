#include <stdio.h>
#define MOD 998244353

struct segTree{
	int value[2000010];
	int lazy[2000010];
	void set(int L, int R, int val, int l=1, int r=500000, int v=1)
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
			if(lazy[v]!=-1)
			{
				value[2*v] = (h-l+1) * lazy[v], lazy[2*v] = lazy[v];
				value[2*v+1] = (r-h) * lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			set(L,R,val,l,h,2*v);
			set(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	int getSum(int L, int R, int l=1, int r=500000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 0;
		else if(r<L) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=-1)
			{
				value[2*v] = (h-l+1) * lazy[v], lazy[2*v] = lazy[v];
				value[2*v+1] = (r-h) * lazy[v], lazy[2*v+1] = lazy[v];
				lazy[v] = -1;
			}
			int s1 = getSum(L,R,l,h,2*v);
			int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T;

long long int power(long long int s, long long int t)
{
	long long int ans = 1;
	long long int k = s;
	while(t)
	{
		if(t%2==1) ans *= k, ans %= MOD;
		k*=k, k%=MOD;
		t/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

struct str2{
	int left;
	int right;
	int value;
}x[500010];
int y[500010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=c;i++) scanf("%d%d%d",&x[i].left,&x[i].right,&x[i].value);
	
	long long int ans = 1;
	for(int i=0;i<b;i++)
	{
		T.set(1,a,1);
		for(int j=1;j<=c;j++) y[j] = ((x[j].value&(1<<i))==0)?0:1;
		for(int j=1;j<=c;j++) if(y[j]==1) T.set(x[j].left,x[j].right,0);
		
		long long int S = 1;
		for(int j=1;j<=c;j++)
		{
			if(y[j]==0)
			{
				int s = T.getSum(x[j].left,x[j].right);
				printf("%d: %d %d %d\n",i,x[j].left,x[j].right,s);
				S -= inv(power(2,s)), S+=MOD, S%=MOD;
			}
		}
		S *= power(2,T.getSum(1,a)), S %= MOD;
		printf("%lld??\n",S);
		S++;
		ans *= S, ans %= MOD;
	}
	printf("%lld",ans);
}

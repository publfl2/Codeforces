#include <stdio.h>
#include <vector>

long long int MAX = 2;
struct segTree{
	std::pair<double,int> value[800010];
	double lazy[800010];
	void add(int L, int R, double val, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) value[v].first += val, lazy[v] += val;
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v].first += lazy[v], value[2*v+1].first += lazy[v];
				lazy[2*v] += lazy[v] , lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			add(L,R,val,l,h,2*v);
			add(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	std::pair<double,int> getMin(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return std::make_pair(-12345,-1);
		else if(r<L) return std::make_pair(-12345,-1);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v].first += lazy[v], value[2*v+1].first += lazy[v];
				lazy[2*v] += lazy[v] , lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			std::pair<double,int> P1 = getMin(L,R,l,h,2*v);
			std::pair<double,int> P2 = getMin(L,R,h+1,r,2*v+1);
			if(P1.first==-12345) return P2;
			else if(P2.first==-12345) return P1;
			else return P1<P2?P1:P2;
		}
	}
	void clear(int l=1, int r=200000, int v=1)
	{
		value[v] = std::make_pair(0,l);
		lazy[v] = 0;
		
		if(l==r) return;
		int h = (l+r)/2;
		clear(l,h,2*v);
		clear(h+1,r,2*v+1);
	}
}T;

long long int x[200010],y[200010];
int main()
{
	for(int i=1;i<=12;i++) MAX*=10;
	MAX++;
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) scanf("%lld",&y[i]);
	
	long long int min = 0, max = MAX;
	long long int ans = max;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		T.clear();
		for(int i=1;i<=a;i++) T.add(i,i,(double)x[i]/y[i]);
		for(int i=1;i<b;i++)
		{
			std::pair<double,int> P = T.getMin(1,a);
			T.add(P.second,P.second,(double)h/y[P.second]);
			T.add(1,a,-1);
			P = T.getMin(1,a);
			if(P.first<0)
			{
				min = h+1;
				goto u;
			}
		}
		ans = h;
		max = h-1;
		u:;
	}
	if(ans>=MAX) printf("-1");
	else printf("%lld",ans);
}

#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 12345678

struct segTree{
	std::pair<int,int> value[400010];
	void setValue(int ind ,int val, int l=1, int r=100000, int v=1)
	{
		if(l==r) value[v] = std::make_pair(val,ind);
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			
			if(value[2*v].first<value[2*v+1].first) value[v] = value[2*v];
			else value[v] = value[2*v+1];
		}
	}
	std::pair<int,int> getMin(int L, int R, int l=1, int r=100000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return std::make_pair(MAX,MAX);
		else if(R<l) return std::make_pair(MAX,MAX);
		else
		{
			int h = (l+r)/2;
			std::pair<int,int> s1 = getMin(L,R,l,h,2*v);
			std::pair<int,int> s2 = getMin(L,R,h+1,r,2*v+1);
			if(s1.first<s2.first) return s1;
			else return s2;
		}
	}
}T;

int x[100010];
std::pair<int,int> y[100010];
long long int ans[100010];
int main()
{
	int a;
	long long int b;
	scanf("%d%lld",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) y[i] = std::make_pair(x[i],i);
	std::sort(y+1,y+a+1);
	for(int i=1;i<=a;i++) T.setValue(i,y[i].second);
	
	for(int i=1;i<=a;i++) ans[i] = -1;
	
	int R = 1;
	long long int S = 0;
	for(int i=1;i<=a;i++)
	{
		if(ans[y[i].second]!=-1) continue;
		while(1)
		{
			if(i==R)
			{
				S = y[i].first;
				R = i+1;
			}
			
			std::pair<int,int> P = T.getMin(i,R-1);
			if(P.first==MAX) break;
			ans[P.first] = S;
			S += b;
			T.setValue(P.second,MAX);
			
			while(R<=a && y[R].first<=S) R++;
		}
	}
	
	for(int i=1;i<=a;i++) printf("%lld ",ans[i]+b);
}
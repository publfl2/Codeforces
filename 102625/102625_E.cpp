#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#define MAX 1234567890

struct segTree{
	int value[800010];
	void setValue(int L, int R, int val, int l=1, int r=200000, int v=1)
	{
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
	int getValue(int ind ,int l=1, int r=200000, int v=1)
	{
		if(l==r) return value[v];
		else
		{
			int h = (l+r)/2;
			if(value[v]!=-1)
			{
				value[2*v] = value[v], value[2*v+1] = value[v];
				value[v] = -1;
			}
			
			if(ind<=h) return getValue(ind,l,h,2*v);
			else return getValue(ind,h+1,r,2*v+1);
		}
	}
}T;

struct str{
	int first;
	int second;
	int value;
}x[200010];
bool cmp(str a, str b)
{
	return a.value<b.value;
}

int y[200010];
std::map<int,int> M;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		x[i] = {c,d,e};
	}
	std::sort(x+1,x+a+1,cmp);
	
	M[-MAX] = 0;
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	for(int i=1;i<=b;i++) M[y[i]] = i;
	M[MAX] = b+1;
	
	for(int i=a;i>=1;i--)
	{
		std::map<int,int> ::iterator it1, it2;
		it1 = M.lower_bound(x[i].first-x[i].value);
		it2 = M.lower_bound(x[i].second-x[i].value);
		it2--;
		
		int L = (it1->second);
		int R = (it2->second);
		
		T.setValue(L,R,i);
	}
	
	for(int i=1;i<=b;i++)
	{
		int t = T.getValue(i);
		if(t==0) printf("-1\n");
		else printf("%d\n",x[t].value);
	}
}
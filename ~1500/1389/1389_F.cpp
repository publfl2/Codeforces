#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

struct segTree1{
	int value[1200010];
	void add(int ind, int val, int l=1, int r=400000, int v=1)
	{
		if(l==r) value[v] += val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) add(ind,val,l,h,2*v);
			else add(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]+value[2*v+1];
		}
	}
	int getSum(int L, int R, int l=1, int r=400000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 0;
		else if(r<L) return 0;
		else
		{
			int h = (l+r)/2;
			return getSum(L,R,l,h,2*v) + getSum(L,R,h+1,r,2*v+1);
		}
	}
}T[3];

struct segTree2{
	int value[1200010];
	void setValue(int ind, int val, int l=1, int r=400000, int v=1)
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
	int getMax(int L, int R, int l=1, int r=400000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 0;
		else if(r<L) return 0;
		else
		{
			int h = (l+r)/2;
			int s1 = getMax(L,R,l,h,2*v);
			int s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>s2?s1:s2;
		}
	}
}T2[3],T3;

struct str{
	int first;
	int second;
	int type;
};
bool cmp(str a, str b)
{
	if(a.first==b.first) return a.second>b.second;
	return a.first<b.first;
}

std::vector<str> V;
std::vector<int> index;
std::map<int,int> hash;

int count[200010];
int DP[200010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		V.push_back({b,c,d});
		index.push_back(b);
		index.push_back(c);
	}
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i;
	for(int i=0;i<V.size();i++)
	{
		V[i].first = hash[V[i].first];
		V[i].second = hash[V[i].second];
	}
	
	std::sort(V.begin(),V.end(),cmp);
	
	for(int i=V.size()-1;i>=0;i--)
	{
		count[i] = T[V[i].type].getSum(V[i].first,V[i].second);
		T[V[i].type].add(V[i].second,1);
	}
	
	for(int i=V.size()-1;i>=0;i--)
	{
		int k1 = T2[V[i].type].getMax(V[i].second+1,2*a) + count[i]+1;
		int k2 = T3.getMax(V[i].second+1,2*a) + count[i]+1;
		DP[i] = k1>k2?k1:k2;
		
		T2[V[i].type].setValue(V[i].second,DP[i]);
		T3.setValue(V[i].first,DP[i]);
	}
	
	int ans = 0;
	for(int i=0;i<V.size();i++) ans = ans>DP[i]?ans:DP[i];
	printf("%d",ans);
}

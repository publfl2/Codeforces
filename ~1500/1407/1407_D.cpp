#include <stdio.h>
#include <vector>

#define MAX 1234567890
struct segTree{
	int min[1200010];
	int minIndex[1200010];
	int max[1200010];
	int maxIndex[1200010];
	
	void setValue(int ind, int val, int l=1, int r=300000, int v=1)
	{
		if(l==r)
		{
			min[v] = max[v] = val;
			minIndex[v] = maxIndex[v] = ind;
		}
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			if(min[2*v]<=min[2*v+1])
			{
				min[v] = min[2*v];
				minIndex[v] = minIndex[2*v];
			}
			else
			{
				min[v] = min[2*v+1];
				minIndex[v] = minIndex[2*v+1];
			}
			
			if(max[2*v]>=max[2*v+1])
			{
				max[v] = max[2*v];
				maxIndex[v] = maxIndex[2*v];
			}
			else
			{
				max[v] = max[2*v+1];
				maxIndex[v] = maxIndex[2*v+1];
			}
		}
	}
	std::pair<int,int> getMin(int L, int R, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) return std::make_pair(min[v],minIndex[v]);
		else if(r<L) return std::make_pair(MAX,0);
		else if(R<l) return std::make_pair(MAX,0);
		else
		{
			int h = (l+r)/2;
			std::pair<int,int> s1 = getMin(L,R,l,h,2*v);
			std::pair<int,int> s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<=s2?s1:s2;
		}
	}
	std::pair<int,int> getMax(int L, int R, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) return std::make_pair(max[v],300000-maxIndex[v]);
		else if(r<L) return std::make_pair(0,300000);
		else if(R<l) return std::make_pair(0,300000);
		else
		{
			int h = (l+r)/2;
			std::pair<int,int> s1 = getMax(L,R,l,h,2*v);
			std::pair<int,int> s2 = getMax(L,R,h+1,r,2*v+1);
			return s1>=s2?s1:s2;
		}
	}
}T;

int a;
int x[300010];
int check[300010];
int func(int k)
{
	if(k>=a) return 0;
	if(check[k]) return check[k];
	
	if(x[k+1]==x[k]) return func(k+1)+1;
	else if(x[k+1]<x[k])
	{
		int min = k+1, max = a;
		int limit = k;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(T.getMax(k+1,h).first>=x[k]) max = h-1;
			else
			{
				limit = h;
				min = h+1;
			}
		}
		
		int s1 = func(k+1)+1,s2;
		if(limit==a) s2 = func(300000-T.getMax(k+1,limit).second)+1;
		else s2 = func(limit+1)+1;
		return check[k] = s1<s2?s1:s2;
	}
	else
	{
		int min = k+1, max = a;
		int limit = k;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(T.getMin(k+1,h).first<=x[k]) max = h-1;
			else
			{
				limit = h;
				min = h+1;
			}
		}
		
		int s1 = func(k+1)+1, s2;
		if(limit==a) s2 = func(T.getMin(k+1,limit).second)+1;
		else s2 = func(limit+1)+1;
		return check[k] = s1<s2?s1:s2;
	}
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) T.setValue(i,x[i]);
	
	printf("%d",func(1));
}

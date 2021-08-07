#include <stdio.h>
#include <vector>
#include <algorithm>

bool cmp(std::pair<int,int> A, std::pair<int,int> B)
{
	int a1 = A.first/400;
	int b1 = B.first/400;
	if(a1==b1) return A.second<B.second;
	else return a1<b1;
}

struct segTree{
	int value[400010];
	void setValue(int ind, int val, int l=1, int r=100001, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]+value[2*v+1];
		}
	}
	int mex(int l=1, int r=100001, int v=1)
	{
		if(value[v]==(r-l+1)) return -1;
		if(l==r) return l;
		
		int h = (l+r)/2;
		int s = mex(l,h,2*v);
		if(s==-1) return mex(h+1,r,2*v+1);
		else return s;
	}
}T;
int count[100010],x[100010];
std::vector<int> V[100010],ans;
std::vector< std::pair<int,int> > interval;

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a+1;i++) V[i].push_back(0);
	for(int i=1;i<=a;i++) V[x[i]].push_back(i);
	for(int i=1;i<=a+1;i++) V[i].push_back(a+1);
	for(int i=1;i<=a+1;i++)
	{
		for(int j=0;j+1<V[i].size();j++)
		{
			if(V[i][j]+1<=V[i][j+1]-1) interval.push_back(std::make_pair(V[i][j]+1,V[i][j+1]-1));
		}
	}
	
	std::sort(interval.begin(),interval.end(),cmp);
	int L = 1, R = 1;
	count[x[1]]++;
	T.setValue(x[1],1);
	for(int i=0;i<interval.size();i++)
	{
		while(R<interval[i].second)
		{
			R++;
			count[x[R]]++;
			if(count[x[R]]==1) T.setValue(x[R],1);
		}
		while(R>interval[i].second)
		{
			count[x[R]]--;
			if(count[x[R]]==0) T.setValue(x[R],0);
			R--;
		}
		while(L>interval[i].first)
		{
			L--;
			count[x[L]]++;
			if(count[x[L]]==1) T.setValue(x[L],1);
		}
		while(L<interval[i].first)
		{
			count[x[L]]--;
			if(count[x[L]]==0) T.setValue(x[L],0);
			L++;
		}
		ans.push_back(T.mex());
	}
	std::sort(ans.begin(),ans.end());
	ans.erase(std::unique(ans.begin(),ans.end()),ans.end());
	int p = 1;
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i]!=p)
		{
			printf("%d",p);
			return 0;
		}
		else p++;
	}
	printf("%d",p);
}

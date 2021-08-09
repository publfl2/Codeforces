#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

struct segTree{
	int lazy[2400010];
	void setValue(int L, int R, int val, int l=1, int r=600000, int v=1)
	{
		if(L>R) return;
		if(L<=l&&r<=R) lazy[v] = lazy[v]>val?lazy[v]:val;
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			int h = (l+r)/2;
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
		}
	}
	int getValue(int ind, int l=1, int r=600000, int v=1)
	{
		if(l==r) return lazy[v];
		else
		{
			int h = (l+r)/2;
			if(ind<=h)
			{
				int k = getValue(ind,l,h,2*v);
				return k>lazy[v]?k:lazy[v];
			}
			else
			{
				int k = getValue(ind,h+1,r,2*v+1);
				return k>lazy[v]?k:lazy[v];
			}
		}
	}
}T1,T2;

std::vector<int> index;
std::map<int,int> hash;
char x[200010][3];
int check[600010];
std::pair<int,int> P[200010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b); // 1left 2up
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		scanf("%s",x[i]+1);
		P[i]=std::make_pair(c,d);
	}
	for(int i=1;i<=b;i++)
	{
		index.push_back(P[i].first-1);
		index.push_back(P[i].first);
		index.push_back(P[i].first+1);
	}
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
	
	for(int i=1;i<=b;i++)
	{
		int c,d;
		c = P[i].first;
		d = P[i].second;
		if(check[hash[c]]) printf("0\n");
		else if(x[i][1]=='L')
		{
			check[hash[c]] = 1;
			int k = T1.getValue(hash[c]);
			printf("%d\n",c-k);
			T2.setValue(hash[k+1],hash[c-1],d);
		}
		else
		{
			check[hash[c]] = 1;
			int k = T2.getValue(hash[c]);
			printf("%d\n",d-k);
			T1.setValue(hash[c+1],hash[a-k],c);
		}
	}
}

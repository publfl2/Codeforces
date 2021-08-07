#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 1234567890

struct segTree{
	std::pair<int,int> value[800010];
	segTree()
	{
		for(int i=1;i<=800000;i++) value[i] = std::make_pair(MAX,MAX);
	}
	void insert(int ind, int val, int l=1, int r=200000, int v=1)
	{
		if(l==r)
		{
			value[v].first = val;
			value[v].second = MAX;
		}
		else
		{
			int h = (l+r)/2;
			if(ind<=h) insert(ind,val,l,h,2*v);
			else insert(ind,val,h+1,r,2*v+1);
			std::vector<int> V;
			V.push_back(value[2*v].first);
			V.push_back(value[2*v].second);
			V.push_back(value[2*v+1].first);
			V.push_back(value[2*v+1].second);
			std::sort(V.begin(),V.end());
			value[v] = std::make_pair(V[0],V[1]);
		}
	}
	std::pair<int,int> getMin(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return std::make_pair(MAX,MAX);
		else if(R<l) return std::make_pair(MAX,MAX);
		else
		{
			int h = (l+r)/2;
			std::pair<int,int> P1 = getMin(L,R,l,h,2*v);
			std::pair<int,int> P2 = getMin(L,R,h+1,r,2*v+1);
			std::vector<int> V;
			V.push_back(P1.first);
			V.push_back(P1.second);
			V.push_back(P2.first);
			V.push_back(P2.second);
			std::sort(V.begin(),V.end());
			return std::make_pair(V[0],V[1]);
		}
	}
}T[11];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		int d = c;
		int C = 1;
		while(d)
		{
			if(d%10!=0) T[C].insert(i,c);
			d/=10;
			C++;
		}
	}
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		if(c==1)
		{
			int f = e;
			int C = 1;
			while(f)
			{
				if(f%10!=0) T[C].insert(d,e);
				f/=10;
				C++;
			}
		}
		else
		{
			std::pair<int,int> ans = std::make_pair(0,0);
			for(int j=1;j<=10;j++)
			{
				std::pair<int,int> P = T[j].getMin(d,e);
				printf("%d %d %d: %d %d!!\n",d,e,j,P.first,P.second);
				if(P.first!=MAX&&P.second!=MAX)
				{
					if(ans==std::make_pair(0,0)) ans = P;
					else if(ans.first+ans.second>P.first+P.second) ans = P;
				}
			}
			if(ans==std::make_pair(0,0)) printf("-1\n");
			else printf("%d\n",ans.first+ans.second);
		}
	}
}

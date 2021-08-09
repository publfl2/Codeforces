#include <stdio.h>
#include <vector>
#define MAX 123456789

struct segTree{
	int value[4000010];
	void insert(int ind, int val, int l=1, int r=1000000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) insert(ind,val,l,h,2*v);
			else insert(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getMin(int L, int R, int l=1, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return MAX;
		else if(r<L) return MAX;
		else
		{
			int h = (l+r)/2;
			int s1 = getMin(L,R,l,h,2*v);
			int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T;

int next0[1000010],next1[1000010];
char x[1000010];
std::vector<int> V[1000010];

int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	next0[a+1] = a+1;
	next1[a+1] = a+1;
	for(int i=a;i>=1;i--)
	{
		if(x[i]=='0') next0[i] = i;
		else next0[i] = next0[i+1];
	}
	for(int i=a;i>=1;i--)
	{
		if(x[i]=='1') next1[i] = i;
		else next1[i] = next1[i+1];
	}
	
	for(int i=1;i<=a;i++)
	{
		T.insert(i,i);
		int k = next0[i]>next1[i]?next0[i]:next1[i];
		V[k-i].push_back(i);
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<V[i-1].size();j++) T.insert(V[i-1][j],MAX);
		
		int ans = 0;
		int t = 1;
		while(1)
		{
			t = T.getMin(t,a);
			if(t==MAX) break;
			ans++;
			t+=i;
		}
		printf("%d ",ans);
	}
}

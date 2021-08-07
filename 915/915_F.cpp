#include <stdio.h>
#include <algorithm>
#include <vector>

struct segTree1{
	int value[4000010];
	int lazy[4000010];
	void addValue(int L, int R, int val, int l=1, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R) value[v] += val, lazy[v] += val;
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int getValue(int ind, int l=1, int r=1000000, int v=1)
	{
		if(l==r) return value[v];
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += lazy[v], value[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v], lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
			if(ind<=h) return getValue(ind,l,h,2*v);
			else return getValue(ind,h+1,r,2*v+1);
		}
	}
	void clear(int l=1, int r=1000000, int v=1)
	{
		value[v] = 0;
		lazy[v] = 0;
		if(l==r) return;
		
		int h = (l+r)/2;
		clear(l,h,2*v);
		clear(h+1,r,2*v+1);
	}
}T1;

struct segTree2{
	int value[4000010];
	void setValue(int ind, int l=1, int r=1000000, int v=1)
	{
		if(l==r) value[v] = 1;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,l,h,2*v);
			else setValue(ind,h+1,r,2*v+1);
		}
	}
	int getArgmax(int L, int R, int l=1, int r=1000000, int v=1)
	{
		if(L<=l&&r<=R)
		{
			if(l==r)
			{
				if(value[v]==1) return l;
				else return -1;
			}
			else
			{
				int h = (l+r)/2;
				int s1 = getArgmax(L,R,h+1,r,2*v+1);
				if(s1!=-1) return s1;
				else return getArgmax(L,R,l,h,2*v);
			}
		}
		else if(r<L) return -1;
		else if(R<l) return -1;
		else
		{
			int h = (l+r)/2;
			int s1 = getArgmax(L,R,h+1,r,2*v+1);
			if(s1!=-1) return s1;
			else return getArgmax(L,R,l,h,2*v);
		}
	}
	
	void clear(int l=1, int r=1000000, int v=1)
	{
		value[v] = 0;
		if(l==r) return;
		
		int h = (l+r)/2;
		clear(l,h,2*v);
		clear(h+1,r,2*v+1);
	}
}T2;

int size[1000010];
std::vector<int> V[1000010];
int getSize(int k, int p)
{
	if(size[k]) return size[k];
	int ans = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		ans += getSize(V[k][i],k);
	}
	return size[k] = ans;
}

int height[1000010],prev[1000010],up[1000010],treePos[1000010];
void init(int k, int p, int h, int target, int &C)
{
	height[k] = h;
	prev[k] = p;
	up[k] = target;
	treePos[k] = C++;
	
	int maxSize = 0, ind = -1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		if(maxSize < getSize(V[k][i],k))
		{
			maxSize = getSize(V[k][i],k);
			ind = V[k][i];
		}
	}
	
	if(ind!=-1) init(ind,k,h+1,target,C);
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		if(V[k][i]==ind) continue;
		init(V[k][i],k,h+1,V[k][i],C);
	}
}

int x[1000010];
std::pair<int,int> y[1000010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	int C = 1;
	getSize(1,0);
	init(1,0,1,1,C);
	
	for(int i=1;i<=a;i++) y[i] = std::make_pair(x[i],i);
	std::sort(y+1,y+a+1);
	
	long long int ans1 = 0, ans2 = 0;
	
	T1.clear();
	for(int i=1;i<=a;i++) T1.addValue(treePos[i],treePos[i],size[i]);
	T2.clear();
	T2.setValue(1);
	for(int i=1;i<=a;i++)
	{
		int ind = y[i].second;
		long long int S1 = 0, S2 = 0, S = 0;
		for(int j=0;j<V[ind].size();j++)
		{
			if(V[ind][j]==prev[ind]) continue;
			long long int t = T1.getValue(treePos[V[ind][j]]);
			S1 += t;
			S2 += (t*t);
		}
		
		while(1)
		{
			int t = T2.getArgmax(treePos[up[ind]],treePos[ind]);
			//printf("%d %d %d %d %d??\n",ind,up[ind],treePos[ind],treePos[up[ind]],t);
			if(t==-1) ind = prev[up[ind]];
			else
			{
				long long int t2 = T1.getValue(t);
				t2 -= T1.getValue(treePos[y[i].second]);
				S1 += t2;
				S2 += (t2*t2);
				break;
			}
		}
		
		S = (S1+1);
		S += (S1*S1-S2)/2;
		ans1 += y[i].first * S;
		
		ind = y[i].second;
		for(int j=0;j<V[ind].size();j++)
		{
			if(V[ind][j]==prev[ind]) continue;
			T2.setValue(treePos[V[ind][j]]);
		}
		
		int val = T1.getValue(treePos[ind]);
		while(1)
		{
			int t = T2.getArgmax(treePos[up[ind]],treePos[ind]);
			if(t==-1)
			{
				T1.addValue(treePos[up[ind]],treePos[ind],-val);
				ind = prev[up[ind]];
			}
			else
			{
				T1.addValue(t,treePos[ind],-val);
				break;
			}
		}
	}
	
	T1.clear();
	for(int i=1;i<=a;i++) T1.addValue(treePos[i],treePos[i],size[i]);
	T2.clear();
	T2.setValue(1);
	for(int i=a;i>=1;i--)
	{
		int ind = y[i].second;
		long long int S1 = 0, S2 = 0, S = 0;
		for(int j=0;j<V[ind].size();j++)
		{
			if(V[ind][j]==prev[ind]) continue;
			long long int t = T1.getValue(treePos[V[ind][j]]);
			S1 += t;
			S2 += (t*t);
		}
		
		while(1)
		{
			int t = T2.getArgmax(treePos[up[ind]],treePos[ind]);
			if(t==-1) ind = prev[up[ind]];
			else
			{
				long long int t2 = T1.getValue(t);
				t2 -= T1.getValue(treePos[y[i].second]);
				S1 += t2;
				S2 += (t2*t2);
				break;
			}
		}
		S = (S1+1);
		S += (S1*S1-S2)/2;
		ans2 += y[i].first * S;
		
		ind = y[i].second;
		for(int j=0;j<V[ind].size();j++)
		{
			if(V[ind][j]==prev[ind]) continue;
			T2.setValue(treePos[V[ind][j]]);
		}
		
		int val = T1.getValue(treePos[ind]);
		while(1)
		{
			int t = T2.getArgmax(treePos[up[ind]],treePos[ind]);
			if(t==-1)
			{
				T1.addValue(treePos[up[ind]],treePos[ind],-val);
				ind = prev[up[ind]];
			}
			else
			{
				T1.addValue(t,treePos[ind],-val);
				break;
			}
		}
	}
	
	printf("%lld",ans2-ans1);
}
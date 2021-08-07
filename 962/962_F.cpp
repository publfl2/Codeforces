#include <stdio.h>
#include <vector>

struct segTree{
	int value[400010];
	int lazy[400010];
	void setValue(int L, int R, int val, int l=1, int r=100000, int v=1)
	{
		if(L<=l&&r<=R)
		{
			if(value[v]!=0) value[v] = -1;
			else value[v] = val;
		}
		else if(r<L);
		else if(R<l);
		else
		{
			int h = (l+r)/2;
			setValue(L,R,val,l,h,2*v);
			setValue(L,R,val,h+1,r,2*v+1);
		}
	}
	int getValue(int ind, int l=1, int r=100000, int v=1)
	{
		if(l==r) return value[v];
		else
		{
			int h = (l+r)/2;
			int s;
			if(ind<=h) s = getValue(ind,l,h,2*v);
			else s = getValue(ind,h+1,r,2*v+1);
			if(s==-1||value[v]==-1) return -1;
			else
			{
				if(s==0) return value[v];
				if(value[v]==0) return s;
				return -1;
			}
		}
	}
}T;

struct HeavyLight{
	segTree T;
	std::vector<int> V[100010];
	int treePos[100010];
	int heavy[100010];
	int prev[100010];
	int up[100010];
	int size[100010];
	int height[100010];
	int C = 1;
	
	int getSize(int v, int p)
	{
		if(size[v]) return size[v];
		int ans = 1;
		for(int i=0;i<V[v].size();i++)
		{
			if(V[v][i]==p) continue;
			ans += getSize(V[v][i],v);
		}
		return size[v] = ans;
	}
	
	void init(int v, int p, int u, int h)
	{
		prev[v] = p;
		up[v] = u;
		treePos[v] = C++;
		height[v] = h;
		
		for(int i=0;i<V[v].size();i++)
		{
			if(V[v][i]==p) continue;
			if(getSize(V[v][i],v)*2>=getSize(v,p))
			{
				heavy[v] = V[v][i];
				init(V[v][i],v,u,h+1);
			}
		}
		for(int i=0;i<V[v].size();i++)
		{
			if(V[v][i]==p) continue;
			if(V[v][i]!=heavy[v]) init(V[v][i],v,V[v][i],h+1);
		}
	}
	
	void doQuery(int L, int R, int val)
	{
		if(height[L]<height[R]) doQuery(R,L,val);
		else
		{
			if(height[up[L]]>height[up[R]])
			{
				T.setValue(treePos[up[L]],treePos[L],val);
				doQuery(prev[up[L]],R,val);
			}
			else
			{
				T.setValue(treePos[R],treePos[L],val);
				return;
			}
		}
	}
	int getQuery(int ind)
	{
		return T.getValue(treePos[ind]);
	}
}H;

std::vector<int> V[100010];
int check[100010];
std::vector<int> ans;
std::vector< std::pair<int,int> > query;
void func(int k, int p)
{
	check[k] = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		if(check[V[k][i]]==1) query.push_back(std::make_pair(k,V[k][i]));
		else if(check[V[k][i]]==0)
		{
			H.V[k].push_back(V[k][i]);
			H.V[V[k][i]].push_back(k);
			func(V[k][i],k);
		}
	}
	check[k] = 2;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0)
		{
			func(i,0);
			H.init(i,0,i,1);
		}
	}
	int C = 1;
	
	for(int i=0;i<query.size();i++) H.doQuery(query[i].first,query[i].second,C++);
	for(int i=1;i<=a;i++) if(H.getQuery(i)>0) ans.push_back(i);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
}

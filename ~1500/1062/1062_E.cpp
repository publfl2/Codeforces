#include <stdio.h>
#include <vector>

std::vector<int> V[100010];
int height;
int sparse[100010][20];

void init(int k, int prev, int h)
{
	height[k] = h;
	sparse[k][0] = prev;
	for(int i=0;i<V[k].size();i++) init(V[k][i],k,h+1);
}

int LCA(int u ,int v)
{
	if(u==0) return v;
	if(v==0) return u;
	if(height[u]>height[v])
	{
		int k = height[u]-height[v];
		for(int i=19;i>=0;i--)
		{
			if(k>=(1<<i))
			{
				u = sparse[u][i];
				k -= (1<<i);
			}
		}
	}
	else if(height[u]<height[v])
	{
		int k = height[v]-height[u];
		for(int i=19;i>=0;i--)
		{
			if(k>=(1<<i))
			{
				v = sparse[v][i];
				k -= (1<<i);
			}
		}
	}
	
	for(int i=19;i>=0;i--)
	{
		if(sparse[u][i]!=sparse[v][i])
		{
			u = sparse[u][i];
			v = sparse[v][i];
		}
	}
	if(u==v) return u;
	else return sparse[u][0];
}


int a;
struct str{
	int x0;
	int y0;
	int z0;
};
struct SegTree{
	int value1[400010];
	int value2[400010];
	int value3[400010];
	
	void update(int k)
	{
		if(value1[2*k]==0)
		{
			value1[k] = value1[2*k];
			value2[k] = value2[2*k];
		}
		else if(value1[2*k+1]==0)
		{
			value1[k] = value1[2*k+1];
			value2[k] = value2[2*k+1];
		}
		else
		{
			value1[k] = LCA(value1[2*k],value1[2*k+1]);
			int s1 = LCA(value1[2*k],value2[2*k+1]);
			int s2 = LCA(value1[2*k+1],value2[2*k]);
			if(height[s1]>height[s2])
			{
				value2[k] = s1;
				value3[k] = value3[2*k+1];
			}
			else
			{
				value2[k] = s2;
				value3[k] = value3[2*k];
			}
		}
	}
	void insert(int index,int l = 1, int r = a, int v = 1)
	{
		if(l==r)
		{
			value1[v] = index;
			value3[v] = index;
			return;
		}
		int h = (l+r)/2;
		if(index<=h) insert(index,l,h,2*v);
		else insert(index,h+1,r,2*v+1);
		update(v);
	}
	
	str getValue(int left, int right, int l = 1, int r = a, int v =1)
	{
		if(left<=l&&r<=right) return {value1[v],value2[v],value3[v]};
		else if(right<l) return {0,0,0};
		else if(r<left) return {0,0,0};
		else
		{
			int h = (l+r)/2;
			std::pair<int,int> P1 = getValue(left,right,l,h,2*v);
			std::pair<int,int> P2 = getValue(left,right,h+1,r,2*v+1);
			
			int s = LCA(P1.first,P2.first);
			int s1 = LCA(P1.first,P2.second);
			int s2 = LCA(P1.second,P2.first);
			if(height[s1]>height[s2])
			{
				t = height[s1];
			}
			int t = height[s1]>height[s2]?height[s1]:height[s2];
			return std::make_pair(s,t);
		}
	}
}T;

int main()
{
	int b;
	scanf("%d%d",&a,&b);
	for(int i=2;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		parent[i] = c;
		V[c].push_back(i);
	}
	init(1,0,1);
	
	for(int i=1;i<=20;i++) for(int j=1;j<=a;j++) sparse[j][i] = sparse[sparse[j][i-1]][i-1];
	
	for(int i=1;i<=a;i++) T.insert(i);
	
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		std::pair<int,int> P = T.getValue(c,d);
		printf("%d %d\n",P.second,)
	}
	
}

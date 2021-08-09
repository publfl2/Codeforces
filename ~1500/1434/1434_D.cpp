#include <stdio.h>
#include <vector>
template <int V> struct SegTree{
    const int MIN = -123456789;
    int value[4*V+1];
    SegTree()
    {
    	for(int i=1;i<=4*V;i++) value[v] = MIN;
	}
    void update(int v)
    {
        value[v] = value[2*v]>value[2*v+1]?value[2*v]:value[2*v+1];
    }
    void insert(int ind, int val,int L=1,int R =V,int v = 1)
    {
        if(L==R) value[v] = value[v]>val?value[v]:val;
        else
        {
            int h = (L+R)/2;
            if(ind<=h) insert(ind,val,L,h,2*v);
            else insert(ind,val,h+1,R,2*v+1);
            update(v);
        }
    }
    int get(int left, int right, int L=1,int R=V, int v=1)
    {
        if(left>right) return MIN;
        if(left<=L&&R<=right) return value[v];
        else if(left>R) return MIN;
        else if(right<L) return MIN;
        else
        {
            int h = (L+R)/2;
            int s1 = get(left,right,L,h,2*v);
            int s2 = get(left,right,h+1,R,2*v+1);
            return s1>s2?s1:s2;
        }
    }
};
template <int V> struct HeavyLight{
    int parent[V+1],heavy[V+1];
    int root[V+1],treePos[V+1];
    int height[V+1],lca[V+1][20];
    std::vector<int> Vec[V+1];
    int p;
    const int MIN = -1;
    SegTree<V> T1,T2,T3,T4;
    void init()
    {
        parent[1] = 0;
        setTree();
        p = 0;
        setHLD();
        for(int i=1;i<=V;i++) lca[i][0] = parent[i];
        for(int i=1;i<=19;i++) for(int j=1;j<=V;j++) lca[j][i] = lca[lca[j][i-1]][i-1];
    }
    void setTree(int v = 1, int h = 1)
    {
        int node = 0;
        for(int i=0;i<Vec[v].size();i++)
        {
            if(Vec[v][i]==parent[v]) continue;
            parent[Vec[v][i]] = v;
            setTree(Vec[v][i],h+1);
        }
        heavy[v] = node;
        height[v] = h;
    }
    void setHLD(int v = 1, int r = 1)
    {
        p++;
        treePos[v] = p;
        root[v] = r;
        if(heavy[v]) setHLD(heavy[v],r);
        for(int i=0;i<Vec[v].size();i++)
        {
            if(Vec[v][i]==parent[v]) continue;
            if(Vec[v][i]==heavy[v]) continue;
            setHLD(Vec[v][i],Vec[v][i]);
        }
    }
    int LCA(int ind1, int ind2)
    {
        if(height[ind1]<height[ind2])
        {
            int t = ind1;
            ind1 = ind2;
            ind2 = t;
        }
        if(height[ind1]>height[ind2])
        {
            int h = height[ind1] - height[ind2];
            for(int i=19;i>=0;i--)
            {
                if((1<<i)<=h)
                {
                    ind1 = lca[ind1][i];
                    h -= (1<<i);
                }
            }
        }
        if(ind1==ind2) return ind1;
        int ans=1;
        for(int i=19;i>=0;i--)
        {
            if(lca[ind1][i]==lca[ind2][i]) ans = lca[ind1][i];
            else ind1 = lca[ind1][i] , ind2 = lca[ind2][i];
        }
        return ans;
    }
    
    void query(int v, int col, int C = 0)
    {
    	if(v==0) return;
    	
    	if(col==0)
    	{
    		int dist = height[v]-height[root[v]];
    		T1.insert(treePos[v],-d+C);
    		T2.insert(treePos[v],d+C);
    		query(parent[root[v]],col,C+dist+1);
		}
		else
		{
			int dist = height[v]-height[root[v]];
    		T3.insert(treePos[v],-d+C);
    		T4.insert(treePos[v],d+C);
    		query(parent[root[v]],col,C+dist+1);
		}
	}
};
HeavyLight<100000> HLD;


int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		V[b].push_back(std::make_pair(c,d));
		V[c].push_back(std::make_pair(b,d));
		HLD.Vec[b].push_back(c);
		HLD.Vec[c].push_back(b);
	}
	HLD.init();
	for(int i=1;i<=a;i++) color[i] = -1;
	setColor(1,0,0);
	for(int i=1;i<=a;i++)
	{
		HLD.query(i,color[i]);
	}
}

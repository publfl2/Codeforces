#include <stdio.h>
#include <vector>

struct segTree{
	int value[1200010];
	void update(int k)
	{
		value[k] = value[2*k]+value[2*k+1];
	}
	void setValue(int ind, int val, int l=1, int r =300000, int v=1)
	{
		if(l==r)
		{
			value[v] = val;
			return;
		}
		int h = (l+r)/2;
		if(ind<=h) setValue(ind,val,l,h,2*v);
		else setValue(ind,val,h+1,r,2*v+1);
		update(v);
	}
	int getValue(int L, int R, int l=1, int r=300000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 0;
		else if(r<L) return 0;
		else
		{
			int h =(l+r)/2;
			return getValue(L,R,l,h,2*v)+getValue(L,R,h+1,r,2*v+1);
		}
	}
}T1,T2;


int min[300010],max[300010],p[300010],pivot[300010],x[300010];
int check[300010];
std::vector<int> V[300010];
void update(int k)
{
	min[k] = min[k]<p[k]?min[k]:p[k];
	max[k] = max[k]>p[k]?max[k]:p[k];
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) V[i].push_back(0);
	for(int i=1;i<=b;i++) V[x[i]].push_back(i);
	for(int i=1;i<=a;i++) V[i].push_back(a+1);
	
	for(int i=1;i<=a;i++) p[i] = min[i] = max[i] = i;
	
	for(int i=1;i<=b;i++)
	{
		T1.setValue(x[i],1);
		if(check[x[i]]==0)
		{
			int s = T1.getValue(x[i]+1,a);
			p[x[i]]+=s;
			update(x[i]);
			p[x[i]] = 1;
			update(x[i]);
			check[x[i]] = 1;
		}
	}
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0)
		{
			int s = T1.getValue(i+1,a);
			p[i] += s;
			update(i);
		}
	}
	
	for(int i=1;i<=a;i++) pivot[i] = 1;
	for(int i=1;i<=a;i++) T2.setValue(V[i][1],1);
	for(int i=1;i<=b;i++)
	{
		int s = T2.getValue(V[x[i]][pivot[x[i]]]+1,b);
		p[x[i]] += s;
		update(x[i]);
		p[x[i]] = 1;
		update(x[i]);
		T2.setValue(V[x[i]][pivot[x[i]]],0);
		pivot[x[i]]++;
		T2.setValue(V[x[i]][pivot[x[i]]],1);
	}
	for(int i=1;i<=a;i++) printf("%d %d\n",min[i],max[i]);
}

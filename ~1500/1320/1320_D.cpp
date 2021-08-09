#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector< std::pair<int,int> > V;

int order[800010],rank[400010],SA[400010],tmp[400010];
char x[200010];
int sum[200010];

int p;
void func()
{
	std::vector<int> count1;
	std::vector< std::vector<int> > check;
	for(int i=0;i<=V.size();i++) count1.push_back(0);
	check.resize(V.size()+1);
	
	for(int i=0;i<V.size();i++) count1[order[i]+1]++;
	for(int i=1;i<=V.size();i++) count1[i] += count1[i-1];
	
	for(int i=0;i<V.size();i++) check[order[i+p]+1].push_back(i);
	for(int i=0;i<=V.size();i++)
	{
		for(int j=0;j<check[i].size();j++)
		{
			int s = check[i][j];
			//printf("%d %d %d!!\n",i,j,s);
			SA[count1[order[s]]++] = s;
		}
	}
}
bool cmp(int a, int b)
{
	if(order[a] == order[b]) return order[a+p] < order[b+p];
	return order[a]<order[b];
}

int upper(int s, int t)
{
	int min,max,ans;
	if(t%2==0) min = 0, max = V.size()/2 -1, ans = V.size()/2;
	else min = V.size()/2, max = V.size()-1, ans = V.size();
	while(min<=max)
	{
		int h = (min+max)/2;
		if(V[h].first<s) min = h+1;
		else
		{
			ans = h;
			max = h-1;
		}
	}
	return ans;
}

int lower(int s, int t)
{
	int min,max,ans;
	if(t%2==0) min = 0, max = V.size()/2 -1, ans = -1;
	else min = V.size()/2, max = V.size()-1, ans = V.size()/2-1;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(V[h].first>s) max = h-1;
		else
		{
			ans = h;
			min = h+1;
		}
	}
	return ans;
}

struct segTree{
	int value[1600010];
	void update(int k)
	{
		value[k] = value[2*k]<value[2*k+1]? value[2*k]:value[2*k+1];
	}
	void set(int ind, int val, int l=1, int r=400000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) set(ind,val,l,h,2*v);
			else set(ind,val,h+1,r,2*v+1);
			update(v);
		}
	}
	int getMin(int L, int R, int l=1, int r=400000, int v=1)
	{
		if(L>R) return 12345678;
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 12345678;
		else if(R<l) return 12345678;
		else
		{
			int h = (l+r)/2;
			int s1 = getMin(L,R,l,h,2*v);
			int s2 = getMin(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T;

int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='1') count++;
		else V.push_back(std::make_pair(i,count%2));
	}
	count = 1;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='1') count++;
		else V.push_back(std::make_pair(i,count%2));
	}
	for(int i=1;i<=a;i++) sum[i] = sum[i-1] + (x[i]=='1'?1:0);
	
	// SA
	for(int i=0;i<V.size();i++) SA[i] = i;
	for(int i=0;i<V.size();i++) order[i] = V[i].second;
	for(int i=V.size();i<=2*V.size();i++) order[i] = -1;
	for(p=1;;p*=2)
	{
		func();
		tmp[SA[0]] = 0;
	
		
		int c = 0;
		for(int i=1;i<V.size();i++)
		{
			if(order[SA[i-1]]==order[SA[i]] && order[SA[i-1]+p] == order[SA[i]+p]);
			else c++;
			tmp[SA[i]] = c;
		}
		for(int i=0;i<V.size();i++) order[i] = tmp[i];
		if(c==V.size()-1) break;
	}
	
	
	// LCP
	for(int i=0;i<V.size();i++) rank[SA[i]] = i;
	int p = 0;
	for(int i=0;i<V.size();i++)
	{
		if(p>0) p--;
		if(rank[i]==0) continue;
		int j = SA[rank[i]-1];
		for(;i+p<V.size() && j+p < V.size();p++) if(V[i+p].second!=V[j+p].second) break;
		T.set(rank[i],p);
	}
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		int L1 = upper(c,sum[c-1]), R1 = lower(c+e-1,sum[c-1]), L2 = upper(d,sum[d-1]), R2 = lower(d+e-1,sum[d-1]);
		if(R1-L1!=R2-L2)
		{
			printf("NO\n");
			continue;
		}
		
		int f;
		if(rank[L1]<=rank[L2]) f = T.getMin(rank[L1]+1,rank[L2]);
		else f = T.getMin(rank[L2]+1,rank[L1]);
		if(R1-L1+1<=f) printf("YES\n");
		else printf("NO\n");
	}
	
}

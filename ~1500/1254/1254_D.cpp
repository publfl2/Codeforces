#include <stdio.h>
#include <vector>
#include <algorithm>
#define MOD 998244353

struct segTree{
	long long int value[600010];
	long long int lazy[600010];
	void addValue(int L, int R, long long int val, int l=1, int r=150000, int v=1)
	{
		if(L<=l&&r<=R) value[v] += (r-l+1)*val, value[v]%=MOD, lazy[v] += val, lazy[v] %= MOD;
		else if(r<L) return;
		else if(R<l) return;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += (h-l+1)* lazy[v], value[2*v] %= MOD;
				value[2*v+1] += (r-h) * lazy[v], value[2*v+1] %= MOD;
				lazy[2*v] += lazy[v], lazy[2*v] %= MOD;
				lazy[2*v+1] += lazy[v], lazy[2*v+1] %= MOD;
				lazy[v] = 0;
			}
			
			addValue(L,R,val,l,h,2*v);
			addValue(L,R,val,h+1,r,2*v+1);
			value[v] = value[2*v]+value[2*v+1];
		}
	}
	
	long long int getSum(int L, int R, int l=1, int r=150000, int v=1)
	{
		if(L>R) return 0;
		
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return 0;
		else if(r<L) return 0;
		else
		{
			int h = (l+r)/2;
			if(lazy[v]!=0)
			{
				value[2*v] += (h-l+1)* lazy[v], value[2*v] %= MOD;
				value[2*v+1] += (r-h) * lazy[v], value[2*v+1] %= MOD;
				lazy[2*v] += lazy[v], lazy[2*v] %= MOD;
				lazy[2*v+1] += lazy[v], lazy[2*v+1] %= MOD;
				lazy[v] = 0;
			}
			long long int s1 = getSum(L,R,l,h,2*v);
			long long int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T;

int a;
std::vector<int> V[150010];
std::vector<int> pos[150010];
int prev[150010],right[150010],left[150010];

int init(int k, int p, int &C)
{
	prev[k] = p;
	right[k] = left[k] = C;
	pos[k].push_back(right[k]);
	C++;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		right[k] = init(V[k][i],k,C);
		pos[k].push_back(right[k]);
	}
	return right[k];
}

int hash[150010];
std::vector<int> heavy;

long long int check[150010];

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}

long long int inv(long long int k)
{
	return power(k,MOD-2);
}

int main()
{
	int b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	for(int i=1;i<=a;i++) if(V[i].size()>=300) heavy.push_back(i);
	for(int i=0;i<=a;i++) hash[i] = -1;
	for(int i=0;i<heavy.size();i++) hash[heavy[i]] = i;
	
	int C = 1;
	init(1,0,C);
	
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		if(c==1)
		{
			int d,e;
			scanf("%d%d",&d,&e);
			if(hash[d]!=-1) check[hash[d]] += e, check[hash[d]] %= MOD;
			else
			{
				for(int j=0;j<V[d].size();j++)
				{
					if(V[d][j]==prev[d]) continue;
					long long int f = a-(right[V[d][j]]-left[V[d][j]]+1);
					f *= e, f %= MOD;
					T.addValue(left[V[d][j]],right[V[d][j]],f);
				}
				if(prev[d]!=0)
				{
					long long int f = (right[d]-left[d]+1);
					f *= e, f %= MOD;
					T.addValue(1,left[d]-1,f);
					T.addValue(right[d]+1,a,f);
				}
				T.addValue(left[d],left[d],((long long int)a*e)%MOD);
			}
		}
		else
		{
			int d;
			scanf("%d",&d);
			long long int s1 = T.getSum(left[d],left[d]);
			for(int j=0;j<heavy.size();j++)
			{
				std::vector<int> ::iterator it = std::lower_bound(pos[d].begin(),pos[d].end(),left[heavy[j]]);
				if(it==pos[d].begin() || it==pos[d].end()) s1 += (long long int)check[j] * (right[d]-left[d]+1), s1%=MOD;
				else
				{
					std::vector<int> ::iterator it2 = it;
					it2--;
					s1 += (long long int)check[j] * (a-((*it)-(*it2))), s1 %= MOD;
				}
			}
			printf("%lld\n",(s1*inv(a))%MOD);
		}
	}
	
}
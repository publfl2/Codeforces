#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

struct segTree{
	long long int value[800010];
	void addValue(int ind, int val, int l=1, int r=200000, int v=1)
	{
		if(l==r) value[v] += val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) addValue(ind,val,l,h,2*v);
			else addValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v] + value[2*v+1];
		}
	}
	long long int getValue(int L, int R, int l=1, int r=200000, int v=1)
	{
		if(L>R) return 0;
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			long long int s1 = getValue(L,R,l,h,2*v);
			long long int s2 = getValue(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T1,T2;

std::vector<int> index;
std::map<int,int> hash;

long long int func(int k)
{
	if(k==0) return 0;
	if(T1.getValue(1,200000)<=k)
	{
		return T2.getValue(1,200000);
	}
	
	int L = 1, R = 200000;
	int p = 200001;
	while(L<=R)
	{
		int h = (L+R)/2;
		if(T1.getValue(h,200000)<k)
		{
			p = h;
			R = h-1;
		}
		else L = h+1;
	}
	//printf("%d %lld %lld %d??\n",p,T2.getValue(p,200000),T1.getValue(p,200000),k);
	long long int ans = T2.getValue(p,200000) + (k-T1.getValue(p,200000))*index[p-1];
	return ans;
}

long long int x[200010],y[200010],z[200010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%lld%lld",&x[i],&y[i]);
	if(c==0)
	{
		long long int sum = 0;
		for(int i=1;i<=a;i++) sum += y[i];
		printf("%lld",sum);
	}
	else
	{
		for(int i=1;i<=a;i++) if(x[i]>y[i]) index.push_back(x[i]-y[i]);
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
		
		for(int i=1;i<=a;i++)
		{
			z[i] = x[i];
			for(int j=1;j<=b;j++) z[i]*=2;
			z[i] -= y[i];
		}
		for(int i=1;i<=a;i++) z[i]=(z[i]>0?z[i]:0);
		long long int sum = 0;
		for(int i=1;i<=a;i++) sum += y[i];
		
		for(int i=2;i<=a;i++)
		{
			if(x[i]>y[i])
			{
				T2.addValue(hash[x[i]-y[i]],x[i]-y[i]);
				T1.addValue(hash[x[i]-y[i]],1);
			}
		}
		long long int ans = 0;
		long long int k = sum + z[1] + func(c-1);
		ans = ans>k?ans:k;
		for(int i=2;i<=a;i++)
		{
			if(x[i]>y[i])
			{
				T2.addValue(hash[x[i]-y[i]],-x[i]+y[i]);
				T1.addValue(hash[x[i]-y[i]],-1);
			}
			if(x[i-1]>y[i-1])
			{
				T2.addValue(hash[x[i-1]-y[i-1]],x[i-1]-y[i-1]);
				T1.addValue(hash[x[i-1]-y[i-1]],1);
			}
			k = sum + z[i] + func(c-1);
			//printf("%lld %lld %lld!!\n",sum,z[i],func(c-1));
			ans = ans>k?ans:k;
		}
		printf("%lld",ans);
	}
}

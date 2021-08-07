#include <stdio.h>
#include <set>
#define MOD 998244353

struct segTree{
	long long int value[800010];
	void setValue(int ind ,long long int val, int l=0, int r=200001, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) setValue(ind,val,l,h,2*v);
			else setValue(ind,val,h+1,r,2*v+1);
			value[v] = (value[2*v]+value[2*v+1])%MOD;
		}
	}
	long long int getSum(int L, int R, int l=0, int r=200001, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			long long int s1 = getSum(L,R,l,h,2*v);
			long long int s2 = getSum(L,R,h+1,r,2*v+1);
			return (s1+s2)%MOD;
		}
	}
}T1;

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

std::set<int> S;
int x[200010];
long long int y[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) y[i] = ((long long int)100*inv(x[i]))%MOD;
	
	y[a+1] = 1;
	for(int i=a;i>=1;i--) y[i] *= y[i+1], y[i] %= MOD;
	for(int i=1;i<=a+1;i++) T1.setValue(i,y[i]);
	
	S.insert(1);
	S.insert(a+1);
	
	long long int ans = T1.getSum(1,a)%MOD;
	while(b--)
	{
		int c;
		scanf("%d",&c);
		std::set<int> ::iterator it = S.lower_bound(c);
		int d = (*it);
		if(c==d)
		{
			std::set<int> ::iterator it2 = it, it3 = it;
			it2++;
			it3--;
			int L = (*it3);
			int R = (*it2);
			ans -= (T1.getSum(c,R-1)*inv(T1.getSum(R,R)))%MOD;
			ans += MOD, ans %= MOD;
			ans -= (T1.getSum(L,c-1)*inv(T1.getSum(c,c)))%MOD;
			ans += MOD, ans %= MOD;
			
			S.erase(it);
			ans += (T1.getSum(L,R-1)*inv(T1.getSum(R,R)))%MOD;
			ans %= MOD;
		}
		else
		{
			std::set<int> ::iterator it2 = it;
			it2--;
			int L = (*it2);
			int R = (*it);
			
			ans -= (T1.getSum(L,R-1)*inv(T1.getSum(R,R)))%MOD;
			ans += MOD, ans %= MOD;
			
			S.insert(c);
			ans += (T1.getSum(c,R-1)*inv(T1.getSum(R,R)))%MOD;
			ans %= MOD;
			ans += (T1.getSum(L,c-1)*inv(T1.getSum(c,c)))%MOD;
			ans %= MOD;
		}
		printf("%lld\n",ans);
	}
}
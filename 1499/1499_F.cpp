#include <stdio.h>
#include <vector>
#include <map>
#define MOD 998244353

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

std::map<long long int, long long int> M;
long long int inv(long long int k)
{
	if(M.find(k)!=M.end()) return M[k];
	return M[k] = power(k,MOD-2);
}

int a,b;
std::vector<int> V[5010];

int save[5010][5010],save2[5010][5010];
long long int func(int k, int prev, int h);
long long int func2(int k, int prev, int h)
{
	if(save2[k][h]!=-1) return save2[k][h];
	
	long long int ans = 0;
	for(int i=0;i<=h;i++) ans += func(k,prev,i), ans %= MOD;
	return save2[k][h] = ans;
}

long long int func(int k, int prev, int h)
{
	long long int ans = 0;
	if(h==-1) return 0;
	
	if(save[k][h]!=-1) return save[k][h];
	
	if(h==0)
	{
		for(int i=b;i>=0;i--)
		{
			if(2*i<=b)
			{
				long long int T = 1;
				for(int j=0;j<V[k].size();j++)
				{
					if(V[k][j]==prev) continue;
					T *= func2(V[k][j],k,i), T %= MOD;
				}
				ans += T, ans %= MOD;
				break;
			}
			else
			{
				long long int T = 1;
				for(int j=0;j<V[k].size();j++)
				{
					if(V[k][j]==prev) continue;
					T *= func2(V[k][j],k,b-i), T %= MOD;
				}
				long long int S = 0;
				for(int j=0;j<V[k].size();j++)
				{
					if(V[k][j]==prev) continue;
					S += func(V[k][j],k,i) * inv(func2(V[k][j],k,b-i));
					S %= MOD;
				}
				ans += (T*S)%MOD, ans %= MOD;
			}
		}
	}
	else if(2*h-2<=b)
	{
		long long int T1 = 1;
		for(int j=0;j<V[k].size();j++)
		{
			if(V[k][j]==prev) continue;
			T1 *= func2(V[k][j],k,h-1), T1 %= MOD;
		}
		
		if(h==1) ans += T1, ans %= MOD;
		else
		{
			long long int T2 = 1;
			for(int j=0;j<V[k].size();j++)
			{
				if(V[k][j]==prev) continue;
				T2 *= func2(V[k][j],k,h-2), T2 %= MOD;
			}
			
			ans += (T1-T2+MOD), ans %= MOD;
		}
	}
	else
	{
		long long int T = 1;
		for(int j=0;j<V[k].size();j++)
		{
			if(V[k][j]==prev) continue;
			T *= func2(V[k][j],k,b-h+1), T %= MOD;
		}
		
		long long int S = 0;
		for(int j=0;j<V[k].size();j++)
		{
			if(V[k][j]==prev) continue;
			S += func(V[k][j],k,h-1)*inv(func2(V[k][j],k,b-h+1));
			S %= MOD;
		}
		ans += (T*S)%MOD, ans %= MOD;
	}
	
	//printf("%d %d %d : %lld!!\n",k,prev,h,ans);
	return save[k][h] = ans;
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	
	for(int i=1;i<=a;i++) for(int j=0;j<=a;j++) save[i][j] = save2[i][j] = -1;
	printf("%lld",func(1,0,0));
}
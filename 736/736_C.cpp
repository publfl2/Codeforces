#include <stdio.h>
#include <vector>
#define MOD 1000000007
std::vector<int> V[110];
int a,b;
long long int func(int s, int t, int k, int prev)
{
	if(k-t>b) return 0;
	
	int start = t-1>b-k-1?t-1:b-k-1;
	if(start<0) start = 0;
	std::vector<long long int> save1,save2;
	
	for(int i=0;i<V[s].size();i++)
	{
		if(V[s][i]==prev) continue;
		long long int S = 0;
		for(int j=k;j<=2*b;j++)
		{
			printf("%d %d %d : %lld\n",V[s][i],start,j,func(V[s][i],start,j,s));
			S += func(V[s][i],start,j,s), S%=MOD;
		}
		save1.push_back(S);
	}
	
	if(k==0)
	{
		long long int C = 1;
		for(int i=0;i<save1.size();i++)
		{
			C*=save1[i];
			C%=MOD;
		}
		return C;
	}
	
	for(int i=0;i<V[s].size();i++)
	{
		if(V[s][i]==prev) continue;
		save2.push_back(func(V[s][i],start,k-1,s));
	}
	save2.push_back(1);
	
	
	long long int C = 1;
	for(int i=save2.size()-2;i>=0;i--)
	{
		save2[i] *= save2[i+1];
		save2[i]%=MOD;
	}
	for(int i=1;i<save1.size();i++)
	{
		save1[i] *= save1[i-1];
		save1[i]%=MOD;
	}
	
	long long int ans = 0;
	for(int i=0;i<save1.size()-1;i++)
	{
		ans += (save1[i]*save2[i+1]);
		ans%=MOD;
	}
	return ans;
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
	
	long long int ans = 0;
	for(int i=0;i<=b;i++) ans += func(1,0,i,0), ans%=MOD;
	printf("%lld",ans);
}

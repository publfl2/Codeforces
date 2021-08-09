#include <stdio.h>
#include <vector>
#define MOD 1073741824
#define LIMIT 45

int x[200010];
std::vector<int> prime;
long long int func(int s1, int s2, int s3)
{
	if(s1==0) return 0;
	
	long long int sum = 0;
	for(int j=1;j<=s2;j++) for(int k=1;k<=s3;k++) sum += x[s1*j*k];
	return sum+func(s1-1,s2,s3);
}

int a,b,c;
int save[110];
long long int func3(int s, int p)
{
	if(prime[p]>LIMIT)
	{
		long long int ans = 1;
		for(int i=0;;i++)
		{
			if(prime[i]>LIMIT) break;
			ans *= (save[i]+1);
		}
		return ans;
	}
	else
	{
		long long int ans = func3(s,p+1);
		int t = 0;
		while(s>=prime[p])
		{
			s/=prime[p];
			save[p]++;
			ans += func3(s,p+1), ans %= MOD;
			t++;
		}
		save[p] -= t;
		return ans;
	}
}

long long int func2(int s, int p)
{
	if(prime[p]>LIMIT) return func3(c,0);
	else
	{
		long long int ans = func2(s,p+1);
		int t = 0;
		while(s>=prime[p])
		{
			s/=prime[p];
			save[p]++;
			ans += func2(s,p+1), ans %= MOD;
			t++;
		}
		save[p] -= t;
		return ans;
	}
}

long long int func1(int s, int p)
{
	//printf("%d %d??\n",s,p);
	if(prime[p]>LIMIT) return func2(b,0);
	else
	{
		long long int ans = func1(s,p+1);
		int t = 0;
		while(s>=prime[p])
		{
			s/=prime[p];
			save[p]++;
			ans += func1(s,p+1), ans %= MOD;
			t++;
		}
		save[p] -= t;
		return ans;
	}
}

int check[2010];
int main()
{
	for(int i=2;i<=2000;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=2000;j+=i) check[j] = 1;
		}
	}
	for(int i=0;i<10;i++) printf("%d ",prime[i]);
	printf("\n");
	for(int i=1;i<=150000;i++)
	{
		int s = i;
		int t = 1;
		for(int j=0;prime[j]<=50;j++)
		{
			int k = 1;
			while(s%prime[j]==0) s/=prime[j],k++;
			t *= k;
		}
		x[i] = t;
	}
	
	
	scanf("%d%d%d",&a,&b,&c);
	long long int ans = func1(a,0);
	
	int start;
	for(int i=0;;i++)
	{
		if(prime[i]>LIMIT)
		{
			start = i;
			break;
		}
	}
	
	printf("!!\n");
	for(int i=start;i<prime.size();i++)
	{
		if(a<prime[i]) break;
		for(int j=start;j<prime.size();j++)
		{
			if(b<prime[j]) break;
			for(int k=start;k<prime.size();k++)
			{
				if(c<prime[k]) break;
				if(i==j&&j==k&&i==k) ans += func(a/prime[i],b/prime[j],c/prime[k])*4, ans%=MOD;
				if(i==j&&j!=k&&i!=k) ans += func(a/prime[i],b/prime[j],c/prime[k])*6, ans%=MOD;
				if(i!=j&&j==k&&i!=k) ans += func(a/prime[i],b/prime[j],c/prime[k])*6, ans%=MOD;
				if(i!=j&&j!=k&&i==k) ans += func(a/prime[i],b/prime[j],c/prime[k])*6, ans%=MOD;
				if(i!=j&&j!=k&&i!=k) ans += func(a/prime[i],b/prime[j],c/prime[k])*8, ans%=MOD;
			}
		}
	}
	printf("%lld",ans);
}

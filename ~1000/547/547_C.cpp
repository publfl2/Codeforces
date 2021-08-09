#include <stdio.h>
#include <vector>

int check[500010];
int num(int k)
{
	if(check[k]) return check[k];
	int ans = 0;
	for(int i=1;i*i<=k;i++)
	{
		if(i*i==k) ans++;
		else if(k%i==0) ans+=2;
	}
	return check[k] = ans;
}


int count[200010];
int x[200010];
int check2[500010];
std::vector<int> V[200010],prime;
int main()
{
	for(int i=2;i<=500000;i++)
	{
		if(check2[i]==0)
		{
			for(int j=i;j<=500000;j+=i) check2[j] = 1;
			prime.push_back(i);
		}
	}
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		int t = x[i];
		for(int j=0;j<prime.size()&&prime[j]*prime[j]<=x[i];j++)
		{
			if(x[i]%prime[j]==0) V[i].push_back(prime[j]);
			while(x[i]%prime[j]==0) x[i]/=prime[j];
		}
		if(t>1) V[i].push_back(t);
	}
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		int sum = 0;
		for(int j=0;j<V[i].size();j++)
		{
			if(num(V[i][j])%2==0) sum += count[V[i][j]];
			else sum -= count[V[i][j]];
		}
		for(int j=0;j<V[i].size();j++) count[V[i][j]]++;
		printf("%d\n",sum);
	}
}

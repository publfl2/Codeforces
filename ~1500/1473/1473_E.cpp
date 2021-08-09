#include <stdio.h>
#include <queue>
#include <vector>

struct str{
	int x0;
	int x1;
	
	long long int y0;
	long long int z0;
	long long int w0;
};

int func(long long int k)
{
	int ans = 0;
	while(k)
	{
		ans++;
		k/=2;
	}
	return ans;
}
bool operator<(str a, str b)
{
	long long int A = a.y0-a.z0+a.w0;
	long long int B = b.y0-b.z0+b.w0;
	return A>B;
}

std::priority_queue<str> Q;
std::vector< std::pair<int,int> > V[200010];
long long int check[200010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		V[c].push_back(std::make_pair(d,e));
		V[d].push_back(std::make_pair(c,e));
	}
	
	for(int i=1;i<=a;i++) check[i] = -1;
	
	for(int i=0;i<V[1].size();i++)
	{
		int s = V[1][i].first;
		long long int t = V[1][i].second;
		Q.push({s,func(t),t,t,t});
	}
	
	while(!Q.empty())
	{
		str A = Q.top();
		Q.pop();
		if(check[A.x0]>=0)
		{
			if(A.y0-A.z0+A.w0>=check[A.x0]) continue;
		}
		
		check[A.x0] = A.y0-A.z0+A.w0;
		for(int i=0;i<V[A.x0].size();i++)
		{
			long long int t = V[A.x0][i].second;
			Q.push({V[A.x0][i].first,func(A.w0<t?A.w0:t),t+A.y0,t>A.z0?t:A.z0,t<A.w0?t:A.w0});
		}
	}
	
	for(int i=2;i<=a;i++) printf("%lld ",check[i]);
}

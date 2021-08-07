#include <stdio.h>
#include <vector>

std::vector< std::pair<int,long long int> > V[100010];
std::pair<long long int,int> sparse[100010][30];
int height[100010];
int A,B;
long long int D;

void makeSparse(int k,int parent, int h)
{
	height[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		int x0 = V[k][i].first;
		long long int value = V[k][i].second;
		if(x0==parent) continue;
		if(height[x0]!=0)
		{
			A = k;
			B = x0;
			D = value;
		}
		else
		{
			sparse[x0][0] = std::make_pair(value,k);
			makeSparse(x0,k,h+1);
		}
	}
}

std::pair<long long int,int> func(int a, int h)
{
	long long int sum = 0;
	for(int i=0;i<19;i++)
	{
		if(h%2==1)
		{
			sum += sparse[a][i].first;
			a = sparse[a][i].second;
		}
		h/=2;
	}
	return std::make_pair(sum,a);
}

long long int getDist(int a, int b)
{
	long long int sum = 0;
	if(height[a]<height[b])
	{
		std::pair<long long int,int> P = func(b,height[b]-height[a]);
		b = P.second; sum += P.first;
	}
	else if(height[a]>height[b])
	{
		std::pair<long long int,int> P = func(a,height[a]-height[b]);
		a = P.second, sum += P.first;
	}
	for(int i=19;i>=0;i--)
	{
		if(sparse[a][i].second==sparse[b][i].second);
		else
		{
			sum += sparse[a][i].first;
			sum += sparse[b][i].first;
			a = sparse[a][i].second;
			b = sparse[b][i].second;
		}
	}
	if(a==b) return sum;
	else return sum + sparse[a][0].first + sparse[b][0].first;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) height[i] = 0;
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++)
		{
			int c,d;
			long long int e;
			scanf("%d%d%I64d",&c,&d,&e);
			V[c].push_back(std::make_pair(d,e));
			V[d].push_back(std::make_pair(c,e));
		}
		makeSparse(1,0,1);
		sparse[1][0] = std::make_pair(0,1);
		
		for(int j=1;j<=20;j++)
		{
			for(int i=1;i<=a;i++)
			{
				long long int c = sparse[sparse[i][j-1].second][j-1].first + sparse[i][j-1].first;
				int d = sparse[sparse[i][j-1].second][j-1].second;
				sparse[i][j] = std::make_pair(c,d);
			}
		}
		
		for(int i=1;i<=b;i++)
		{
			int d,e;
			scanf("%d%d",&d,&e);
			
			long long int s1 = getDist(d,e);
			long long int s2 = getDist(d,A) + D + getDist(B,e);
			long long int s3 = getDist(d,B) + D + getDist(A,e);
			printf("%I64d\n",s1<s2?s1<s3?s1:s3:s2<s3?s2:s3);
		}
	}
}

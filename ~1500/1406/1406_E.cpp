#include <stdio.h>
#include <vector>

int a;
int check[100010];

long long int getQuery(int s, long long int t)
{
	if(s==1) printf("A %lld\n",t);
	else printf("B %lld\n",t);
	fflush(stdout);
	
	long long int a;
	scanf("%lld",&a);
	return a;
}

long long int gcd(long long int a,long long int b)
{
	return a?gcd(b%a,a):b;
}
long long int lcm(long long int a,long long int b)
{
	return (a/gcd(a,b))*b;
}

std::vector<long long int> prime;
void func1(long long int k)
{
	long long int ans = k;
	for(int i=0;i<prime.size();i++)
	{
		if(k*prime[i]>a) break;
		int b = getQuery(1,k*prime[i]);
		if(b==1) ans = lcm(ans,k*prime[i]);
	}
	printf("C %lld\n",ans);
	fflush(stdout);
}

void func2(int L, int R)
{
	for(int i=L;i<=R;i++)
	{
		int b = getQuery(1,prime[i]);
		if(b==1)
		{
			printf("C %lld\n",prime[i]);
			fflush(stdout);
			return;
		}
	}
}

int main()
{
	for(int i=2;i<=100000;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=100000;j+=i) check[j] = 1;
		}
	}
	
	scanf("%d",&a);
	
	int start = -1, end = -1;
	for(int i=0;i<prime.size()&&prime[i]*prime[i]<=a;i++)
	{
		start = i;
		int b = getQuery(2,prime[i]);
		int c = getQuery(1,prime[i]);
		if(c==1)
		{
			func1(prime[i]);
			return 0;
		}
	}
	start++;
	
	for(int i=prime.size()-1;i>=0;i--)
	{
		if(prime[i]<=a)
		{
			end = i;
			break;
		}
	}
	
	while(start<=end)
	{
		int h = (start+end)/2;
		for(int i=start;i<=h;i++)
		{
			int b = getQuery(2,prime[i]);
		}
		int c = getQuery(1,1);
		if(c==(end-h+1)) start = h+1;
		else
		{
			func2(start,h);
			return 0;
		}
	}
	printf("C 1\n");
	fflush(stdout);
	return 0;
}

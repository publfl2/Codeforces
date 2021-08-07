#include <stdio.h>
#include <vector>
#define MAX 1000000000
std::vector<int> prime;
long long int x[1010];

int query1(int k)
{
	printf("? %lld\n",x[k]);
	fflush(stdout);
	int a;
	scanf("%d",&a);
	
	int count = 0;
	while(a>1)
	{
		a/=prime[k];
		count++;
	}
	return count;
}
int query2(long long int k, int i)
{
	printf("? %lld\n",k);
	fflush(stdout);
	int a;
	scanf("%d",&a);
	
	int count1 = 1, count2 = 1;
	if(a%prime[i]==0) count1++, a/=prime[i];
	if(a%prime[i]==0) count1++, a/=prime[i];
	if(a%prime[i+1]==0) count2++, a/=prime[i+1];
	if(a%prime[i+1]==0) count2++, a/=prime[i+1];
	return count1*count2;
}
void query3(long long int k)
{
	printf("! %lld\n",k);
	fflush(stdout);
}

int check[150];
int main()
{
	for(int i=2;i<=130;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=130;j+=i) check[j] = 1;
		}
	}
	
	for(int i=0;i<18;i++)
	{
		long long int s = prime[i];
		while(s<MAX) s*=prime[i];
		s/=prime[i];
		x[i] = s;
	}
	
	int T;
	scanf("%d",&T);
	
	long long int ans = 1;
	while(T--)
	{
		for(int i=0;i<18;i++)
		{
			int s = query1(i);
			ans *= (s+1);
		}
		
		if(ans==1)
		{
			query3(8);
			continue;
		}
		
		for(int i=18;i<25;i+=2)
		{
			int s = query2(prime[i]*prime[i]*prime[i+1]*prime[i+1],i);
			ans *= s;
		}
		query3(ans*2);
	}
}

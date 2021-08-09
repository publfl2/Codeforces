#include <stdio.h>
#include <vector>
 
std::vector<long long int> prime,prime2;
int check[400010],check2[10000010];
 
long long int func(int k, long long int s, long long int limit , int count)
{
	
	if(s>limit) return 0;
	else if(s*prime[k]>limit)
	{
		if(count<=1) return 0;
		else return limit/s;
	}
	if(k==prime.size())
	{
		if(count<=1) return 0;
		else return limit/s;
	}
	
	long long int s1 = func(k+1,s,limit,count);
	long long int s2 = func(k+1,s*prime[k],limit,count+1);
	if(count<=1) return s1+s2;
	return s1-s2;
	
}
int main()
{
	for(int i=2;i<=400000;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=400000;j+=i) check[j] = 1;
		}
	}
	for(int i=2;i<=10000000;i++)
	{
		if(check2[i]==0)
		{
			prime2.push_back(i);
			for(int j=i;j<=10000000;j+=i) check2[j] = 1;
		}
	}
	
	long long int a;
	scanf("%lld",&a);
	
	long long int ans = 0;
	for(int i=0;i<prime.size();i++)
	{
		if(prime[i]*prime[i]*prime[i]<=a) ans++;
		else break;
	}
	
	for(int i=0;i<prime.size();i++)
	{
		if(prime[i]<=1000&&a/prime[i]>=10000000)
		{
			long long int s = a/prime[i];
			long long int S = s - func(0,1,s,0);
			
			S--;
			for(int j=0;j<prime.size();j++)
			{
				long long int t1 = prime[j];
				while(1)
				{
					t1 *= prime[j];
					if(t1<=s) S--;
					else break;
				}				
			}
			S -= i;
			ans += S;
		}
		else
		{
			int min = i+1, max = prime2.size()-1;
			int val = 0;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(prime[i]*prime2[h]<=a)
				{
					val = h-i;
					min = h+1;
				}
				else max = h-1;
			}
			ans += val;
		}
	}
	printf("%lld",ans);
}
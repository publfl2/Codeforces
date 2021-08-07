#include <stdio.h>
#include <vector>
#define MOD 998244353
struct str{
	long long int x1;
	long long int value1;
	long long int x2;
	long long int value2;
	long long int x3;
	long long int value3;
	long long int x4;
	long long int value4;
};

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int s = a;
	while(b)
	{
		if(b%2==1) ans*=s, ans%=MOD;
		s*=s, s%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

std::vector<int> V[300010];

str func(int k, int prev)
{
	long long int s1=1,s2=1,s3=1,s4=1;
	long long int value1=0,value2=0,value3=0,value4=0;
	long long int t=1,t2=0;
	//1
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		str A = func(V[k][i],k);
		
		s1 *= (A.x2+A.x3+A.x4) , s1%=MOD;
	}
	
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		str A = func(V[k][i],k);
		
		value1 += (s1*inv(A.x2+A.x3+A.x4)%MOD)*(A.value2+A.value3+A.value4);
		value1 %= MOD;
	}
	value1 += s1, value1 %= MOD;
	
	//2
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		str A = func(V[k][i],k);
		
		s2 *= (A.x1+A.x2+A.x3+A.x4) , s2%=MOD;
	}
	
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		str A = func(V[k][i],k);
		
		value2 += (s2*inv(A.x1+A.x2+A.x3+A.x4)%MOD)*(A.value1+A.value2+A.value3+A.value4);
		value2 %= MOD;
	}
	
	//3
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		str A = func(V[k][i],k);
		
		s3 *= (A.x2+A.x3+A.x4) , s3%=MOD;
		t *= (A.x3+A.x4), t%=MOD;
	}
	
	
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		str A = func(V[k][i],k);
		
		value3 += (s3*inv(A.x2+A.x3+A.x4)%MOD)*(A.value2+A.value3+A.value4);
		value3 %= MOD;
		
		t2 += (t*inv(A.x3+A.x4)%MOD)*(A.value3+A.value4);
		t2 %= MOD;
	}
	s3 -= t, s3+=MOD, s3 %= MOD;
	value3 -= t2, value3 += MOD, value3 %= MOD;
	value3 += s3, value3 %= MOD;
	
	//4
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		str A = func(V[k][i],k);
		
		s4 *= (A.x1+A.x2+A.x3+A.x4) , s4%=MOD;
	}
	
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		str A = func(V[k][i],k);
		
		value4 += (s4*inv(A.x1+A.x2+A.x3+A.x4)%MOD)*(A.value1+A.value2+A.value3+A.value4);
		value4 %= MOD;
	}
	printf("%d:\n",k);
	printf("%lld %lld %lld %lld %lld %lld %lld %lld\n\n",s1,value1,s2,value2,s3,value3,s4,value4);
	return {s1,value1,s2,value2,s3,value3,s4,value4};
}


int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	str A = func(1,0);
	printf("%lld",A.value3+A.value4);
}

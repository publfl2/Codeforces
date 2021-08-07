#include <stdio.h>
#define MOD 1000000007

long long int check[1010][1010];
long long int comb(int s, int t)
{
	if(t==0) return 1;
	if(s==t) return 1;
	if(check[s][t]) return check[s][t];
	return check[s][t] = (comb(s-1,t-1)+comb(s-1,t))%MOD;
}
long long int fact[1010];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=1000;i++)
	{
		fact[i] = fact[i-1]*i;
		fact[i] %= MOD;
	}
	
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int left = 0, right = a;
	int count1 = 0, count2 = 0;
	while(left<right)
	{
		int h = (left+right)/2;
		if(c<h)
		{
			count2++;
			right = h;
		}
		else
		{
			count1++;
			left = h+1;
		}
	}
	//printf("%d %d!!\n",count1,count2);
	long long int s1 = comb(b-1,count1-1)*fact[count1-1];
	s1 %= MOD;
	long long int s2 = comb(a-b,count2)*fact[count2];
	s2%=MOD;
	long long int s3 = fact[a-(count1+count2)];
	printf("%lld",((s1*s2)%MOD*s3)%MOD);
}

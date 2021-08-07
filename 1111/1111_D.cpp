#include <stdio.h>
#include <string.h>
#define MOD 1000000007

int a;
long long int check[60][100010];
int y[60];
char x[100010];
long long int save[60][60];
int start;
long long int func(int s, int t)
{
	if(s==start) return func(s+1,t);
	if(y[s]==0) return func(s+1,t);
	if(s>52)
	{
		if(t*2==a) return 1;
		else return 0;
	}
	if(check[s][t]!=-1) return check[s][t];
	
	long long int s1 = func(s+1,t+y[s]);
	long long int s2 = func(s+1,t);
	if(s1>0)
	{
		save[start][s]+=s1;
		save[start][s]%=MOD;
	}
	return check[s][t] = (s1+s2)%MOD;
}
int table[510];

void clear()
{
	for(int i=1;i<=52;i++)
	{
		for(int j=1;j<=a;j++) check[i][j] = -1;
	}
}

long long int inv(long long int k)
{
	long long int s = 1;
	long long int t = MOD-2;
	long long int h = k;
	while(t)
	{
		if(t%2==1)
		{
			s *= h;
			s %= MOD;
		}
		h*=h;
		h%=MOD;
		t/=2;
	}
	return s;
}

int main()
{
	for(char i='a';i<='z';i++) table[i] = i-'a'+1;
	for(char i='A';i<='Z';i++) table[i] = i-'A'+27;
	scanf("%s",x+1);
	a = strlen(x+1);
	
	for(int i=1;i<=a;i++) y[table[x[i]]]++;
	
	long long int C = 1;
	for(int i=1;i<=a/2;i++) C *= i, C %= MOD;
	for(int i=1;i<=a/2;i++) C *= i, C %= MOD;
	
	for(int i=1;i<=52;i++) for(int j=1;j<=y[i];j++) C*=inv(j), C%=MOD;
	
	for(int i=1;i<=52;i++)
	{
		if(y[i]==0) continue;
		clear();
		start = i;
		save[i][i] = func(1,y[i]);
	}
	
	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=6;j++) printf("%d ",save[i][j]);
		printf("\n");
	}
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		long long int s = C*save[table[x[c]]][table[x[d]]];
		s %= MOD;
		printf("%lld\n",(2*s)%MOD);
	}
	
}

#include <stdio.h>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}
int lcm(int a, int b)
{
	return (a/gcd(a,b))*b;
}

int x[100010];
int check[100010];
int prime[100010], p = 1;
int main()
{
	for(int i=2;i*i<=1000000000;i++)
	{
		for(int j=1;j<p;j++)
		{
			if(i%prime[j]==0) goto u;
		}
		prime[p++] = i;
		u:;
	}
	
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) check[i] = 0;
		if(c%b!=0)
		{
			printf("-1\n");
			continue;
		}
		if(a==1)
		{
			if(b==c)
			{
				if(x[1]==b) printf("0\n");
				else printf("1\n");
			}
			else printf("-1\n");
			continue;
		}
		
		int count1=0;
		for(int i=1;i<=a;i++) if(x[i]%b!=0) check[i] = 1;
		for(int i=1;i<=a;i++) if(c%x[i]!=0) check[i] = 1;
		for(int i=1;i<=a;i++) if(check[i]==1) count1++;
		
		int A = 0, B = 0;
		int count2 = 0;
		for(int i=1;i<=a;i++)
		{
			if(check[i]==0)
			{
				if(A==0) A = x[i],B=x[i];
				else
				{
					A = gcd(A,x[i]);
					B = lcm(B,x[i]);
				}
			}
		}
		
		if(A!=0&&A!=b) count2++;
		if(A!=0&&B!=c) count2++;
		
		int ans = count1>count2?count1:count2;
		if(ans>a) printf("-1\n");
		else printf("%d\n",ans);
	}
}

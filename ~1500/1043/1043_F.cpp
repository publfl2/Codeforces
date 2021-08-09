#include <stdio.h>
int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

int x[300010],check[300010];

int check2[300010];
int func(int k)
{
	int control = 0;
	for(int i=2;i*i<=300000;i++)
	{
		if(k%i==0&&check2[i]==0)
		{
			control = 1;
			check2[i] = 1;
		}
		while(k%i==0) k/=i;
	}
	if(k>1)
	{
		if(check2[k]==0)
		{
			control = 1;
			check2[k] = 1;
		}
	}
	return control;
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=300000;i++) check[i] = 1234567;
	check[x[1]] = 1;
	func(x[1]);
	for(int i=2;i<=a;i++)
	{
		if(func(x[i])==1)
		{
			for(int j=1;j<=300000;j++)
			{
				check[gcd(j,x[i])] = check[gcd(j,x[i])]<check[j]+1?check[gcd(j,x[i])]:check[j]+1;
			}
		}
	}
	int min = 1234567;
	if(check[1]>=1234567) printf("-1");
	else printf("%d",check[1]);
}

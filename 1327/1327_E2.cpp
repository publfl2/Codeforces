#include <stdio.h>

int check[200010];
int power(int s, int t)
{
	int ans = 1;
	for(int i=1;i<=t;i++) ans*=s;
	return ans;
}
void func(int k, int C)
{
	if(k==0) return;
	
	for(int i=1;i<k;i++)
	{
		func(k-i,9*C);
		long long int s = 9*power(10,k-i-1);
		check[i] += C*s;
	}
	check[k] += C;
}
int main()
{
	int a;
	scanf("%d",&a);
	func(a,10);
	for(int i=1;i<=a;i++) printf("%d ",check[i]);
}

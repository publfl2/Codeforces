#include <stdio.h>
#include <vector>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

std::vector<int> left[710],right[710];

int func(int s, int t)
{
	for(int i=s;i<=t;i++)
	{
		return ?
	}
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		for(int j=i-1;j>=1;j--) if(gcd(x[i],x[j])>1) left[i].push_back(j);
		for(int j=i+1;j<=a;j++) if(gcd(x[i],x[j])>1) right[i].push_back(j);
	}
	func(1,a);
}

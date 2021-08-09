#include <stdio.h>
#include <vector>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

int check[710];
std::vector<int> V[710];
void clear()
{
	for(int i=1;i<=700;i++) check[i] = 0;
}
void func(int k)
{
	if(check[k]) return;
	check[k] = 1;
	for(int i=0;i<V[k].size();i++) func(V[k][i]);
}

int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			if(gcd(x[i],x[j])>1)
			{
				V[i].push_back(j);
				V[j].push_back(i);
			}
		}
	}
	
	func(1);
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0)
		{
			printf("No");
			return 0;
		}
	}
	clear();
	
	for(int i=1;i<=a;i++)
	{
		int count = 0;
		clear();
		check[i] = 1;
		for(int j=0;j<V[i].size();j++)
		{
			if(check[V[i][j]]==0)
			{
				count++;
				func(V[i][j]);
			}
		}
		if(count>=4)
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}

#include <stdio.h>
#include <vector>

int check[200010],check2[200010];
std::vector<int> V[200010];

int func(int k)
{
	check2[k] = 1;
	int ans = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(check[V[k][i]]==1&&check2[V[k][i]]==0)
		{
			ans += func(V[k][i]);
		}
	}
	return ans;
}

long long int ans[200010];
int x[200010];
std::vector<int> save[200010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j*j<=x[i];j++)
		{
			if(x[i]%j==0)
			{
				save[j].push_back(i);
				if(j*j!=x[i]) save[x[i]/j].push_back(i);
			}
		}
	}
	
	for(int i=1;i<=200000;i++)
	{
		for(int j=0;j<save[i].size();j++) check[save[i][j]] = 1;
		for(int j=0;j<save[i].size();j++)
		{
			if(check2[save[i][j]]==0)
			{
				int C = func(save[i][j]);
				ans[i] += (long long int)C*(C+1)/2;
			}
		}
		for(int j=0;j<save[i].size();j++) check2[save[i][j]] = 0;
		for(int j=0;j<save[i].size();j++) check[save[i][j]] = 0;
	}
	
	for(int i=200000;i>=1;i--)
	{
		for(int j=2*i;j<=200000;j+=i) ans[i] -= ans[j];
	}
	
	for(int i=1;i<=200000;i++)
	{
		if(ans[i]>0) printf("%d %lld\n",i,ans[i]);
	}
}

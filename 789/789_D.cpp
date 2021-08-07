#include <stdio.h>
#include <vector>
std::vector<int> V[1000010];
int check[1000010], x[1000010];
void func(int k,int color)
{
	check[k] = color;
	for(int i=0;i<V[k].size();i++) if(check[V[k][i]]==0) func(V[k][i],color);
}
int main()
{
	int a,b,c,d;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		scanf("%d%d",&c,&d);
		if(c==d) V[c].push_back(c);
		else
		{
			V[c].push_back(d);
			V[d].push_back(c);
		}
	}
	int color = 1;
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0) func(i,color),color++;
	}
	int count = 0;
	for(int i=1;i<=a;i++) if(V[i].size()>0) x[check[i]]=1;
	for(int i=1;i<=a;i++) if(x[i]>0) count++;
	if(count<=1);
	else
	{
		printf("0");
		return 0;
	}
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		long long int t = V[i].size();
		ans+=t*(t-1)/2;
	}
	printf("%I64d",ans);
}

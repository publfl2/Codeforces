#include <stdio.h>
#include <vector>
int x[100010],y[100010],check[100010],ans=0;
std::vector<int> V[100010];
void func(int k)
{
	// -1 : all is ok
	// -2 : no answer
	check[k] = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(check[V[k][i]]) continue;
		if(x[k]!=x[V[k][i]])
		{
			y[k]++;
			y[V[k][i]]++;
			ans++;
		}
		func(V[k][i]);
	}
}
int main()
{
	int a,b,c;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	func(1);
	for(int i=1;i<=a;i++)
	{
		if(ans==y[i])
		{
			printf("YES\n%d",i);
			return 0;
		}
	}
	printf("NO");
}

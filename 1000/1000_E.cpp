#include <stdio.h>
#include <vector>

std::vector<int> V[300010];
int check[300010],height[300010],value[300010];
int count = 0;
int func(int k, int prev, int h)
{
	check[k] = 1;
	height[k] = h;
	int ans = height[k];
	
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		if(check[V[k][i]]==1) ans = ans<height[V[k][i]]?ans:height[V[k][i]];
		else
		{
			int t = func(V[k][i],k,h+1);
			ans = ans<t?ans:t;
		}
	}
	
	if(ans==height[k]) value[k] = 1;
	else value[k] = 0;
	return ans;
}

int ans = 0;
int func2(int k, int prev)
{
	int max1 = 0, max2 = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		if(height[V[k][i]]<=height[k]) continue;
		
		int t = func2(V[k][i],k);
		if(max1<t)
		{
			max2 = max1;
			max1 = t;
		}
		else if(max2<t) max2 = t;
	}
	ans = ans>max1+max2?ans:max1+max2;
	return max1+value[k];
}

int main()
{
	freopen("input.txt","r",stdin);
	int a,b;
	scanf("%d%d",&a,&b);
	printf("!\n");
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	printf("!!\n");
	func(1,0,1);
	printf("!!!\n");
	func2(1,0);
	printf("%d",ans);
}
#include <stdio.h>
#include <vector>

std::vector<int> V[10010];
int size[10010],height[10010];
int a;

int func(int v, int p, int h)
{
	height[v] = h;
	int sum = 0;
	for(int i=0;i<V[v].size();i++)
	{
		if(V[v][i]==p) continue;
		sum += func(V[v][i],v,h+1);
	}
	return size[v] = sum+1;
}

std::pair<int,int> func2(int v)
{
	int sum1 = 0;
	int sum2 = 0;
	int max1 = 0, max2 = 0;
	for(int i=0;i<V[v].size();i++)
	{
		int s;
		if(height[V[v][i]]<height[v]) s = (a+1)-size[v];
		else s = size[V[v][i]];
		sum1 += s;
		sum2 += s*s;
		if(s>=max1)
		{
			max2 = max1;
			max1 = s;
		}
		else if(s>=max2) max2 = s;
	}
	return std::make_pair(((sum1*sum1)-sum2)/2,max1*max2);
}
int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	func(0,-1,1);
	
	std::pair<int,int> P = func2(0);
	for(int i=1;i<=a;i++)
	{
		std::pair<int,int> P2 = func2(i);
		if(P2.first>P.first) P = P2;
	}
	printf("%d %d",P.first,P.first-P.second);
}

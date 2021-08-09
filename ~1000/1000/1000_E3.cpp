#include <stdio.h>
#include <vector>
#include <stack>

std::vector<int> V[300010];
int check[300010],height[300010],value[300010],p[300010];
int value1[300010],value2[300010],value3[300010];
std::vector<int> temp;

struct str{
	int first;
	int second;
	int third;
};
std::stack<str> St;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	
	St.push({1,0,1});
	while(!St.empty())
	{
		int k = St.top().first;
		int prev = St.top().second;
		int h = St.top().third;
		St.pop();
		if(check[k]) continue;
		
		check[k] = 1;
		p[k] = prev;
		height[k] = h;
		temp.push_back(k);
		
		for(int i=0;i<V[k].size();i++) if(check[V[k][i]]==0) St.push({V[k][i],k,h+1});
	}
	
	for(int i=temp.size()-1;i>=0;i--)
	{
		int k = temp[i];
		value1[k] = height[k];
		for(int j=0;j<V[k].size();j++)
		{
			if(V[k][j]==p[k]) continue;
			if(height[V[k][j]]>height[k])
			{
				int t = value1[V[k][j]];
				value1[k] = value1[k]<t?value1[k]:t;
			}
			else value1[k] = value1[k]<height[V[k][j]]?value1[k]:height[V[k][j]];
		}
		if(value1[k]==height[k]) value[k] = 1;
		else value[k] = 0;
	}
	
	
	int ans = 0;
	for(int i=temp.size()-1;i>=0;i--)
	{
		int k = temp[i];
		int max1 = 0, max2 = 0;
		for(int i=0;i<V[k].size();i++)
		{
			if(height[V[k][i]]<height[k]) continue;
			
			int t = value3[V[k][i]];
			if(max1<t)
			{
				max2 = max1;
				max1 = t;
			}
			else if(max2<t) max2 = t;
		}
		ans = ans>max1+max2?ans:max1+max2;
		value3[k] = max1 + value[k];
	}
	
	printf("%d",ans);
}
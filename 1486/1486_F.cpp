#include <stdio.h>
#include <vector>
#include <algorithm>

int height[300010];
int next[300010][30];
std::vector<int> V[300010];
void func(int k, int prev,int h)
{
	height[k] = h;
	next[k][0] = prev;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k,h+1);
	}
}

int up(int s, int k)
{
	if(k<0) return 0;
	for(int i=20;i>=0;i--)
	{
		if((1<<i)<=k)
		{
			s = next[s][i];
			k -= (1<<i);
		}
	}
	return s;
}

int LCA(int s, int t)
{
	if(height[s]>height[t])
	{
		int k = height[s]-height[t];
		for(int i=20;i>=0;i--)
		{
			if((1<<i)<=k)
			{
				s = next[s][i];
				k -= (1<<i);
			}
		}
	}
	if(height[s]<height[t])
	{
		int k = height[t]-height[s];
		for(int i=20;i>=0;i--)
		{
			if((1<<i)<=k)
			{
				t = next[t][i];
				k -= (1<<i);
			}
		}
	}
	
	for(int i=20;i>=0;i--)
	{
		if(next[s][i]!=next[t][i])
		{
			s = next[s][i];
			t = next[t][i];
		}
	}
	if(s!=t) s = next[s][0];
	return s;
}

std::pair<int,int> query[300010];
int count1[300010],count2[300010],value[300010],value2[300010];
int x[300010];
bool cmp(int a, int b)
{
	return height[a]<height[b];
}

long long int C[300010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	func(1,0,1);
	for(int j=1;j<=20;j++) for(int i=1;i<=a;i++) next[i][j] = next[next[i][j-1]][j-1];
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		query[i] = std::make_pair(c,d);
		count1[c]++;
		count1[d]++;
		
		int t = LCA(c,d);
		count2[t]++;
	}
	
	for(int i=1;i<=a;i++) x[i] = i;
	std::sort(x+1,x+a+1,cmp);
	
	for(int i=a;i>=1;i--)
	{
		value[x[i]] = count1[x[i]]-count2[x[i]];
		value2[x[i]] = count1[x[i]] - 2*count2[x[i]];
		count1[next[x[i]][0]] += value2[x[i]];
	}
	
	long long int ans = 0;
	for(int i=1;i<=b;i++)
	{
		int t = LCA(query[i].first,query[i].second);
		int val = value[t]-1;
		int s1 = up(query[i].first,height[query[i].first]-height[t]-1);
		int s2 = up(query[i].second,height[query[i].second]-height[t]-1);
		if(s1!=0) val -= (value2[s1]-1);
		if(s2!=0) val -= (value2[s2]-1);
	}
	
	printf("%lld",ans);
}
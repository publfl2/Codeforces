#include <stdio.h>
#include <vector>
int parent[5010],height[5010];
int check[5010];
std::vector<int> V[5010];

void func(int k, int prev, int h)
{
	parent[k] = prev;
	height[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k,h+1);
	}
}

int findLast(int k)
{
	int t = -1;
	for(int i=1;i<=k;i++)
	{
		if(check[i]==1) continue;
		if(t==-1) t = i;
		else if(height[t]<height[i]) t = i;
	}
	return t;
}
int findUp(int k)
{
	int t = -1;
	for(int i=1;i<=k;i++)
	{
		if(t==-1) t = i;
		else if(height[t]>height[i]) t = i;
	}
	return t;
}

int getSum(int k, int prev, int t)
{
	int ans = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		if(V[k][i]==t) continue;
		ans += getSum(V[k][i],k,t);
	}
	return ans;
}

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
	
	long long int ans = 0;
	for(int j=0;j<V[1].size();j++)
	{
		long long int s = getSum(V[1][j],1,0);
		ans += s*(s-1)/2;
	}
	
	for(int i=2;i<=a+1;i++)
	{
		for(int j=1;j<=a;j++) check[j] = 0;
		
		int s = findLast(i-1);
		printf("%d ",s);
		int t;
		int k = s;
		while(k!=0)
		{
			check[k] = 1;
			k = parent[k];
		}
		k = findLast(i-1);
		if(k==-1) t = findUp(i-1);
		else
		{
			t = k;
			while(k!=0)
			{
				check[k] = 1;
				k = parent[k];
			}
			k = findLast(i-1);
			if(k!=-1) goto u;
		}
		printf("%d!!\n",t);
		
		long long int sum1 = 1, sum2 = 1;
		for(int j=0;j<V[t].size();j++)
		{
			if(V[t][j]<=i-1) continue;
			sum1 += getSum(V[t][j],t,i);
		}
		for(int j=0;j<V[s].size();j++)
		{
			if(V[s][j]<=i-1) continue;
			sum2 += getSum(V[s][j],s,i);
		}
		printf("%lld %lld??\n",sum1,sum2);
		long long int S = sum1*sum2*i;
		
		if(s==t)
		{
			for(int j=0;j<V[t].size();j++)
			{
				if(V[t][j]<=i-1) continue;
				long long int k = getSum(V[t][j],t,i);
				S -= k*k*i;
			}
			S/=2;
		}
		ans += S;
	}
	u:;
	printf("%lld",ans);
}

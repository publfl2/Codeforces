#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
std::vector<int> V[200010];
int MAX,check[200010];
bool cmp(std::stack<int> a, std::stack<int> b)
{
	return a.size()<b.size();
}
std::vector< std::stack<int> > ans;
std::stack<int> func(int k)
{
	std::vector< std::stack<int> > V2;
	std::stack<int> X;
	check[k] = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(check[V[k][i]]!=0) continue;
		V2.push_back(func(V[k][i]));
	}
	std::sort(V2.begin(),V2.end(),cmp);
	
	int s = 0, t = V2.size()-1;
	while(s<=t)
	{
		if(s==t)
		{
			if(!X.empty()) ans.push_back(X);
			X = V2[s];
			break;
		}
		if(V2[s].size()+V2[t].size()<MAX)
		{
			V2[t].push(k);
			while(!V2[s].empty()) V2[t].push(V2[s].top()),V2[s].pop();
			ans.push_back(V2[t]);
			s++,t--;
		}
		else
		{
			if(!X.empty()) ans.push_back(X);
			X = V2[t];
			t--; 
		}
	}
	if(X.empty())
	{
		if(V[k].size()==1) X.push(k);
		return X;
	}
	else
	{
		X.push(k);
		return X;
	}
}
int main()
{
	int a,b,c,d,e;
	scanf("%d%d%d",&a,&b,&c);
	if((2*a)%c==0) MAX = (2*a)/c;
	else MAX = (2*a)/c+1;
	for(int i=1;i<=b;i++)
	{
		scanf("%d%d",&d,&e);
		V[d].push_back(e);
		V[e].push_back(d);
	}
	std::stack<int> k = func(1);
	if(!k.empty()) ans.push_back(k);
	for(int i=0;i<ans.size();i++)
	{
		printf("%d ",ans[i].size());
		while(!ans[i].empty()) printf("%d ",ans[i].top()),ans[i].pop();
		printf("\n");
	}
}

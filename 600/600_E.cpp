#include <stdio.h>
#include <algorithm>
#include <set>
#define SIZE 400

struct str{
	int first;
	int second;
	int index;
	long long int ans;
}query[1000010];
bool cmp(str a, str b)
{
	if(a.first/SIZE==b.first/SIZE) return a.second<b.second;
	return (a.first/SIZE)<(b.first/SIZE);
}
bool cmp2(str a, str b)
{
	return a.index<b.index;
}

int x[1000010],hash[1000010];
std::vector<int> V[1000010];

int func(int k, int prev, int &C)
{
	query[k].index = k;
	query[k].first = C++;
	query[k].second = query[k].first;
	hash[query[k].first] = k;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		query[k].second = func(V[k][i],k,C);
	}
	return query[k].second;
}

int count[1000010];
long long int sum[1000010];
std::set<int> S;

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
	int C = 1;
	func(1,0,C);
	std::sort(query+1,query+a+1,cmp);
	
	int L = 1, R = 1;
	count[x[hash[1]]]++;
	S.insert(1);
	sum[1] = x[hash[1]];
	for(int i=1;i<=a;i++)
	{
		if(i==x[hash[1]]) continue;
		sum[0] += i;
	}
	S.insert(0);
	
	for(int i=1;i<=a;i++)
	{
		while(L>query[i].first)
		{
			L--;
			sum[count[x[hash[L]]]] -= x[hash[L]];
			if(sum[count[x[hash[L]]]]==0) S.erase(count[x[hash[L]]]);
			count[x[hash[L]]]++;
			sum[count[x[hash[L]]]] += x[hash[L]];
			if(sum[count[x[hash[L]]]]==x[hash[L]]) S.insert(count[x[hash[L]]]);
		}
		while(L<query[i].first)
		{
			sum[count[x[hash[L]]]] -= x[hash[L]];
			if(sum[count[x[hash[L]]]]==0) S.erase(count[x[hash[L]]]);
			count[x[hash[L]]]--;
			sum[count[x[hash[L]]]] += x[hash[L]];
			if(sum[count[x[hash[L]]]]==x[hash[L]]) S.insert(count[x[hash[L]]]);
			L++;
		}
		
		while(R<query[i].second)
		{
			R++;
			sum[count[x[hash[R]]]] -= x[hash[R]];
			if(sum[count[x[hash[R]]]]==0) S.erase(count[x[hash[R]]]);
			count[x[hash[R]]]++;
			sum[count[x[hash[R]]]] += x[hash[R]];
			if(sum[count[x[hash[R]]]]==x[hash[R]]) S.insert(count[x[hash[R]]]);
		}
		while(R>query[i].second)
		{
			sum[count[x[hash[R]]]] -= x[hash[R]];
			if(sum[count[x[hash[R]]]]==0) S.erase(count[x[hash[R]]]);
			count[x[hash[R]]]--;
			sum[count[x[hash[R]]]] += x[hash[R]];
			if(sum[count[x[hash[R]]]]==x[hash[R]]) S.insert(count[x[hash[R]]]);
			R--;
		}
		
		std::set<int> ::iterator it = S.end();
		it--;
		int c = (*it);
		query[i].ans = sum[c];
	}
	
	std::sort(query+1,query+a+1,cmp2);
	for(int i=1;i<=a;i++) printf("%lld ",query[i].ans);
}
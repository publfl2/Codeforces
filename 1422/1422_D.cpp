#include<stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
 
struct str{
	int first;
	int second;
	int index;
}P[1000010];
bool cmp1(str a, str b)
{
	if(a.first==b.first) return a.index<b.index;
	return a.first<b.first;
}
bool cmp2(str a, str b)
{
	if(a.second==b.second) return a.index<b.index;
	return a.second<b.second;
}
 
int next[1000010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}
std::vector< std::pair<int,long long int> > V[1000010];
long long int dist[1000010];
std::priority_queue< std::pair<long long int,int> > Q;
 
long long int abs(long long int k)
{
	return k>0?k:-k;
}
long long int min(long long int a, long long int b)
{
	return a<b?a:b;
}
 
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	if(b==0)
	{
		printf("%lld",abs(x1-x2)+abs(y1-y2));
		return 0;
	}
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		P[i]={c,d,i};
	}
	std::sort(P+1,P+b+1,cmp1);
	for(int i=1;i<=b;i++) next[i] = i;
	
	for(int i=1;i<b;i++)
	{
		if(P[i].first==P[i+1].first)
		{
			int s = find(P[i+1].index);
			int t = find(P[i].index);
			next[s] = t;	
		}
	}
	std::sort(P+1,P+b+1,cmp2);
	for(int i=1;i<b;i++)
	{
		if(P[i].second==P[i+1].second)
		{
			int s = find(P[i+1].index);
			int t = find(P[i].index);
			next[s] = t;	
		}
	}
	
	for(int i=1;i<=b;i++)
	{
		int s = find(P[i].index);
		V[0].push_back(std::make_pair(s,min(abs(P[i].first-x1),abs(P[i].second-y1))));
		V[s].push_back(std::make_pair(0,min(abs(P[i].first-x1),abs(P[i].second-y1))));
	}
	for(int i=1;i<=b;i++)
	{
		int s = find(P[i].index);
		V[b+1].push_back(std::make_pair(s,abs(P[i].first-x2)+abs(P[i].second-y2)));
		V[s].push_back(std::make_pair(b+1,abs(P[i].first-x2)+abs(P[i].second-y2)));
	}
	
	std::sort(P+1,P+b+1,cmp1);
	for(int i=1;i<b;i++)
	{
		int s = find(P[i].index);
		int t = find(P[i+1].index);
		if(s==t) continue;
		V[s].push_back(std::make_pair(t,P[i+1].first-P[i].first));
		V[t].push_back(std::make_pair(s,P[i+1].first-P[i].first));
	}
	std::sort(P+1,P+b+1,cmp2);
	for(int i=1;i<b;i++)
	{
		int s = find(P[i].index);
		int t = find(P[i+1].index);
		if(s==t) continue;
		V[s].push_back(std::make_pair(t,P[i+1].second-P[i].second));
		V[t].push_back(std::make_pair(s,P[i+1].second-P[i].second));
	}
	V[0].push_back(std::make_pair(b+1,abs(x1-x2)+abs(y1-y2)));
	V[b+1].push_back(std::make_pair(0,abs(x1-x2)+abs(y1-y2)));
	
	Q.push(std::make_pair(-1,0));
	while(!Q.empty())
	{
		long long int d = Q.top().first;
		int ind = Q.top().second;
		Q.pop();
		if(dist[ind]) continue;
		dist[ind] = -d;
		for(int i=0;i<V[ind].size();i++) if(dist[V[ind][i].first]==0) Q.push(std::make_pair(-(-d+V[ind][i].second),V[ind][i].first));
	}
	printf("%lld",dist[b+1]-1);
}

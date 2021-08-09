#include <stdio.h>
#include <queue>

int value[5010];
int x[510][510];
int next[5010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

struct str{
	int first;
	int second;
	int value;
};
bool operator<(str a, str b)
{
	return a.value>b.value;
}
std::priority_queue<str> Q;
std::vector< std::pair<int,int> > ans;

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) scanf("%d",&x[i][j]);
	for(int i=1;i<=a;i++) for(int j=i+1;j<=a;j++) Q.push({i,j,x[i][j]});
	for(int i=1;i<=a;i++) value[i] = x[i][i];
	int C = a+1;
	for(int i=1;i<=a;i++) next[i] = i;
	
	while(!Q.empty())
	{
		int s = Q.top().first;
		int t = Q.top().second;
		int k = Q.top().value;
		Q.pop();
		
		s = find(s);
		t = find(t);
		if(s==t) continue;
		
		if(value[s]==k && value[t]==k) continue;
		else if(value[s]==k)
		{
			next[t] = s;
			ans.push_back({t,s});
		}
		else if(value[t]==k)
		{
			next[s] = t;
			ans.push_back({s,t});
		}
		else
		{
			next[s] = C;
			next[t] = C;
			next[C] = C;
			ans.push_back({s,C});
			ans.push_back({t,C});
			value[C] = k;
			C++;
		}
	}
	
	printf("%d\n",C-1);
	for(int i=1;i<C;i++) printf("%d ",value[i]);
	printf("\n%d\n",find(1));
	for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
}
#include <stdio.h>
#include <vector>

int check[100010];
std::vector<int> St;
std::vector<int> temp;
std::vector<int> V[100010],V2[100010],V3[100010];

void getStack(int k)
{
	if(check[k]) return;
	check[k] = 1;
	for(int i=0;i<V[k].size();i++) getStack(V[k][i]);
	St.push_back(k);
}
void SCC(int k)
{
	if(check[k]) return;
	check[k] = 1;
	temp.push_back(k);
	for(int i=0;i<V2[k].size();i++) SCC(V2[k][i]);
}

int next[100010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

int color[100010];
std::pair<int,int> query[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V2[d].push_back(c);
		query[i]=std::make_pair(c,d);
	}
	
	int ans = 0;
	
	for(int i=1;i<=a;i++) getStack(i);
	int C = 0;
	for(int i=1;i<=a;i++) check[i] = 0;
	for(int i=St.size()-1;i>=0;i--)
	{
		if(check[St[i]]) continue;
		C++;
		temp.clear();
		SCC(St[i]);
		for(int j=0;j<temp.size();j++) color[temp[j]] = C;
		if(temp.size()>=2) ans += (temp.size());
	}
	for(int i=1;i<=a;i++) next[i] = i;
	for(int i=1;i<=b;i++)
	{
		int c = color[query[i].first];
		int d = color[query[i].second];
		c = find(c);
		d = find(d);
		if(c==d) continue;
		next[c] = d;
		ans++;
	}
	printf("%d",ans);
}

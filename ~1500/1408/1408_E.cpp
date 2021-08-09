#include <stdio.h>
#include <vector>
#include <algorithm>

int cost1[100010],cost2[100010];
std::vector<int> V[100010];
std::pair<int,int> x[100010];
int next1[100010],next2[100010];
std::vector<int> temp;
std::vector< std::pair<int,int> >temp2;
std::vector<int> save[100010];
int check[100010];

int find(int k)
{
	if(k==next2[k]) return k;
	else return next2[k] = find(next2[k]);
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&cost1[i]);
	for(int j=1;j<=b;j++) scanf("%d",&cost2[j]);
	
	for(int i=1;i<=a;i++) next2[i] = i;
	
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		temp2.clear();
		for(int j=1;j<=c;j++)
		{
			int d;
			scanf("%d",&d);
			temp2.push_back(std::make_pair(cost2[d],d));
		}
		std::sort(temp2.begin(),temp2.end());
		for(int j=0;j<temp2.size();j++) V[i].push_back(temp2[j].second);
	}
	
	for(int i=1;i<=a;i++) x[i] = std::make_pair(cost1[i],i);
	std::sort(x+1,x+a+1);
	
	long long int ans = 0;
	for(int i=a;i>=1;i--)
	{
		int ind = x[i].second;
		for(int j=0;j<V[ind].size();j++)
		{
			if(next1[V[ind][j]]==0) continue;
			
			int t = next1[V[ind][j]];
			t = find(t);
			
			if(check[t]==0)
			{
				check[t] = 1;
				temp.push_back(t);
			}
			save[t].push_back(cost1[ind]+cost2[V[ind][j]]);
		}
		
		for(int j=0;j<temp.size();j++)
		{
			if(save[temp[j]].size()>=2)
			{
				std::sort(save[temp[j]].begin(),save[temp[j]].end());
				for(int k=0;k<save[temp[j]].size()-1;k++) ans += save[temp[j]][k];
			}
		}
		for(int j=0;j<temp.size();j++) next2[temp[j]] = ind;
		for(int j=0;j<V[ind].size();j++) next1[V[ind][j]] = ind;
		for(int j=0;j<temp.size();j++) check[temp[j]] = 0;
		for(int j=0;j<temp.size();j++) save[temp[j]].clear();
		temp.clear();
	}
	printf("%lld",ans);
}

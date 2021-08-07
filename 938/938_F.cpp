#include <stdio.h>
#include <vector>
#include <string.h>

char x[5010];
std::vector<int> next[5010];
int check[5010][5010];
std::vector< std::pair<int,int> > V1,V2;
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	
	int sum = 0;
	for(int i=0;;i++)
	{
		sum += (1<<i);
		if(sum>=a)
		{
			sum -= (1<<i);
			break;
		}
	}
	for(int i=0;i<=sum;i++) for(int j=0;j<=sum;j++) if((i&j)==i) next[i].push_back(j-i);
	
	V1.push_back({1,0});
	check[1][0] = 1;
	while(!V1.empty())
	{
		char min = 'z'+1;
		for(int i=0;i<V1.size();i++)
		{
			int s = V1[i].first;
			int t = V1[i].second;
			for(int j=0;j<next[t].size();j++)
			{
				if(next[t][j]+s>a) break;
				if(check[s+next[t][j]+1][t+next[t][j]]==1) continue;
				if((a-s-next[t][j])<(sum-t-next[t][j])) continue;
				
				check[s+next[t][j]+1][t+next[t][j]] = 1;
				char c = x[s+next[t][j]];
				if(min>c)
				{
					min = c;
					V2.clear();
					V2.push_back({s+next[t][j]+1,t+next[t][j]});
				}
				else if(min==c) V2.push_back({s+next[t][j]+1,t+next[t][j]});
			}
		}
		if(V2.empty()) break;
		printf("%c",min);
		V1 = V2;
		V2.clear();
	}
	
}
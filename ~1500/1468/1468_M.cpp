#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#define SIZE 500


std::vector<int> temp2[200010];
void inverse(std::vector< std::vector<int> > &V1, std::vector< std::vector<int> > &V2, int MAX)
{
	for(int i=1;i<=MAX;i++) temp2[i].clear();
	for(int i=0;i<V1.size();i++) for(int j=0;j<V1[i].size();j++) temp2[V1[i][j]].push_back(i+1);
	for(int i=1;i<=MAX;i++) V2.push_back(temp2[i]);
}

std::vector< std::vector<int> > V1,V2,V3,V4,V5,V6;
struct str{
	int index;
	int first;
	int second;
};
bool operator<(str a, str b)
{
	if(a.first==b.first) return a.second<b.second;
	return a.first<b.first;
}
std::vector<str> V7;

void func(int s, int t)
{
	int control = 0;
	for(int i=0;i<V1.size();i++)
	{
		int C = 0;
		for(int j=0;j<V1[i].size();j++)
		{
			if(V1[i][j]==s) C++;
			if(V1[i][j]==t) C++;
		}
		if(C==2)
		{
			printf("%d ",i+1);
			control++;
			if(control==2)
			{
				printf("\n");
				return;
			}
		}
	}
}

std::vector<int> count[200010];
int check[200010];
std::vector<int> index;
std::map<int,int> hash;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		V3.clear();
		V4.clear();
		V5.clear();
		V6.clear();
		V7.clear();
		index.clear();
		hash.clear();
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			
			std::vector<int> temp;
			for(int j=1;j<=b;j++)
			{
				int c;
				scanf("%d",&c);
				temp.push_back(c);
				index.push_back(c);
			}
			V1.push_back(temp);
		}
		std::sort(index.begin(),index.end());
		for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
		int M = index.size();
		for(int i=0;i<V1.size();i++) for(int j=0;j<V1[i].size();j++) V1[i][j] = hash[V1[i][j]];
		inverse(V1,V2,M);
		
		for(int k=1;k<=a;k++) count[k].clear();
		for(int k=1;k<=a;k++) check[k] = 0;
		for(int i=0;i<V2.size();i++) for(int j=0;j<V2[i].size();j++) count[V2[i][j]].push_back(i);
		
		for(int k=1;k<=a;k++)
		{
			if(count[k].size()>SIZE)
			{
				for(int i=0;i<count[k].size();i++)
				{
					for(int j=0;j<V2[count[k][i]].size();j++)
					{
						if(V2[count[k][i]][j]==k) continue;
						if(check[V2[count[k][i]][j]]==1)
						{
							printf("%d %d\n",k,V2[count[k][i]][j]);
							goto END;
						}
						check[V2[count[k][i]][j]] = 1;
					}
				}
			}
		}
		
		for(int i=0;i<V2.size();i++)
		{
			std::vector<int> temp;
			for(int j=0;j<V2[i].size();j++)
			{
				if(count[V2[i][j]].size()<=SIZE) temp.push_back(V2[i][j]);
			}
			V3.push_back(temp);
		}
		inverse(V3,V4,a);
		
		for(int k=1;k<=a;k++) count[k].clear();
		for(int k=1;k<=M;k++) check[k] = 0;
		for(int i=0;i<V4.size();i++) for(int j=0;j<V4[i].size();j++) count[V4[i][j]].push_back(i);
		
		for(int k=1;k<=a;k++)
		{
			if(count[k].size()>SIZE)
			{
				for(int i=0;i<count[k].size();i++)
				{
					for(int j=0;j<V4[count[k][i]].size();j++)
					{
						if(V4[count[k][i]][j]==k) continue;
						if(check[V4[count[k][i]][j]]==1)
						{
							func(k,V4[count[k][i]][j]);
							goto END;
						}
						check[V4[count[k][i]][j]] = 1;
					}
				}
			}
		}
		
		for(int i=0;i<V4.size();i++)
		{
			std::vector<int> temp;
			for(int j=0;j<V4[i].size();j++)
			{
				if(count[V4[i][j]].size()<=SIZE) temp.push_back(V4[i][j]);
			}
			V5.push_back(temp);
		}
		
		inverse(V5,V6,M);
		
		for(int i=0;i<V6.size();i++)
		{
			for(int j=0;j<V6[i].size();j++)
			{
				for(int k=j+1;k<V6[i].size();k++)
				{
					V7.push_back({i,V6[i][j],V6[i][k]});
				}
			}
		}
		std::sort(V7.begin(),V7.end());
		for(int i=0;i+1<V7.size();i++)
		{
			if(V7[i].first==V7[i+1].first&&V7[i].second==V7[i+1].second)
			{
				printf("%d %d\n",V7[i].first,V7[i].second);
				goto END;
			}
		}
		printf("-1\n");
		
		END:;
	}
}

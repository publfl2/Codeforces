#include <stdio.h>
#include <vector>
#include <stack>

std::vector<int> V[1000010];
std::vector<int> V2[1000010];
std::stack<int> St;

int check[1000010];
void init(int k)
{
	check[k] = 1;
	for(int i=0;i<V[k].size();i++) if(check[V[k][i]]==0) init(V[k][i]);
	St.push(k);
}

std::vector<int> colorSet[1000010];
int color[1000010];

void SCC(int k ,int C)
{
	colorSet[C].push_back(k);
	check[k] = 0;
	color[k] = C;
	for(int i=0;i<V2[k].size();i++) if(check[V2[k][i]]==1) SCC(V2[k][i],C);
}

std::vector<int> V3[1000010];
std::vector<int> V4[1000010];
int type[1000010];
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
	}
	for(int i=1;i<=a;i++) if(check[i]==0) init(i);
	
	int C = 1;
	while(!St.empty())
	{
		int k = St.top();
		St.pop();
		if(check[k]==0) continue;
		
		SCC(k,C++);
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<V[i].size();j++)
		{
			V3[color[i]].push_back(color[V[i][j]]);
			V4[color[V[i][j]]].push_back(color[i]);
		}
	}
	for(int i=1;i<C;i++) if(V4[i].size()==0) check[i] = 1;
	for(int i=1;i<C;i++)
	{
		if(check[i]==0)
		{
			for(int k=0;k<V3[i].size();k++)
			{
				if(check[V3[i][k]]==1) // checked
				{
					check[i] = 2;
					goto u;
				}
			}
			
			for(int k=0;k<V4[i].size();k++)
			{
				if(check[V4[i][k]]==1) // checked
				{
					check[i] = 2;
					goto u;
				}
			}
		
			check[i] = 1;
			u:;
		}
	}
	for(int i=1;i<C;i++)
	{
		if(check[i]==1)
		{
			for(int j=0;j<colorSet[i].size();j++)
			{
				for(int k=0;k<V[colorSet[i][j]].size();k++)
				{
					if(color[V[colorSet[i][j]][k]]==i&&type[V[colorSet[i][j]][k]]==1)
					{
						type[colorSet[i][j]] = 2;
						goto v;
					}
				}
				
				for(int k=0;k<V2[colorSet[i][j]].size();k++)
				{
					if(color[V2[colorSet[i][j]][k]]==i&&type[V2[colorSet[i][j]][k]]==1)
					{
						type[colorSet[i][j]] = 2;
						goto v;
					}
				}
				
				type[colorSet[i][j]] = 1;
				v:;
			}
		}
	}
	
	int sum = 0;
	for(int i=1;i<=a;i++) if(type[i]==1) sum++;
	
	printf("%d\n",sum);
	for(int i=1;i<=a;i++) if(type[i]==1) printf("%d ",i);
}

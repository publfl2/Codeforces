#include <stdio.h>
#include <vector>
char x[110][110];
int direX[5]={1,0,-1,0};
int direY[5]={0,1,0,-1};
int count = 0,a,b,c;
std::vector< std::pair<int,int> > dfs[110][110];
std::vector< std::pair<int,int> > root;
int height[110][110],up[110][110];
void clear()
{
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) check[i][j] = 0;
}
void func(int s,int t,int c1, int c2,int h)
{
	if(check[s][t]==1) return;
	check[s][t] = 1;
	height[s][t] = h;
	up[s][t] = h;
	for(int i=0;i<4;i++)
	{
		if(check[s+direX[i]][t+direY[i]]==1)
		{
			if(s+direX[i]==c1&&t+direY[i]==c2);
			else
			{
				if(up[s][t]>up[s+direX[i]][t+direY[i]]) up[s][t] = up[s+direX[i]][t+direY[i]];
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		if(check[s+direX[i]][t+direY[i]]==0)
		{
			dfs[s][t].push_back(std::make_pair(s+direX[i],t+direY[i]));
			func(s+direX[i],t+direY[i],s,t);
			if(up[s][t]>up[s+direX[i]][t+direY[i]]) up[s][t] = up[s+direX[i]][t+direY[i]];
		}
	}
}

void divide(int s, int t)
{
	
}


int main()
{
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(check[i][j]==0)
			{
				count++;
				root.push_back(std::make_pair(i,j));
				func(i,j,0,0,1);
			}
		}
	}
	while(1)
	{
		for(int j=0;j<root.size();j++)
		{
			divide(root[j].first,root[j].second);
		}
	}
}

#include <stdio.h>
#include <vector>

std::vector<int> V[1000010];
int height[1000010];
int up[1000010];
int ans[1000010];

void func(int v, int h, int u)
{
	height[v] = h;
	
	int count = 0;
	for(int i=0;i<V[v].size();i++) if(height[V[v][i]]==0) count++;
	up[v] = u;
	
	
	for(int i=0;i<V[v].size();i++)
	{
		if(height[V[v][i]]==0)
		{
			if(V[v])
			if(count==1) func(V[v][i],h+1,u);
			else func(V[v][i],h+1,V[v][i]);		
		}
	}
}

int main()
{
	
}


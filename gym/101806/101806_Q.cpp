#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <stack>

std::vector<int> V[30];
std::stack<int> St;
int y[10010][10010];
int prev[10010],next[10010];
int ans[10010];
char x[100010];
int main()
{
	int a;
	scanf("%d%s",&a,x+1);
	
	int pivot = 0;
	for(int i=1;i<=a;i++)
	{
		int count = 0;
		if('a'<=x[i]&&x[i]<='z')
		{
			int c = x[i]-'a';
			next[pivot] = i;
			for(int j=0;j<V[c].size();j++)
			{
				int d = V[c][j];
				if(next[d]>pivot||y[pivot][next[d]]==1)
				{
					y[i][d] = 1;
					y[d][i] = 1;
					count++;
				}
			}
			y[i][i] = 1;
			count++;
			St.push(c);
			V[c].push_back(i);
			printf("%d ",ans[i] = count+ans[pivot]);
			prev[i] = pivot;
			pivot = i;
		}
		else
		{
			int c = St.top();
			V[c].pop_back();
			pivot = prev[pivot];
			next[pivot] = 0;
			St.pop();
			
			printf("%d ",ans[pivot]);
		}
	}
}

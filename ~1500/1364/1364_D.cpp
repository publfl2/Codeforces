#include <stdio.h>
#include <stack>
#include <queue>
#include <vector>

std::stack<int> St;
int check[100010],level[100010];
std::vector<int> ans;
std::vector<int> V[100010],S[3];
int control = 0;

void func(int s, int prev, int h)
{
	if(control) return;
	
	if(check[s]==1)
	{
		std::stack<int> St2 = St;
		ans.push_back(s);
		
		while(!St2.empty())
		{
			if(St2.top()!=s) ans.push_back(St2.top()), St2.pop();
			else break;
		}
		control = 1;
		return;
	}
	
	St.push(s);
	check[s] = 1;
	level[s] = h;
	for(int i=0;i<V[s].size();i++)
	{
		if(V[s][i]==prev) continue;
		func(V[s][i],s,h+1);
	}
	check[s] = 2;
}

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		V[d].push_back(e);
		V[e].push_back(d);
	}
	func(1,0,1);
	
	if(ans.size()==0)
	{
		for(int i=1;i<=a;i++) S[level[i]%2].push_back(i);
		if(S[0].size()>=(c+1)/2)
		{
			printf("1\n");
			for(int i=0;i<(c+1)/2;i++) printf("%d ",S[0][i]);
		}
		else
		{
			printf("1\n");
			for(int i=0;i<(c+1)/2;i++) printf("%d ",S[1][i]);
		}
	}
	else
	{
		for(int i=1;i<=a;i++) level[i] = 0;
		for(int i=0;i<ans.size();i++) level[ans[i]] = i+1;
		
		int t = ans.size()+1;
		std::pair<int,int> P = std::make_pair(ans[0],ans.size()-1);
		for(int i=0;i<ans.size();i++)
		{
			for(int j=0;j<V[ans[i]].size();j++)
			{
				if(level[V[ans[i]][j]]==0) continue;
				if(level[V[ans[i]][j]]==level[ans[i]]-1) continue;
				
				if(level[V[ans[i]][j]] < level[ans[i]])
				{
					int k = 1 + level[ans[i]] - level[V[ans[i]][j]];
					if(t>k)
					{
						t = k;
						P = std::make_pair(V[ans[i]][j],i);
					}
				}
			}
		}
		if(t<=c)
		{
			printf("2\n%d\n",t);
			for(int i=P.second;;i--)
			{
				printf("%d ",ans[i]);
				if(ans[i]==P.first) break;
			}
		}
		else
		{
			printf("1\n");
			int count = 0;
			for(int i=P.second;;i-=2)
			{
				count++;
				printf("%d ",ans[i]);
				if(count>=(c+1)/2) break;
			}
		}
	}
}

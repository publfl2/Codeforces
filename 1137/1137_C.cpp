#include <stdio.h>
#include <vector>

std::vector<int> V[100010];
int check[100010][60],c;
void func(int s, int t)
{
	if(check[s][t]>=1) return;
	check[s][t] = 1;
	for(int i=0;i<V[s].size();i++) func(V[s][i],(t+1)%c);
	check[s][t] = 2;
}

char x[100010][60];
std::vector<int> ans;
int main()
{
	int a,b;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=b;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		V[d].push_back(e);
	}
	for(int i=1;i<=a;i++) scanf("%s",x[i]);
	
	func(1,0);
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(x[i][j]=='1' && check[i][j]>0)
			{
				ans.push_back(i);
				break;
			}
		}
	}
	printf("%d",ans.size());
}

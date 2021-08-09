#include <stdio.h>

void func(int k ,int c)
{
	check[k] = c;
	for(int i=0;i<V[k].size();i++)
	{
		if(flag[color[V[k][i]]]==1)
		{
			if(check[V[k][i]]==0) func(V[k][i],(c%2)+1);
			else
			{
				int C = check[V[k][i]];
				if(C==check[k]) return 0;
			}
		}
	}
	return 1;
}
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&color[i]);
	for(int i=1;i<=a;i++) save[color[i]].push_back(i);
	for(int j=1;j<=b;j++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		V[d].push_back(e);
		V[e].push_back(d);
		if(color[d]==color[e])
		{
			temp.push_back(d);
			//temp.push_back(e);
		}
	}
	
	int s = a;
	for(int i=1;i<=a;i++)
	{
		flag[i] = 1;
		for(int j=0;j<save[i].size();j++)
		{
			if(check[save[i][j]]==0)
			{
				int C = func(save[i][j],1);
				if(C==0)
				{
					s--;
					break;
				}
			}
		}
		flag[i] = 0;
	}
	long long int ans = (long long int)s*(s-1)/2;
	for(int i=0;i<temp.size();i++)
	{
		
	}
}

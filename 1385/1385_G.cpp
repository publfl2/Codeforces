#include <stdio.h>
#include <vector>

int check[200010];
std::vector<int> V[3][200010];
int x[3][200010];
int count[200010];
std::vector<int> ans,U3;

void func(int type, int k, std::vector<int>& U)
{
	if(check[k]==1) return;
	check[k] = 1;
	
	if(V[type][x[type][k]].size()!=2) return;
	else
	{
		int s0 = V[type][x[type][k]][0];
		int t0 = V[type][x[type][k]][1];
		if(s0==k)
		{
			if(check[t0]==1) return;
			func(3-type,t0,U);
			U.push_back(t0);
		}
		else
		{
			if(check[s0]==1) return;
			func(3-type,s0,U);
			U.push_back(s0);
		}
	}
}

void swap(int k)
{
	int S = x[1][k], T = x[2][k];
	std::vector<int> temp;
	for(int i=0;i<V[1][S].size();i++) temp.push_back(V[1][S][i]);
	V[1][S].clear();
	for(int i=0;i<temp.size();i++) if(temp[i]!=k) V[1][S].push_back(temp[i]);
	temp.clear();
	
	for(int i=0;i<V[2][T].size();i++) temp.push_back(V[2][T][i]);
	V[2][T].clear();
	for(int i=0;i<temp.size();i++) if(temp[i]!=k) V[2][T].push_back(temp[i]);
	temp.clear();
	x[1][k] = T, x[2][k] = S;
	V[1][T].push_back(k);
	V[2][S].push_back(k);
	
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		ans.clear();
		scanf("%d",&a);
		for(int i=1;i<=a;i++) count[i] = 0;
		for(int i=1;i<=a;i++) V[1][i].clear();
		for(int i=1;i<=a;i++) V[2][i].clear();
		for(int i=1;i<=a;i++) check[i] = 0;
		
		
		for(int i=1;i<=a;i++) scanf("%d",&x[1][i]);
		for(int i=1;i<=a;i++) scanf("%d",&x[2][i]);
		for(int i=1;i<=a;i++) count[x[1][i]]++, count[x[2][i]]++;
		for(int i=1;i<=a;i++)
		{
			if(count[i]!=2)
			{
				printf("-1\n");
				goto u;
			}
		}
		
		for(int i=1;i<=a;i++) V[1][x[1][i]].push_back(i);
		for(int i=1;i<=a;i++) V[2][x[2][i]].push_back(i);
		
		for(int i=1;i<=a;i++)
		{
			if(check[i]==0)
			{
				std::vector<int> U1,U2;
				func(1,i,U1);
				check[i] = 0;
				func(2,i,U2);
				
				U3.clear();
				for(int i=U1.size()-1;i>=0;i--) U3.push_back(U1[i]);
				U3.push_back(i);
				for(int i=0;i<U2.size();i++) U3.push_back(U2[i]);
				for(int i=1;i<U3.size();i+=2) ans.push_back(U3[i]);
				if(U3.size()%2==0) swap(U3[U3.size()-1]),check[U3[U3.size()-1]]=0;
			}
		}
		
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		printf("\n");
		u:;
	}
}

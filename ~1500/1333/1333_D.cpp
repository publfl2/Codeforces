#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > V,V2;

int check[3010][3010],check2[3010][3010];
char x[3010];
int y[3010];
int locate[3010],next[3010];
int func(std::pair<int,int> P)
{
	int a = P.first;
	int b = P.second;
	return locate[a] + (b-y[next[locate[a]]]);
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	
	int count1=0,count2=0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='L') y[i]=++count1;
		else y[i]=++count2;
	}
	
	int L = 0, R = 12345678;
	for(int i=1;i<a;i++)
	{
		if(x[i]=='R'&&x[i+1]=='L')
		{
			check2[y[i]][y[i+1]] = 1;
			R = R<y[i]?R:y[i];
			L = L>y[i+1]?L:y[i+1];
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='L')
		{
			for(int j=i-1;j>=1;j--)
			{
				if(x[j]=='L') break;
				next[j] = i;
			}
		}
	}
	for(int i=1;i<=a;i++) if(x[i]=='R') locate[y[i]] = i;
	
	if(L==0)
	{
		printf("-1");
		return 0;
	}
	int p = 0;
	V.push_back(std::make_pair(R,L));
	check[R][L] = 1;
	
	while(p<V.size())
	{
		int s = V[p].first;
		int t = V[p].second;
		if(check2[s][t])
		{
			p++;
			continue;
		}
		if(s<count1 && check[s+1][t]==0) V.push_back(std::make_pair(s+1,t)), check[s+1][t] = 1;
		if(t>1 && check[s][t-1]==0) V.push_back(std::make_pair(s,t-1)), check[s][t-1] = 1;
		p++;
	}
	
	int sum = 0;
	for(int i=V.size()-1;i>=0;i--)
	{
		if(b-sum>i+1)
		{
			printf("-1");
			return 0;
		}
		if(b-sum==i+1)
		{
			if(!V2.empty())
			{
				printf("%d ",V2.size());
				for(int j=0;j<V2.size();j++) printf("%d ",func(V2[j]));
				printf("\n");
				V2.clear();
			}
			printf("1 %d\n",func(V[i]));
			sum++;
		}
		else
		{
			if(V2.empty())
			{
				sum++;
				V2.push_back(V[i]);
			}
			else
			{
				if(V2[0].second-V2[0].first == V[i].second - V[i].first) V2.push_back(V[i]);
				else
				{
					printf("%d ",V2.size());
					for(int j=0;j<V2.size();j++) printf("%d ",func(V2[j]));
					printf("\n");
					V2.clear();
					
					sum++;
					V2.push_back(V[i]);
				}
			}
		}
	}
}

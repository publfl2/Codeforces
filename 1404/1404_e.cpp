#include <stdio.h>
#include <vector>
#include <map>

std::map<int,int> check[210][210][210];

int check2[16000010];
int sum[16000010];
std::vector<int> V[16000010];
int func(int k, int prev)
{
	if(check2[k]) return 0;
	check2[k] = 1;
	int ans = sum[k];
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		ans += func(V[k][i],k);
	}
	return ans;
}

char x[210][210],y[210];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) x[i][j] = '.';
	for(int i=1;i<=a;i++)
	{
		scanf("%s",y+1);
		for(int j=1;j<=b;j++) x[i][j] = y[j];
	}
	
	int p = 1;
	int count = 0;
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) if(x[i][j]=='#') count++;
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='#')
			{
				if(x[i+1][j]=='#') check[i][j][i+1][j] = p++;
				if(x[i][j+1]=='#') check[i][j][i][j+1] = p++;
			}
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='#')
			{
				std::vector<int> V1,V2;
				if(x[i+1][j]=='#') V1.push_back(check[i][j][i+1][j]);
				if(x[i-1][j]=='#') V1.push_back(check[i-1][j][i][j]);
				
				if(x[i][j+1]=='#') V2.push_back(check[i][j][i][j+1]);
				if(x[i][j-1]=='#') V2.push_back(check[i][j-1][i][j]);
				for(int k1=0;k1<V1.size();k1++)
				{
					for(int k2=0;k2<V2.size();k2++)
					{
						V[V1[k1]].push_back(V2[k2]+p);
						V[V2[k2]+p].push_back(V1[k1]);
						
						V[V2[k2]].push_back(V1[k1]+p);
						V[V1[k1]+p].push_back(V2[k2]);
					}
				}
			}
		}
	}
	for(int i=1;i<p;i++) sum[i] = 1;
	
	printf("!!\n");
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		if(check2[i]) continue;
		int s1 = func(i,0);
		int s2 = func(i+p,0);
		ans += (s1>s2?s1:s2);
	}
	printf("%d",count-ans);
}

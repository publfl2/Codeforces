#include <stdio.h>
#include <vector>

std::vector< std::vector<char> > x,y;
std::vector< std::vector< std::vector< int > > > z;
std::vector< std::vector< std::pair< std::pair<int,int> , int> > > check;
std::vector< std::vector<int> > check2,period,end;

std::pair< std::pair<int,int> ,int> func(int s, int t, int c)
{
	printf("%d %d %d!!\n",s,t,c);
	
	if(check[s][t].second>0) return check[s][t];
	if(check2[s][t]&&end[s][t]==0) period[s][t] = c - check2[s][t], end[s][t] = 1;
	if(end[s][t]) return std::make_pair( std::make_pair(s,t),0);
	
	check2[s][t] = c;
	
	std::pair< std::pair<int,int> , int> A;
	if(y[s][t]=='U') A = func(s-1,t,c+1);
	if(y[s][t]=='R') A = func(s,t+1,c+1);
	if(y[s][t]=='D') A = func(s+1,t,c+1);
	if(y[s][t]=='L') A = func(s,t-1,c+1);
	return check[s][t] = std::make_pair(A.first,A.second+1);
}

char S[1000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		x.clear(),y.clear(),z.clear();
		check2.clear(),period.clear(),end.clear(),check.clear();
		
		int a,b;
		scanf("%d%d",&a,&b);
		x.resize(a+1), y.resize(a+1), z.resize(a+1);
		for(int i=1;i<=a;i++) z[i].resize(b+1);
		check2.resize(a+1),period.resize(a+1),end.resize(a+1);
		for(int i=1;i<=a;i++) check2[i].resize(b+1), period[i].resize(b+1), end[i].resize(b+1);
		check.resize(a+1);
		for(int i=1;i<=a;i++) check[i].resize(b+1);
		
		for(int i=1;i<=a;i++)
		{
			scanf("%s",S+1);
			x[i].push_back(0);
			for(int j=1;j<=b;j++) x[i].push_back(S[j]);
		}
		for(int i=1;i<=a;i++)
		{
			scanf("%s",S+1);
			y[i].push_back(0);
			for(int j=1;j<=b;j++) y[i].push_back(S[j]);
		}
		
		int s1=0, s2=0;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				int x1 = func(i,j,1).first.first;
				int y1 = func(i,j,1).first.second;
				int dist = func(i,j,1).second;
				printf("1\n");
				if(z[x1][y1].size()==0) for(int k=0;k<=period[x1][y1];k++) z[x1][y1].push_back(0);
				printf("2\n");
				if(x[i][j]=='0')
				{
					printf("%d %d %d %d!!\n",x1,y1,dist,period[x1][y1]);
					if(z[x1][y1][dist%period[x1][y1]]==0)
					{
						s1++;
						z[x1][y1][dist%period[x1][y1]] = 1;
					}
				}
				else if(x[x1][y1]=='1')
				{
					if(z[x1][y1][dist%period[x1][y1]]==0)
					{
						s1++,s2++;
						z[x1][y1][dist%period[x1][y1]] = 2;
					}
					else if(z[x1][y1][dist%period[x1][y1]]==1)
					{
						s2++;
						z[x1][y1][dist%period[x1][y1]] = 2;
					}
				}
			}
		}
		printf("%d %d\n",s1,s2);
	}
}

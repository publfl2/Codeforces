#include <stdio.h>
#include <algorithm>
#include <string.h>
char x[110][110],y[110];
int z[10];
std::pair<int,int> dire[5];
std::pair<int,int> S,E;
int main()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
	for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) x[i][j] = '#';
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='S') S = std::make_pair(i,j);
			if(x[i][j]=='E') E = std::make_pair(i,j);
		}
	}
	scanf("%s",y+1);
	c = strlen(y+1);
	z[0] = 0, z[1] = 1, z[2] = 2, z[3] = 3;
	dire[0] = std::make_pair(0,1);
	dire[1] = std::make_pair(0,-1);
	dire[2] = std::make_pair(1,0);
	dire[3] = std::make_pair(-1,0);
	int count = 0;
	do{
		std::pair<int,int> P = S;
		for(int i=1;i<=c;i++)
		{
			P.first+=dire[z[y[i]-'0']].first;
			P.second+=dire[z[y[i]-'0']].second;
			if(x[P.first][P.second]=='#') goto u;
			if(x[P.first][P.second]=='E')
			{
				count++;
				goto u;
			}
		}
		if(x[P.first][P.second]=='E') count++;
		u:;
	}while(std::next_permutation(z,z+4));
	printf("%d",count);
}

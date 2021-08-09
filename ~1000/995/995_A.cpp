#include <stdio.h>
#include <vector>

struct str{
	int x0;
	int y0;
	int z0;
}ans[20010];

std::pair<int,int> S[110],T[110];
int x[10][110];
int check[110];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	x[1][0] = x[2][0] = x[3][0] = x[4][0] = 1;
	x[1][a+1] = x[2][a+1] = x[3][a+1] = x[4][a+1] = 1;
	for(int i=1;i<=4;i++) for(int j=1;j<=a;j++) scanf("%d",&x[i][j]);
	for(int j=1;j<=a;j++) if(x[1][j]>0) T[x[1][j]] = {1,j};
	for(int j=1;j<=a;j++) if(x[2][j]>0) S[x[2][j]] = {2,j};
	for(int j=1;j<=a;j++) if(x[3][j]>0) S[x[3][j]] = {3,j};
	for(int j=1;j<=a;j++) if(x[4][j]>0) T[x[4][j]] = {4,j};
	
	
	for(int i=1;i<=b;i++)
	{
		if(S[i].first==2&&T[i].first==4)
		{
			printf("-1");
			return 0;
		}
		if(S[i].first==3&&T[i].first==1)
		{
			printf("-1");
			return 0;
		}
	}
	
	int count = 0;
	while(1)
	{
		for(int i=1;i<=b;i++)
		{
			if(check[i]) continue;
			if(S[i].second==T[i].second)
			{
				x[S[i].first][S[i].second] = 0;
				ans[count++] = {i,T[i].first,T[i].second};
				check[i] = 1;
				goto v;
			}
			else if(S[i].second<T[i].second)
			{
				int sum = 0;
				for(int j=S[i].second+1;j<=a;j++) if(x[S[i].first][j]>0) sum++;
				if(sum<=a-T[i].second)
				{
					while(1)
					{
						for(int j=S[i].second+1;j<=T[i].second;j++)
						{
							if(x[S[i].first][j]>0&&x[S[i].first][j+1]==0)
							{
								ans[count++] = {x[S[i].first][j],S[i].first,j+1};
								S[x[S[i].first][j]].second++;
								x[S[i].first][j+1] = x[S[i].first][j];
								x[S[i].first][j] = 0;
								goto u1;
							}
						}
						
						for(int j=S[i].second+1;j<=T[i].second;j++) ans[count++] = {i,S[i].first,j};
						ans[count++] = {i,T[i].first,T[i].second};
						x[S[i].first][S[i].second] = 0;
						check[i] = 1;
						break;
						
						u1:;
					}
					goto v;
				}
			}
			else if(S[i].second>T[i].second)
			{
				int sum = 0;
				for(int j=S[i].second-1;j>=1;j--) if(x[S[i].first][j]>0) sum++;
				if(sum<=T[i].second-1)
				{
					while(1)
					{
						for(int j=S[i].second-1;j>=T[i].second;j--)
						{
							if(x[S[i].first][j]>0&&x[S[i].first][j-1]==0)
							{
								ans[count++] = {x[S[i].first][j],S[i].first,j-1};
								S[x[S[i].first][j]].second--;
								x[S[i].first][j-1] = x[S[i].first][j];
								x[S[i].first][j] = 0;
								goto u2;
							}
						}
						
						for(int j=S[i].second-1;j>=T[i].second;j--) ans[count++] = {i,S[i].first,j};
						ans[count++] = {i,T[i].first,T[i].second};
						x[S[i].first][S[i].second] = 0;
						check[i] = 1;
						break;
						
						u2:;
					}
					goto v;
				}
			}
		}
		
		for(int i=1;i<=b;i++)
		{
			if(check[i]==0)
			{
				printf("-1");
				return 0;
			}
		}
		
		printf("%d\n",count);
		for(int i=0;i<count;i++) printf("%d %d %d\n",ans[i].x0,ans[i].y0,ans[i].z0);
		return 0;
		v:;
	}
}

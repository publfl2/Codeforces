#include <stdio.h>
#include <algorithm>
#include <queue>
#define MAX 123456


struct str{
	int x0;
	int y0;
	int type;
	int dist;
};

int a;
int next[11][11];

int direX[10]={1,2,2,1,-1,-2,-2,-1};
int direY[10]={2,1,-1,-2,-2,-1,1,2};
int func(int s, int t, int type) // 1: rook 2 : bishop 3: knight
{
	
	int s1=MAX,s2=MAX,s3=MAX;
	Q.push({s,t,type,0});
	while(!Q.empty())
	{
		int x0 = Q.front().x0;
		int y0 = Q.front().y0;
		int ty = Q.front().type;
		int dist = Q.front().dist;
		Q.pop();
		
		if(dist>=4) continue;
		if(check[x0][y0][ty]) continue;
		check[x0][y0][ty] = 1;
		if(next[x0][y0]==next[s][t]+1)
		{
			if(ty==1) s1 = func(x0,y0,ty)+dist;
			if(ty==2) s2 = func(x0,y0,ty)+dist;
			if(ty==3) s3 = func(x0,y0,ty)+dist;
		}
		
		if()
		
		if(ty!=1) Q.push({x0,y0,1,dist+1});
		if(ty!=2) Q.push({x0,y0,2,dist+1});
		if(ty!=3) Q.push({x0,y0,3,dist+1});
		if(ty==1)
		{
			for(int i=1;i<=a;i++) Q.push({i,y0,1,dist+1});
			for(int i=1;i<=a;i++) Q.push({x0,i,1,dist+1});
		}
		else if(ty==2)
		{
			for(int i=1;i<=a;i++) if(1<=x0+y0-i&&x0+y0-i<=a) Q.push({i,x0+y0-i,2,dist+1});
			for(int i=1;i<=a;i++) if(1<=i-x0+y0&&i-x0+y0<=a) Q.push({i,i-x0+y0,2,dist+1});
		}
		else if(ty==3)
		{
			for(int i=0;i<8;i++)
			{
				if(1<=x0+direX[i]&&x0+direX[i]<=a&&1<=y0+direY[i]&&y0+direY[i]<=a)
				{
					Q.push({x0+direX[i],y0+direY[i],3,dist+1});
				}
			}
		}
	}
	
	int s4,s5,s6;
	s4 = func(P[next[s][t]+1])
}


int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			int b;
			scanf("%d",&b);
			P[b] = std::make_pair(i,j);
			next[i][j] = b;
		}
	}
	
}

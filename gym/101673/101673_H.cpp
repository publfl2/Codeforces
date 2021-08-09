#include <stdio.h>


char x[110][110];
int check[110][110];

int direx[10]={0,1,1,1,0,-1,-1,-1};
int direy[10]={1,1,0,-1,-1,-1,0,1};
void func(int s, int t, int color)
{
	check[s][t] = color;
	for(int i=0;i<8;i++)
	{
		int s0 = s+direx[i];
		int t0 = t+direy[i];
		if(check[s0][t0]==0&&x[s0][t0]=='#') func(s0,t0,color);
	}
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	
	int c = 1;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='#')
			{
				if(check[i][j]==0)
				{
					func(i,j,c++);
				}
			}
		}
	}
	printf("%d",c-1);
}

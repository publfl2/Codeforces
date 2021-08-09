#include <stdio.h>
#include <vector>

int direX[10]={0,1,1,1,0,-1,-1,-1},direY[10]={1,1,0,-1,-1,-1,0,1};
int control = 0;
std::vector<char> x[1000010];
std::vector<int> check[1000010],check2[1000010];

void func(int s, int t, int C)
{
	if(check[s][t]!=0)
	{
		if(check[s][t]!=C) control = 1;
		return;
	}
	
	check[s][t] = C;
	for(int i=0;i<8;i++) if(x[s+direX[i]][t+direY[i]]=='#') func(s+direX[i],t+direY[i],C);
}

int a,b;
int func2(int s, int t)
{
	if(s==a&&t==b) return 1;
	if(check2[s][t]) return check2[s][t];
	
	if(x[s][t+1]=='.' && func2(s,t+1)==1) return check2[s][t] = 1;
	if(x[s+1][t]=='.' && func2(s+1,t)==1) return check2[s][t] = 1;
	else return check2[s][t] = 2;
}

char y[1000010];
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) check[i].push_back(0),check2[i].push_back(0);
	for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) x[i].push_back(0);
	
	for(int i=1;i<=a;i++)
	{
		scanf("%s",y+1);
		for(int j=1;j<=b;j++) x[i][j] = y[j];
	}
	
	if(func2(1,1)==2)
	{
		printf("0");
		return 0;
	}
	
	for(int j=1;j<=b;j++) check[0][j] = 1;
	for(int i=1;i<=a;i++) check[i][b+1] = 1;
	for(int j=1;j<=b;j++) check[a+1][j] = 2;
	for(int i=1;i<=a;i++) check[i][0] = 2;
	
	for(int j=1;j<=b;j++) if(x[1][j]=='#') func(1,j,1);
	for(int i=1;i<=a;i++) if(x[i][b]=='#') func(i,b,1);
	for(int j=1;j<=b;j++) if(x[a][j]=='#') func(a,j,2);
	for(int i=1;i<=a;i++) if(x[i][1]=='#') func(i,1,2);
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(i==1&&j==1) continue;
			if(i==a&&j==b) continue;
			if(check2[i][j]==2) continue;
			
			int s1 = 0, s2 = 0;
			for(int k=0;k<8;k++)
			{
				if(check[i+direX[k]][j+direY[k]]==1) s1++;
				if(check[i+direX[k]][j+direY[k]]==2) s2++;
			}
			if(s1>0&&s2>0)
			{
				printf("1");
				return 0;
			}
		}
	}
	printf("2");
}

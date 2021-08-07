#include <stdio.h>

int state[6][6];
int x[6][1010][1010];
char y[100010];
int main()
{
	state[1][1] = 2;
	state[1][2] = 3;
	state[2][1] = 1;
	state[2][2] = 4;
	state[3][1] = 5;
	state[3][2] = 1;
	state[4][1] = 3;
	state[4][2] = 2;
	state[5][1] = 3;
	state[5][2] = 2;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) scanf("%d",&x[1][i][j]);
		
		//L
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) x[2][i][x[1][i][j]] = j;
		//R
		for(int j=1;j<=a;j++) for(int i=1;i<=a;i++) x[3][x[1][i][j]][j] = i;
		//LR
		for(int j=1;j<=a;j++) for(int i=1;i<=a;i++) x[4][x[2][i][j]][j] = i;
		//RL
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) x[5][i][x[3][i][j]] = j;
		
		int S = 1;
		int L = 0, U = 0;
		int count = 0;
		scanf("%s",y+1);
		for(int i=1;i<=b;i++)
		{
			if(y[i]=='L') L++;
			if(y[i]=='R') L--;
			if(y[i]=='D') U--;
			if(y[i]=='U') U++;
			if(y[i]=='I')
			{
				S = state[S][1];
				count += L;
			}
			if(y[i]=='C')
			{
				S = state[S][2];
				count += U;
			}
			L = (L+a)%a, U = (U+a)%a, count = (count+a)%a;
		}
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				//printf("%d %d : %d %d??\n",i,j,(i-U-1+a)%a+1,(j-L-1+a)%a+1);
				printf("%d ",(x[S][(i+U-1+a)%a+1][(j+L-1+a)%a+1]+count-1+a)%a+1);
			}
			printf("\n");
		}
		printf("\n");
	}
}

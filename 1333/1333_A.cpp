#include <stdio.h>

char x[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) x[i][j] = 'W';
		if(a>=3)
		{
			for(int i=1;i<=b;i++) x[1][i] = 'B';
			x[2][1] = 'B';
		}
		else
		{
			for(int i=1;i<=a;i++) x[i][1] = 'B';
			x[1][2] = 'B';
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++) printf("%c",x[i][j]);
			printf("\n");
		}
	}
}

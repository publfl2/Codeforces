#include <stdio.h>

char x[310][310];
int count[310][310];

int main()
{
	for(int i=0;i<=300;i++) x[0][i] = '.';
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		
		if(a<=2)
		{
			for(int i=1;i<=a;i++) printf("%s\n",x[i]+1);
			continue;
		}
		int C = 0;
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				if(count[i][j]==2)
				{
					if(x[i][j]=='X') x[i][j] = 'O';
					else if(x[i][j]=='O') x[i][j] = 'X';
					check[i][j] = 1;
				}
			}
		}
		
		printf("%d!!\n",C);
		for(int i=1;i<=a;i++) printf("%s\n",x[i]+1);
	}
}

#include <stdio.h>

char x[510][510],ans[510][510];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		if(b==1)
		{
			for(int i=1;i<=a;i++) printf("X\n");
			continue;
		}
		
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) ans[i][j] = '.';
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(x[i][j]=='X') ans[i][j] = 'X';
		
		for(int i=1;i<=a;i+=2) for(int j=1;j<=b;j++) ans[i][j] = 'X';
		
		int left = 1;
		for(int i=2;i<a;i+=2)
		{
			int count = 0;
			for(int j=1;j<=b;j++) if(x[i][j]=='X') count++;
			if(count==0)
			{
				ans[i][1] = 'X';
				left = 1;
			}
			else if(count==1) left = 1;
			else if(count>=2)
			{
				int control = 0;
				for(int j=1;j<=b;j++)
				{
					if(x[i][j]=='X')
					{
						if(control==0) control = 1;
						else if(control==1)
						{
							if(x[i-2][j-1]=='X'||x[i-1][j-1]=='X')
							{
								ans[i-1][j] = '.';
								control = 0;
							}
							else ans[i-1][j-1] = '.';
						}
					}
				}
				if(control==0)
				{
					if(left==0) left = 1;
					else
					{
						if(x[i][b-1]=='X')
						{
							ans[i+1][b] = '.';
							ans[i][b] = 'X';
							left = 0;
						}
						else if(x[i][b]=='X');
						else ans[i][b] = 'X';
					}
				}
				else left = 1;
			}
		}
		if(a%2==0 && x[a][b]=='X'&&left==0)
		{
			if(x[a][b-2]=='X')
			{
				ans[a-1][b-1] = '.';
				ans[a][b-1] = 'X';
				ans[a-1][b] = 'X';
			}
			else ans[a][b-1] = 'X';
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++) printf("%c",ans[i][j]);
			printf("\n");
		}
	}
}
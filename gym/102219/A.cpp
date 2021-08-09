#include <stdio.h>
#include <string.h>

char x[1010][1010],y[1010][1010];
char b[10010];
int main()
{
	int a;
	scanf("%d%s",&a,b+1);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	
	int c = strlen(b+1);
	int count = 0;
	for(int i=1;i<=c;i++)
	{
		if(b[i]=='L') count += 3;
		else count += 1;
	}
	count %=4;
	
	while(count--)
	{
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++)
			{
				if(x[i][j]=='>') y[j][a-i+1] = 'v';
				if(x[i][j]=='v') y[j][a-i+1] = '<';
				if(x[i][j]=='<') y[j][a-i+1] = '^';
				if(x[i][j]=='^') y[j][a-i+1] = '>';
				if(x[i][j]=='.') y[j][a-i+1] = '.';
			}
		}
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) x[i][j] = y[i][j];
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++) printf("%c",x[i][j]);
		printf("\n");
	}
}

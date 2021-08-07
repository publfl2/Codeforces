#include <stdio.h>
#include <string.h>

char x[110][110];
int main()
{
	for(int i=1;i<=3;i++) scanf("%s",x[i]+1);
	
	int s,t;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=10;j++)
		{
			if(x[i][j]=='=')
			{
				s = i;
				t = j;
			}
		}
	}
	
	for(int j=t+1;j<=10;j++)
	{
		if(x[s][j]!='.')
		{
			printf("%c",x[s][j]);
			return 0;
		}
	}
	printf("You shall pass!!!");
}

#include <stdio.h>

char x[110][110];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	for(int i=0;i<64;i++)
	{
		scanf("%s",x[i]);
	}
	for(int i=0;i<64;i++)
	{
		printf("{");
		for(int j=0;j<63;j++)
		{
			printf("%d,",x[i][j]-'0');
		}
		printf("%d},\n",x[i][63]-'0');
	}
}

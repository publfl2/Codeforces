#include <stdio.h>
#include <string.h>

char x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",x+1,y+1);
		int a = strlen(x+1);
		if(x[(a+1)/2]!=y[(a+1)/2])
		{
			printf("-1\n");
			continue;
		}
		
		int ans = 0;
		int isFlip = 0;
		for(int i=1;i<(a+1)/2;i++)
		{
			if(isFlip==0)
			{
				if(x[i]==y[i]&&x[a+1-i]==y[a+1-i]);
				else if(x[i]==y[a+1-i]&&y[i]==x[a+1-i])
				{
					isFlip = 1;
					ans++;
				}
				else
				{
					printf("-1\n");
					goto u;
				}
			}
			else
			{
				if(x[i]==y[a+1-i]&&y[i]==x[a+1-i]);
				else if(x[i]==y[i]&&x[a+1-i]==y[a+1-i])
				{
					isFlip = 0;
					ans++;
				}
				else
				{
					printf("-1\n");
					goto u;
				}
			}
		}
		
		printf("%d\n",ans);
		u:;
	}
}

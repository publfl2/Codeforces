#include <stdio.h>

int ans[1010][1010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(c==1)
	{
		if(b==1)
		{
			if(a==1)
			{
				printf("YES\n");
				printf("0");
				return 0;
			}
			if(a<=3)
			{
				printf("NO");
				return 0;
			}
			
			for(int i=1;i<=a;i++)
			{
				for(int j=1;j<=a;j++)
				{
					if(i==j) continue;
					ans[i][j] = 1;
				}
			}
			for(int i=2;i<=a-1;i++)
			{
				ans[1][i] = 0;
				ans[i][1] = 0;
			}
			ans[a][a-1] = 0;
			ans[a-1][a] = 0;
		}
		else
		{
			for(int i=1;i<=a-b+1;i++)
			{
				for(int j=1;j<=a-b+1;j++)
				{
					if(i==j) continue;
					ans[i][j] = 1;
				}
			}
		}
	}
	else
	{
		if(b!=1)
		{
			printf("NO");
			return 0;
		}
		else
		{
			for(int i=1;i<=a;i++)
			{
				for(int j=1;j<=a;j++)
				{
					if(i==j) continue;
					ans[i][j] = 1;
				}
			}
			for(int i=2;i<=a-c+1;i++)
			{
				ans[1][i] = 0;
				ans[i][1] = 0;
			}
		}
	}
	
	printf("YES\n");
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++) printf("%d",ans[i][j]);
		printf("\n");
	}
}

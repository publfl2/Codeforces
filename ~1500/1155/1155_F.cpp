#include <stdio.h>

int start,a;
int check[20];
int x[20][20];
int func(int k, int prev)
{
	if(check[k]) return 0;
	check[k] = 1;
	for(int i=1;i<=a;i++)
	{
		if(i==prev) continue;
		if(x[k][i]==1)
		{
			if(i==start) return 1;
			
			int t = func(i,k);
			if(t==1) return 1;
		}
	}
	return 0;
}
int main()
{
	int b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		x[c][d] = x[d][c] = 1;
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(x[i][j]==1)
			{
				x[i][j] = x[j][i] = 0;
				for(int k=1;k<=a;k++)
				{
					for(int l=1;l<=a;l++) check[l] = 0;
					start = k;
					if(func(k,0)==0)
					{
						x[i][j] = x[j][i] = 1;
						goto u;
					}
				}
				u:;
			}
		}
	}
	
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			count += x[i][j];
		}
	}
	printf("%d\n",count);
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			if(x[i][j]==1) printf("%d %d\n",i,j);
		}
	}
}

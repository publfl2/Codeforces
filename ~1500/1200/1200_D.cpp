#include <stdio.h>

int s1[2010][2010],s2[2010][2010],check[2010][2010];
int count[2010];

int row_sum(int k, int s, int t)
{
	return s1[k][t]-s1[k][s-1];
}
int col_sum(int k, int s, int t)
{
	return s2[t][k] - s2[s-1][k];
}

int y1[2010],y2[2010],z1[2010],z2[2010];
char x[2010][2010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(x[i][j]=='W') s1[i][j] = s1[i][j-1] + 1;
			else s1[i][j] = s1[i][j-1];
		}
	}
	for(int j=1;j<=a;j++)
	{
		for(int i=1;i<=a;i++)
		{
			if(x[i][j]=='W') s2[i][j] = s2[i-1][j] + 1;
			else s2[i][j] = s2[i-1][j];
		}
	}
	
	for(int j=1;j<=a-b+1;j++)
	{
		for(int i=1;i<=a;i++) count[i] = 0;
		int sum = 0;
		
		for(int i=1;i<=b;i++)
		{
			if(row_sum(i,1,j-1)+row_sum(i,j+b,a)==a-b) count[i] = 1, sum++;
			else count[i] = 0;
		}
		check[1][j] += sum;
		for(int i=b+1;i<=a;i++)
		{
			sum -= count[i-b];
			if(row_sum(i,1,j-1)+row_sum(i,j+b,a)==a-b) count[i] = 1, sum++;
			else count[i] = 0;
			check[i-b+1][j] += sum;
		}
	}
	
	for(int i=1;i<=a-b+1;i++)
	{
		for(int j=1;j<=a;j++) count[j] = 0;
		int sum = 0;
		
		for(int j=1;j<=b;j++)
		{
			if(col_sum(j,1,i-1)+col_sum(j,i+b,a)==a-b) count[j] = 1, sum++;
			else count[j] = 0;
		}
		check[i][1] += sum;
		for(int j=b+1;j<=a;j++)
		{
			sum -= count[j-b];
			if(row_sum(j,1,i-1)+row_sum(j,i+b,a)==a-b) count[j] = 1, sum++;
			else count[j] = 0;
			check[i][j-b+1] += sum;
		}
	}
	
	for(int i=1;i<=a;i++) if(row_sum(i,1,a)==a) y1[i] = 1;
	for(int j=1;j<=a;j++) if(col_sum(j,1,a)==a) z1[j] = 1;
	for(int i=1;i<=a;i++) y2[i] = y2[i-1] + y1[i];
	for(int j=1;j<=a;j++) z2[j] = z2[j-1] + z1[j];
	
	
	for(int i=1;i<=a-b+1;i++)
	{
		for(int j=1;j<=a-b+1;j++)
		{
			check[i][j] += (y2[i-1] - y2[0]);
			check[i][j] += (z2[j-1] - z2[0]);
			check[i][j] += (y2[a] - y2[i+b-1]);
			check[i][j] += (z2[a] - z2[j+b-1]);
		}
	}
	
	int ans = 0;
	for(int i=1;i<=a-b+1;i++) for(int j=1;j<=a-b+1;j++) ans = ans>check[i][j]?ans:check[i][j];
	printf("%d",ans);
}

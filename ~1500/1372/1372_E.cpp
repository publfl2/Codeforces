#include <stdio.h>

int a,b;
int check[110];
int right[110][110];
int func(int k)
{
	if(check[k]!=-1) return check[k];
	
	int count[110]={};
	int limit = b;
	for(int i=1;i<=a;i++) limit = limit<right[i][right[i][k]+1]?limit:right[i][right[i][k]+1];
	
	for(int i=1;i<=a;i++) for(int j = right[i][k]+1;j<=right[i][right[i][k]+1];j++) count[j]++;
	
	int ans = 0;
	for(int j=k+1;j<=limit;j++)
	{
		int S = func(j) + count[j]*count[j];
		ans = ans>S?ans:S;
	}
	return check[k] = ans;
}
int main()
{
	scanf("%d%d",&a,&b);
	for(int j=0;j<=b+1;j++) check[j] = -1;
	
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		for(int j=1;j<=c;j++)
		{
			int d,e;
			scanf("%d%d",&d,&e);
			for(int k=d;k<=e;k++) right[i][k] = e;
		}
		right[i][b+1] = b+1;
	}
	
	printf("%d",func(1)+a*a);
}

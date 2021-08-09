#include <stdio.h>

int x[5010];
int a;
int check[5010][10];

int func(int s, int t)
{
	int ans = 0;
	if(check[s][t]!=-1) return check[s][t];
	if(t==0)
	{
		if(x[s]<x[s+1]) return func(s+1,1)+1;
		else return 1;
	}
	else if(t==1)
	{
		if(x[s]>x[s+1]) return func(s+1,0)+1;
		else return 1;
	}
	return check[s][t] = ans;
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=0;i<=a;i++) check[i][0] = check[i][1] = -1;
	
	int ans = 2;
	for(int i=1;i<=a;i++)
	{
		int s = func(i,1);
		int t = func(i,0);
		ans = ans>s?ans:s;
		ans = ans>t?ans:t;
	}
	printf("%d",ans);
}

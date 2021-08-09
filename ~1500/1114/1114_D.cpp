#include <stdio.h>

int a;
int x[5010],end[5010],next[5010],y[5010];
int check[5010][5010];
int func(int s, int t)
{
	if(s>t) return 12345678;
	if(end[s]==end[t]) return 0;
	
	if(check[s][t]!=-1) return check[s][t];
	int s1;
	if(next[s]!=0) s1 = func(end[s]+1,next[s]-1) + 1 + func(next[s],t);
	else s1 = 12345678;
	int s2 = func(end[s]+1,t) + 1;
	return check[s][t] = s1<s2?s1:s2;
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) check[i][j] = -1;
	for(int i=a;i>=1;i--)
	{
		if(x[i]!=x[i+1])
		{
			end[i] = i;
			next[i] = y[x[i]];
		}
		else
		{
			end[i] = end[i+1];
			next[i] = next[i+1];
		}
		y[x[i]] = i;
	}
	
	printf("%d",func(1,a));
}

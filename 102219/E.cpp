#include <stdio.h>

int b;
int x[1010],select[1010][1010],check[1010][1010];
int func(int s, int t)
{
	if(s>b) return 0;
	if(check[s][t]!=-1) return check[s][t];
	if(t<x[s])
	{
		select[s][t] = -1;
		return check[s][t] = func(s+1,t);
	}
	int s1 = func(s+1,t-x[s])+x[s];
	int s2 = func(s+1,t);
	if(s1>=s2)
	{
		select[s][t] = 1;
		return check[s][t] = s1;
	}
	else if(s1<s2)
	{
		select[s][t] = -1;
		return check[s][t] = s2;
	}
}
int main()
{
	while(1)
	{
		int a;
		scanf("%d",&a);
		if(a==0) break;
		else scanf("%d",&b);
		for(int i=1;i<=b;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=b;i++) for(int j=0;j<=a;j++) check[i][j] = -1;
		int s = func(1,a);
		
		int t0 = a;
		for(int i=1;i<=b;i++)
		{
			if(select[i][t0]==1)
			{
				printf("%d ",x[i]);
				t0-=x[i];
			}
		}
		printf("%d\n",s);
	}
}

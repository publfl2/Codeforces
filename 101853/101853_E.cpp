#include <stdio.h>

int a;
int x[20][20];
int check[20][20][140010];
int func(int s, int t, int bit)
{
	if(s>a) return 0;
	if(t>a) return func(s+1,1,bit);
	if(check[s][t][bit]!=-1) return check[s][t][bit];
	if((bit&(1<<t))>0) return check[s][t][bit] = func(s,t+1,bit-(1<<t));
	else
	{
		int s1 = func(s,t+1,bit);
		int bit1 = bit;
		bit1 |= (1<<t);
		if(t<a) bit1 |= (1<<(t+1));
		if(t>1) bit1 |= (1<<(t-1));
		int s2 = func(s,t+2,bit1) + x[s][t];
		return check[s][t][bit] = s1>s2?s1:s2;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) scanf("%d",&x[i][j]);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) for(int k=0;k<=(1<<(a+1));k++) check[i][j][k] = -1;
		printf("%d\n",func(1,1,0));
	}
}

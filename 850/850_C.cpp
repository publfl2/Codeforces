#include <stdio.h>
int func(int s, int t, int k)
{
	if(s==0&&t==0&&k==0) return 0;
	//printf("%d %d %d?\n",s,t,k);
	int check[110]={};
	for(int i=1;i<=k || i<=s || i<=t;i++)
	{
		int c = func(s<i?s:s-i,t<i?t:t-i,k<i?k:k-i);
		check[c] = 1;
	}
	for(int i=0;i<100;i++) if(check[i]==0) return i;
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=0;i<=a;i++)
	{
		for(int j=i;j<=a;j++)
		{
			for(int k=i;k<=i;k++)
			{
				printf("%d %d %d : %d\n",i,j,k,func(i,j,k));
			}
		}
	}
}

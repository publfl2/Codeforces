#include <stdio.h>

int a;
int p[200010];
int x[200010];
int main()
{
	int b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&p[i]);
	for(int i=1;i<=a;i++) hash[p[i]] = i;
	for(int i=1;i<=b;i++)
	{
		int d;
		scanf("%d",&d);
		x[i] = hash[d];
	}
	
	for(int i=b;i>=1;i--)
	{
		if(x[i]==1)
	}
}

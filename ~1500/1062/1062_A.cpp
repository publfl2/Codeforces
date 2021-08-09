#include <stdio.h>

int x[100100];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	x[0] = x[1]-1;
	
	int p = 0, ans = 0;
	for(int i=1;i<a;i++)
	{
		if(x[i]==x[i-1]+1&&x[i+1]==x[i]+1)
		{
			ans = ans>i-p?ans:i-p;
		}
		else
		{
			p = i;
		}
	}
	printf("%d",ans);
}

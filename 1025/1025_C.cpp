#include <stdio.h>
#include <string.h>


char x[200010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++) x[a+i] = x[i];
	int ans = 1;
	int p = 1;
	for(int i=2;i<=2*a;i++)
	{
		if(x[i]!=x[i-1]) p++;
		else p = 1;
		ans = ans>p?ans:p;
	}
	printf("%d",ans);
}

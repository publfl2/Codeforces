#include <stdio.h>
char x[1010];
int main()
{
	int a;
	scanf("%d\n",&a);
	fgets(x+1,1234,stdin);
	
	int ans = 0;
	int s = 0;
	for(int i=1;i<=a;i++)
	{
		if('A'<=x[i]&&x[i]<='Z') s++;
		else if(x[i]==' ') ans = ans>s?ans:s, s = 0;
	}
	printf("%d",ans>s?ans:s);
}

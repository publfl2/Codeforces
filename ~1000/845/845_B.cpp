#include <stdio.h>
char x[10];
int y[10];
int ans = 10;
void func(int s, int t)
{
	if(s==7)
	{
		if(y[1]+y[2]+y[3]==y[4]+y[5]+y[6]) ans = ans<t?ans:t;
		return;
	}
	for(int i=0;i<=9;i++)
	{
		y[s] = i;
		func(s+1,t+1);
	}
	y[s] = x[s];
	func(s+1,t);
}
int main()
{
	scanf("%s",x+1);
	for(int i=1;i<=6;i++) x[i]-='0';
	func(1,0);
	printf("%d",ans);
}

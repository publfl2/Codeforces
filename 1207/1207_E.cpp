#include <stdio.h>

int main()
{
	int C = 133;
	int a;
	int ans = 0;
	printf("? ");
	for(int i=0;i<100;i++) printf("%d ",128*i+127);
	fflush(stdout);
	a = ((128*37+127)&C);
	//scanf("%d",&a);
	ans += (a&(127));
	
	printf("? ");
	for(int i=0;i<100;i++) printf("%d ",127*128 +i);
	fflush(stdout);
	a = ((127*128+64)&C);
	//scanf("%d",&a);
	ans += (a&(127*128));
	
	printf("! %d",ans);
	fflush(stdout);
}

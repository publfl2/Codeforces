#include <stdio.h>

char x[1000010];

char y[1000010],z[1000010];
int s=1,t=1;
int main()
{
	int a;
	scanf("%d%s",&a,x+1);
	
	int start;
	for(start=1;start<=a;start++) if(x[start]=='0') goto u;
	
	printf("0 0");
	return 0;
	
	u:;
	
	
	
}

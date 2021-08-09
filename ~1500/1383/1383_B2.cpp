#include <stdio.h>

int func(int a, int b, int s, int t)
{
	if(a<0 || b<0) return 1;
	
	if(a==0&&b==0)
	{
		if(s%2==1) return 1;
		else return 0;
	}
	
	int s1 = func(a-1,b,t,s+1);
	int s2 = func(a,b-1,t,s);
	if(s1==0||s2==0) return 1;
	else return 0;
}

int main()
{
	for(int i=1
	;i<=15;i+=2)
	{
		for(int j=0;j<=15;j++) printf("%d ",func(i,j,0,0));
		printf("\n");
	}
}

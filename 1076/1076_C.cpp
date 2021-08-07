#include <stdio.h>
#include <math.h>

void func(int k)
{
	if((k-2)*(k-2)-4<0)
	{
		printf("N\n");
		return;
	}
	else
	{
		double s = sqrt((k-2)*(k-2)-4);
		double t1 = (k-2+s)/2;
		double t2 = (k-2-s)/2;
		if(t1+1>=0&&t2+1>=0) printf("Y %.12lf %.12lf\n",t1+1,t2+1);
		else printf("N\n");
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		int a;
		scanf("%d",&a);
		func(a);
	}
}

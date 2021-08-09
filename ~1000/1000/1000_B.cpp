#include <stdio.h>



int x[100010];
int a;
int check[100010][5];

int func(int s, int t)
{
	if(s==a) return x[a+1]-x[a];
	else if(s>a) return 0;
	
	if(check[s][t]) return check[s][t];
	
	if(t==0)
	{
		int s1,s2,s3;
		if(x[s+1]-1!=x[s]) s1 = (x[s+1]-x[s]-1) + func(s+1,1);
		else s1 = 0;
		if(x[s+2]!=x[s+1]+1) s2 = (x[s+1]-x[s]) + (x[s+2]-x[s+1]-1) + func(s+3,1);
		else s2 = 0;
		s3 = (x[s+1]-x[s]) + func(s+2,0);
		return check[s][t] = s1>s2?s1>s3?s1:s3:s2>s3?s2:s3;
	}
	else if(t==1) return check[s][t] = (x[s+1]-x[s]) + func(s+2,1);
}

int main()
{
	int b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	x[a+1] = b;
	x[0] = 0;
	printf("%d",func(0,0));
}

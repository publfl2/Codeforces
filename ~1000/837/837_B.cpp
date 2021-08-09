#include <stdio.h>
char x[110][110];
int a,b;
bool func1()
{
	int c = a/3;
	if(x[1][1]+x[c+1][1]+x[2*c+1][1]!='R'+'G'+'B') return false;
	for(int k=0;k<=2;k++)
	{
		for(int i=1;i<=c;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(x[k*c+i][j]!=x[k*c+1][1]) return false;
			}
		}
	}
	return true;
}
bool func2()
{
	int c = b/3;
	if(x[1][1]+x[1][c+1]+x[1][2*c+1]!='R'+'G'+'B') return false;
	for(int k=0;k<=2;k++)
	{
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=c;j++)
			{
				if(x[i][k*c+j]!=x[1][k*c+1]) return false;
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	if(a%3==0)
	{
		if(func1())
		{
			printf("YES");
			return 0;
		}
	}
	if(b%3==0)
	{
		if(func2())
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}

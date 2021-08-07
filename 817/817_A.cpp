#include <stdio.h>
int abs(int k)
{
	return k>0?k:-k;
}
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int e,f,g,h;
	e = abs(a-c);
	f = abs(b-d);
	scanf("%d%d",&g,&h);
	if(e%g!=0)
	{
		printf("NO");
		return 0;
	}
	if(f%h!=0)
	{
		printf("NO");
		return 0;
	}
	e/=g, f/=h;
	if((e+f+12345678)%2==0)
	{
		printf("YES");
		return 0;
	}
	else printf("NO");
}

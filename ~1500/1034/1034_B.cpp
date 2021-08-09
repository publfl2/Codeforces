#include <stdio.h>

long long int ans[10][10] = {
	{0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0},
	{0,0,0,4,0,8,8},
	{0,0,4,8,0,14,18},
	{0,0,0,0,0,0,0},
	{0,0,8,14,0,24,28},
	{0,0,8,18,0,28,36}
};
int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	if(a==1||b==1)
	{
		printf("0");
		return 0;
	}
	if(a%4==0||b%4==0) printf("%lld",a*b);
	else
	{
		long long int c,d;
		c = a%4, d = b%4;
		if(c==1) c += 4;
		if(c==2&&a>=6) c+=4;
		if(d==1) d += 4;
		if(d==2&&b>=6) d+=4;
		printf("%lld",a*b-c*d+ans[c][d]);
	}
}

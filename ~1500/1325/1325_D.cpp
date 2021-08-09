#include <stdio.h>

long long int ans[200];
int check1[110],check2[110],check3[110];
int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	if(a==0&&b==0)
	{
		printf("0");
		return 0;
	}
	long long int c = a;
	
	if(a==0&&b==0)
	{
		printf("0");
		return 0;
		
	}
	for(int i=0;i<=60;i++)
	{
		check1[i] = a%2;
		a/=2;
	}
	for(int i=0;i<=60;i++)
	{
		check2[i] = b%2;
		b/=2;
	}
	for(int i=0;i<=60;i++) check3[i] = check2[i] - check1[i];
	if(check3[0]!=0)
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=60;i++)
	{
		if(check3[i]==-1)
		{
			check3[i] += 2;
			check3[i+1]--;
		}
	}
	if(check3[61]==-1)
	{
		printf("-1");
		return 0;
	}
	
	long long int d = 0;
	for(int i=1;i<=60;i++) if(check3[i]==1) d += (1<<(i-1));
	if(d==0)
	{
		printf("1\n");
		printf("%lld",c);
	}
	else if((c&d)==0)
	{
		printf("2\n");
		printf("%lld %lld",c+d,d);
	}
	else
	{
		printf("3\n");
		printf("%lld %lld %lld",c,d,d);
	}
}

#include <stdio.h>
long long int x[100010];
long long int abs(long long int k)
{
	return k>0?k:-k;
}
int main()
{
	long long int a,b,c;
	int d;
	scanf("%I64d%I64d%I64d%d",&a,&b,&c,&d);
	for(int i=1;i<=d;i++) scanf("%I64d",&x[i]);
	if(a==0)
	{
		for(int i=1;i<=d;i++)
		{
			if(x[i]==0)
			{
				printf("0");
				return 0;
			}
		}
		printf("inf");
		return 0;
	}
	if(b==0)
	{
		for(int i=1;i<=d;i++)
		{
			if(x[i]==0)
			{
				if(a==0) printf("0");
				else
				{
					for(int j=1;j<=d;j++)
					{
						if(x[j]==a)
						{
							printf("0");
							return 0;
						}
					}
					if(abs(a)<=c) printf("1");
					else printf("0");
				}
				return 0;
			}
		}
		printf("inf");
		return 0;
	}
	if(b==1)
	{
		if(abs(a)>c)
		{
			printf("0");
			return 0;
		}
		for(int i=1;i<=d;i++)
		{
			if(x[i]==a)
			{
				printf("0");
				return 0;
			}
		}
		printf("inf");
		return 0;
	}
	if(b==-1)
	{
		if(abs(a)>c)
		{
			printf("0");
			return 0;
		}
		int check1 = 0, check2 = 0;
		for(int i=1;i<=d;i++)
		{
			if(x[i]==a)
			{
				check1 = 1;
				break;
			}
		}
		for(int i=1;i<=d;i++)
		{
			if(x[i]==-a)
			{
				check2 = 1;
				break;
			}
		}
		if(check1==1&&check2==1) printf("0");
		else printf("inf");
		return 0;
	}
	
	int count = 0;
	while(1)
	{
		if(abs(a)>c)
		{
			printf("%d",count);
			return 0;
		}
		for(int j=1;j<=d;j++)
		{
			if(x[j]==a)
			{
				goto z;
			}
		}
		count++;
		z:;
		a*=b;
	}
}

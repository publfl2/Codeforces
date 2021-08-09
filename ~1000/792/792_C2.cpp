#include <stdio.h>
#include <string.h>
char x[100010];
int a,y[3];
void print(int k, int s, int t)
{
	for(int i=k;i<=a;i++)
	{
		if((x[i]-'0')%3==s&&t>0) t--;
		else printf("%c",x[i]);
	}
}
int main()
{
	int b = 0;
	scanf("%s",x+1);
	a = strlen(x+1);
	for(int i=1;i<=a;i++) b+=x[i]-'0';
	for(int i=2;i<=a;i++) y[(x[i]-'0')%3]++;
	if(b%3==0)
	{
		print(1,0,0);
		return 0;
	}
	else if(b%3==1)
	{
		if(y[1]>=1)
		{
			printf("%c",x[1]);
			print(2,1,1);
			return 0;
		}
		else if(y[2]>=2)
		{
			printf("%c",x[1]);
			print(2,2,2);
			return 0;
		}
	}
	else if(b%3==2)
	{
		if(y[2]>=1)
		{
			printf("%c",x[1]);
			print(2,2,1);
			return 0;
		}
		else if(y[1]>=2)
		{
			printf("%c",x[1]);
			print(2,1,2);
			return 0;
		}
	}
	
	// 1 except
	int k;
	b = y[0] = y[1] = y[2] = 0;
	for(int i=2;i<=a;i++)
	{
		if(x[i]!='0')
		{
			k = i;
			goto u;
		}
	}
	k = a;
	u:;
	
	for(int i=k;i<=a;i++) b+=x[i]-'0';
	for(int i=k;i<=a;i++) y[(x[i]-'0')%3]++;
	if(b%3==0)
	{
		print(k,0,0);
		return 0;
	}
	else if(b%3==1)
	{
		if(y[1]>=1&&a-k+1!=1)
		{
			print(k,1,1);
			return 0;
		}
		else if(y[2]>=2&&a-k+1!=2)
		{
			print(k,2,2);
			return 0;
		}
	}
	else if(b%3==2)
	{
		if(y[2]>=1&&a-k+1!=1)
		{
			print(k,2,1);
			return 0;
		}
		else if(y[1]>=2&&a-k+1!=2)
		{
			print(k,1,2);
			return 0;
		}
	}
	
	printf("-1");
}

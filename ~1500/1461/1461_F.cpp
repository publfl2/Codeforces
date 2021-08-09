#include <stdio.h>
#include <string.h>
#include <vector>

#define MAX1 1000000
long long int MAX2 = 1;
int x[100010];
char ans[100010];
void func(int L, int R)
{
	if(L>R) return;
	if(x[L]==1)
	{
		ans[L] = '+';
		func(L+1,R);
		return;
	}
	if(x[R]==1)
	{
		ans[R-1] = '+';
		func(L,R-1);
		return;
	}
	
	std::vector<int> V;
	int p = -1;
	for(int i=L;i<=R;i++)
	{
		if(x[i]==1)
		{
			if(p!=-1) V.push_back(p);
			V.push_back(x[i]);
			p = -1;
		}
		else
		{
			if(p==-1) p = x[i];
			else
			{
				p*=x[i];
				if(p>=MAX1) p = MAX1;
			}
		}
	}
	if(p!=-1) V.push_back(p);
	
	for(int i=0;i<V.size();i++)
	{
		
	}
	
	if(type==1) for(int i=L;i<R;i++) ans[i] = '*';
	else
	{
		for(int i=L;i<R;i++)
		{
			if(x[i]>=2&&x[i+1]>=2) ans[i] = '*';
			else ans[i] = '+';
		}
	}
}

char y[5];
int check[5];
int main()
{
	for(int i=1;i<=12;i++) MAX2*=10;
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	scanf("%s",y+1);
	int b = strlen(y+1);
	if(b==1)
	{
		printf("%d",x[1]);
		for(int i=2;i<=a;i++)
		{
			printf("%c",y[1]);
			printf("%d",x[i]);
		}
		return 0;
	}
	else
	{
		for(int i=1;i<=b;i++)
		{
			if(y[i]=='+') check[1] = 1;
			if(y[i]=='-') check[2] = 1;
			if(y[i]=='*') check[3] = 1;
		}
		if(check[1]==1&&check[3]==1)
		{
			int p = 0;
			for(int i=1;i<=a;i++)
			{
				if(x[i]==0)
				{
					ans[p] = '+';
					ans[i-1] = '+';
					func(p+1,i-1);
					p = i;
				}
			}
			ans[p] = '+';
			func(p+1,a);
			for(int i=1;i<a;i++)
			{
				printf("%d",x[i]);
				printf("%c",ans[i]);
			}
			printf("%d",x[a]);
		}
		else if(check[1]==1&&check[2]==1)
		{
			for(int i=1;i<a;i++)
			{
				printf("%d",x[i]);
				printf("+");
			}
			printf("%d",x[a]);
		}
		else
		{
			int limit = a+1;
			for(int i=1;i<=a;i++)
			{
				if(x[i]==0)
				{
					limit = i;
					break;
				}
			}
			for(int i=1;i<=limit-2;i++) ans[i] = '*';
			ans[limit-1] = '-';
			for(int i=limit;i<a;i++) ans[i] = '*';
			
			for(int i=1;i<a;i++)
			{
				printf("%d",x[i]);
				printf("%c",ans[i]);
			}
			printf("%d",x[a]);
		}
	}
}

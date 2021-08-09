#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
char x[100010];
std::vector<char> ans[5];
int a,b,y[3];
void print(int k, int s, int t, int count)
{
	for(int i=k;i<=a;i++)
	{
		if((x[i]-'0')%3==s&&t>0) t--;
		else ans[count].push_back(x[i]);
	}
}
int func(int T, int count)
{
	if(count==0)
	{
		b = 0;
		for(int i=T;i<=a;i++) b+=x[i]-'0';
		if(b%3==0) print(T,0,0,count);
		return 0;
	}
	b = y[0] = y[1] = y[2] = 0;
	for(int i=T;i<=a;i++) b+=x[i]-'0';
	for(int i=T+1;i<=a;i++) y[(x[i]-'0')%3]++;
	if(b%3==0)
	{
		print(T,0,0,count);
		return 0;
	}
	else if(b%3==1)
	{
		if(y[1]>=1)
		{
			ans[count].push_back(x[T]);
			print(T+1,1,1,count);
		}
		else if(y[2]>=2)
		{
			ans[count].push_back(x[T]);
			print(T+1,2,2,count);
		}
	}
	else if(b%3==2)
	{
		if(y[2]>=1)
		{
			ans[count].push_back(x[T]);
			print(T+1,2,1,count);
		}
		else if(y[1]>=2)
		{
			ans[count].push_back(x[T]);
			print(T+1,1,2,count);
		}
	}
	
	// 1 except
	int k;
	b = y[0] = y[1] = y[2] = 0;
	for(int i=T+1;i<=a;i++)
	{
		if(x[i]!='0')
		{
			k = i;
			goto u;
		}
	}
	k = a;
	u:;
	func(k,count-1);
}
int main()
{
	scanf("%s",x+1);
	a = strlen(x+1);
	func(1,2);
	
	int s2 = ans[2].size();
	int s1 = ans[1].size();
	int s0 = ans[0].size();
	if(s1==0&&s2==0&&s0==0)
	{
		printf("-1");
		return 0;
	}
	if(s2>=s1&&s2>=s0)
	{
		for(int i=0;i<ans[2].size();i++) printf("%c",ans[2][i]);
		return 0;
	}
	if(s1>=s2&&s1>=s0)
	{
		for(int i=0;i<ans[1].size();i++) printf("%c",ans[1][i]);
		return 0;
	}
	if(s0>=s1&&s0>=s2)
	{
		for(int i=0;i<ans[0].size();i++) printf("%c",ans[0][i]);
		return 0;
	}
}

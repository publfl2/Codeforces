#include <stdio.h>
#include <stack>
char x[300010];
int next[300010];
long long int check[300010];
int a,b,c;
long long int func(int k)
{
	if(k>a) return 0;
	if(check[k]!=-1) return check[k];
	if(x[k]=='1') return check[k] = func(k+1);
	else
	{
		if(next[k]==a+1) return check[k] = c;
		long long int s1 = func(next[next[k]]) + b;
		long long int s2 = func(next[k]) + c;
		return check[k] = s1<s2?s1:s2;
	}
}
std::stack<int> St;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<=a+1;i++) check[i] = -1;
	scanf("%s",x+1);
	St.push(1);
	for(int i=2;i<=a+1;i++)
	{
		if(x[i-1]!=x[i])
		{
			while(!St.empty())
			{
				next[St.top()] = i;
				St.pop();
			}
		}
		St.push(i);
	}
	printf("%I64d",func(1));
}

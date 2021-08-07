#include <stdio.h>
#include <string.h>
#include <stack>
char x[10010];
std::stack<int> St;
int main()
{
	int a,b;
	scanf("%d",&a);
	scanf("%d\n",&b);
	for(int i=1;i<=b;i++)
	{
		scanf("%s",x+1);
		int c = strlen(x+1);
		if(x[1]=='u')
		{
			int d;
			scanf("%d",&d);
			while(d--) St.pop();
		}
		else if(x[1]=='-')
		{
			int sum = 0;
			for(int j=2;j<=c;j++)
			{
				sum*=10;
				sum+=(x[j]-'0');
			}
			St.push(-sum);
		}
		else
		{
			int sum = 0;
			for(int j=1;j<=c;j++)
			{
				sum*=10;
				sum+=(x[j]-'0');
			}
			St.push(sum);
		}
	}
	int s = 0;
	while(!St.empty())
	{
		s += St.top();
		St.pop();
	}
	s%=a;
	s+=a;
	s%=a;
	printf("%d",s);
}

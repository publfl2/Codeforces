#include <stdio.h>
#include <string.h>
#include <queue>

std::queue<char> Q;
char x[100010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='1') count++;
		else Q.push(x[i]);
	}
	
	int control = 0;
	while(!Q.empty())
	{
		if(Q.front()=='2')
		{
			if(control==0)
			{
				control = 1;
				while(count--) printf("1");
			}
		}
		printf("%c",Q.front());
		Q.pop();
	}
	if(control==0) while(count--) printf("1");
}

#include <stdio.h>
#include <string.h>

char x[100010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	char s = 0;
	char c = 0;
	char sign = 1;
	for(int i=1;i<=a;i++)
	{
		if('1'<=x[i]&&x[i]<='9')
		{
			c*=10;
			c+=x[i];
		}
		else if(x[i]=='+')
		{
			s += c*sign;
			sign = 1;
			c = 0;
		}
		else
		{
			s += c*sign;
			sign = -1;
			c = 0;
		}
	}
	s += c*sign;
	printf("%d",s);
}

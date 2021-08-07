#include <stdio.h>
#include <string.h>

char x[100010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	
	int sum = 0;
	for(int i=1;i<=a;i++) sum += (x[i]-'A');
	sum%=26;
	for(int i=1;i<=a/2;i++)
	{
		int b = x[i]-'A';
		int c = x[i+a/2]-'A';
		printf("%c",(b+c+sum)%26+'A');
	}
}

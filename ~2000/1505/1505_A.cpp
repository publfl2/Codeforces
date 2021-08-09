#include <stdio.h>
#include <string.h>
char x[110];
int main()
{
	while(1)
	{
		fgets(x+1,500,stdin);
		int a = strlen(x+1);
		if(a==0) break;
		printf("NO");
		fflush(stdout);
	}
}
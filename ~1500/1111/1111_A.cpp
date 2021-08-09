#include <stdio.h>
#include <string.h>

char x[100010],y[100010];
int z[500];
int main()
{
	scanf("%s%s",x+1,y+1);
	z['a'] = 1;
	z['e'] = 1;
	z['i'] = 1;
	z['u'] = 1;
	z['o'] = 1;
	int a = strlen(x+1);
	int b = strlen(y+1);
	if(a!=b)
	{
		printf("No");
		return 0;
	}
	for(int i=1;i<=a;i++)
	{
		if(z[x[i]]!=z[y[i]])
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}

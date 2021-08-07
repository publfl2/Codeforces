#include <stdio.h>
char x[110];
int main()
{
	int a,b,s=0;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%d%s",&b,x+1);
		if(x[1]=='N')
		{
			if(s%40000==0)
			{
				printf("NO");
				return 0;
			}
			else s+=(4000000-b),s%=40000;
		}
		else if(x[1]=='S')
		{
			if(s%40000==20000)
			{
				printf("NO");
				return 0;
			}
			else s+=b,s%=40000;
		}
		else
		{
			if(s%20000==0)
			{
				printf("NO");
				return 0;
			}
		}
	}
	if(s%40000==0) printf("YES");
	else printf("NO");
}

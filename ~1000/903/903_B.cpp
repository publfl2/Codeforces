#include <stdio.h>

int x[100010];
int p = 1;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int d,e;
	scanf("%d%d",&d,&e);
	while(1)
	{
		if(d<=b)
		{
			x[p++] = 1;
			break;
		}
		else if(a<=e)
		{
			x[p++] = 2;
			a += c;
			a -= e;
		}
		else
		{
			x[p++] = 1;
			d -= b;
			a -= e;
		}
	}
	printf("%d\n",p-1);
	for(int i=1;i<p;i++)
	{
		printf("%s\n",x[i]==1?"STRIKE":"HEAL");
	}
}

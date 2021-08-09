#include <stdio.h>

int check[100010];
int main()
{
	for(int i=1;i<=50;i++)
	{
		int a,b,c;
		for(int j=1;j<=1000;j++)
		{
			if(check[j]==0)
			{
				check[j] = 1;
				a = j;
				break;
			}
		}
		for(int j=a+1;j<=1000;j++)
		{
			if(check[j]==0&&check[j^a]==0&&j!=(j^a))
			{
				check[j] = 1;
				check[j^a] = 1;
				b = j;
				c = j^a;
				break;
			}
		}
		printf("%d %d %d\n",a,b,c);
	}
}

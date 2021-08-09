#include <stdio.h>

int x[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int sum = 0;
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]==0)
		{
			if(sum<0) count++;
		}
		else
		{
			if(x[i]<0)
			{
				
			}
		}
	}
}

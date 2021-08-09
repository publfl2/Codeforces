#include <stdio.h>

int check[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	int sum = 0;
	int c = 0;
	for(int i=1;i<=a+b;i++)
	{
		sum += i;
		if(sum>a+b)
		{
			c = i-1;
			break;
		}
	}
	
	for(int i=1;i<=c;i++) check[i] = 2;
	
	sum = a;
	for(int i=c;i>=1;i--)
	{
		if(sum<=i)
		{
			if(sum==0) break;
			else
			{
				check[sum] = 1;
				break;
			}
		}
		else
		{
			check[i] = 1;
			sum -= i;
		}
	}
	
	int S = 0;
	for(int i=1;i<=c;i++) if(check[i]==1) S++;
	printf("%d\n",S);
	for(int i=1;i<=c;i++) if(check[i]==1) printf("%d ",i);
	printf("\n%d\n",c-S);
	for(int i=1;i<=c;i++) if(check[i]==2) printf("%d ",i);
}

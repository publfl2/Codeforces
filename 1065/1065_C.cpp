#include <stdio.h>
#include <algorithm>

int x[200010];
int check[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	int min = 200010;
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		min = min<c?min:c;
		check[c]++;
	}
	
	int sum =0;
	for(int i=200000;i>=1;i--)
	{
		sum += check[i];
		x[i] = sum;
	}
	
	sum = 0;
	int count = 0;
	for(int i=200000;i>min;i--)
	{
		if(sum+x[i]>b)
		{
			count++;
			sum = 0;
		}
		sum += x[i];
	}
	
	if(sum>0) count++;
	
	printf("%d",count);
}

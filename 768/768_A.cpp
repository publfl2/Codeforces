#include <stdio.h>
#include <algorithm>
int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	int b,c;
	for(int i=2;i<=a;i++)
	{
		if(x[i]!=x[i-1])
		{
			b = i;
			break;
		}
	}
	
	for(int i=a-1;i>=1;i--)
	{
		if(x[i]!=x[i+1])
		{
			c = i;
			break;
		}
	}
	if(b>c) printf("0");
	else printf("%d",c-b+1);
}

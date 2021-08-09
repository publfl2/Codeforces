#include <stdio.h>
#include <algorithm>
int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	int s = x[1]+x[2]+x[3];
	
	if(x[1]==x[2]&&x[2]==x[3])
	{
		long long int count = 0;
		for(int i=1;i<=a;i++) if(x[i]==x[1]) count++;
		printf("%I64d",count*(count-1)*(count-2)/6);
	}
	else if(x[1]==x[2])
	{
		long long int count = 0;
		for(int i=1;i<=a;i++) if(x[i]==x[3]) count++;
		printf("%I64d",count);
	}
	else if(x[2]==x[3])
	{
		long long int count = 0;
		for(int i=1;i<=a;i++) if(x[i]==x[3]) count++;
		printf("%I64d",count*(count-1)/2);
	}
	else
	{
		long long int count = 0;
		for(int i=1;i<=a;i++) if(x[i]==x[3]) count++;
		printf("%I64d",count);
	}
}

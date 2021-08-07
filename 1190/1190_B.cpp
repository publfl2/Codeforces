#include <stdio.h>
#include <algorithm>

int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	if(x[1]==0&&x[2]==0)
	{
		printf("cslnb");
		return 0;
	}
	
	int count = 0;
	for(int i=1;i<a;i++) if(x[i]==x[i+1]) count++;
	if(count>=2)
	{
		printf("cslnb");
		return 0;
	}
	
	long long int s = 0;
	for(int i=1;i<=a;i++) s += x[i];
	s -= (long long int)a*(a-1)/2;
	printf("%s",s%2==1?"sjfnb":"cslnb");
}

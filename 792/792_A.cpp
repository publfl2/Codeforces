#include <stdio.h>
#include <algorithm>
int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	int b = x[2]-x[1] , c = 1;
	for(int i=2;i<a;i++)
	{
		if(x[i+1]-x[i]<b) b = x[i+1]-x[i], c = 1;
		else if(x[i+1]-x[i]==b) c++;
	}
	printf("%d %d",b,c);
}

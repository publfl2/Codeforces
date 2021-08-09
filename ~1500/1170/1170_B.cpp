#include <stdio.h>
#include <algorithm>
int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	if(a<=2)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int s1 = x[1], s2 = x[2];
	if(s1<s2)
	{
		int t = s1;
		s1 = s2;
		s2 = t;
	}
	
	int count = 0;
	for(int i=3;i<=a;i++)
	{
		if(x[i]<s2) count++;
		if(x[i]>=s1)
		{
			s2 = s1;
			s1 = x[i];
		}
		else if(x[i]>s2) s2 = x[i];
	}
	printf("%d",count);
}

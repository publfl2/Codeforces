#include <stdio.h>

int main()
{
	int a,b,s=0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		s+=c;
	}
	if(s+(a-1)==b) printf("YES");
	else printf("NO");
}

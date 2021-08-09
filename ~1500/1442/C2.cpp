#include <stdio.h>

int main()
{
	freopen("input.txt","w",stdout);
	int a;
	scanf("%d",&a);
	printf("%d %d\n",a,a-1);
	for(int i=2;i<=a;i+=2)
	{
		printf("%d %d\n",i,i-1);
		if(i!=a) printf("%d %d\n",i,i+1);
	}
	//printf("%d %d",a,1);
}

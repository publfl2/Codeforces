#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a==1) printf("9\n");
		else if(a==2) printf("98\n");
		else
		{
			printf("98");
			for(int i=2;i<a;i++) printf("%d",9-(i%10));
			printf("\n");
		}
	}
}

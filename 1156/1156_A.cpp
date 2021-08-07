#include <stdio.h>

int x[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int count = 0;
	for(int i=1;i<a;i++)
	{
		if(x[i]==1&&x[i+1]==2) count += 3;
		if(x[i]==1&&x[i+1]==3) count += 4;
		if(x[i]==2&&x[i+1]==1) count += 3;
		if(x[i]==2&&x[i+1]==3)
		{
			printf("Infinite");
			return 0;
		}
		if(x[i]==3&&x[i+1]==1) count += 4;
		if(x[i]==3&&x[i+1]==2)
		{
			printf("Infinite");
			return 0;
		}
	}
	printf("Finite\n");
	printf("%d",count);
}

#include <stdio.h>


char x[2010][2010];
int check[2010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(a>b)
	{
		printf("YES");
		return 0;
	}
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int j=1;j<=b;j++)
	{
		int sum = 0;
		for(int i=1;i<=a;i++) sum += x[i][j]-'0';
		if(sum==1) for(int i=1;i<=a;i++) if(x[i][j]=='1') check[i] = 1;
	}
	
	int sum = 0;
	for(int i=1;i<=a;i++) sum+=check[i];
	printf("%s",sum==a?"NO":"YES");
}

#include <stdio.h>


int x[1010][1010],y[1010][1010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
	
	for(int i=1;i<=a;i++)
	{
		int s = 0;
		for(int j=1;j<=b;j++) if(x[i][j]==0) s++;
		for(int j=1;j<=s;j++) y[i][j] = 0;
		for(int j=s+1;j<=b;j++) y[i][j] = x[i][j-s];
	}
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) x[i][j] = y[i][j];
	
	for(int j=1;j<=b;j++)
	{
		int s = 0;
		for(int i=1;i<=a;i++) if(x[i][j]==0) s++;
		for(int i=a;i>=a-s+1;i--) y[i][j] = 0;
		for(int i=a-s;i>=1;i--) y[i][j] = x[i+s][j];
	}
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) x[i][j] = y[i][j];
	
	for(int i=1;i<=a;i++)
	{
		int s = 0;
		for(int j=1;j<=b;j++) if(x[i][j]==0) s++;
		for(int j=b;j>=b-s+1;j--) y[i][j] = 0;
		for(int j=b-s;j>=1;j--) y[i][j] = x[i][j+s];
	}
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) x[i][j] = y[i][j];
	
	for(int j=1;j<=b;j++)
	{
		int s = 0;
		for(int i=1;i<=a;i++) if(x[i][j]==0) s++;
		for(int i=1;i<=s;i++) y[i][j] = 0;
		for(int i=s+1;i<=a;i++) y[i][j] = x[i-s][j];
	}
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) x[i][j] = y[i][j];
	
	printf("!!\n");
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++) printf("%2d ",x[i][j]);
		printf("\n");
	}
}

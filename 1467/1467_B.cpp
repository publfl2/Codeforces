#include <stdio.h>

int x[300010],y[300010],check[300010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) x[i] = y[i] = check[i] = 0;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<a;i++) y[i] = x[i+1]-x[i];
		for(int i=1;i<a;i++)
		{
			if(y[i]>0) y[i] = 1;
			if(y[i]<0) y[i] = -1;
		}
		
		int control1 = 0, control2 = 0;
		int ans = 0;
		for(int i=1;i<=a-2;i++) if(y[i]*y[i+1]<0) check[i] = 1;
		for(int i=1;i<=a-2;i++) ans += check[i];
		
		int max = 0;
		for(int i=1;i<=a-2;i++)
		{
			int S = check[i-1] + check[i] + check[i+1];
			max = max>S?max:S;
		}
		printf("%d\n",ans-max);
	}
}

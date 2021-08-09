#include <stdio.h>

long long int x[5010],y[5010],left[5010],right[5010],value[5010][5010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) scanf("%lld",&y[i]);
	
	for(int i=1;i<=a;i++) left[i] = x[i]*y[i];
	for(int i=2;i<=a;i++) left[i] += left[i-1];
	for(int i=1;i<=a;i++) right[i] = x[i]*y[i];
	for(int i=a-1;i>=1;i--) right[i] += right[i+1];
	
	for(int i=1;i<=a;i++) value[i][i] = x[i]*y[i];
	for(int i=2;i<=a-1;i++) for(int j=1;i+j-1<=a;j++) value[j][i+j-1] = x[j]*y[i+j-1] + x[i+j-1]*y[j] + value[j+1][i+j-2];
	
	long long int max = left[a];
	for(int i=1;i<=a;i++)
	{
		for(int j=i;j<=a;j++)
		{
			long long int t = left[i-1] + right[j+1] + value[i][j];
			max = max>t?max:t;
		}
	}
	printf("%lld",max);
}
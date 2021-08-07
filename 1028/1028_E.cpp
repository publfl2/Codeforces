#include <stdio.h.>

int x[150010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) y[i] = x[i];
	for(int i=1;i<=a;i++)
	{
		y[a+1] = y[1];
		if(y[i]==0) y[i] += y[i+1];
		else if(y[i]%y[i+1]!=x[i])
		{
			
		}
	}
}

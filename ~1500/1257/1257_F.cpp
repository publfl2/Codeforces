#include <stdio.h>

void swap(int s, int t)
{
	int temp[110]={};
	for(int i=1;i<=60;i++) temp[i] = z[s][i];
	for(int i=1;i<=60;i++) z[s][i] = z[t][i];
	for(int i=1;i<=60;i++) z[t][i] = temp[i];
}
void Gauss(int s, int t)
{
	for(int i=1;i<=s;i++)
	{
		for(int j=p[i-1]+1;j<=t;j++)
		{
			for(int k=i;k<=s;k++)
			{
				if(z[k][j]!=0)
				{
					swap(k,i);
					p[i] = j;
					goto u;
				}
			}
		}
		for(int k=i;k<=s;k++) p[k] = t+1;
		return;
		
		u:;
		for(int k=i+1;k<=s;k++)
		{
			if(z[k][p[i]]==1)
			{
				for(int j=1;j<=t;j++) z[k][j] += (2-z[i][j]),z[k][j]%=2;
				y[k] += (2-y[i]), y[k]%=2;
			}
		}
	}
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		for(int j=1;j<=30;j++)
		{
			if(b%2==1) x[i][2*j-1] = 1;
			else x[i][2*j] = 1;
			b/=2;
		}
	}
	for(int i=a+1;i<=a+30;i++)
	{
		for(int j=1;j<=30;j++)
		{
			x[i][2*j] = 1;
			x[i][2*j-1] = 1;
		}
	}
	
	for(int C=0;C<=30;C++)
	{
		for(int i=1;i<=a;i++) y[i] = C;
		for(int i=a+1;i<=a+30;i++) y[i] = 1;
		
		for(int i=1;i<=a+30;i++) for(int j=1;j<=60;j++) z[i][j] = x[i][j];
		
		Gauss(a+30,60);
	}
}

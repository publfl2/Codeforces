#include <stdio.h>

int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++) count[i] = count[i-1] + (x[i]=='1'?1:0);
	for(int i=1;i<=SIZE;i++)
	{
		for(int j=0;j<=SIZE*a;j++) check[j] = 0;
		for(int j=0;j<=a;j++) check[i*count[j]-j+a]++;
		for(int j=0;j<=SIZE*a;j++) ans += (long long int)check[j]*(check[j]-1)/2;
	}
	
}

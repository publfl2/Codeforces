#include <stdio.h>
#include <string.h>
#define SIZE 300
#define MAX 12345678
int abs(int k)
{
	return k>0?k:-k;
}

char x[60];
int digit[60],digit2[60];
int check[60][SIZE+1][10*SIZE+11];
int func(int s, int t, int k)
{
	if(s==0)
	{
		if(t==0) return 0;
		else return MAX;
	}
	if(check[s][t][k]!=-1) return check[s][t][k];
	
	int C = digit[s]+10*t;
	int ans = MAX;
	for(int i=0;i<=C&&i<=SIZE;i++)
	{
		int s1 = func(s-1,i,(C-i)) + abs((C-i)-k)*s;
		ans = ans<s1?ans:s1;
	}
	return check[s][t][k] = ans;
}

int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++) digit[a-i+1] = x[i]-'0';
	for(int i=1;i<=a;i++) for(int j=0;j<=SIZE;j++) for(int k=0;k<=10*SIZE+10;k++) check[i][j][k] = -1;
	int s1 = func(a,0,0);
	
	for(int i=1;i<=a+1;i++) digit2[i] = 1;
	for(int i=1;i<=a;i++) digit2[i] -= digit[i];
	for(int i=1;i<=a;i++)
	{
		if(digit2[i]<0)
		{
			digit2[i] += 10;
			digit2[i+1]--;
		}
	}
	for(int i=1;i<=a+1;i++) digit[i] = digit2[i];
	if(digit[a+1]>0) a++;
	
	for(int i=1;i<=a;i++) for(int j=0;j<=SIZE;j++) for(int k=0;k<=10*SIZE+10;k++) check[i][j][k] = -1;
	int s2 = func(a,0,0)+(a+1);
	
	printf("%d",s1<s2?s1:s2);
}
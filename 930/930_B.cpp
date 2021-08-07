#include <stdio.h>
#include <string.h>
#include <set>
char x[100010];
int a;
int count[30];
int S[30][5010][30];
int find_cycle()
{
	for(int i=1;i<=a;i++)
	{
		if(a%i!=0) continue;
		int j = 1;
		for(j = 1;j<=i;j++)
		{
			int k = i+j;
			for(k = i+j;k<=a;k+=i) if(x[k]!=x[j]) break;
			if(k<=a) break;
		}
		if(j>i) return i;
	}
}
int main()
{
	scanf("%s",x+1);
	a = strlen(x+1);
	for(int i=a+1;i<=2*a;i++) x[i]=x[i-a];
	int b = find_cycle();
	if(b!=a)
	{
		printf("0.000000000");
		return 0;
	}
	for(int i=1;i<=b;i++)
	{
		count[x[i]-'a'+1]++;
		for(int j=i;j<=a+i-1;j++) S[x[i]-'a'+1][j-i+1][x[j]-'a'+1]++;
	}
	int ans = 0;
	for(int i=1;i<=26;i++)
	{
		if(count[i]==0) continue;
		int max = 0;
		for(int j=2;j<=a;j++)
		{
			int c = 0;
			for(int k=1;k<=26;k++)
			{
				if(S[i][j][k]==1) c++;
			}
			max = max>c?max:c;
		}
		ans += max;
	}
	printf("%.12lf",(double)ans/b);
}

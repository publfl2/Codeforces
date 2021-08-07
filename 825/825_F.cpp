#include <stdio.h>
#include <string.h>
#include <vector>
#define MOD 9999973
#define MAX 3000000

int a;
char x[8010];
long long int hash[8010];
int dist[8010][8010];
int check[8010];

int func(int k)
{
	if(k>a) return 0;
	if(check[k]!=0) return check[k];
	
	int ans = MAX;
	for(int i=k+1;i<=a+1;i++)
	{
		int t = func(i)+dist[k][i];
		ans = ans<t?ans:t;
	}
	return check[k] = ans;
}

int func2(int k)
{
	if(k==0) return 0;
	else return 1 + func2(k/10);
}

int main()
{
	scanf("%s",x+1);
	a = strlen(x+1);
	for(int i=1;i<=a+1;i++) for(int j=1;j<=a+1;j++) dist[i][j] = MAX;
	for(int j=1;j<=a;j++)
	{
		for(int i=1;i+j-1<=a;i++)
		{
			hash[i] *= MOD;
			hash[i] += x[i+j-1];
		}
		for(int i=1;i<=a;i++)
		{
			for(int k=i;k+j-1<=a;k+=j)
			{
				if(hash[i]!=hash[k]) break;
				if(dist[i][k+j]!=MAX) break;
				
				int t = ((k-i)/j)+1;
				dist[i][k+j] = j+func2(t);
			}
		}
	}
	
	printf("%d",func(1));
}
#include <stdio.h>
#include <algorithm>
#include <map>

int x[20],a;
char x2[20];
char y[500010][20];
int z[500010];

int M[5010][5010];
int check[5010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%s",y[i]+1);
	for(int i=1;i<=b;i++)
	{
		int s = 0;
		for(int j=1;j<=a;j++)
		{
			s *=2;
			s += (y[i][j]-'0');
		}
		z[i] = s;
	}
	for(int i=0;i<(1<<a);i++)
	{
		int s = 0;
		for(int j=0;j<a;j++) if((i&(1<<j))==0) s += x[a-j];
		check[i] = s;
	}
	for(int i=0;i<(1<<a);i++) for(int j=1;j<=b;j++) M[i][i^z[j]]++;
	for(int i=1;i<=c;i++)
	{
		int d;
		scanf("%s",x2+1);
		
		int s = 0;
		for(int j=1;j<=a;j++)
		{
			s *=2;
			s += (x2[j]-'0');
		}
		scanf("%d",&d);
		
		int count = 0;
		for(int j=0;j<(1<<a);j++) if(check[s^j]<=d) count += M[s][s^j];
		printf("%d\n",count);
	}
}

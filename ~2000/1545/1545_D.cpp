#include <stdio.h>
#include <multiset>

std::multiset<int> S;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++) for(int j=1;j<=a;j++) scanf("%d",&x[i][j]);
	
	for(int j=1;j<=a;j++) S1 += x[1][j];
	for(int j=1;j<=a;j++) S2 += x[b][j];
	int gap = (S2-S1)/(b-1);
	
	int p,T;
	for(int i=2;i<=b-1;i++)
	{
		int S = 0;
		for(int j=1;j<=a;j++) S += x[i][j];
		if(S != (i-1)*gap + S1)
		{
			p = i;
			T = (i-1)*gap + S1 - S;
			break;
		}
	}
	
	for(int i=1;i<=b;i++)
	{
		
	}
}
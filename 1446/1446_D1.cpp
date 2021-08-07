#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) count[x[i]][i]++;
	for(int i=1;i<=100;i++) for(int j=1;j<=a;j++) count[i][j] += count[i][j-1];
	
	for(int i=1;i<=a;i++) V[i].push_back(0);
	for(int i=1;i<=a;i++) V[x[i]].push_back(i);
	for(int i=1;i<=a;i++) V[i].push_back(a+1);
	
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<V[i].size();j++)
		{
			for(int k=1;k<=100;k++) T[k].addValue(1,j,count[k][V[i][j]]-count[k][V[i][j-1]]);
		}
	}
}

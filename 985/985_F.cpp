#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	for(int i=0;i<=25;i++) for(int j=1;j<=a;j++) V1[i].push_back(0),V2[j].push_back(0);
	for(int i=1;i<=a;i++)
	{
		int t = x[i]-'a';
		V1[t][i-1] = 1;
		V2[t][a-i] = 1;
	}
	
	for(int i=0;i<=25;i++) for(int j=0;j<=25;j++) V3[i][j] = atcoder::convolution(V1[i],V2[j]);
	for(int i=0;i<=25;i++) for(int j=1;j<V1[i].size();j++) V1[i][j] += V1[i][j-1];
	
	
}
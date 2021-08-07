#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int b = strlen(x+1);
		for(int j=1;j<=b;j++) V[i].push_back(x[j]);
	}
	
	if(a>=500)
	{
		for(int i=1;i<=a;i++) V2[i] = V[i];
		for(int i=1;i<=a;i++) std::sort(V2[i].begin(),V2[i].end());
		for(int i=1;i<=a;i++)
		{
			long long int sum1 = 0, sum2 = 0;
			for(int j=0;j<V[i].size();j++) sum1 += C[j] * V[i][j];
			for(int j=0;j<V2[i].size();j++) sum2 += C[j] * V2[i][j];
			type[i] = sum2;
			M[std::make_pair(sum2,sum1)]++;
		}
		
		for(int i=1;i<=a;i++)
		{
			check.clear();
			for(int j=0;j<V[i].size();j++)
			{
				long long int sum = 0;
				for(int k=0;k<V[i].size();k++) sum += C[j] * V[i][j];
				for(int k=j;k<V[i].size();k++)
				{
					// j~k sort
					
				}
			}
		}
	}
}
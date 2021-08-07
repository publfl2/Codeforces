#include <stdio.h>
#include <map>
int x[510];
std::map<int,int> M[510];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		M[i][x[i]+1] = 1;
		for(int j=1;j*j<=x[i];j++)
		{
			int t = (x[i]-1)/j+1;
			M[i][t] = j;
		}
		for(int j=1;j*j<=x[i];j++)
		{
			int t = (x[i]-1)/j+1;
			M[i][j] = t;
		}
	}
	
	long long int ans=1;
	for(int i=1;i<=13;i++) ans*=10;
	std::map<int,int> ::iterator it;
	for(it=M[2].begin();it!=M[2].end();it++) printf("%d %d\n",it->first,it->second);
	for(it=M[1].begin();it!=M[1].end();it++)
	{
		int t = it->first;
		long long int sum = 0;
		for(int i=1;i<=a;i++)
		{
			if(M[i].find(t)==M[i].end()) goto u;
			sum+=M[i][t];
			//printf("%d %d : %d\n",i,t,M[i][t]);
		}
		ans = ans<sum?ans:sum;
		u:;
	}
	printf("%I64d",ans);
}

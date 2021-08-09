#include <stdio.h>
#include <map>
int x[510];
std::map<int,std::pair<int,long long int> > M;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		M[x[i]+1].first++;
		M[x[i]+1].second += 1; 
		for(int j=1;j*j<=x[i];j++)
		{
			int t = (x[i]-1)/j+1;
			long long int a = (t-1);
			a*=(t-1);
			if(a<x[i]) continue;
			M[t].first++;
			M[t].second+= j;
		}
		for(int j=1;(j-1)*(j-1)<x[i];j++)
		{
			int t = (x[i]-1)/j+1;
			M[j].first++;
			M[j].second+= t;
		}
	}
	
	long long int ans=1;
	for(int i=1;i<=13;i++) ans*=10;
	std::map<int,std::pair<int,long long int> > ::iterator it;
	for(it=M.begin();it!=M.end();it++)
	{
		std::pair<int,long long int> A = it->second;
		//printf("%d : %d %d\n",it->first,A.first,A.second);
	}
	for(it=M.begin();it!=M.end();it++)
	{
		std::pair<int,long long int> A = it->second;
		if(A.first==a) ans=ans<A.second?ans:A.second;
		u:;
	}
	printf("%I64d",ans);
}

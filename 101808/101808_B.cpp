#include <stdio.h>
#include <map>
long long int hash[4010][4010];
long long int mul[2010][2010];
long long int add[2010][2010];
std::pair<int,int> x[2010];
std::map< std::pair<long long int,long long int> , int> M;

void clear(int k)
{
	for(int i=1;i<=2*k;i++) for(int j=1;j<=2*k;j++) hash[i][j] = 0;
	for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) mul[i][j] = add[i][j] = 0;
	M.clear();
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		clear(a);
		for(int i=1;i<=a;i++) scanf("%d%d",&x[i].first,&x[i].second);
		
		for(int i=1;i<=2*a;i++) for(int j=1;j<=2*a;j++) hash[i][j] = (i*i+j*j)*1234567+29384*(i*j);
		
		for(int i=1;i<=a;i++) mul[i][i] = add[i][i] = hash[x[i].first][x[i].second];
		for(int i=2;i<=a;i++)
		{
			for(int j=1;j+i-1<=a;j++)
			{
				mul[j][j+i-1] = mul[j][j+i-2] * hash[x[j+i-1].first][x[j+i-1].second];
				add[j][j+i-1] = add[j][j+i-2] + hash[x[j+i-1].first][x[j+i-1].second];
			}
		}
		
		
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			M.clear();
			for(int j=1;j+i-1<=a;j++) M[std::make_pair(add[j][j+i-1],mul[j][j+i-1])]++;
			std::map< std::pair<long long int,long long int> , int> ::iterator it;
			for(it=M.begin();it!=M.end();it++)
			{
				int c = (*it).second;
				ans += (long long int)c*(c-1)/2;
			}
		}
		
		/*
		for(int i=1;i<=a;i++) for(int j=i;j<=a;j++) M[std::make_pair(add[i][j],mul[i][j])]++;
		
		long long int ans = 0;
		std::map< std::pair<long long int,long long int> , int> ::iterator it;
		for(it=M.begin();it!=M.end();it++)
		{
			int c = (*it).second;
			ans += (long long int)c*(c-1)/2;
		}
		*/
		printf("%I64d\n",ans);
	}
}

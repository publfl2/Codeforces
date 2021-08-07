#include <stdio.h>
#include <set>
#include <string.h>
#define SIZE 600
#define MOD 100000393

long long int MOD2 = (long long int)6943838317593173489;

std::set<unsigned long long int> S1[6010];
std::set< std::pair<unsigned long long int,int> > S2;

char x[3000010];
int main()
{
	int T;
	scanf("%d",&T);
	int C = T;
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		int b = strlen(x+1);
		for(int i=1;i<=b;i++) x[i] -= 'a';
		
		if(a==1)
		{
			unsigned long long int S = 0;
			for(int i=1;i<=b;i++) S*=MOD, S += x[i], S %= MOD2;
			if(b<=SIZE) S1[b].insert(S);
			else S2.insert({S,b});
		}
		if(a==2)
		{
			unsigned long long int S = 0;
			for(int i=1;i<=b;i++) S*=MOD, S += x[i], S %= MOD2;
			if(b<=SIZE) S1[b].erase(S);
			else S2.erase({S,b});
		}
		if(a==3)
		{
			long long int ans = 0;
			for(int i=1;i<=SIZE&&i<=b;i++)
			{
				unsigned long long int S = 0;
				unsigned long long int P = 1;
				for(int j=1;j<=i;j++) S*=MOD, S += x[j], S %= MOD2;
				for(int j=1;j<=i;j++) P*=MOD, P %= MOD2;
				
				if(S1[i].find(S)!=S1[i].end()) ans++;
				for(int j=i+1;j<=b;j++)
				{
					S*=MOD, S += x[j], S %= MOD2;
					S += (MOD2-P)*x[j-i], S %= MOD2;
					if(S1[i].find(S)!=S1[i].end()) ans++;
				}
			}
			
			for(std::set< std::pair<unsigned long long int,int> > ::iterator it = S2.begin();it!=S2.end();it++)
			{
				int i = (it->second);
				if(i>b) continue;
				
				unsigned long long int S = 0;
				unsigned long long int P = 1;
				for(int j=1;j<=i;j++) S*=MOD, S += x[j], S %= MOD2;
				for(int j=1;j<=i;j++) P*=MOD, P %= MOD2;
				
				if(S==(it->first)) ans++;
				for(int j=i+1;j<=b;j++)
				{
					S*=MOD, S += x[j], S %= MOD2;
					S += (MOD2-P)*x[j-i], S %= MOD2;
					if(S==(it->first)) ans++;
				}
			}
			printf("%lld\n",ans);
			fflush(stdout);
		}
	}
}
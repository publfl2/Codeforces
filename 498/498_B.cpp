#include <stdio.h>
#include <algorithm>
#include <vector>

double DP1[10010],DP2[10010];
double power(double a, int b)
{
	double ans = 1;
	double k = a;
	while(b)
	{
		if(b%2==1) ans*=k;
		b/=2;
		k*=k;
	}
	return ans;
}

std::pair<double,int> P[5010];
int last[5010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		P[i]=std::make_pair((double)c/100,d);
	}
	for(int i=a;i>=1;i--) last[i] = last[i+1] + P[i].second;
	
	
	for(int i=0;i<=b;i++) DP2[i] = 0;
	for(int i=a;i>=1;i--)
	{
		if(P[i].first==1||P[i].second==1)
		{
			for(int j=0;j<b;j++) DP1[j] = 1+DP2[j+1];
			DP1[b] = 0;
			for(int j=0;j<=b;j++) DP2[j] = DP1[j];
			
			for(int j=0;j<=b;j++) if(j+last[i]<b) DP2[j] = 0;
			continue;
		}
		
		for(int j=0;j<=b;j++) DP2[j]++;
		double sum = 0;
		double C = 1;
		for(int j=1;j<P[i].second;j++)
		{
			sum += C*DP2[j];
			C*= (1-P[i].first);
		}
		DP1[0] = sum*P[i].first;
		for(int j=1;j<b;j++)
		{
			sum -= DP2[j];
			sum /= (1-P[i].first);
			if(j+P[i].second-1<=b) sum += power(1-P[i].first,P[i].second-2)*DP2[j+P[i].second-1];
			DP1[j] = sum*P[i].first;
		}
		for(int j=0;j<b;j++) if(j+P[i].second<=b) DP1[j] += power(1-P[i].first,P[i].second-1)*DP2[j+P[i].second];
		DP1[b] = 0;
		for(int j=0;j<=b;j++) DP2[j] = DP1[j];
		
		for(int j=0;j<=b;j++) if(j+last[i]<b) DP2[j] = 0;
	}
}

#include <stdio.h>
#include <map>
#define MIN -12345678

int a,b;
std::map<int,int> M[210][210];
int two[210],five[210];

int func(int s, int t, int k) // k = five - two
{
	if(t==b) return 0;
	if(s>a) return MIN;
	if(M[s][t].find(k)!=M[s][t].end()) return M[s][t][k];
	int s1 = func(s+1,t,k);
	int s2;
	if(k>0) s2 = func(s+1,t+1,k+five[s]-two[s]) + (two[s]<five[s]+k?two[s]:five[s]+k);
	else s2 = func(s+1,t+1,k+five[s]-two[s]) + (two[s]-k<five[s]?two[s]-k:five[s]);
	return M[s][t][k] = s1>s2?s1:s2;
}
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		long long int c;
		scanf("%I64d",&c);
		for(long long int d = c; d%2==0; d/=2) two[i]++;
		for(long long int d = c; d%5==0; d/=5) five[i]++;
	}
	printf("%d",func(1,0,0));
}

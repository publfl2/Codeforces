#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#define MIN -1234567

int a,b;
std::vector<int> check[210][210];
std::pair<int,int> x[210];
int func(int s, int t, int k)
{
	if(k<-27*(a-s+1)) k = -27*(a-s+1);
	if(k>60*(a-s+1)) k = 60*(a-s+1);
	if(check[s][t].size()==0) for(int k=0;k<=87*(a-s+1)+1;k++) check[s][t].push_back(-1);
	
	if(t>b) return MIN;
	if(s>a)
	{
		if(t==b) return 0;
		else return MIN;
	}
	if(check[s][t][k+27*(a-s+1)]!=-1) return check[s][t][k+27*(a-s+1)];
	
	int s1 = func(s+1,t,k);
	int count2 = x[s].first, count5 = x[s].second;
	if(k<0) count2 -= k;
	else count5 += k;
	int s2 = func(s+1,t+1,count5-count2) + (count2<count5?count2:count5);
	return check[s][t][k+27*(a-s+1)] = s1>s2?s1:s2;
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		long long int c;
		scanf("%lld",&c);
		int count2 = 0, count5 = 0;
		while(c%2==0) count2++,c/=2;
		while(c%5==0) count5++,c/=5;
		x[i] = std::make_pair(count2,count5);
	}
	
	printf("%d",func(1,0,0));
}
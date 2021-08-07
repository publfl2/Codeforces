#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#define MIN -(long long int)1e16

int x[300010],y[300010];

struct str{
	int first;
	int second;
	int index;
}z[300010];
bool cmp(str a, str b)
{
	return a.first<b.first;
}

std::set<int> S;
long long int sum[300010];
int check[300010];

struct str2{
	long long int max;
	long long int first;
	long long int second;
};

int a;
str2 func(int L, int R, int k)
{
	if(k>a) return {0,0,0};
	if(L<=z[k].index&&z[k].index<=R)
	{
		str2 P1= func(L,z[k].index-1,k+1);
		str2 P2 = func(z[k].index+1,R,k+1);
		str2 ans;
		ans.first = P1.first>P1.first + z[k].second + P2.max?P1.first:P1.first + z[k].second + P2.max;
		ans.second = P2.second>P2.second + z[k].second + P1.max?P2.second:P2.second + z[k].second + P1.max;
		ans.max = P1.max;
		ans.max = ans.max>P2.max?ans.max:P2.max;
		ans.max = ans.max>P1.max + P2.max + z[k].second?ans.max:P1.max+P2.max+z[k].second;
		
		return ans;
	}
	else return func(L,R,k+1);
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	
	for(int i=1;i<=a;i++) z[i] = {x[i],y[i],i};
	std::sort(z+1,z+a+1,cmp);
	
	str2 A = func(1,z[1].index-1,2);
	str2 B = func(z[1].index+1,a,2);
	printf("%lld",A.first+z[1].second+B.second);
}
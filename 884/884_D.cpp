#include <stdio.h>
#include <algorithm>
#include <map>
int x[200010];
long long int S[200010];
long long int sum(int s, int t)
{
	return S[t]-S[s-1];
}
std::map<int,long long int> check[200010];
long long int func(int s, int t)
{
	if(t<=s) return 0;
	if(check[s].find(t)!=check[s].end()) return check[s][t];
	int h1 = (2*s+t)/3;
	int h2 = (s+2*t)/3;
	long long int s1 = sum(s,t)+func(s,h1)+func(h1+1,h2)+func(h2+1,t);
	
	int h = (s+t)/2;
	long long int s2 = sum(s,t)+func(s,h)+func(h+1,t-1);

	long long int s3 = 0;
	for(int i=t;i>s;i-=2) s3+=sum(s,i);
	//long long int s3 = sum(s,t)+func(s,t-2);
	return check[s][t] = s1<s2?s3<s1?s3:s1:s3<s2?s3:s2;
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	for(int i=1;i<=a;i++) S[i]=S[i-1]+x[i];
	printf("%I64d",func(1,a));
}

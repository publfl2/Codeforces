#include <stdio.h>
#include <map>

std::map<int,int> check[30010];

int gem[30010];
int func(int s, int t)
{
	if(s>30000) return 0;
	std::map<int,int> ::iterator it = check[s].find(t);
	if(it!=check[s].end()) return check[s][t];
	
	int s1 = 0;
	if(t-1>0) s1 = func(s+t-1,t-1)+gem[s];
	int s2 = func(s+t,t)+gem[s];
	int s3 = func(s+t+1,t+1)+gem[s];
	int m = s1;
	m = m>s2?m:s2;
	m = m>s3?m:s3;
	return check[s][t] = m;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		gem[c]++;
	}
	printf("%d",func(b,b));
}

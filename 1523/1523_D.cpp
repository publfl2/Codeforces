#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

int a,b,c;
char x[200010][70];
long long int y[200010];
std::vector<int> temp;
std::vector<long long int> save[200010];
int ans1 = 0;
long long int ans2 = 0;
std::set<long long int> S;

void func(int k, long long int C)
{
	if(C==0) return;
	if(S.find(C)!=S.end()) return;
	
	if(temp.size()>=(a+1)/2)
	{
		long long int C2 = C;
		int sum = 0;
		for(int j=1;j<=b;j++) sum += C2%2, C2 /=2;
		if(sum>ans1) ans1 = sum, ans2 = C;
		return;
	}
	if(k>a) return;
	
	temp.push_back(k);
	func(k+1,(C&y[k]));
	temp.pop_back();
	
	if((C&y[k])!=C) func(k+1,C);
	S.insert(C);
}

int main()
{
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	
	for(int i=1;i<=a;i++)
	{
		long long int sum = 0;
		long long int p = 1;
		for(int j=1;j<=b;j++)
		{
			sum += p*(x[i][j]-'0');
			p*=2;
		}
		y[i] = sum;
	}
	std::sort(y+1,y+a+1);
	
	long long int C = 0;
	long long int p = 1;
	for(int j=1;j<=b;j++) C += p, p*=2;
	func(1,C);
	
	for(int j=1;j<=b;j++)
	{
		printf("%lld",ans2%2);
		ans2 /= 2;
	}
}
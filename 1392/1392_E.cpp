#include <stdio.h>
#include <vector>

long long int power(long long int s, int t)
{
	long long int ans = 1;
	for(int i=1;i<=t;i++) ans*=s;
	return ans;
}
std::vector< std::pair<int,int> > ans;
long long int check[50][50];

int main()
{
	int a;
	scanf("%d",&a);
	
	check[1][1] = 1;
	for(int i=2;i<=a;i++) check[i][1] = check[i-1][1]*4;
	for(int i=1;i<=a;i++) for(int j=2;j<=a;j++) check[i][j] = check[i][j-1]*2;
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			printf("%lld ",check[i][j]);
			fflush(stdout);
		}
		printf("\n");
		fflush(stdout);
	}
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		ans.clear();
		long long int c;
		scanf("%lld",&c);
		
		int s = 1, t = 1;
		int p = 0;
		while(1)
		{
			ans.push_back(std::make_pair(s,t));
			if(s==a&&t==a) break;
			if((c/power(2,p+1))%2==0)
			{
				s++;
				p+=2;
			}
			else
			{
				t++;
				p++;
			}
		}
		for(int i=0;i<ans.size();i++)
		{
			printf("%d %d\n",ans[i].first,ans[i].second);
			fflush(stdout);
		}
	}
}

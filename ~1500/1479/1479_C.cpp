#include <stdio.h>
#include <vector>
struct str{
	int first;
	int second;
	int value;
};
std::vector<str> ans;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("YES\n");
	if(a==1&&b==1)
	{
		printf("2 1\n1 2 1");
		return 0;
	}
	if(a==1)
	{
		ans.push_back({1,32,1});
		a++;
	}
	ans.push_back({1,2,a-1});
	b -= (a-1);
	a = 1;
	
	for(int i=2;i<=22;i++)
	{
		for(int j=i+1;j<=22;j++)
		{
			ans.push_back({i,j,1<<(j-3)});
		}
	}
	
	int k = (b-a);
	for(int i=2;i<=22;i++)
	{
		if((1<<(i-2))-1<=k) ans.push_back({i,32,1});
		else break;
	}
	
	int S = 0;
	for(int i=22;i>=3;i--)
	{
		S += (1<<(i-3));
		if(S>k) S -= (1<<(i-3));
		else
		{
			if(S+(1<<(i-3))-1>k)
			{
				int T = k-S;
				for(int j=22;j>=2;j--)
				{
					if((1<<(j-2))-1<=T)
					{
						ans.push_back({j,31,S-1});
						break;
					}
				}
			}
		}
	}
	ans.push_back({31,32,1});
	printf("32 %d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d %d\n",ans[i].first,ans[i].second,ans[i].value);
}

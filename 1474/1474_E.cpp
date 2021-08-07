#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > ans;
int next[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		long long int sum = 0;
		ans.clear();
		
		int l = 1, r = a;
		int count = 0;
		while(1)
		{
			if(l==r)
			{
				next[l] = 1;
				break;
			}
			
			sum += (long long int)(r-l)*(r-l);
			if(count%2==0)
			{
				ans.push_back(std::make_pair(r,l));
				next[l] = r;
				l++;
			}
			else
			{
				ans.push_back(std::make_pair(l,r));
				next[r] = l;
				r--;
			}
			count++;
		}
		printf("%lld\n",sum);
		for(int i=1;i<=a;i++) printf("%d ",next[i]);
		printf("\n");
		printf("%d\n",ans.size());
		for(int i=ans.size()-1;i>=0;i--) printf("%d %d\n",ans[i].first,ans[i].second);
	}
}

#include <stdio.h>
#include <stdio.h>
#include <vector>
#include <queue>
 
struct str{
	int x0;
	int y0;
	int z0;
};
std::vector<str> ans;

int x[10010];
void func(int s, int t, int k)
{
	ans.push_back({s,t,k});
	x[s] -= k*s;
	x[t] += k*s;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int sum = 0;
		for(int i=1;i<=a;i++) sum += x[i];
		
		if((sum%a)!=0)
		{
			printf("-1\n");
			continue;
		}
		
		int limit = sum/a;
		for(int i=2;i<=a;i++)
		{
			int t = (i-(x[i]%i))%i;
			func(1,i,t);
			int s = x[i]/i;
			func(i,1,s);
		}
		for(int i=2;i<=a;i++) func(1,i,limit);
		
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d %d %d\n",ans[i].x0,ans[i].y0,ans[i].z0);
	}
}

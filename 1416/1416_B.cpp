#include <stdio.h>
#include <vector>
#include <queue>
 
struct str{
	int x0;
	int y0;
	int z0;
};
std::vector<str> ans;
 
struct str2{
	int first;
	int second;
};
bool operator<(str2 a, str2 b)
{
	if(a.first==b.first) return a.second<b.second;
	return a.first>b.first;
}
std::priority_queue<str2> Q;
 
 
int x[10010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		while(!Q.empty()) Q.pop();
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		if(a==1)
		{
			printf("0\n");
			continue;
		}
		
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
			int t = x[i]/i;
			ans.push_back({i,1,t});
			x[i] -= t*i;
			x[1] += t*i;
		}
		
		for(int i=2;i<=a;i++)
		{
			if(x[i]>limit)
			{
				int t = (x[i]-limit)%i;
				if(t>0) Q.push({i-t,i});
			}
		}
		
		while(!Q.empty())
		{
			str2 A = Q.top();
			Q.pop();
			ans.push_back({1,A.second,A.first});
			x[1] -= A.first;
			x[A.second] += A.first;
			if(x[1]<0)
			{
				printf("-1\n");
				goto u;
			}
			ans.push_back({A.second,1,(x[A.second]-limit)/A.second});
			x[1] += (x[A.second]-limit);
			x[A.second] = limit;
		}
		
		for(int i=2;i<=a;i++)
		{
			if(x[i]<limit)
			{
				ans.push_back({1,i,limit-x[i]});
				x[1] -= (limit-x[i]);
				x[i] = limit;
			}
		}
		
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)
		{
			printf("%d %d %d\n",ans[i].x0,ans[i].y0,ans[i].z0);
		}
		u:;
	}
}

#include <stdio.h>
#include <algorithm>

int next[200010];
int find(int k)
{
	if(k==next[k]) return k;
	else return next[k] = find(next[k]);
}

int x[200010];
std::pair<int,int> y[200010];

int left[200010],right[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) next[i] = left[i] = right[i] = i;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) y[i] = {x[i],i};
		std::sort(y+1,y+a+1);
		
		long long int ans = 0;
		for(int j=1;j<=a;j++)
		{
			int t = y[j].second;
			if(x[t]>=b) continue;
			for(int i=t-1;i>=1;i--)
			{
				if(x[i]%x[t]==0)
				{
					int s1 = find(i);
					int s2 = find(t);
					if(s1!=s2)
					{
						ans += x[t];
						next[s1] = s2;
						left[s2] = left[s1];
					}
					else i = left[s1];
				}
				else break;
			}
			for(int i=t+1;i<=a;i++)
			{
				if(x[i]%x[t]==0)
				{
					int s1 = find(i);
					int s2 = find(t);
					if(s1!=s2)
					{
						ans += x[t];
						next[s1] = s2;
						right[s2] = right[s1];
					}
					else i = right[s1];
				}
				else break;
			}
		}
		
		
		for(int i=1;i<a;i++) if(find(i)!=find(i+1)) ans += b;
		printf("%lld\n",ans);
	}
}
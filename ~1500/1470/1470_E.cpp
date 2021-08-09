#include <stdio.h>
#include <algorithm>

int left[300010],right[300010];
int x[300010],y[300010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int min = 1;
		int max = 1;
		for(int i=1;i<=b;i++) max += (a-i);
		
		for(int i=1;i<=a;i++)
		{
			left[i] = min;
			right[i] = max;
			for(int j=2;j<=b+1&&i+j-1<=a;j++) y[j] = x[i+j-1];
			for(int j=2;j<=b+1&&i+j-1<=a;j++)
			{
				if(y[j]<x[i]) min++;
				else max--;
			}
		}
		left[a+1] = min;
		right[a+1] = max;
		
		for(int i=1;i<=c;i++)
		{
			int d,e;
			scanf("%d%d",&d,&e);
			if(e>right[1])
			{
				printf("-1\n");
				continue;
			}
			
			int m = 1, M = a+1;
			int ans = 1;
			while(m<=M)
			{
				int h = (m+M)/2;
				if(left[h]<=e&&e<=right[h])
				{
					ans = h;
					m = h+1;
				}
				else M = h-1;
			}
			
			printf("%d %d %d!!\n",ans,left[ans],right[ans]);
			
			if(ans==a+1) printf("%d\n",x[d]);
			else if(d<=ans-1) printf("%d\n",x[d]);
			else
			{
				int start = b+1<a-ans+1?b+1:a-ans+1;
				for(int j=2;j<=start;j++) y[j] = x[ans+j-1];
				std::sort(y+2,y+start+1);
				int pick;
				if(e<left[ans+1])
				{
					for(int j=2;j<=start;j++)
					{
						if(left[ans]+j-2==e)
						{
							pick = y[j];
							break;
						}
					}
				}
				else
				{
					for(int j=start;j>=2;j--)
					{
						if(right[ans]+j-start==e)
						{
							pick = y[j];
							break;
						}
					}
				}
				
				printf("%d??\n",pick);
				for(int j=2;j<=start;j++)
				{
					if(y[j]==pick)
					{
						if(d>start) printf("%d\n",x[d]);
						else
						{
							int f = (d-ans);
							int g = (j-1-f);
							printf("%d\n",x[g]);
						}
						break;
					}
				}
			}
		}
	}
}

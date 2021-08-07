#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i].first);
	for(int i=1;i<=a;i++) scanf("%d",&x[i].second);
	std::sort(x+1,x+a+1);
	
	for(int i=1;i<=a;i++)
	{
		if(x[i].first<=x[i].second)
		{
			Tright.
		}
		else
		{
			int L = 1, R = i-1;
			int p = 1;
			while(L<=R)
			{
				int h = (L+R)/2;
				if(x[h].first<=x[i].second)
				{
					p = h;
					min = h+1;
				}
				else max = h-1;
			}
			
			long long int t = T.getMax(1,h);
			if(t>=x[i].first)
			{
				ans = ans>2*(x[i].first-x[i].second)?ans:2*(x[i].first-x[i].second);
			}
			else if(t>=x[i].second)
			{
				ans = ans>2*(t-x[i].second)?ans:2*(t-x[i].second);
			}
			
			t = T.getMax(h+1,i-1);
			if(t>=x[i].first)
			{
				ans = ans>2*(x[i].first-x[i].second)?ans:2*(x[i].first-x[i].second);
			}
			else if(t>=x[i].second)
			{
				ans = ans>2*(t-x[i].second)?ans:2*(t-x[i].second);
			}
			
		}
	}
}
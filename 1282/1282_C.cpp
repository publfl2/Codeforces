#include <stdio.h>
#include <algorithm>

struct str{
	int x0;
	int y0;
}x[200010];

bool cmp(str a, str b)
{
	return a.y0<b.y0;
}

int type[10],S[10];
int main()
{
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&type[0],&type[1]);
		for(int i=1;i<=a;i++) scanf("%d",&x[i].x0);
		for(int i=1;i<=a;i++) scanf("%d",&x[i].y0);
		std::sort(x+1,x+a+1,cmp);
		
		for(int i=1;i<=a;i++)
		{
			if(x[i].x0==0) S[0]++;
			else S[1]++;
		}
		x[a+1].y0 = b+1;
		x[0].y0 = -1;
		x[0].x0 = 2;
		
		long long int s = 0;
		int ans = 0;
		for(int i=0;i<=a;i++)
		{
			while(x[i].y0==x[i+1].y0)
			{
				s += type[x[i].x0];
				S[x[i].x0]--;
				i++;
			}
			s+= type[x[i].x0];
			S[x[i].x0]--;
			
			if(s<x[i+1].y0)
			{
				if(s+S[0]*type[0]+S[1]*type[1]<x[i+1].y0) ans = i + S[0] + S[1];
				else if(s+S[0]*type[0]<x[i+1].y0) ans = ans > i+S[0]+(x[i+1].y0-1-s-S[0]*type[0])/type[1]?ans:i+S[0]+(x[i+1].y0-1-s-S[0]*type[0])/type[1];
				else ans = ans > i + (x[i+1].y0-1-s)/type[0]?ans:i+(x[i+1].y0-1-s)/type[0];
			}
		}
		printf("%d\n",ans);
	}
}

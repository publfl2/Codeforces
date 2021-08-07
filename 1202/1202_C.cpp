#include <stdio.h>
#include <string.h>

char x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int b = strlen(x+1);
		
		int x0 = 0, y0 = 0;
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		for(int i=1;i<=b;i++)
		{
			if(x[i]=='W') y0++;
			if(x[i]=='S') y0--;
			if(x[i]=='D') x0++;
			if(x[i]=='A') x0--;
			x1 = x1<x0?x1:x0;
			x2 = x2>x0?x2:x0;
			y1 = y1<y0?y1:y0;
			y2 = y2>y0?y2:y0;
		}
		long long int W = x2-x1+1, H = y2-y1+1;
		long long int ans1 = W*H, ans2 = W*H;
		if(W>=3) ans1 = (W-1)*H;
		if(H>=3) ans2 = (H-1)*W;
		printf("%lld\n",ans1<ans2?ans1:ans2);
	}
}

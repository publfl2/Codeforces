#include <stdio.h>
#include <algorithm>
#define MAX 1000000010
char c[5];
struct str{
	int x0;
	int color;
}x[300010];
bool cmp(str a, str b)
{
	return a.x0<b.x0;
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%d%s",&x[i].x0,c+1);
		if(c[1]=='G') x[i].color = 1;
		if(c[1]=='R') x[i].color = 2;
		if(c[1]=='B') x[i].color = 3;
	}
	std::sort(x+1,x+a+1,cmp);
	int control = 0;
	for(int i=1;i<=a;i++) if(x[i].color==1) control = 1;
	if(control==0)
	{
		int first_R=0, first_B=0, last_R=0, last_B=0;
		for(int i=1;i<=a;i++)
		{
			if(x[i].color==2)
			{
				first_R = i;
				break;
			}
		}
		for(int i=1;i<=a;i++)
		{
			if(x[i].color==3)
			{
				first_B = i;
				break;
			}
		}
		for(int i=a;i>=1;i--)
		{
			if(x[i].color==2)
			{
				last_R = i;
				break;
			}
		}
		for(int i=a;i>=1;i--)
		{
			if(x[i].color==3)
			{
				last_B = i;
				break;
			}
		}
		long long int ans = 0;
		long long int min = MAX;
		ans += (x[last_R].x0-x[first_R].x0);
		ans += (x[last_B].x0-x[first_B].x0);
		for(int i=1;i<a;i++) if(x[i].color+x[i+1].color==5) min = min<x[i+1].x0-x[i].x0?min:x[i+1].x0-x[i].x0;
		if(min==MAX) printf("%I64d",ans);
		else printf("%I64d",ans+min);
		return 0;
	}
	x[0].x0 = -MAX, x[0].color = 1;
	x[a+1].x0 = 2*MAX, x[a+1].color = 1;
	
	int last_G = -1;
	int last_B = 0;
	int last_R = 0;
	long long int ans=0;
	long long int max2 = 0;
	long long int max3 = 0;
	for(int i=1;i<=a+1;i++)
	{
		if(x[i].color==1)
		{
			if(last_B!=-1)
			{
				ans += x[i].x0-x[last_B].x0;
				max3 = max3>x[i].x0-x[last_B].x0?max3:x[i].x0-x[last_B].x0;
				ans-=max3;
			}
			if(last_R!=-1)
			{
				ans += x[i].x0-x[last_R].x0;
				max2 = max2>x[i].x0-x[last_R].x0?max2:x[i].x0-x[last_R].x0;
				ans-=max2;
			}
			last_B = last_R = i;
			max2 = max3 = 0;
			if(last_G!=-1&&i!=a+1) ans += x[i].x0-x[last_G].x0;
			last_G = i;
		}
		else if(x[i].color==2)
		{
			ans += x[i].x0-x[last_R].x0;
			max2 = max2 > x[i].x0-x[last_R].x0? max2:x[i].x0-x[last_R].x0;
			last_R = i;
		}
		else if(x[i].color==3)
		{
			ans += x[i].x0-x[last_B].x0;
			max3 = max3 > x[i].x0-x[last_B].x0? max3:x[i].x0-x[last_B].x0;
			last_B = i;
		}
	}
	printf("%I64d",ans);
}

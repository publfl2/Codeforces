#include <stdio.h>
#include <set>
#include <algorithm>
struct str{
	int x0;
	int y0;
}y[100010];
bool cmp(str a, str b)
{
	if(a.x0==b.x0) return a.y0<b.y0;
	return a.x0<b.x0;
}
int x[100010];
int check[100010];
std::set<int> S;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) y[i].x0 = x[i] , y[i].y0 = i;
	
	long long int ans = 0;
	std::sort(y+1,y+a+1,cmp);
	for(int i=1;i<=a;i++)
	{
		std::set<int> ::iterator l = S.lower_bound(y[i].y0);
		std::set<int> ::iterator r = S.upper_bound(y[i].y0);
		int k1, k2;
		if(l==S.begin()) k1 = 0;
		else k1 = *(--l);
		if(r==S.end()) k2 = a+1;
		else k2 = *r;
		long long int t = (long long int)(y[i].y0-k1) * (k2-y[i].y0);
		ans -= t*y[i].x0;
		
		k1 = a;
		for(int j=y[i].y0+1;j<=a;j++)
		{
			if(check[j]==0)
			{
				k1 = j-1;
				break;
			}
		}
		k2 = 1;
		for(int j=y[i].y0-1;j>=1;j--)
		{
			if(check[j]==0)
			{
				k2 = j+1;
				break;
			}
		}
		t = (long long int)(y[i].y0-k2+1) * (k1-y[i].y0+1);
		ans += t*y[i].x0;
		S.insert(y[i].y0);
		check[y[i].y0] = 1;
	}
	printf("%I64d",ans);
}

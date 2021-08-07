#include <stdio.h>
#include <math.h>
#include <algorithm>
#define PI 3.14159265358979

std::pair<double,int> x[100010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		x[i] = {atan2(b,c),i};
	}
	std::sort(x+1,x+a+1);
	double min = (x[1].first+2*PI)-x[a].first;
	int p = a;
	for(int i=1;i<a;i++)
	{
		if(min>(x[i+1].first-x[i].first))
		{
			min = (x[i+1].first-x[i].first);
			p = i;
		}
	}
	if(p==a) printf("%d %d",x[a].second,x[1].second);
	else printf("%d %d",x[p].second,x[p+1].second);
}
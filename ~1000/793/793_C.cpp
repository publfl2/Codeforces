#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 12345678
int x1,y1,x2,y2;

double func1(int x0, int y0, int vx, int vy, int h)
{
	// x parallel
	if(vx==0&&vy==0)
	{
		if(y0==h && x1<=x0&&x0<=x2) return 0;
		else return MAX;
	}
	else if(vy==0) return MAX;
	else
	{
		double t = (double)(h-y0)/vy;
		if(t<0) return MAX;
		double nx0 = x0+t*vx;
		if(x1<=nx0&&nx0<=x2) return t;
		else return MAX;
	}
}

double func2(int x0, int y0, int vx, int vy, int h)
{
	// y parallel
	if(vx==0&&vy==0)
	{
		if(x0==h && y1<=y0&&y0<=y2) return 0;
		else return MAX;
	}
	else if(vx==0) return MAX;
	else
	{
		double t = (double)(h-x0)/vx;
		if(t<0) return MAX;
		double ny0 = y0+t*vy;
		if(y1<=ny0&&ny0<=y2) return t;
		else return MAX;
	}
}

std::vector<double> V;
std::pair<int,int> P[100010],Q[100010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	
	double L = 0, R = MAX;
	for(int i=1;i<=a;i++)
	{
		V.clear();
		int b,c,d,e;
		scanf("%d%d%d%d",&b,&c,&d,&e);
		P[i]=std::make_pair(b,c);
		Q[i]=std::make_pair(d,e);
		
		if(d==0&&e==0)
		{
			if(x1<b&&b<x2&&y1<c&&c<y2);
			else
			{
				printf("-1");
				return 0;
			}
		}
		
		double k;
		k = func1(b,c,d,e,y1);
		if(k<MAX) V.push_back(k);
		k = func1(b,c,d,e,y2);
		if(k<MAX) V.push_back(k);
		k = func2(b,c,d,e,x1);
		if(k<MAX) V.push_back(k);
		k = func2(b,c,d,e,x2);
		if(k<MAX) V.push_back(k);
		if(x1<=b&&b<=x2&&y1<=c&&c<=y2) V.push_back(0);
		std::sort(V.begin(),V.end());
		V.erase(std::unique(V.begin(),V.end()),V.end());
		
		
		if(V.size()<=1)
		{
			printf("-1");
			return 0;
		}
		else if(V.size()==2)
		{
			L = L>V[0]?L:V[0];
			R = R<V[1]?R:V[1];
		}
	}
	
	if(L<R) printf("%.12lf",L);
	else if(L==R)
	{
		for(int i=1;i<=a;i++)
		{
			double nx = P[i].first + L*Q[i].first;
			double ny = P[i].second + L*Q[i].second;
			if(x1<nx&&nx<x2&&y1<ny&&ny<y2);
			else
			{
				printf("-1");
				return 0;
			}
		}
		printf("%.12lf",L);
	}
	else printf("-1");
}

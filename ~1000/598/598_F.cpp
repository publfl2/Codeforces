#include <stdio.h>
#include <math.h>
#include <algorithm>

int SCC(double a, double b, double c, double d)
{
	return a*d-b*c<0?-1:1;
}

std::pair<double,int> func(double x1, double y1, double x2, double y2, double x3, double y3, double v, double w, int type)
{
	double s= w*(x2-x1) - v*(y2-y1);
	double t = -w*(x1-x3) + v*(y1-y3);
	if(s==0) return std::make_pair(0,0);
	else
	{
		double k = t/s;
		double x = x1+k*(x2-x1);
		double y = y1+k*(y2-y1);
		double maxX = x1>x2?x1:x2;
		double minX = x1<x2?x1:x2;
		double maxY = y1>y2?y1:y2;
		double minY = y1<y2?y1:y2;
		if(minX<=x&&x<=maxX&&minY<=y&&y<=maxY)
		{
			if(type==0) return std::make_pair(x,SCC(x2-x1,y2-y1,v,w));
			else return std::make_pair(y,SCC(x2-x1,y2-y1,v,w));
		}
		else return std::make_pair(0,0);
	}
}

double intersection(double l1, double r1, double l2, double r2)
{
	printf("%lf %lf %lf %lf??\n",l1,r1,l2,r2);
	if(r1<=l2) return 0;
	if(r2<=l1) return 0;
	double min = l1>l2?l1:l2;
	double max = r1<r2?r1:r2;
	return max-min;
}

std::pair<double,double> x[1010];
std::vector< std::pair<double,int> > V;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		double c,d;
		scanf("%lf%lf",&c,&d);
		x[i]={c,d};
	}
	x[a+1] = x[1];
	
	for(int i=1;i<=b;i++)
	{
		double c,d,e,f;
		scanf("%lf%lf%lf%lf",&c,&d,&e,&f);
		if(c>e)
		{
			double t = c;
			c = e;
			e = t;
			t = d;
			d = f;
			f = t;
		}
		else if(c==e&&d>f)
		{
			double t = d;
			d = f;
			f = t;
		}
		
		V.clear();
		for(int j=1;j<=a;j++)
		{
			std::pair<double,int> P;
			if(c!=e) P = func(x[j].first,x[j].second,x[j+1].first,x[j+1].second,c,d,e-c,f-d,0);
			else P = func(x[j].first,x[j].second,x[j+1].first,x[j+1].second,c,d,e-c,f-d,1);
			if(P.second==0) continue;
			V.push_back(P);
		}
		std::sort(V.begin(),V.end());
		
		
		int type = 0;
		double ans = 0;
		for(int i=0;i<V.size();i++)
		{
			if(type!=0)
			{
				if(c!=e) ans += intersection(c,e,V[i-1].first,V[i].first);
				else ans += intersection(d,f,V[i-1].first,V[i].first);
			}
			type += V[i].second;
		}
		double ratio;
		if(c!=e) ratio = sqrt((e-c)*(e-c)+(f-d)*(f-d))/(e-c);
		else ratio = sqrt((e-c)*(e-c)+(f-d)*(f-d))/(f-d);
		
		printf("%.12lf\n",ans * ratio);
	}
}
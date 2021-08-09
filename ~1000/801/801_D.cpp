#include <stdio.h>
#include <math.h>
#define PHI 3.1415926535
#define error 0.00001
struct Point{
	double x0;
	double y0;
}x[1010];
Point point(double a, double b)
{
	Point A;
	A.x0 = a;
	A.y0 = b;
	return A;
}
double dist(Point a, Point b)
{
	long long int s = a.x0-b.x0;
	long long int t = a.y0-b.y0;
	return sqrt(s*s+t*t);
}
double ans = 1.415*2000000000;
void func(int s, int t)
{
	//point s , line t - t+1
	double min = 0, max = 1;
	while(max-min<error)
	{
		double s1 = (2*min+max)/3;
		double s2 = (min+2*max)/3;
		
		double t1 = dist(x[s],point(x[t].x0+s1*(x[t+1].x0-x[t].x0),x[t].y0+s1*(x[t+1].y0-x[t].y0)));
		double t2 = dist(x[s],point(x[t].x0+s2*(x[t+1].x0-x[t].x0),x[t].y0+s2*(x[t+1].y0-x[t].y0)));
		if(t1>t2) min = s1;
		else max = s2;
	}
	double k = dist(x[s],point(x[t].x0+min*(x[t+1].x0-x[t].x0),x[t].y0+min*(x[t+1].y0-x[t].y0)));
	ans = ans<k?ans:k;
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lf%lf",&x[i].x0,&x[i].y0);
	x[0].x0 = x[a].x0, x[0].y0 = x[a].y0;
	x[a+1].x0 = x[1].x0, x[a+1].y0 = x[1].y0;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			//point i and line j - j+1
			double s1,s2,t;
			s1 = atan2(x[i].y0-x[i-1].y0,x[i].x0-x[i-1].x0);
			s2 = atan2(x[i+1].y0-x[i].y0,x[i+1].x0-x[i].x0);
			t = atan2(x[j+1].y0-x[j].y0,x[j+1].x0-x[j].x0);
			
			if(s1==0)
			{
				s2>0?(s1=-PHI):(s1=PHI);
				s2+=(s2>0?-PHI:PHI);
			}
			else if(s2==0)
			{
				s1>0?(s2=-PHI):(s2=PHI);
				s1+=(s1>0?-PHI:PHI);
			}
			else
			{
				s1+=(s1>0?-PHI:PHI);
				s2+=(s2>0?-PHI:PHI);
			}
			if(t<=-PHI) t+=2*PHI;
			
			if((s1-t)*(s2-t)<=0)
			{
				//printf("%d %d : %lf %lf %lf\n",i,j,s1,s2,t);
				func(i,j);
			}
		}
	}
	printf("%lf\n",ans);
}

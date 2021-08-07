#include <stdio.h>
#include <math.h>

struct Point{
	double x0;
	double y0;
	double z0;
}x,y,z;

double dist(Point A, Point B)
{
	return sqrt((A.x0-B.x0)*(A.x0-B.x0)+(A.y0-B.y0)*(A.y0-B.y0)+(A.z0-B.z0)*(A.z0-B.z0));
}
double area(double a, double b, double c)
{
	double s = (a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}
double angle(double a, double b, double c)
{
	return acos((a*a+b*b-c*c)/(2*a*b));
}

int main()
{
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		double r;
		scanf("%lf%lf%lf%lf",&x.x0,&x.y0,&x.z0,&r);
		scanf("%lf%lf%lf",&y.x0,&y.y0,&y.z0);
		scanf("%lf%lf%lf",&z.x0,&z.y0,&z.z0);
		
		if(area(dist(x,y),dist(y,z),dist(x,z))*2<=r*dist(y,z))
		{
			if(angle(dist(x,y),dist(y,z),dist(x,z))*2<3.1415926535&&angle(dist(x,z),dist(y,z),dist(x,y))*2<3.1415926535)
			{
				double ans = 0;
				double theta = angle(dist(x,y),dist(x,z),dist(y,z));
				ans += sqrt(dist(x,y)*dist(x,y)-r*r);
				ans += sqrt(dist(x,z)*dist(x,z)-r*r);
				theta -= acos(r/dist(x,y));
				theta -= acos(r/dist(x,z));
				
				ans += r*theta;
				printf("%.12lf\n",ans);
			}
			else printf("%.12lf\n",dist(y,z));
		}
		else printf("%.12lf\n",dist(y,z));
	}
}

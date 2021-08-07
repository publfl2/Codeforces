#include <stdio.h>
#include <math.h>
#define error 0.0000001
#define MAX 2000000000
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
double abs(double k)
{
	return k>0?k:-k;
}
double dist(Point a, Point b)
{
	double s = a.x0-b.x0;
	double t = a.y0-b.y0;
	return sqrt(s*s+t*t);
}
double ans = 1.415*2000000000;
void func(int s,int k1, int k2)
{
	//point s , line t - t+1
	double T = abs(x[k1].x0-x[k2].x0)>abs(x[k1].y0-x[k2].y0)?abs(x[k1].x0-x[k2].x0):abs(x[k1].y0-x[k2].y0);
	double min = -MAX/T, max = MAX/T;
	while(max-min>=error)
	{
		double s1 = (2*min+max)/3;
		double s2 = (min+2*max)/3;
		
		double t1 = dist(x[s],point(x[k1].x0+s1*(x[k2].x0-x[k1].x0),x[k1].y0+s1*(x[k2].y0-x[k1].y0)));
		double t2 = dist(x[s],point(x[k1].x0+s2*(x[k2].x0-x[k1].x0),x[k1].y0+s2*(x[k2].y0-x[k1].y0)));
		if(t1>t2) min = s1;
		else max = s2;
	}
	double k = dist(x[s],point(x[k1].x0+min*(x[k2].x0-x[k1].x0),x[k1].y0+min*(x[k2].y0-x[k1].y0)));
	ans = ans<k/2?ans:k/2;
}
int check[1010][1010];
void func2(int s,int k1, int k2)
{
	//point s , line t - t+1
	if(check[s][k1]) return;
	check[s][k1] = 1;
	double T = abs(x[k1].x0-x[k2].x0)>abs(x[k1].y0-x[k2].y0)?abs(x[k1].x0-x[k2].x0):abs(x[k1].y0-x[k2].y0);
	double min = -MAX/T, max = MAX/T;
	while(max-min>=error)
	{
		double s1 = (2*min+max)/3;
		double s2 = (min+2*max)/3;
		
		double t1 = dist(x[s],point(x[k1].x0+s1*(x[k2].x0-x[k1].x0),x[k1].y0+s1*(x[k2].y0-x[k1].y0)));
		double t2 = dist(x[s],point(x[k1].x0+s2*(x[k2].x0-x[k1].x0),x[k1].y0+s2*(x[k2].y0-x[k1].y0)));
		if(t1>t2) min = s1;
		else max = s2;
	}
	double k = dist(x[s],point(x[k1].x0+min*(x[k2].x0-x[k1].x0),x[k1].y0+min*(x[k2].y0-x[k1].y0)));
	ans = ans<k/2?ans:k/2;
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lf%lf",&x[i].x0,&x[i].y0);
	x[0].x0 = x[a].x0, x[0].y0 = x[a].y0;
	x[a+1].x0 = x[1].x0, x[a+1].y0 = x[1].y0;
	for(int i=1;i<=a;i++) func(i,i-1,i+1);
	
	for(int i=3;i<=a-1;i++) func2(1,i,i+1),func2(2,i,i+1);
	for(int i=2;i<a;i++)
	{
		//x[i], x[i+1]
		//1~2, 2~3, .... i-2,i-1, i+2,i+3, ... a-1,a, a,1
		for(int j=1;j<=i-2;j++) func2(i,j,j+1),func2(i+1,j,j+1);
		for(int j=i+2;j<=a;j++) func2(i,j,j+1),func2(i+1,j,j+1);
	}
	for(int i=2;i<=a-2;i++) func2(a,i,i+1),func2(1,i,i+1);
	printf("%.12lf",ans);
}

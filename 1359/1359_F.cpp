#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d,e,f;
		scanf("%d%d%d%d%d",&b,&c,&d,&e,&f);
		x[i]={b,c,d,e,f};
	}
	
	double min = 0, max = 3000;
	int count = 100;
	while(count--)
	{
		double h = (min+max)/2;
		for(int i=1;i<=a;i++) P1[i] = std::make_pair(x[i].x0,x[i].y0);
		for(int i=1;i<=a;i++) P2[i] = std::make_pair(x[i].x0+h*x[i].speed*x[i].dx0,x[i].y0+h*x[i].speed*x[i].dy0);
		if(P1[i].first > P2[i].first)
		{
			std::pair<double,double> P3 = P1[i];
			P1[i] = P2[i];
			P2[i] = P3;
		}
		for(int i=1;i<=a;i++) P3[i] = std::make_pair(P1[i],P2[i]);
		std::sort(P3+1,P3+a+1,cmp);
		
	}
}

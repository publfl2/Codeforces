#include <stdio.h>

struct Edge{
	double leftX;
	double leftY;
	double rightX;
	double rightY;
};

std::vector<Edge> UP;
std::vector<Edge> DOWN;

std::pair<Edge,Edge> divideUp(Edge a, Edge b)
{
	if(a.rightX<=b.leftX) return std::make_pair(a,b);
	else if(b.rightX<=a.leftX) return std::make_pair(b,a);
	
}

void insertUp(Edge A)
{
	for(int i=0;i<UP.size();i++)
	{
		double left = UP[i].leftX>A.
	}
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		
	}
}

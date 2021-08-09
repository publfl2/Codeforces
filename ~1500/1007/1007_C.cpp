#include <stdio.h>
#include <vector>
#include <stdlib.h>
struct Number{
	long long int value1;
	long long int value2;
	long long int M = 1;
	Number()
	{
		for(int i=1;i<=18;i++) M*=10;
		value1 = value2 = 0;
	}
	Number(long long int k)
	{
		for(int i=1;i<=18;i++) M*=10;
		value1 = 0, value2 = k;
	}
};

Number operator*(Number a, Number b)
{
	long long int M2 = 1;
	for(int i=1;i<=9;i++) M2*=10;
	
	long long int a1 = a.value2/M2;
	long long int a2 = a.value2%M2;
	long long int b1 = b.value2/M2;
	long long int b2 = b.value2%M2;
	
	Number c;
	c.value1 = a1*b1;
	c.value2 = a2*b2;
	long long int s = a1*b2+a2*b1;
	c.value1 += s/c.M;
	c.value2 += s%c.M;
	return c;
}

Number operator-(Number a, Number b)
{
	Number c;
	c.value1 = a.value1-b.value1;
	c.value2 = a.value2-b.value2;
	if(c.value2<0) c.value1--,c.value2 += c.M;
	return c;
}

Number operator+(Number a, Number b)
{
	Number c;
	c.value1 = a.value1+b.value1;
	c.value2 = a.value2+b.value2;
	if(c.value2>c.M) c.value1++,c.value2 -=c.M;
	return c;
}

bool operator<(Number a, Number b)
{
	if(a.value1==b.value1) return a.value2<b.value2;
	return a.value1<b.value1;
}

std::pair<long long int,long long int> func(long long int x1, long long int y1, long long int x2, long long int y2)
{
	
	if((Number)y1*(x1-x2)<(Number)x2*((y1-y2)/2)) return std::make_pair(x2,(y1+y2)/2);
	if((Number)x1*(y1-y2)<(Number)y2*((x1-x2)/2)) return std::make_pair((x1+x2)/2,y2);
	printf("%lld %lld %lld %lld!!\n",x1,x2,y1,y2);
	
	long long int minX = x2;
	long long int minY = y2;
	long long int maxX = x1;
	long long int maxY = y1;
	while(maxX-minX>=2&&maxY-minY>=2)
	{
		long long int x3 = (maxX+minX)/2;
		long long int y3 = (maxY+minY)/2;
		
		
		long long int s1 = y1*(x1-x3);
		long long int s2 = x1*(y1-y3);
		long long int s3 = x3*y3 - x2*y2;
		printf("%lld %lld %lld!!!\n",s1,s2,s3);
		/*Number s1 = (Number)y1*(x1-x3);
		Number s2 = (Number)x1*(y1-y3);
		Number s3 = (Number)x3*y3 - (Number)x2*y2;*/
		
		if(s1<s2&&s1<s3) maxX = x3-1;
		else if(s2<s1&&s2<s3) maxY = y3-1;
		else
		{
			if(s1<s2) minY = y3;
			else if(s1>s2) minX = x3;
			else
			{
				if(maxX-minX<maxY-minY) minY = y3;
				else maxX = x3;
			}
		}
		printf("%lld %lld %lld %lld!!\n",maxX,minX,maxY,minY);
	}
	return std::make_pair((maxX+minX)/2,(maxY+minY)/2);
}

long long int a = 2, b = 4;
int getQuery(long long int x0, long long int y0)
{
	if(a==x0&&b==y0) return 0;
	int check[5] = {};
	if(x0<a) check[1] = 1;
	if(y0<b) check[2] = 1;
	if(x0>a||y0>b) check[3] = 1;
	while(1)
	{
		int s = rand()%3 + 1;
		if(check[s]) return s;
	}
}

int main()
{
	long long int N;
	scanf("%lld",&N);
	
	long long int x1 = N;
	long long int x2 = 0;
	long long int y1 = N;
	long long int y2 = 0;
	long long int left = 0;
	long long int down = 0;
	
	while(1)
	{
		if(x1<=1&&y1<=1)
		{
			printf("end\n");
			return 0;
		}
		std::pair<long long int, long long int> P = func(x1,x2,y1,y2);
		int c = getQuery(left+x1-P.first,down+y1-P.second);
		if(c==0) return 0;
		
		if(c==1)
		{
			if(P.first==x2)
			{
				left += (x1-x2);
				x1 = P.first;
				x2 = 0;
				y1 = y1-y2;
				y2 = 0;
			}
			else
			{
				left += (x1-P.first);
				x1 = P.first;
			}
		}
		else if(c==2)
		{
			if(P.second==y2)
			{
				down += (y1-y2);
				x1 = x1-x2;
				x2 = 0;
				y1 = P.second;
				y2 = 0;
			}
			else
			{
				down += (y1-P.second);
				y1 = P.second;
			}
		}
		else
		{
			x2 = P.first;
			y2 = P.second;
		}
		
	}
}

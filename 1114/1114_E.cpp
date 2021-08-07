#include <stdio.h>
#include <algorithm>
#define MAX 1000000000
int getQuery1(int k)
{
	printf("? %d\n",k);
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	return a;
}

int getQuery2(int k)
{
	printf("> %d\n",k);
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	return a;
}

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}

int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	
	if(a<=50)
	{
		for(int i=1;i<=a;i++) x[i] = getQuery1(i);
		std::sort(x+1,x+a+1);
		printf("! %d %d\n",x[1],x[2]-x[1]);
		fflush(stdout);
		return 0;
	}
	
	int min = 0, max = MAX;
	int val = MAX+1;
	while(min<max)
	{
		int h = (min+max)/2;
		int s = getQuery2(h);
		if(s==1) min = h+1;
		else
		{
			val = h;
			max = h-1;
		}
	}
	val--;
	
	int d = 0;
	
	for(int i=1;i<=20;i++)
	{
		int s = getQuery1(i);
		int t = val-s;
		d = gcd(d,t);
	}
	printf("! %d %d\n",val-(a-1)*d,d);
	fflush(stdout);
}

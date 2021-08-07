#include <stdio.h>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}


int func(int k)
{
	int t = k;
	int ans = 1;
	for(int i=2;i*i<=k;i++)
	{
		int s = 1;
		while(t%i==0)
		{
			s++;
			t/=i;
		}
		ans *= s;
	}
	if(t==1) return ans;
	else return ans*2;
}

int func2(int a, int b, int c)
{
	int count = 0;
	for(int i=1;i<=100;i++)
	{
		for(int j=i;j<=100;j++)
		{
			for(int k=j;k<=100;k++)
			{
				if(a%i==0&&b%j==0&&c%k==0) count++;
				else if(a%i==0&&c%j==0&&b%k==0) count++;
				else if(b%i==0&&a%j==0&&c%k==0) count++;
				else if(b%i==0&&c%j==0&&a%k==0) count++;
				else if(c%i==0&&a%j==0&&b%k==0) count++;
				else if(c%i==0&&b%j==0&&a%k==0) count++;
			}
		}
	}
	return count;
}

struct str{
	int x0;
	int y0;
	int value;
}x[5][5];

int check[5][5];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		int e,f,g;
		e = gcd(b,c);
		f = gcd(c,d);
		g = gcd(b,d);
		int h;
		h = gcd(e,d);
		
		int b0 = func(b);
		int c0 = func(c);
		int d0 = func(d);
		int e0 = func(e);
		int f0 = func(f);
		int g0 = func(g);
		int h0 = func(h);
		
		
		ans = 0;
		for(int i1=1;i1<=4;i1++)
		{
			check[1][x[1][i1].x0] = 1;
			check[1][x[1][i1].y0] = 1;
			for(int i2=1;i2<=4;i2++)
			{
				check[2][x[2][i2].x0] = 1;
				check[2][x[2][i2].y0] = 1;
				for(int i3=1;i3<=4;i3++)
				{
					check[3][x[3][i3].x0] = 1;
					check[3][x[3][i3].y0] = 1;
					
					int s1 = 0, s2 = 0, s3 = 0;
					int t1 = x[1][i1].value;
					int t2 = x[2][i2].value;
					int t3 = x[3][i3].value;
					if(check[1][2]==1&&check[2][1]==1) s3 = 1;
					if(check[1][3]==1&&check[3][1]==1) s2 = 1;
					if(check[2][3]==1&&check[3][2]==1) s1 = 1;
					
					if(s1+s2+s3==3)
					{
						int s = x[1][i1].value;
						ans += s*(s-1)*(s-2)/6;
						ans += s*(s-1);
						ans += s;
					}
					else if(s1+s2==2)
					{
						ans += (t1-t2);
					}
					
					
					check[3][x[3][i3].x0] = 0;
					check[3][x[3][i3].y0] = 0;
				}
				check[2][x[2][i2].x0] = 1;
				check[2][x[2][i2].y0] = 1;
			}
			check[1][x[1][i1].x0] = 0;
			check[1][x[1][i1].y0] = 0;
		}
		
		printf("%d %d %d %d: %d!!\n",ans1,ans2,ans3,b0*c0*d0,func2(b,c,d));
	}
}

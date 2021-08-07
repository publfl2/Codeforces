#include <stdio.h>
#define MOD 100007
struct Matrix{
	int size;
	int value[10][10];
	Matrix()
	{
		for(int i=1;i<=7;i++) for(int j=1;j<=7;j++) value[i][j] = 0;
	}
};

Matrix operator*(Matrix A, Matrix B)
{
	Matrix C;
	C.size = A.size;
	int size = A.size;
	for(int i=1;i<=size;i++)
	{
		for(int j=1;j<=size;j++)
		{
			for(int k=1;k<=size;k++)
			{
				C.value[i][j] += A.value[i][k] * B.value[k][j];
				C.value[i][j] %= MOD;
			}
		}
	}
	return C;
}

Matrix func(long long int power, int size)
{
	if(power==0)
	{
		Matrix A;
		A.size = size;
		for(int i=1;i<=size;i++) A.value[i][i] = 1;
		return A;
	}
	else if(power==1)
	{
		Matrix A;
		A.size = size;
		for(int i=1;i<=size;i++) A.value[1][i] = 1;
		for(int i=2;i<=size;i++) A.value[i][i-1] = 1;
		return A;
	}
	else
	{
		if(power%2==0)
		{
			int h = power/2;
			Matrix A = func(h,size);
			return A*A;
		}
		else
		{
			int h = (power-1)/2;
			Matrix A = func(h,size);
			A = A*A;
			return A*func(1,size);
		}
	}
}

long long int x[100010],y[100010],x2[100010],y2[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	x2[1] = y2[1] = 1;
	for(int i=1;i<=b;i++)
	{
		char c[10];
		int d,e,f;
		scanf("%s%d%d%d",c+1,&d,&e,&f);
		if(c[1]=='a')
		{
			if(d<=e)
			{
				x2[d] += f;
				x2[e+1] -= f;
			}
			else // d>e
			{
				x2[d] += f;
				x2[a+1] -= f;
				x2[1] += f;
				x2[e+1] -= f;
			}
		}
		if(c[1]=='b')
		{
			if(d<=e)
			{
				y2[d] += f;
				y2[e+1] -= f;
			}
			else // d>e
			{
				y2[d] += f;
				y2[a+1] -= f;
				y2[1] += f;
				y2[e+1] -= f;
			}
		}
	}
	
	int s = 0;
	for(int i=1;i<=a;i++)
	{
		s += x2[i];
		x[i] = s;
	}
	s = 0;
	for(int i=1;i<=a;i++)
	{
		s += y2[i];
		y[i] = s;
	}
	for(int i=1;i<=a;i++) y[i]%=7;
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		if(y[i]==0)
		{
			ans++;
			continue;
		}
		//if(y[i]==0) y[i] += 7;
		if(x[i]<y[i])
		{
			ans++;
			continue;
		}
		Matrix A = func(x[i]-y[i],y[i]);
		int count = 0;
		for(int j=1;j<=A.size;j++)
		{
			count += A.value[1][j];
			count %= MOD;
		}
		ans += count;
	}
	printf("%d",ans);
}

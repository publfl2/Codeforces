#include <stdio.h>

char x[260][260];
int y[260][260][30];

int getSum(int k, int L, int R,int c)
{
	return y[k][R][c] - y[k][L-1][c];
}

long long int A[510];
int min(int a, int b)
{
	return a<b?a:b;
}
long long int func(int s1, int t1, int s2, int t2)
{
	printf("%d %d %d %d!!\n",s1,t1,s2,t2);
	if(s2>t2) return 0;
	int r = 0, p = 0;
	for(int i=1;i<=t2-s2+1;i++)
	{
		if(i<=r) A[i] = min(A[2*p-i],r-i);
		else A[i] = 0;
		while(i-A[i]-1>0 && i+A[i]+1<=t2-s2+1)
		{
			for(int j=1;j<=26;j++)
			{
				if(getSum(i+s2-1-A[i]-1,s1,t1,j)!=getSum(i+s2-1+A[i]+1,s1,t1,j)) goto u;
			}
			A[i]++;
		}
		u:;
		if(r<i+A[i]) r = i+A[i], p = i;
	}
	
	long long int sum = 0;
	for(int i=1;i<=t2-s2+1;i++) sum += A[i];
	return sum;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			for(int k=1;k<=26;k++) y[i][j][k] = y[i][j-1][k];
			y[i][j][x[i][j]-'a'+1]++;
		}
	}
	
	long long int ans = 0;
	for(int i=1;i<=b;i++)
	{
		for(int j=i;j<=b;j++)
		{
			int pivot = 1;
			if((j-i+1)%2==0)
			{
				for(int k=1;k<=a;k++)
				{
					for(int z=1;z<=26;z++)
					{
						if(getSum(k,i,j,z)%2==1)
						{
							ans += func(i,j,pivot,k-1);
							pivot = k+1;
							break;
						}
					}
				}
				ans += func(i,j,pivot,a);
			}
			else
			{
				for(int k=1;k<=a;k++)
				{
					int control = 0;
					for(int z=1;z<=26;z++)
					{
						if(getSum(k,i,j,z)%2==1&&control==1)
						{
							ans += func(i,j,pivot,k-1);
							pivot = k+1;
							break;
						}
						else if(getSum(k,i,j,z)%2==1) control = 1;
					}
					if(control==0)
					{
						ans += func(i,j,pivot,k-1);
						pivot = k+1;
					}
				}
				ans += func(i,j,pivot,a);
			}
		}
	}
	
	printf("%lld",ans);
}

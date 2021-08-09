#include <stdio.h>
#include <algorithm>

long long int MIN = -1;
long long int x[500010];
long long int y[500010],z[500010];

int a;
long long int b;
int p = -1;

long long int func1(int s, int t)
{
	return y[t] - y[s-1];
}
long long int func2(int s, int t)
{
	return (z[t] - z[s-1])-s*func1(s,t);
}

long long int check3[500010],check4[500010];
int C3[500010],C4[500010];
long long int func3(int s, int t)
{
	if(s==1&&C3[t]!=-1) return check3[t];
	if(s>t) return 0;
	long long int ans = func3(s+b+1,t)+func1(s,t);
	
	if(s==1)
	{
		C3[t] = 1;
		check3[t] = ans;
	}
	return ans;
}
long long int func4(int s, int t)
{
	if(C4[s]!=-1) return check4[s];
	if(s>t) return 0;
	C4[s] = 1;
	return check4[s] = func4(s+b,t) + func1(s,t);
}

int main()
{
	
	for(int i=1;i<=18;i++) MIN*=10;
	scanf("%d%lld",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=0;i<=a;i++) C4[i] = C3[i] = -1;
	
	std::sort(x+1,x+a+1);
	for(int i=1;i<=a;i++) y[i] = y[i-1] + x[i];
	for(int i=1;i<=a;i++) z[i] = z[i-1] + (i*x[i]);
	
	if(b==0)
	{
		long long int S = 0;
		long long int ans = 0;
		for(int i=a;i>=1;i--)
		{
			ans += S;
			S += x[i];
		}
		printf("%lld",ans);
	}
	else
	{
		long long int S = 0;
		long long int sum = 0;
		for(int i=a;i>=1;i--)
		{
			if(x[i]>=0)
			{
				sum += S;
				S += x[i];
			}
			else
			{
				p = i;
				break;
			}
		}
		
		if(p==-1)
		{
			printf("%lld",sum);
			return 0;
		}
		
		//1~p left
		
		long long int ans = MIN;
		int q = 0;
		for(int i=0;i<=p;i++)
		{
			//printf("%d %d %d!!\n",i,b,p);
			long long int t = S*i+sum;
			
			if(i*(b+1)<=p)
			{
				t += func3(1,i*(b+1)) - func1(1,i*(b+1));
				t += func4(i*(b+1)+1,p) + (i-1)*func1(i*(b+1)+1,p);
			}
			else
			{
				while(!(p-q<=(i-q)*(b+1)&&p-q>(i-q-1)*(b+1)))
				{
					q++;
					if(q>p) break;
				}
				t += func3(1,p-q) - func1(1,p-q);
				t += func2(p-q+1,p) + (i-q)*func1(p-q+1,p);
			}
			ans = ans>t?ans:t;
		}
		
		printf("%lld",ans);
	}
}

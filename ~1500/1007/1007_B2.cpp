#include <stdio.h>
#include <vector>

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

long long int check[100010];
long long int getCount(long long int k)
{
	if(check[k]) return check[k];
	std::vector<long long int> V;
	for(int i=1;i*i<=k;i++) if(k%i==0) V.push_back(i);
	for(int i=V.size()-1;i>=0;i--)
	{
		if(V[i]*V[i]==k) continue;
		V.push_back(k/V[i]);
	}
	return check[k] = V.size();
}

struct str{
	long long int x0;
	long long int y0;
	long long int z0;
}x[10];


long long int s1,s2,s3;
//1 2 6
void func(int k, long long int x1, long long int y1, long long int z1, int count)
{
	if(k>6)
	{
		if(count==0) return;
		else
		{
			long long int e = gcd(gcd(x1,y1),z1);
			long long int S1 = getCount(x1)*getCount(y1)*getCount(z1);
			long long int S2 = 0;
			S2 += getCount(gcd(x1,y1))*getCount(z1);
			S2 += getCount(gcd(x1,z1))*getCount(y1);
			S2 += getCount(gcd(y1,z1))*getCount(x1);
			long long int S3 = getCount(e)*getCount(e)*getCount(e);
			if(count%2==1)
			{
				s1 += S1;
				s2 += S2;
				s3 += S3;
				return;
			}
			else
			{
				s1 -= S1;
				s2 -= S2;
				s3 -= S3;
				return;
			}
		}
	}
	
	func(k+1,x1,y1,z1,count);
	func(k+1,gcd(x1,x[k].x0),gcd(y1,x[k].y0),gcd(z1,x[k].z0),count+1);
}
int main()
{
	int a;
	scanf("%d",&a);
	while(a--)
	{
		long long int b,c,d;
		scanf("%lld%lld%lld",&b,&c,&d);
		x[1].x0 = b, x[1].y0 = c, x[1].z0 = d;
		x[2].x0 = b, x[2].y0 = d, x[2].z0 = c;
		x[3].x0 = c, x[3].y0 = b, x[3].z0 = d;
		x[4].x0 = c, x[4].y0 = d, x[4].z0 = b;
		x[5].x0 = d, x[5].y0 = b, x[5].z0 = c;
		x[6].x0 = d, x[6].y0 = c, x[6].z0 = b;
		
		s1=s2=s3=0;
		func(1,b*c*d,b*c*d,b*c*d,0);
		printf("%lld %lld %lld : %lld\n",s1,s2,s3,s1+3*s2+2*s3);
	}
}

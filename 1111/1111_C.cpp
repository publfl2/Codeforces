#include <stdio.h>
#include <algorithm>
long long int a,b,c,d;
int x[100010];
long long int func(int left, int right, int L, int R)
{
	if(left==right) return (R-L+1) * d;
	int h = (left+right)/2;
	long long int s1 = (R-L+1)*d*(right-left+1);
	long long int s2;
	if(x[R]<=h) s2 = func(left,h,L,R)+c;
	else if(x[L]>=h+1) s2 = func(h+1,right,L,R)+c;
	else
	{
		int L2 = L, R2 = R;
		int t = L;
		while(L2<=R2)
		{
			int h2 = (L2+R2)/2;
			if(x[h2]<=h)
			{
				t = h2;
				L2 = h2+1;
			}
			else R2 = h2-1;
		}
		s2 = func(left,h,L,t) + func(h+1,right,t+1,R);
	}
	return s1<s2?s1:s2;
}
int main()
{
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	for(int i=1;i<=b;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+b+1);
	printf("%lld",func(1,(1<<a),1,b));
}

#include <stdio.h>

int query(long long int k)
{
	printf("? %lld\n",k);
	fflush(stdout);
	int C;
	scanf("%d",&C);
	return C;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	query(1);
	long long int L,R;
	for(int i=1;;i++)
	{
		long long int s = ((long long int)i*(i+1))/2;
		int k = query((s%a)+1);
		if(k<b)
		{
			L = s;
			R = s+i+1;
			break;
		}
		if(k>b)
		{
			R = s;
			L = s-i-1;
			break;
		}
	}
	L+=a, R+=a;
	L%=a, R%=a;
	while(L<=R)
	{
		long long int h = (L+R)/2;
		long long int d = (h-1)%a+1;
		long long int k = query(d);
		if(k==b)
		{
			printf("! %lld",d);
			fflush(stdout);
			return 0;
		}
		if(k<b) L = h+1;
		else R = h-1;
	}
}

#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		long long int x,y,p,q;
		scanf("%lld%lld%lld%lld",&x,&y,&p,&q);
		if(p==q)
		{
			if(x==y) printf("0\n");
			else printf("-1\n");
		}
		else
		{
			if(p*y<q*x) printf("0\n");
			else
			{
				long long int s = (p*y-q*x);
				long long int t = q-p;
				
				if(s%t==0) printf("%lld\n",s/t);
				else printf("%lld\n",s/t+1);
			}
		}
	}
}
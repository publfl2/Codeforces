#include <stdio.h>

long long int x[40],y[40];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		long long int e;
		scanf("%d%d%lld",&c,&d,&e);
		if(c==1) x[d] = e;
		else
		{
			for(int j=0;j<=a;j++) y[j] = x[j];
			long long int sum1 = 0, sum2 = 0;
			for(int j=0;j<=d;j++) sum1 += y[j];
			for(int j=0;j<=d;j++) sum2 += (long long int)((1<<j)-1)*y[j];
			
			if(sum1>=e) printf("0\n");
			else
			{
				long long int ans = 0;
				
				u:;
				long long int v = 1;
				for(int j=d+1;j<a;j++)
				{
					v*=2;
					if(v*y[j]<=(e-sum1))
					{
						sum1 += v*y[j];
						ans += (v-1)*y[j];
						sum2 += (long long int)((1<<d)-1)*v*y[j];
						y[j] = 0;
					}
					else
					{
						long long int t = (e-sum1)/v;
						if(t>0)
						{
							sum1 += v*t;
							ans += (v-1)*t;
							sum2 += (long long int)((1<<d)-1)*v*t;
							y[j] -= t;
						}
						else
						{
							if(sum2>=e-sum1)
							{
								printf("%lld\n",ans+(e-sum1));
								goto v2;
							}
							else if(j==d+1)
							{
								printf("%lld\n",ans+((e-sum1-1)/2+1));
								goto v2;
							}
							else
							{
								for(int k=j;k>=d+2;k--)
								{
									y[k]--;
									y[k-1]+=2;
									ans++;
								}
								goto u;
							}
						}
					}
				}
				//printf("%lld %lld %lld??\n",sum1,sum2,e);
				if(sum2>=e-sum1) printf("%lld\n",ans+(e-sum1));
				else printf("-1\n");
				v2:;
			}
		}
	}
}

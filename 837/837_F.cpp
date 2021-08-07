#include <stdio.h>
#include <math.h>
#define MAX 1234567890
long long int x[200010];
long long int sum[200010][3];
int main()
{
	int a;
	long long int b;
	scanf("%d%I64d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%I64d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		if(x[i]>=b)
		{
			printf("0");
			return 0;
		}
	}
	
	int start = 1;
	for(int i=1;i<=a;i++)
	{
		if(x[i]>0)
		{
			start = i;
			break;
		}
	}
	if(a-start==1)
	{
		// last 2 only
		// mth => (m,1)
		printf("%I64d",(b-x[a]-1)/x[a-1]+1);
	}
	else if(a-start==2)
	{
		//last 3 only
		// mth => (m(m+1)/2,m,1)
		long long int s1 = (long long int)sqrt(b/x[a-2])+10;
		long long int s2;
		if(x[a-1]==0) s2 = MAX;
		else s2 = b/x[a-1]+10;
		long long int min = 1, max = s1<s2?s1:s2;
		long long int ans = max;
		while(min<=max)
		{
			long long int h = (min+max)/2;
			long long int s1 = (h*(h+1)/2)*x[a-2]+h*x[a-1]+x[a];
			long long int s2 = h*x[a-2]+x[a-1];
			long long int s3 = x[a-2];
			if(s1>=b||s2>=b||s3>=b)
			{
				ans = h;
				max = h-1;
			}
			else min = h+1;
		}
		printf("%I64d",ans);
	}
	else
	{
		for(int i=start;i<=a;i++) sum[i][1] = x[i];
		long long int ans = 0;
		while(1)
		{
			ans++;
			for(int i=start;i<=a;i++)
			{
				sum[i][2] = sum[i-1][2] + sum[i][1];
				if(sum[i][2]>=b)
				{
					printf("%I64d",ans);
					return 0;
				}
			}
			
			ans++;
			for(int i=start;i<=a;i++)
			{
				sum[i][1] = sum[i-1][1] + sum[i][2];
				if(sum[i][1]>=b)
				{
					printf("%I64d",ans);
					return 0;
				}
			}
		}
	}
}

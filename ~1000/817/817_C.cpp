#include <stdio.h>
long long int s[20],t[20];
int main()
{
	t[1] = 1;
	for(int i=2;i<=19;i++) s[i] = s[i-1]*10 + 9;
	for(int i=2;i<=19;i++) t[i] = t[i-1]*10;
	
	long long int a,b;
	scanf("%I64d%I64d",&a,&b);
	
	long long int ans = 0;
	for(int i=2;i<=19;i++)
	{
		ans = 0;
		long long int S = b;
		for(int j=19;j>i;j--)
		{
			if(S>s[j])
			{
				if(S>9*s[j]) S-=9*s[j] , ans+=9*t[j];
				else ans+=(S/s[j])*t[j] , S-=(S/s[j])*s[j];
			}
		}
		if(S<=9*s[i])
		{
			ans+=((S-1)/s[i]+1)*t[i];
			break;
		}
	}
	if(ans>a) printf("0");
	else printf("%I64d",a-ans+1);
}

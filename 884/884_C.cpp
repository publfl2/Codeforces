#include <stdio.h>
#include <algorithm>
int x[100010];
int check[100010],S[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		int sum = 0;
		int t = i;
		while(1)
		{
			if(check[t]==1) break;
			check[t] = 1;
			sum++;
			t = x[t];
		}
		S[i] = sum;
	}
	std::sort(S+1,S+a+1);
	long long int ans = 0;
	ans = (long long int)(S[a]+S[a-1])*(S[a]+S[a-1]);
	for(int i=a-2;i>=1;i--) ans += (long long int)S[i]*S[i];
	printf("%I64d",ans);
}

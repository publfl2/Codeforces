#include <stdio.h>
#include <atcoder/convolution>

int x[200010],sum[200010],count[200010];
std::vector<long long int> V1,V2,V3;
long long int ans[200010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		if(x[i]<b) sum[i] = sum[i-1] + 1;
		else sum[i] = sum[i-1];
	}
	
	for(int i=0;i<=a;i++) V1.push_back(0),V2.push_back(0);
	for(int i=0;i<=a;i++) V1[sum[i]]++;
	for(int i=0;i<=a;i++) V2[a-sum[i]]++;
	
	V3 = atcoder::convolution(V1,V2);
	
	for(int i=a+1;i<=2*a;i++) ans[i-a] = V3[i];
	
	for(int i=0;i<=a;i++)
	{
		ans[0] += count[sum[i]];
		count[sum[i]]++;
	}
	
	printf("%lld ",ans[0]);
	for(int i=1;i<=a;i++) printf("%lld ",ans[i]);
}
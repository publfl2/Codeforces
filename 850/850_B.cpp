#include <stdio.h>
#include <queue>
 
int check[1000010],check2[1000010];
int x[500010];
std::queue<int> Q;
int main()
{
	freopen("input.txt","r",stdin);
	
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int j=2;j<=1000;j++)
	{
		long long int C = 0;
		for(int i=1;i<=a;i++)
		{
			long long int k = ((x[i]-1)/j+1)*j - x[i];
			C += (k*c<b?k*c:b);
		}
		ans = ans<C?ans:C;
	}
	
	for(int i=1;i<=a;i++) number[x[i]]++;
	for(int i=1;i<=a;i++) sum[x[i]]+=x[i];
	
	for(int j=1001;j<=1000000;j++)
	{
		
	}
	
	
	printf("%lld",ans);
}

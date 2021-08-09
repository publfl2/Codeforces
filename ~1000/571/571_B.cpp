#include <stdio.h>
#define MAX 2134567890
int x[300010];
int count[5010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) count[i%b]++;
	
	int L = 1;
	int R = a;
	long long int ans = 0;
	for(int i=1;i<=b;i++)
	{
		printf("%d %d!!\n",L,R);
		ans-=x[L];
		
		int tempVal = MAX;
		int tempR,tempL;
		for(int j=1;j<count[i%b];j++)
		{
			int L2 = L+j;
			int R2 = R-(count[i%b]-j);
			if(x[R]-x[L2]<tempVal)
			{
				tempVal = x[R2] - x[L2];
				tempR = R2;
				tempL = L2;
			}
		}
		if()
		L = tempL;
		R = tempR;
	}
	printf("%lld",ans);
}

#include <stdio.h>
#include <map>
#include <string.h>

char x[300010];
int left[300010],right[300010],value[300010];
std::map<int,int> M;

int main()
{
	int a;
	scanf("%d",&a);
	
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int b = strlen(x+1);
		int sum = 0;
		int limit = 0;
		for(int j=1;j<=b;j++)
		{
			if(x[j]==')') sum--;
			else sum++;
			limit = limit<sum?limit:sum;
		}
		//printf("%d : %d %d!!\n",i,limit,sum);
		if(limit==0)
		{
			if(sum==0) count++;
			else left[i] = 1,value[i] = sum;
		}
		else if(limit-sum>=0) right[i] = 1, value[i] = sum;
	}
	
	long long int ans = (long long int)count*count;
	for(int i=1;i<=a;i++) if(left[i]==1) M[-value[i]]++;
	for(int i=1;i<=a;i++) if(right[i]==1) ans += M[value[i]];
	printf("%lld",ans);
}

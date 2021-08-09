#include <stdio.h>
#include <algorithm>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		x[0] = 1;
		
		int p = a;
		int count = 0;
		while(1)
		{
			if(p>=x[p]) count++, p -= x[p];
			else break;
		}
		printf("%d\n",count);
	}
}

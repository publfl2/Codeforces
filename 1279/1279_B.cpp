#include <stdio.h>
#include <queue>
#include <vector>

std::priority_queue< int, std::vector<int>, std::greater<int> > Q;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		while(!Q.empty()) Q.pop();
		int b,c;
		scanf("%d%d",&b,&c);
		for(int j=1;j<=b;j++)
		{
			int d;
			scanf("%d",&d);
			Q.push(d);
		}
		long long int s = 0;
		
		if(Q.top()>c)
		{
			printf("0\n");
			goto u;
		}
		while(!Q.empty())
		{
			s+=Q.top();
			Q.pop();
			b--;
			
			if(s>c)
			{
				printf("%d\n",b+1);
				goto u;
			}
		}
		printf("0\n");
		
		u:;
	}
}

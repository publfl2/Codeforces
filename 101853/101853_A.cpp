#include <stdio.h>
#include <map>

std::map<int,int> M;
int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		M.clear();
		int count = 0;
		for(int i=1;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			if(M[c]==0&&c!=0) count++;
			M[c]++;
			x[i] = c;
		}
		for(int i=1;i<=b;i++)
		{
			int c;
			scanf("%d",&c);
			if(c==1)
			{
				int d,e;
				scanf("%d%d",&d,&e);
				M[x[d]]--;
				if(M[x[d]]==0&&x[d]!=0) count--;
				if(M[e]==0&&e!=0) count++;
				M[e]++;
				x[d] = e;
			}
			else if(c==2)
			{
				printf("%d\n",count);
			}
		}
	}
}

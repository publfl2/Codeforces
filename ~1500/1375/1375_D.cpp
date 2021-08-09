#include <stdio.h>
#include <vector>

std::vector<int> V,V2;
int x[1010],check[1010],y[1010];
int a;

int MEX()
{
	for(int j=0;j<=a;j++) check[j] = 0;
	for(int j=1;j<=a;j++) check[x[j]]++;
			
	for(int j=0;j<=a;j++)
	{
		if(check[j]==0)
		{
			return j;
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=a;i++) check[x[i]]++;
		
		int C;
		for(int i=1;i<=a;i++)
		{
			C = MEX();
			if(check[x[i]]>1)
			{
				V.push_back(i);
				check[x[i]]--;
				x[i] = C;
				check[C]++;
			}
		}
		
		for(int i=1;i<=a;i++) printf("%d ",x[i]);
		printf("!!\n");
		
		
		printf("%d\n",V.size());
		for(int i=0;i<V.size();i++) printf("%d ",V[i]);
		printf("\n");
	}
}

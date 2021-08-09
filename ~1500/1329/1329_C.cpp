#include <stdio.h>
#include <vector>
#include <map>

std::vector<int> V;
int x[2000010],y[2000010];
int check[2000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=((1<<a)-1);i++) scanf("%d",&x[i]);
		for(int i=a;i>b;i--)
		{
			for(int j=(1<<i)-1;j>=(1<<(i-1));j-=2)
			{
				V.push_back(j/2);
				int L = x[j-1];
				int R = x[j];
				if(L>R)
				{
					y[j/2] = R;
					x[j/2] = L;
				}
				else
				{
					y[j/2] = L;
					x[j/2] = R;
				}
			}
			
			for(int j=(1<<(i-1))-1;j>=3;j-=2)
			{
				int L = x[j-1];
				int R = x[j];
				if(check[j-1]==1&&check[j]==1)
				{
					y[j/2] = x[j/2];
					check[j/2] = 1;
					continue;
				}
				else if(check[j-1]==1)
				{
					if(L>R)
					{
						V.push_back(j);
						y[j/2] = x[j/2];
						check[j/2] = 1;
					}
					else
					{
						V.push_back(j/2);
						y[j/2] = R;
						x[j/2] = R;
						check[j/2] = 1;
					}
					continue;
				}
				else if(check[j]==1)
				{
					if(L<R)
					{
						V.push_back(j-1);
						y[j/2] = x[j/2];
						check[j/2] = 1;
					}
					else
					{
						V.push_back(j/2);
						y[j/2] = L;
						x[j/2] = L;
						check[j/2] = 1;
					}
					continue;
				}
				
				
				V.push_back(j/2);
				printf("%d %d??\n",L,R);
				if(L>R)
				{
					y[j/2] = R;
					x[j/2] = L;
					if(y[j-1]>x[j])
					{
						V.push_back(j);
						check[j/2] = 1;
					}
				}
				else
				{
					y[j/2] = L;
					x[j/2] = R;
					if(y[j]>x[j-1])
					{
						V.push_back(j-1);
						check[j/2] = 1;
					}
				}
			}
			
			for(int j=(1<<(i-1))-1;j>=1;j--) x[j] = y[j];
		}
		
		long long int ans = 0;
		for(int i=1;i<(1<<b);i++) ans += x[i];
		printf("%lld\n",ans);
		for(int i=0;i<V.size();i++) printf("%d ",V[i]);
	}
}

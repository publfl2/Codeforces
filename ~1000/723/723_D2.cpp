#include <stdio.h>
#include <vector>
std::vector< std::pair<int,int> > V[3];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]=='.')
			{
				V[(i+j)%2].push_back(std::make_pair(i,j));
			}
		}
	}
	
	if(V[0].size()>=c)
	{
		for(int i=0;i<V[1].size();i++)
		{
			
		}
	}
}

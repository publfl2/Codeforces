#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		temp[c].push_back({d,e});
	}
	
	for(int i=0;i<a;i++)
	{
		std::sort(temp[i].begin(),temp[i].end());
		for(int j=0;j<temp[i].size();j++)
		{
			
		}
	}
	for(int i=0;i<a;i++) for(int j=0;j<a;j++) V[i][j].push_back({i,(j+1)%a,1});
	
	
}
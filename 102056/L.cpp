#include <stdio.h>
#include <vector>

int x[100010];
std::vector<int> V[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int s=0,t=0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]==1) s++;
		else t++;
	}
	
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(x[c]!=x[d])
		{
			V[c].push_back(d);
			V[d].push_back(c);
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]==1) printf("%d ",s-1+2*t-V[i].size());
		else printf("%d ",t-1+2*s-V[i].size());
	}
}

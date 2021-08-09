#include <stdio.h>
#include <vector>

int gcd(int a, int b)
{
	return a?gcd(b%a,a):b;
}
int a,b;
std::vector< std::pair<int,int> > V;
int main()
{
	scanf("%d%d",&a,&b);
	if(b<a-1)
	{
		printf("Impossible");
		return 0;
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			if(V.size()==b) goto u;
			else if(gcd(i,j)==1) V.push_back(std::make_pair(i,j));
		}
	}
	
	u:;
	if(V.size()==b)
	{
		printf("Possible\n");
		for(int i=0;i<V.size();i++) printf("%d %d\n",V[i].first,V[i].second);
	}
	else printf("Impossible");
}



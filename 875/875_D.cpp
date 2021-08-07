#include <stdio.h>
#include <set>
std::set< std::pair<int,int> > S;
int x[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) S.insert(std::make_pair(x[i],i));
	
	while(!S.empty())
	{
		int index = (S.begin())->second;
		
	}
}

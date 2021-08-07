#include <stdio.h>
#include <vector>

std::vector<int> V;
int main()
{
	for(int i=0;i<V.size()-1;i++)
	{
		printf("%d %d\n",i,V.size());
	}
}

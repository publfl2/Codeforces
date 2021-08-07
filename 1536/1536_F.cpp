#include <stdio.h>
#include <vector>
#include <algorithm>

int check1[110],check2[110];
std::vector<int> V;
int main()
{
	check1[0] = 0;
	check2[0] = 0;
	check1[1] = 1;
	check2[1] = 0;
	for(int i=2;i<=100;i++)
	{
		V.clear();
		for(int j=1;j<i-1;j++)
		{
			V.push_back(check1[j]^check1[i-1-j]);
			V.push_back(check2[j]^check2[i-1-j]);
		}
		V.push_back(check2[i-1]);
		std::sort(V.begin(),V.end());
		V.erase(std::unique(V.begin(),V.end()),V.end());
		for(int j=0;j<V.size();j++)
		{
			if(V[j]!=j)
			{
				check1[i] = j;
				goto u1;
			}
		}
		check1[i] = V.size();
		u1:;
		
		V.clear();
		for(int j=1;j<i-1;j++)
		{
			V.push_back(check1[j]^check2[i-1-j]);
			V.push_back(check2[j]^check1[i-1-j]);
		}
		V.push_back(check1[i-1]);
		std::sort(V.begin(),V.end());
		V.erase(std::unique(V.begin(),V.end()),V.end());
		for(int j=0;j<V.size();j++)
		{
			if(V[j]!=j)
			{
				check2[i] = j;
				goto u2;
			}
		}
		check2[i] = V.size();
		u2:;
	}
	
	for(int i=1;i<=100;i++) printf("%d : %d %d\n",i,check1[i],check2[i]);
}
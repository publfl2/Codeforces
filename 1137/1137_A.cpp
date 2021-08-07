#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

int x[1010][1010];
int min1[1010][1010],min2[1010][1010],max2[1010][1010],max1[1010][1010];
std::vector<int> index;
std::map<int,int> hash;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
	for(int i=1;i<=a;i++)
	{
		index.clear();
		hash.clear();
		for(int j=1;j<=b;j++) index.push_back(x[i][j]);
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		for(int j=0;j<index.size();j++) hash[index[j]] = j;
		for(int j=1;j<=b;j++)
		{
			int k = hash[x[i][j]];
			min1[i][j] = k;
			max1[i][j] = index.size()-1-k;
		}
	}
	for(int j=1;j<=b;j++)
	{
		index.clear();
		hash.clear();
		for(int i=1;i<=a;i++) index.push_back(x[i][j]);
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		for(int i=0;i<index.size();i++) hash[index[i]] = i;
		for(int i=1;i<=a;i++)
		{
			int k = hash[x[i][j]];
			min2[i][j] = k;
			max2[i][j] = index.size()-1-k;
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			int s = min1[i][j]>min2[i][j]?min1[i][j]:min2[i][j];
			int t = max1[i][j]>max2[i][j]?max1[i][j]:max2[i][j];
			printf("%d ",s+t+1);
		}
		printf("\n");
	}
}

#include <stdio.h>
#include <vector>
 
std::vector<int> V[100010];
std::pair<int,int> func(int k ,int prev)
{
	std::vector< std::pair<int,int> > V2;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		V2.push_back(func(V[k][i],k));
	}
	
	int s1 = 1;
	int max0 = 0;
	for(int i=0;i<V2.size();i++) max0 = max0>V2[i].second?max0:V2[i].second;
	s1 += max0; 
	
	int s2 = 0;
	for(int i=0;i<V2.size();i++) s2 += V2[i].second;
	
	std::vector<int> V3;
	for(int i=0;i<V2.size();i++) V3.push_back((1>V2[i].second?1:V2[i].second));
	
	int S = 0;
	for(int i=0;i<V3.size();i++) S += V3[i];
	int max1 = 0;
	for(int i=0;i<V3.size();i++)
	{
		int M = S - V3[i] + V2[i].first;
		max1 = max1>M?max1:M;
	}
	s2 = s2>max1?s2:max1;
	
	return std::make_pair(s1,s2);
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	std::pair<int,int> ans = func(1,0);
	printf("%d",ans.first>ans.second?ans.first:ans.second);
}

#include <stdio.h>
#include <vector>
#include <algorithm>

struct str{
	int first;
	int second;
	int index;
}P[200010];
bool cmp1(str a, str b)
{
	return a.first<b.first;
}
bool cmp2(str a, str b)
{
	return a.second<b.second;
}

std::vector<int> V1[200010],V2[200010],V3[200010];
int check[200010];
void func(int k, int color)
{
	if(check[k]) return;
	check[k] = color;
	for(int i=0;i<V3[k].size();i++) func(V3[k][i],3-color);
}

std::vector<int> save1[200010],save2[200010];
int count1[3][200010],count2[3][200010];
std::vector<str> temp;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		P[i] = {b,c,i};
	}
	std::sort(P+1,P+a+1,cmp1);
	for(int i=1;i<a;i++)
	{
		if(P[i].first==P[i+1].first)
		{
			V1[P[i].index].push_back(P[i+1].index);
			V1[P[i+1].index].push_back(P[i].index);
		}
	}
	std::sort(P+1,P+a+1,cmp2);
	for(int i=1;i<a;i++)
	{
		if(P[i].second==P[i+1].second)
		{
			V2[P[i].index].push_back(P[i+1].index);
			V2[P[i+1].index].push_back(P[i].index);
		}
	}
	
	for(int i=1;i<=a;i++) if(V1[P[i].index].size()>0&&V2[P[i].index].size()>0) temp.push_back(P[i]);
	//for(int i=0;i<temp.size();i++) printf("%d ",temp[i].index);
	//printf("!!\n");
	std::sort(temp.begin(),temp.end(),cmp1);
	for(int i=0;i+1<temp.size();i++)
	{
		if(temp[i].first==temp[i+1].first)
		{
			V3[temp[i].index].push_back(temp[i+1].index);
			V3[temp[i+1].index].push_back(temp[i].index);
		}
	}
	std::sort(temp.begin(),temp.end(),cmp2);
	for(int i=0;i+1<temp.size();i++)
	{
		if(temp[i].second==temp[i+1].second)
		{
			V3[temp[i].index].push_back(temp[i+1].index);
			V3[temp[i+1].index].push_back(temp[i].index);
		}
	}
	
	for(int i=0;i<temp.size();i++) func(temp[i].index,1);
	for(int i=0;i<temp.size();i++)
	{
		count1[check[temp[i].index]][temp[i].first]++;
		count2[check[temp[i].index]][temp[i].second]++;
	}
	
	for(int i=1;i<=a;i++)
	{
		if(V1[P[i].index].size()==0||V2[P[i].index].size()==0)
		{
			if(V1[P[i].index].size()==0) save2[P[i].second].push_back(P[i].index);
			else save1[P[i].first].push_back(P[i].index);
		}
	}
	for(int i=1;i<=200000;i++)
	{
		for(int j=0;j<save1[i].size();j++)
		{
			if(count1[1][i]>count1[2][i])
			{
				check[save1[i][j]] = 2;
				count1[2][i]++;
			}
			else
			{
				check[save1[i][j]] = 1;
				count1[1][i]++;
			}
		}
	}
	for(int i=1;i<=200000;i++)
	{
		for(int j=0;j<save2[i].size();j++)
		{
			if(count2[1][i]>count2[2][i])
			{
				check[save2[i][j]] = 2;
				count2[2][i]++;
			}
			else
			{
				check[save2[i][j]] = 1;
				count2[1][i]++;
			}
		}
	}
	//for(int i=1;i<=a;i++) printf("%d " ,check[i]);
	for(int i=1;i<=a;i++)
	{
		if(check[i]==1) printf("r");
		else printf("b");
	}
}

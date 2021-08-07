#include <stdio.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>


long long int abs(long long int k)
{
	return k>0?k:-k;
}

std::vector<int> index1,index2;
std::map<int,int> hash1, hash2;
int check[1010][1010],check2[1010][1010];

std::set<int> S1[5][1010],S2[5][1010];
std::pair<int,int> P[1010];
std::vector< std::pair<int,int> > V[1010];

long long int dist(int s, int t)
{
	return abs(hash1[P[s].first]-hash1[P[t].first])+abs(hash2[P[s].second]-hash2[P[t].second]);
}

void func(int k, long long int limit, int color)
{
	check2[hash1[P[k].first]][hash2[P[k].second]] = color;
	S1[color][hash1[P[k].first]].insert(hash2[P[k].second]);
	S2[color][hash2[P[k].second]].insert(hash1[P[k].first]);
	
	for(int i=0;i<V[k].size();i++)
	{
		if(check2[hash1[P[V[k][i].first].first]][hash2[P[V[k][i].first].second]]==0 && V[k][i].second <= limit)
		{
			func(V[k][i].first,limit,color);
		}
	}
}


long long int MAX = 2;
int main()
{
	for(int i=1;i<=9;i++) MAX*=10;
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		P[i]=std::make_pair(b,c);
		index1.push_back(b);
		index2.push_back(c);
	}
	std::sort(index1.begin(),index1.end());
	std::sort(index2.begin(),index2.end());
	index1.erase(std::unique(index1.begin(),index1.end()),index1.end());
	index2.erase(std::unique(index2.begin(),index2.end()),index2.end());
	for(int i=0;i<index1.size();i++) hash1[index1[i]] = i+1;
	for(int i=0;i<index2.size();i++) hash2[index2[i]] = i+1;
	
	for(int i=1;i<=a;i++) check[hash1[P[i].first]][hash2[P[i].second]] = i;
	
	for(int i=1;i<=1000;i++)
	{
		int p = -1;
		for(int j=1;j<=1000;j++)
		{
			if(check[i][j]>0)
			{
				if(p==-1) p = j;
				else
				{
					int d = dist(check[i][p],check[i][j]);
					V[check[i][p]].push_back(std::make_pair(check[i][j],d));
					V[check[i][j]].push_back(std::make_pair(check[i][p],d));
					p = j;
				}
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		printf("%d!!\n",V[i].size());
	}
	
	for(int j=1;j<=1000;j++)
	{
		int p = -1;
		for(int i=1;i<=1000;i++)
		{
			if(check[i][j]>0)
			{
				if(p==-1) p = i;
				else
				{
					int d = dist(check[p][j],check[i][j]);
					V[check[p][j]].push_back(std::make_pair(check[i][j],d));
					V[check[i][j]].push_back(std::make_pair(check[p][j],d));
					p = i;
				}
			}
		}
	}
	
	long long int min = 1, max = MAX;
	long long int ans = MAX+1;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		
		int C = 1;
		for(int i=1;i<=a;i++) check2[hash1[P[i].first]][hash2[P[i].second]] = 0;
		for(int i=1;i<=a;i++) for(int j=1;j<=4;j++)
		{
			S1[j][i].clear();
			S2[j][i].clear();
		}
		for(int i=1;i<=a;i++)
		{
			if(check2[hash1[P[i].first]][hash2[P[i].second]]==0) func(i,h,C++);
		}
		printf("%lld : %d!!\n",h,C);
		
		if(C>4) min = h+1;
		else if(C==1)
		{
			ans = h;
			max = h-1;
		}
		else
		{
			for(int i=1;i<=index1.size();i++)
			{
				for(int j=1;j<=index2.size();j++)
				{
					if(check[i][j]>0) continue;
					for(int k=1;k<=C;k++)
					{
						std::set<int> ::iterator it = S1[k][i].lower_bound(j);
						if(it!=S1[k][i].end())
						{
							if(abs(hash2[(*it)]-hash2[j])<=h)
							{
								goto u;
							}
						}
						if(it!=S1[k][i].begin())
						{
							it--;
							if(abs(hash2[(*it)]-hash2[j])<=h)
							{
								goto u;
							}
						}
						
						it = S2[k][j].lower_bound(i);
						if(it!=S2[k][j].end())
						{
							if(abs(hash1[(*it)]-hash1[i])<=h)
							{
								goto u;
							}
						}
						if(it!=S2[k][j].begin())
						{
							it--;
							if(abs(hash1[(*it)]-hash1[i])<=h)
							{
								goto u;
							}
						}
						goto u2;
						u:;
					}
					ans = h;
					max = h-1;
					goto v;
					u2:;
				}
			}
			min = h+1;
			v:;
		}
	}
	printf("%lld",ans);
}

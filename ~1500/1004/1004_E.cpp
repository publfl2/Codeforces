#include <stdio.h>
#include <vector>
#define MAX 1000000000

std::vector< std::pair<int,int> > V[100010];

std::pair<int,int> size[100010];
int maxDist[100010];
std::pair<int,int> func(int k,int p)
{
	int max1=0, max2=0;
	int max=0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==p) continue;
		std::pair<int,int> P = func(V[k][i].first,k);
		P.first += V[k][i].second;
		max = max>P.second?max:P.second;
		if(P.first>=max1)
		{
			max2 = max1;
			max1 = P.first;
		}
		else if(P.first>max2) max2 = P.first;
	}
	maxDist[k] = max1+max2;
	max = max>max1+max2?max:max1+max2;
	return size[k] = std::make_pair(max1,max);
}

int func3(int k, int p, int h)
{
	int count = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==p) continue;
		if(size[V[k][i].first].second>h) count++;
		else if(size[V[k][i].first].first+V[k][i].second>h) count++;
	}
	if(count>=2) return 123456;
	else if(count==1)
	{
		for(int i=0;i<V[k].size();i++)
		{
			if(V[k][i].first==p) continue;
			if(size[V[k][i].first].second>h) return func3(V[k][i].first,k,h)+1;
			else if(size[V[k][i].first].first+V[k][i].second>h) return func3(V[k][i].first,k,h)+1;
		}
	}
	else return 1;
}

int func2(int k, int p, int h, int save)
{
	int count = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first == p) continue;
		if(size[V[k][i].first].second>h) count++;
		else if(size[V[k][i].first].first+V[k][i].second>h) count++;
	}
	if(count>2) return 123456;
	else if(count==2)
	{
		int sum = 0;
		for(int i=0;i<V[k].size();i++)
		{
			if(V[k][i].first==p) continue;
			if(size[V[k][i].first].second>h) sum += func3(V[k][i].first,k,h);
			else if(size[V[k][i].first].first+V[k][i].second>h) sum += func3(V[k][i].first,k,h);
		}
		return sum+1;
	}
	else if(count==1)
	{
		int max1 = 0, max2 = 0;
		for(int i=0;i<V[k].size();i++)
		{
			if(V[k][i].first==p) continue;
			if(size[V[k][i].first].second>h) continue;
			if(size[V[k][i].first].first+V[k][i].second>h) continue;
			
			int dist = size[V[k][i].first].first+V[k][i].second;
			if(dist>=max1)
			{
				max2 = max1;
				max1 = dist;
			}
			else if(dist>max2) max2 = dist;
		}
		if((max1+max2>h)||(max1+save>h))
		{
			for(int i=0;i<V[k].size();i++)
			{
				if(V[k][i].first==p) continue;
				if(size[V[k][i].first].second>h) return func3(V[k][i].first,k,h)+1;
				if(size[V[k][i].first].first+V[k][i].second>h) return func3(V[k][i].first,k,h)+1;
			}
		}
		else
		{
			for(int i=0;i<V[k].size();i++)
			{
				if(V[k][i].first==p) continue;
				if(size[V[k][i].first].second>h)
				{
					if(V[k][i].second+save>h) return func3(V[k][i].first,k,h)+1;
					else return func2(V[k][i].first,k,h,V[k][i].second+(save>max1?save:max1));
				}
				if(size[V[k][i].first].first+V[k][i].second>h)
				{
					if(V[k][i].second+save>h) return func3(V[k][i].first,k,h)+1;
					else return func2(V[k][i].first,k,h,V[k][i].second+(save>max1?save:max1));
				}
			}
		}
	}
	else
	{
		int max1 = 0, max2 = 0;
		for(int i=0;i<V[k].size();i++)
		{
			if(V[k][i].first == p) continue;
			int dist = size[V[k][i].first].first + V[k][i].second;
			if(dist>=max1)
			{
				max2 = max1;
				max1 = dist;
			}
			else if(dist>max2) max2 = dist;
		}
		if((save+max1)>h||(max1+max2)>h) return 1;
		else return 0;
	}
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<a;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		V[c].push_back(std::make_pair(d,e));
		V[d].push_back(std::make_pair(c,e));
	}
	func(1,0);
	
	int min =0 , max = MAX;
	int ans = MAX;
	while(min<=max)
	{
		int h = (min+max)/2;
		int k = func2(1,0,h,0);
		if(k<=b)
		{
			ans = h;
			max = h-1;
		}
		else min = h+1;
	}
	printf("%d",ans);
}

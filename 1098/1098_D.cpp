#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
#define MAX 2e9

struct segTree{
	long long int value[2000010];
	void addValue(int ind, int val, int l=1, int r=500000, int v=1)
	{
		if(l==r) value[v] += val;
		else
		{
			int h = (l+r)/2;
			if(ind<=h) addValue(ind,val,l,h,2*v);
			else addValue(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]+value[2*v+1];
		}
	}
	long long int getSum(int L, int R, int l=1, int r=500000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(r<L) return 0;
		else if(R<l) return 0;
		else
		{
			int h = (l+r)/2;
			long long int s1 = getSum(L,R,l,h,2*v);
			long long int s2 = getSum(L,R,h+1,r,2*v+1);
			return s1+s2;
		}
	}
}T;

std::vector<int> index;
std::map<int,int> hash,M;
std::vector< std::pair<int,int> > query;
char x[10];
int main()
{
	int a;
	scanf("%d",&a);
	M[0]++, M[MAX]++;
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%s",x+1);
		scanf("%d",&b);
		if(x[1]=='+') query.push_back(std::make_pair(1,b));
		else query.push_back(std::make_pair(2,b));
	}
	
	for(int i=1;i<=a;i++) index.push_back(query[i].second);
	std::sort(index.begin(),index.end());
	index.erase(std::unique(index.begin(),index.end()),index.end());
	for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
	
	int sum1 = 0, sum2 = 0;
	for(int i=0;i<query.size();i++)
	{
		int t = query[i].second;
		if(query[i].first==1)
		{
			sum1++;
			M[t]++;
			std::map<int,int> ::iterator it = M.find(t),it2,it3;
			it2 = it, it3 = it;
			it2++, it3--;
			int L = (it3->first), R = (it2->first);
			if(M[t]==1)
			{
				if(L!=0&&R!=MAX) if(T.getSum(1,hash[L])*2>=R) sum2--;
				T.addValue(hash[t],t);
				if(L!=0)
				{
					if(T.getSum(1,hash[L])*2>=t) sum2++;
				}
				if(R!=a+1) if(T.getSum(1,hash[t])*2>=R) sum2++;
			}
			else
			{
				T.addValue(hash[t],t);
				long long int temp = T.getSum(1,hash[t]);
				if((temp-t)*2<R && 2*temp>=R) sum2++;
				sum2++;
			}
		}
		else
		{
			sum1--;
			M[t]--;
			std::map<int,int> ::iterator it = M.find(t),it2,it3;
			it2 = it, it3 = it;
			it2++, it3--;
			int L = (it3->first), R = (it2->first);
			if(M[t]==0)
			{
				if(L!=0) if(T.getSum(1,hash[L])*2>=t) sum2--;
				if(R!=a+1) if(T.getSum(1,hash[t])*2>=R) sum2--;
				T.addValue(hash[t],-t);
				if(L!=0&&R!=MAX) if(T.getSum(1,hash[L])*2>=R) sum2++;
				M.erase(it);
			}
			else
			{
				T.addValue(hash[t],-t);
				long long int temp = T.getSum(1,hash[t]);
				if((temp+t)*2>=R && 2*temp<R) sum2--;
				sum2--;
			}
		}
		printf("%d\n",sum2);
	}
}
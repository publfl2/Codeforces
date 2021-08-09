#include <stdio.h>
#include <set>
#include <algorithm>

std::multiset< std::pair<int,int> > S;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		S.insert(std::make_pair(b,c));
	}
	
	std::multiset< std::pair<int,int> > ::iterator it = S.end();
	it--;
	int rLimit = (it->first);
	int lLimit = (it->second);
	S.erase(it);
	long long int count = 0;
	for(int i=2;i<=a;i++)
	{
		it = std::lower_bound(S.begin(),S.end(),std::make_pair(lLimit+1,0));
		if(it==S.begin())
		{
			count += (it->first);
			printf("%d!!\n",it->first);
			lLimit = (it->second);
			S.erase(it);
		}
		else
		{
			it--;
			count += (lLimit);
			printf("%d??\n",lLimit);
			lLimit = (it->second);
			S.erase(it);
		}
	}
	count += (rLimit>lLimit)?rLimit:lLimit;
	printf("%lld",count+a);
}

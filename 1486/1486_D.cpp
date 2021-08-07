#include <stdio.h>
#include <set>

std::multiset<int> S1,S2;

int x[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int ans = 0;
	std::multiset<int> ::iterator it;
	for(int i=1;i<=b;i++)
	{
		S1.insert(x[i]);
		while(S1.size()>S2.size()+2)
		{
			it = S1.begin();
			S2.insert(*it);
			S1.erase(it);
		}
		while(S2.size()>=S1.size())
		{
			it = S2.end();
			it--;
			S2.insert(*it);
			S1.erase(it);
		}
		while(S1.size()>S2.size()+2)
		{
			it = S1.begin();
			S2.insert(*it);
			S1.erase(it);
		}
	}
	it = S1.begin();
	ans = ans>(*it)?ans:(*it);
	for(int i=b+1;i<=a;i++)
	{
		it = S1.find(x[i-b]);
		if(it!=S1.end()) S1.erase(it);
		else
		{
			it = S2.find(x[i-b]);
			S2.erase(it);
		}
		
		S1.insert(x[i]);
		while(S1.size()>S2.size()+2)
		{
			it = S1.begin();
			S2.insert(*it);
			S1.erase(it);
		}
		while(S2.size()>=S1.size())
		{
			it = S2.end();
			it--;
			S2.insert(*it);
			S1.erase(it);
		}
		while(S1.size()>S2.size()+2)
		{
			it = S1.begin();
			S2.insert(*it);
			S1.erase(it);
		}
		
		it = S1.begin();
		ans = ans>(*it)?ans:(*it);
	}
	
	b++;
	S1.clear();
	S2.clear();
	if(b>a)
	{
		printf("%d",ans);
		return 0;
	}
	
	for(int i=1;i<=b;i++)
	{
		S1.insert(x[i]);
		while(S1.size()>S2.size()+2)
		{
			it = S1.begin();
			S2.insert(*it);
			S1.erase(it);
		}
		while(S2.size()>=S1.size())
		{
			it = S2.end();
			it--;
			S2.insert(*it);
			S1.erase(it);
		}
		while(S1.size()>S2.size()+2)
		{
			it = S1.begin();
			S2.insert(*it);
			S1.erase(it);
		}
	}
	it = S1.begin();
	ans = ans>(*it)?ans:(*it);
	for(int i=b+1;i<=a;i++)
	{
		it = S1.find(x[i-b]);
		if(it!=S1.end()) S1.erase(it);
		else
		{
			it = S2.find(x[i-b]);
			S2.erase(it);
		}
		
		S1.insert(x[i]);
		while(S1.size()>S2.size()+2)
		{
			it = S1.begin();
			S2.insert(*it);
			S1.erase(it);
		}
		while(S2.size()>=S1.size())
		{
			it = S2.end();
			it--;
			S2.insert(*it);
			S1.erase(it);
		}
		while(S1.size()>S2.size()+2)
		{
			it = S1.begin();
			S2.insert(*it);
			S1.erase(it);
		}
		it = S1.begin();
		ans = ans>(*it)?ans:(*it);
	}
	
	printf("%d",ans);
}
#include <stdio.h>
#include <vector>

struct str{
	long long int first;
	long long int second;
	int type;
};
std::vector<str> ans;
std::vector<int> V;
std::vector<long long int> T;
int func(long long int k)
{
	T.clear();
	V.clear();
	long long int k2 = k;
	while(k2)
	{
		V.push_back(k2%2);
		k2/=2;
	}
	
	int L=0,R,d=0;
	for(int i=0;i<V.size();i++)
	{
		if(V[i]==1) break;
		else L++;
	}
	R = V.size();
	for(int i=V.size()-1;i>=0;i--)
	{
		if(V[i]==0)
		{
			d = i+1;
			break;
		}
	}
	if(L+1==R) return -1;
	
	long long int curr = k;
	for(int i=L+1;i<R;i++)
	{
		ans.push_back({curr,curr,1});
		curr*=2;
	}
	for(int i=1;i<d;i++) curr/=2;
	long long int t = curr;
	long long int t2 = k;
	int p = R-d;
	for(int i=1;i<=d;i++)
	{
		if((t2&t)!=0)
		{
			ans.push_back({t,t2,2});
			t2 = (t^t2);
			T.push_back(t);
		}
		p++;
		t*=2;
	}
	ans.push_back({t2,k,1});
	long long int t3 = (t2+k);
	for(int i=0;i<T.size();i++) ans.push_back({T[i],t3,2});
	return t3;
}

std::vector<long long int> basis;
int main()
{
	long long int a;
	scanf("%lld",&a);
	while(1)
	{
		basis.push_back(a);
		a = func(a);
		printf("%lld!!\n",a);
		if(a==-1) break;
	}
	
	int k = basis.size()-1;
	long long int t = basis.back();
	for(int i=basis.size()+1;i<=20;i++)
	{
		ans.push_back({t,t,1});
		t*=2;
	}
	
	for(int i=k;i>=0;i--)
	{
		long long int s = basis[i];
		for(int j=20;j>i;j--)
		{
			if((s&(1<<j))!=0)
			{
				ans.push_back({s,(1<<j),2});
				s -= (1<<j);
			}
		}
	}
	
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i].type==1) printf("%lld + %lld\n",ans[i].first,ans[i].second);
		if(ans[i].type==2) printf("%lld ^ %lld\n",ans[i].first,ans[i].second);
	}
}

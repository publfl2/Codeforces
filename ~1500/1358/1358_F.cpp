#include <stdio.h>
#include <vector>

std::vector<long long int> V1, V2;
std::vector<char> ans;
int a;
int control = 0;

int ansCheck1()
{
	for(int i=0;i<a;i++) if(V1[i]!=V2[i]) return 0;
	return 1;
}
int ansCheck2()
{
	for(int i=0;i<a;i++) if(V1[i]!=V2[a-i-1]) return 0;
	return 1;
}

int type1()
{
	for(int i=0;i<a-1;i++) if(V2[i]>=V2[i+1]) return 0;
	return 1;
}
int type2()
{
	for(int i=0;i<a-1;i++) if(V2[i]<=V2[i+1]) return 0;
	return 1;
}

void func()
{
	if(ans.size()>500000)
	{
		control = -1;
		return;
	}
	
	if(ansCheck1())
	{
		control = 1;
		return;
	}
	if(ansCheck2())
	{
		control = 1;
		ans.push_back('R');
		return;
	}
	
	if(type1())
	{
		ans.push_back('P');
		std::vector<long long int> V3;
		V3.push_back(V2[0]);
		for(int i=1;i<a;i++) V3.push_back(V2[i]-V2[i-1]);
		V2 = V3;
	}
	else if(type2())
	{
		ans.push_back('R');
		ans.push_back('P');
		std::vector<long long int> V3;
		V3.push_back(V2[a-1]);
		for(int i=a-1;i>=1;i--) V3.push_back(V2[i-1]-V2[i]);
		V2 = V3;
	}
	else
	{
		control = -1;
		return;
	}
	
}

int main()
{
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		long long int b;
		scanf("%lld",&b);
		V1.push_back(b);
	}
	for(int i=1;i<=a;i++)
	{
		long long int b;
		scanf("%lld",&b);
		V2.push_back(b);
	}
	
	while(1)
	{
		func();
		
		if(control==-1)
		{
			printf("IMPOSSIBLE");
			return 0;
		}
		
		if(control==1)
		{
			int count = 0;
			for(int i=0;i<ans.size();i++) if(ans[i]=='P') count++;
			if(count>200000)
			{
				printf("BIG\n%d",count);
				return 0;
			}
			else
			{
				printf("SMALL\n");
				printf("%d\n",ans.size());
				for(int i=ans.size()-1;i>=0;i--) printf("%c",ans[i]);
				return 0;
			}
		}
	}
}

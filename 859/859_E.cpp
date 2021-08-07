#include <stdio.h>
#include <vector>
#include <stack>
#define MOD 1000000007
int next[200010],check[200010],Col[200010];
int main()
{
	int a,d=3;
	long long int ans = 1;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		next[b] = c;
	}
	for(int i=1;i<=2*a;i++)
	{
		if(check[i]==0&&next[i]!=0)
		{
			std::vector<int> St;
			int t = i;
			if(next[i]==i)
			{
				check[i] = 2;
				continue;
			}
			while(1)
			{
				St.push_back(t);
				if(next[t]==0)
				{
					for(int j=0;j<St.size();j++) check[St[j]] = d;
					Col[d]+=St.size();
					d++;
					break;
				}
				else if(check[next[t]]==0)
				{
					check[t] = 1;
					t = next[t];
				}
				else
				{
					if(check[next[t]]==1)
					{
						for(int j=St.size()-1;j>=0;j--) if(next[t]==St[j]) ans*=(St.size()-j),ans%=MOD;
						for(int j=0;j<St.size();j++) check[St[j]] = 2;
						break;
					}
					else if(check[next[t]]==2)
					{
						for(int j=0;j<St.size();j++) check[St[j]] = 2;
						break;
					}
					else
					{
						int c = check[next[t]];
						Col[c]+=St.size();
						for(int j=0;j<St.size();j++) check[St[j]] = c;
						break;
					}
				}
			}
		}
	}
	for(int i=3;i<d;i++) ans*=Col[i],ans%=MOD;
	printf("%I64d",ans);
}

#include <stdio.h>
#include <algorithm>
#include <vector>

struct str{
	int value;
	int index;
}x[500010];
bool cmp(str a, str b)
{
	return a.value>b.value;
}

int getHeight(int k ,int prev)
{
	int s = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		int t = getHeight(V[k][i],k);
		s = s>t?s:t;
	}
	return s+1;
}

void func1(int k)
{
	V2.clear();
	for(int i=0;i<V[k].size();i++)
	{
		int t = getHeight(V[k][i],k);
		V2.push_back(t);
	}
	
	std::sort(V2.begin(),V2.end());
	for(int i=0;i<V2.size();i++)
	{
		if(V2[i]==V2[i+1]) ans[2*i] = ans[2*i]>V2[i]?ans2*[i]:V2[i];
		else ans[2*i+1] = ans[2*i+1]>V2[i]?ans[2*i+1]:V2[i];
	}
}
void func2(int k)
{
	V2.clear();
	for(int i=0;i<V[k].size();i++)
	{
		int t = getHeight(V[k][i],k);
		V2.push_back(t);
	}
	
	std::sort(V2.begin(),V2.end());
	for(int i=0;i<V2.size();i++)
	{
		if(V2[i]==V2[i+1]) ans[2*V2[i]] = ans[2*V2[i]] > (V2.size()-i) ? ans[2*V2[i]] : (V2.size()-1);
		else ans[2*V2[i]+1] = ans[2*V2[i]+1] > (V2.size()-i) ? ans[2*V2[i]+1] : (V2.size()-1);
	}
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
	for(int i=1;i<=a;i++) x[i]={V[i].size(),i};
	std::sort(x+1,x+a+1,cmp);
	
	int p = 1;
	for(int i=1;i<=a;i++)
	{
		if(x[i].value>=1000)
		{
			func1(x[i].index);
		}
		else
		{
			func2(i);
		}
	}
}

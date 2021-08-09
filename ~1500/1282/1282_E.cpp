#include <stdio.h>
#include <set>
int a;

std::set<int> S[100010];
int x[100010];
int ans1[300010],ans2[100010];
void func(int s, int t, int prev)
{
	if(t>=a) return;
	std::set<int> ::iterator it = S[s].begin();
	if(*it == prev)
	{
		it++;
		ans1[t] = *it;
		func(*it,t+1,s);
	}
	else
	{
		ans1[t] = *it;
		func(*it,t+1,s);
	}
}
int main()
{
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		scanf("%d",&a);
		for(int i=1;i<=a;i++) S[i].clear();
		for(int i=1;i<=a;i++) x[i] = 0;
		for(int i=1;i<=a-2;i++)
		{
			int b,c,d;
			scanf("%d%d%d",&b,&c,&d);
			if(S[b].find(c)!=S[b].end()) S[b].erase(c);
			else S[b].insert(c);
			if(S[b].find(d)!=S[b].end()) S[b].erase(d);
			else S[b].insert(d);
			if(S[c].find(b)!=S[c].end()) S[c].erase(b);
			else S[c].insert(b);
			if(S[c].find(d)!=S[c].end()) S[c].erase(d);
			else S[c].insert(d);
			if(S[d].find(b)!=S[d].end()) S[d].erase(b);
			else S[d].insert(b);
			if(S[d].find(c)!=S[d].end()) S[d].erase(c);
			else S[d].insert(c);
			x[b]++,x[c]++,x[d]++;
		}
		ans1[0] = 1;
		func(1,1,-1);
		for(int i=0;i<a;i++) ans1[a+i] = ans1[i], ans1[2*a+i] = ans1[i];
		
		int pivot = 0;
		for(int i=a;i<2*a;i++)
		{
			if(x[ans1[i]]==1)
			{
				pivot = i;
				x[ans1[pivot]]--, x[ans1[pivot-1]]--,x[ans1[pivot+1]]--;
				break;
			}
		}
		
		ans2[1] = ans1[pivot];
		int left = pivot-1, right = pivot+1;
		for(int i=2;i<=a-2;i++)
		{
			for(int j=1;j<=6;j++) printf("%d ",x[j]);
			printf("\n");
			if(x[ans1[left]]==1)
			{
				ans2[i] = ans1[left];
				x[ans1[left]]--,x[ans1[right]]--,x[ans1[left-1]]--;
				left--;
			}
			else
			{
				ans2[i] = ans1[right];
				x[ans1[left]]--,x[ans1[right]]--,x[ans1[right+1]]--;
				right++;
			}
		}
		for(int i=0;i<a;i++) printf("%d ",ans1[i]);
		printf("\n");
		for(int i=1;i<=a-2;i++) printf("%d ",ans2[i]);
		printf("\n");
	}
}

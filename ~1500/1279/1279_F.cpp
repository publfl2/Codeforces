#include <stdio.h>
#include <set>
struct str{
	int value;
	int index;
};

bool operator<(str a, str b)
{
	if(a.value==b.value) return a.index<b.index;
	return a.value<b.value;
}

int a,b,c;
int s[3][2000010];
int A[2000010];
int next1[2000010],next2[2000010],prev[2000010];
std::set<str> T;
int func(int type)
{
	T.clear();
	int S = 0;
	for(int i=1;i<=c;i++) S += s[type][i];
	A[1] = S;
	for(int i=2;i<=a-c+1;i++)
	{
		S -= s[type][i-1];
		S += s[type][i+c-1];
		A[i] = S;
	}
	for(int i=a-c+2;i<=a;i++)
	{
		S -= s[type][i-1];
		A[i] = S;
	}
	for(int i=1;i<=a;i++)
	{
		next1[i] = i+1;
		prev[i] = i-1;
		next2[i] = i+c;
	}
	
	int ans = 0;
	for(int i=1;i<=a;i++) ans += s[type][i];
	for(int i=1;i<=a;i++) T.insert({A[i],i});
	for(int i=1;i<=b;i++)
	{
		if(T.empty()) break;
		std::set<str> ::iterator it;
		it = T.end(); it--;
		ans -= (it->value);
		
		int count = c;
		int v = it->index;
		next1[prev[v]] = next2[v];
		prev[next2[v]] = prev[v];
		
		while(count--)
		{
			v = prev[v];
			if(v<=0) break;
			T.erase({A[v],v});
			A[v] = A[v] + A[next2[v]] - (it->value);
			T.insert({A[v],v});
			next2[v] = next2[next2[v]];
		}
		
		count = c;
		v = it->index;
		while(count--)
		{
			if(v>=a+1) break;
			T.erase({A[v],v});
			v = next1[v];
		}
	}
	return ans;
}

char x[1000010];
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++) s[1][i] = (('a'<=x[i]&&x[i]<='z')?1:0);
	for(int i=1;i<=a;i++) s[2][i] = (('A'<=x[i]&&x[i]<='Z')?1:0);
	
	int s1 = func(1);
	int s2 = func(2);
	printf("%d",s1<s2?s1:s2);
}

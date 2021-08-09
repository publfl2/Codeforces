#include <stdio.h>
#include <vector>

struct str{
	char type;
	int height;
	int left;
	int right;
};
int a,b;
int left[1010][1010],right[1010][1010];
char x[1010][1010];

long long int func(int L, int R)
{
	if(L>R) return 0;
	
	int h = (L+R)/2;
	long long int S1 = func(L,h-1);
	long long int S2 = func(h+1,R);
	long long int ans = S1+S2;
	
	std::vector<str> V;
	for(int j=1;j<=a;j++)
	{
		if(V.empty()) V.push_back({x[j][h],1,left[j][h],right[j][h]});
		else
		{
			if(V.back().type==x[j][h])
			{
				int h2 = V.back().height + 1;
				int s = V.back().left>left[j][h]?V.back().left:left[j][h];
				int t = V.back().right<right[j][h]?V.back().right:right[j][h];
				V[V.size()-1] = {x[j][h],h2,s,t};
			}
			else V.push_back({x[j][h],1,left[j][h],right[j][h]});
		}
	}
	for(int i=0;i<V.size();i++)
	{
		V[i].left = V[i].left>L?V[i].left:L;
		V[i].right = V[i].right<R?V[i].right:R;
	}
	
	//printf("%d!!\n",h);
	//for(int i=0;i<V.size();i++) printf("%c %d %d %d!!\n",V[i].type,V[i].height,V[i].left,V[i].right);
	for(int j=1;j+1<V.size();j++)
	{
		if(V[j-1].height>=V[j].height&&V[j+1].height>=V[j].height)
		{
			int L = V[j-1].left;
			L = L>V[j].left?L:V[j].left;
			L = L>V[j+1].left?L:V[j+1].left;
			int R = V[j-1].right;
			R = R<V[j].right?R:V[j].right;
			R = R<V[j+1].right?R:V[j+1].right;
			ans += (long long int)(h-L+1)*(R-h+1);
		}
	}
	return ans;
}
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(x[i][j]==x[i][j-1]) left[i][j] = left[i][j-1];
			else left[i][j] = j;
		}
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=b;j>=1;j--)
		{
			if(x[i][j]==x[i][j+1]) right[i][j] = right[i][j+1];
			else right[i][j] = j;
		}
	}
	printf("%lld",func(1,b));
}

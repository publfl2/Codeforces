#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
std::vector<int> V[300010];
int x[300010];
int y[300010];
int max[300010];
int z[300010];
int func(int k,int h)
{
	int s = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==h) continue;
		z[s++] = x[V[k][i]];
	}
	if(s==0) return 0;
	std::sort(z,z+s);
	int m = z[s-1]+2;
	for(int i=0;i<s;i++) m = m>z[s-i-1]+i+2?m:z[s-i-1]+i+2;
	printf("%d %d : %d\n",k,h,m);
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==h) continue;
		int l = func(V[k][i],k);
		m = m>l?m:l;
	}
	return m;
}
int main()
{
	int a,b,c;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<a;i++)
	{
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<V[i].size();j++) z[j] = x[V[i][j]];
		std::sort(z,z+V[i].size());
		max[i] = z[V[i].size()-1]+1;
		for(int j=0;j<V[i].size();j++) max[i] = max[i]>z[V[i].size()-j-1]+j+1?max[i]:z[V[i].size()-j-1]+j+1;
		
	}
	for(int i=1;i<=a;i++) printf("%d ",max[i]);
	printf("\n");
	int d = 1;
	for(int i=2;i<=a;i++) if(max[d]<max[i]) d = i;
	
	int m = x[d];
	for(int i=0;i<V[d].size();i++)
	{
		int k = func(V[d][i],d);
		m = m > k ? m : k;
	}
	printf("%d",m>max[m]?m:max[m]);
}

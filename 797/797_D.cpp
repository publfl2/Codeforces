#include <stdio.h>
#include <set>

int x[100010],left[100010],right[100010];
int check[100010];
std::set<int> S;

void func(int k, int l, int r)
{
	if(l>r) return;
	
	if(l<=x[k]&&x[k]<=r) S.insert(x[k]);
	
	if(left[k]!=-1) func(left[k],l,x[k]-1);
	if(right[k]!=-1) func(right[k],x[k]+1,r);
}

int parent[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		x[i] = b;
		left[i] = c;
		right[i] = d;
		if(c!=-1) parent[c] = i;
		if(d!=-1) parent[d] = i;
	}
	
	int r = 1;
	for(int i=1;i<=a;i++) if(parent[i]==0) r = i;
	
	func(r,0,1000000000);
	
	int ans = 0;
	for(int i=1;i<=a;i++) if(S.find(x[i])==S.end()) ans++;
	printf("%d",ans);
}
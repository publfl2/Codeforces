#include <stdio.h>
#include <queue>

struct str{
	int x0;
	int y0;
	int l;
	int r;
};

bool operator<(str a, str b)
{
	if(a.l==b.l) return a.r>b.r;
	return a.l>b.l;
}

int check[2010][2010];
char x[2010][2010];
std::priority_queue<str> Q;
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int left,right;
	scanf("%d%d",&left,&right);
	for(int i=0;i<=a+1;i++) for(int j=0;j<=b+1;j++) x[i][j] = '*';
	for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
	for(int i=0;i<=a+1;i++) x[i][b+1] = '*';
	
	Q.push({c,d,0,0});
	int count = 0;
	while(!Q.empty())
	{
		int x0 = Q.top().x0;
		int y0 = Q.top().y0;
		int l = Q.top().l;
		int r = Q.top().r;
		Q.pop();
		
		if(l>left) continue;
		if(r>right) continue;
		if(x[x0][y0]=='*') continue;
		if(check[x0][y0]) continue;
		check[x0][y0] = 1;
		count++;
		Q.push({x0,y0+1,l,r+1});
		Q.push({x0,y0-1,l+1,r});
		Q.push({x0+1,y0,l,r});
		Q.push({x0-1,y0,l,r});
	}
	printf("%d",count);
}

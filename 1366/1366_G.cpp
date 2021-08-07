#include <stdio.h>
#include <string.h>
#define MAX 24680
struct segTree{
	short value[40010];
	void set(short ind, short val, int l=0, int r=10000, int v=1)
	{
		if(l==r) value[v] = val;
		else
		{
			short h = (l+r)/2;
			if(ind<=h) set(ind,val,l,h,2*v);
			else set(ind,val,h+1,r,2*v+1);
			value[v] = value[2*v]<value[2*v+1]?value[2*v]:value[2*v+1];
		}
	}
	int get(int L, int R, int l=0, int r=10000, int v=1)
	{
		if(L<=l&&r<=R) return value[v];
		else if(R<l) return MAX;
		else if(r<L) return MAX;
		else
		{
			int h = (l+r)/2;
			int s1 = get(L,R,l,h,2*v);
			int s2 = get(L,R,h+1,r,2*v+1);
			return s1<s2?s1:s2;
		}
	}
}T;

int sum[10010];
int cost(int L, int R)
{
	int C1 = sum[R] - sum[L-1];
	int C2 = T.get(L,R);
	if(C2>=0) return C1;
	else return C1-(2*C2);
}

int a,b;
char x[10010],y[10010];
short DP[10010][10010];
void func(int L, int R, int k, int l, int r)
{
	printf("%d %d %d %d %d!!\n",L,R,k,l,r);
	if(L>R) return;
	
	int h = (L+R)/2;
	int C = 0;
	for(int i=l;i<=r && i<h;i++)
	{
		int P = 0;
		if(x[i]!=y[k]) P = MAX/2;
		
		int v = DP[i][k-1] + cost(i,h-1) + P;
		if(DP[h][k]>v)
		{
			DP[h][k] = v;
			C = i;
		}
	}
	func(L,h-1,k,l,C);
	func(h+1,R,k,C,r);
}

int main()
{
	scanf("%s%s",x+1,y+1);
	a = strlen(x+1);
	b = strlen(y+1);
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='.') sum[i] = sum[i-1]-1;
		else sum[i] = sum[i-1]+1;
	}
	for(int i=0;i<=a;i++) T.set(i,sum[i]);
	
	for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) DP[i][j] = MAX;
	for(int i=0;i<=a;i++) DP[i][0] = 0;
	
	for(int j=1;j<=b;j++) func(0,a,j,0,a);
	
	for(int j=0;j<=b;j++)
	{
		for(int i=1;i<=a;i++) printf("%d ",DP[i][j]);
		printf("\n");
	}
}

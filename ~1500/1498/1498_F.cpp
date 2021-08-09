#include <stdio.h>
#include <vector>

std::vector<int> V[100010];
int prev[100010];
void func(int k, int p)
{
	prev[k] = p;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		func(V[k][i],k);
	}
}

int value[100010][50];
int x[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	func(1,0);
	for(int i=1;i<=a;i++)
	{
		int p = i;
		int c = 0;
		while(c<2*b&&p!=0)
		{
			value[p][c] ^= x[i];
			p = prev[p];
			c++;
		}
	}
	
	for(int i=1;i<=a;i++) for(int j=1;j<2*b;j++) value[i][j] ^= value[i][j-1];
	
	for(int i=1;i<=a;i++)
	{
		for(int j=0;j<2*b;j++) printf("%d ",value[i][j]);
		printf("!!\n");
	}
	
	
	for(int i=1;i<=a;i++)
	{
		int val = (value[i][2*b-1] ^ value[i][b-1]);
		int p = prev[i];
		int c = i;
		int d = 1;
		while(p!=0&&d<=2*b)
		{
			int val2;
			if(d<=b) val2 = (value[p][2*b-d]^value[p][b-d]);
			else val2 = value[p][2*b-d];
			if(d+1<=b) val2 ^= (value[c][2*b-d-1]^value[c][b-d-1]);
			else if(d+1<=2*b) val2 ^= value[c][2*b-d-1];
			val ^= val2;
			c = p;
			p = prev[p];
			d++;
		}
		
		if(val==0) printf("0 ");
		else printf("1 ");
	}
}
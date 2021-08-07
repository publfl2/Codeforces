#include <stdio.h>
#include <vector>
#include <stack>

int ansType = 1;
std::vector<int> V[300010];
int check[300010];
struct str{
	int s;
	int t;
	int k;
};
str Str(int s, int t, int k)
{
	str A;
	A.s = s;
	A.t = t;
	A.k = k;
	return A;
}
std::stack<str> St;
void func(int s, int t, int k)
{
	//printf("%d %d %d!!\n",s,t,k);
	if(s>=t) return;
	if(V[s].size()<=k)
	{
		for(int i=s;i<=t;i++)
		{
			if(V[i].size()>k)
			{
				St.push(Str(i,t,k));
				//func(i,t,k);
				break;
			}
		}
		return;
	}
	for(int i=s+1;i<=t;i++)
	{
		if(V[i].size()<=k)
		{
			ansType = 0;
			return;
		}
	}
	for(int i=t;i>=s;i--)
	{
		if(check[V[i][k]]==2)
		{
			for(int j=s;j<i;j++)
			{
				if(check[V[j][k]]==1) ansType = 0;
				else check[V[j][k]] = 2;
			}
			break;
		}
	}
	for(int i=s+1;i<=t;i++)
	{
		if(V[i][k]<V[i-1][k])
		{
			for(int j=s;j<i;j++)
			{
				//1 ¾È¹Ù²Þ 2 ¹Ù²Þ 
				if(check[V[j][k]]==1) ansType = 0;
				else check[V[j][k]] = 2;
			}
			if(check[V[i][k]]==2) ansType = 0;
			else check[V[i][k]] = 1;
			for(int j=i+1;j<=t;j++)
			{
				if(V[j][k]<V[j-1][k]) ansType = 0;
				if(check[V[j][k]]==2) ansType = 0;
				else check[V[j][k]] = 1;
			}
			//func(s,i-1,k+1);
			//func(i,t,k+1);
			break;
		}
	}
	int p = s;
	for(int i=s+1;i<=t;i++)
	{
		if(V[i][k]!=V[i-1][k])
		{
			St.push(Str(p,i-1,k+1));
			p = i;
		}
	}
	St.push(Str(p,t,k+1));
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		for(int j=1;j<=c;j++)
		{
			int d;
			scanf("%d",&d);
			V[i].push_back(d);
		}
	}
	St.push(Str(1,a,0));
	while(!St.empty())
	{
		str A = St.top(); St.pop();
		func(A.s,A.t,A.k);
		if(ansType==0)
		{
			printf("No");
			return 0;
		}
	}
	//func(1,a,0);
	if(ansType==0)
	{
		printf("No");
		return 0;
	}
	else
	{
		printf("Yes\n");
		int count = 0;
		for(int i=1;i<=b;i++) if(check[i]==2) count++;
		printf("%d\n",count);
		for(int i=1;i<=b;i++) if(check[i]==2) printf("%d ",i);
	}
}

#include <stdio.h>
#include <queue>
int x[500010][5];
int length[5];
int a;
int start[500010],end[500010];
long long int func(int s, int t ,int k)
{
	
	start[1] = length[k]+1;
	end[1] = 0;
	for(int j=1;j<=length[k];j++)
	{
		if(x[j][k]>=x[1][s])
		{
			start[1] = j;
			break;
		}
	}
	for(int j=length[k];j>=1;j--)
	{
		if(x[j][k]<=x[1][s]+a)
		{
			end[1] = j;
			break;
		}
	}
	
	
	for(int i=2;i<=length[s];i++)
	{
		start[i] = length[k]+1;
		end[i] = 0;
		for(int j=start[i-1];j<=length[k];j++)
		{
			if(x[j][k]>=x[i][s])
			{
				start[i] = j;
				break;
			}
		}
		for(int j=end[i-1];j<=length[k]+1;j++)
		{
			if(x[j][k]>x[i][s]+a)
			{
				end[i] = j-1;
				break;
			}
		}
	}
	long long int ans = 0;
	long long int sum = 0;
	
	int S = 1,E = 0;
	std::queue<int> Q;
	
	for(int i=1;i<=length[s];i++)
	{
		for(int j=end[i-1]+1;j<=end[i];j++)
		{
			while(1)
			{
				E++;
				if(x[E][t]>x[j][k]+a)
				{
					E--;
					Q.push(E);
					sum += E;
					break;
				}
			}
		}
		while(1)
		{
			if(x[S][t]<x[i][s]) S++;
			else break;
		}
		while(!Q.empty())
		{
			int value = Q.front();
			if(value<S)
			{
				sum -= value;
				Q.pop();
			}
			else break;
		}
		ans += (sum - (S-1)*Q.size());
	}
	printf("%lld!\n",ans);
	return ans;
}
int main()
{
	int b,c,d;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)!=-1)
	{
		length[1] = b;
		length[2] = c;
		length[3] = d;
		for(int i=1;i<=b;i++) scanf("%d",&x[i][1]);
		for(int i=1;i<=c;i++) scanf("%d",&x[i][2]);
		for(int i=1;i<=d;i++) scanf("%d",&x[i][3]);
		x[b+1][1] = x[c+1][2] = x[d+1][3] = 2100000000;
		printf("%lld\n",func(1,2,3)+func(1,3,2)+func(2,1,3)+func(2,3,1)+func(3,1,2)+func(3,2,1));
	}
}

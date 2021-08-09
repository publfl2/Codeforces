#include <iostream>
#include <string>
#include <deque>

struct query{
	int x1;
	int y1;
	int x2;
	int y2;
}ans[400010];
int p = 1;

std::string x[310][310],y[310][310];
std::deque<char> X,Y;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) std::cin>>x[i][j];
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) std::cin>>y[i][j];
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			while(!x[i][j].empty())
			{
				X.push_front(x[i][j].back());
				x[i][j].pop_back();
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			while(!y[i][j].empty())
			{
				Y.push_front(y[i][j].back());
				y[i][j].pop_back();
			}
		}
	}
	
	while(!X[1][1].empty())
	{
		char c = X[1][1].back();
		if(c=='1')
		{
			query[p++]={1,1,a,b-1};
			X[a][b].push_front(c);
		}
		else
		{
			query[p++]={1,1,1,2};
			X[1][2].push_front(c);
		}
		X[1][1].pop_back();
	}
	
	while(!X[a][b].empty())
	{
		char c = X[a][b].back();
		if(c=='1')
		{
			query[p++]={a,b,a,b-1};
			X[a][b-1].push_front(c);
		}
		else
		{
			query[p++]={a,b,1,2};
			X[1][2].push_front(c);
		}
		X[a][b].pop_back();
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(i==1&&j==1) continue;
			if(i==a&&j==b) continue;
			while(!X[i][j].empty())
			{
				char c = X[i][j].back();
				if(c=='1')
				{
					query[p++]={i,j,a,b};
					X[a][b].push_front(c);
				}
				else
				{
					query[p++]={i,j,1,1};
					X[1][1].push_front(c);
				}
				X[i][j].pop_back();
			}
		}
	}
	
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(i==1&&j==1) continue;
			if(i==a&&j==b) continue;
			
			while(!Y[i][j].empty())
			{
				char c = Y[i][j].back();
				if(c=='1')
				{
					query[p++]={a,b,i,j};
					X[a][b].pop_back();
				}
				else
				{
					query[p++]={1,1,i,j};
					X[1][1].pop_back();
				}
				Y[i][j].pop_back();
			}
		}
	}
	
	
}
